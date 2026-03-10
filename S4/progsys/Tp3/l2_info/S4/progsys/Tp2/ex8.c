#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 3

void init_processus_fils() {
    while (1) {
        sleep(1);
    }//slide 37&38
}


int main() {
    int t[N];
    int marche[N];
    int en_pause[N];
    int compteur = N;

    for (int i = 0; i < N; i++) {
        marche[i] = 1;
    }

    for(int i=0;i<N;i++) {
        int pid = fork();
        if (pid == 0) init_processus_fils();
        t[i] = pid;
        en_pause[i] = 0;
    }

    printf("Processus fils : ");
    for(int i=0;i<N;i++) {
        printf("%d ", t[i]);
    }

    printf("\n");

    int r;
    int status;
    do {
        printf("avant waitpid ...\n");
        r = waitpid(-1, &status, WSTOPPED | WCONTINUED );
        printf(" ... waitpid a retourné %d, le status = %d\n\n", r,status);
        if (r > -1){
            if (WIFSTOPPED(status)){
                printf(" ... à mimir\n", WIFSTOPPED(status));
            } else if(WIFCONTINUED(status)){
                printf(" ... relancé\n", WIFCONTINUED(status));
            }
        }
        for(int i = 0 ; i< N; i++){
            if(t[i]==r){
                if (WIFSTOPPED(status)){
                    en_pause[i] = 1;
                } else if(WIFCONTINUED(status)){
                    en_pause[i] = 0;
                } else if (WIFSIGNALED(status)){        
                    int temp = fork();
                    en_pause[i] = 0;
                    if(temp == 0){
                        init_processus_fils();
                    }
                    printf("Création du procéssus %d\n",temp);
                }
            }
        }
        for(int i = 0; i < N;i++){
            printf("processus no %d",t[i]);
            if (en_pause[i]){
                printf("en pause");
            }
            printf(" | ");
        }


        

    } while (r != -1);

    printf("fin du processus père\n");
}