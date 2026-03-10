#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#define NS_ATTENTE 500000000

int total = 0;

struct timespec attente = {0, NS_ATTENTE};

void traiter_signal(int signum) {
    printf("\nsignal n° = %d recu\n", signum);
    fflush(stdout);
    if (signum == SIGINT) {
        printf("arret dans ... ");
        fflush(stdout);
        for(int i=5;i>0;i--) {
            nanosleep(&attente, 0);
            printf("%d ", i);
            fflush(stdout);
        }

        printf("\nTotal = %d !\n", total);
        exit(0);
    }
}

int main() {
    printf("getpid = %d\n", getpid());
    fflush(stdout);

    // mise en place du traitement des signaux SIGINT et SIGUSR1

    struct sigaction act1;
    sigemptyset(&(act1.sa_mask));
    act1.sa_flags = 0;
    act1.sa_handler = traiter_signal;
    sigaction(SIGINT, &act1, NULL);
    sigaction(SIGUSR1, &act1, NULL);
    printf("===================================================\nInsert un nombre\n");
    int tmp;
    while(1) {
        int nb = scanf("%d", &tmp);
        total += tmp;
    }
    // attend une saisie au clavier

    getchar();
    printf("après getchar()\n");

    return 0;
}
