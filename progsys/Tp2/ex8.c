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

    for (int i = 0; i < N; i++) {
        marche[i] = 1;
    }

    for(int i=0;i<N;i++) {
        int pid = fork();
        if (pid == 0) init_processus_fils();
        t[i] = pid;
    }
    printf("Processus fils : ");
    for(int i=0;i<N;i++) {
        printf("%d ", t[i]);
    }
    printf("\n");

    int r;
    int status;
    int temp = N;
    int temp2 = 0;
    int cnt ;
    do {
        printf("avant waitpid ...\n");
        r = waitpid(-1, &status, WSTOPPED | WCONTINUED );
        printf(" ... waitpid a retourné %d\n\n", r);
        for(int i=0;i<temp;i++) {
            if (r == t[i]) {
                if (WIFSTOPPED(status)) {
                    marche[i] = 0;
                    printf("%d est en pause(à mimir) \n",t[i]);
                    int new_pid = fork();
                    if (new_pid == 0) {
                        init_processus_fils();
                        temp2++;
                    }
                    t[i] = new_pid;
                    printf("Nouveau fils créé : %d\n", new_pid);


                    init_processus_fils();
                    temp2 = temp++;
                } else if(WIFCONTINUED(status)) {
                    marche[i] = 1;
                    printf("%d charbonne smr\n",t[i]);
                }
            }
        }

        temp = temp2;
        cnt = temp;
        marche[cnt] = 1;


        printf("Marche ou pas\n");
        for(int i=0;i<temp;i++) {
            printf("état = %d\n",marche[i]);
        }

    } while (r != -1);

    printf("fin du processus père\n");
    //faire des tets sur plusieurs terminals
}

//  a - il à retourné les autre pid
//  b - tant qu'on à pas entré ctrl+c pour sortir
//  c - le processus parent s'eteint mais les fils sont toujours là
