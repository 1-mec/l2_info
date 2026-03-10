#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10
#define NS_ATTENTE 200000000

struct timespec attente = {0, NS_ATTENTE};

int main() {
/*
    printf("==========================================================\npetit a)\n");
    for(int i=1;i<=N;i++) {
        nanosleep(&attente, 0);
        printf("%d/%d\n", i, N);
        fflush(stdout);
    }*/
    printf("==========================================================\npetit b)\n");
    fork();
    printf("ppid : %d et pid : %d avant boucle\n",getppid(),getpid());    
    for(int i=1;i<=N;i++) {
        nanosleep(&attente, 0);
        printf("%d/%d, pid = %d\n", i, N,getpid());
        fflush(stdout);
    }
}


//a) Serait-il possible d’implémenter nanosleep sans faire appel au noyau ? Quelles seraient les difficultés ? 
//-> Oui , la gestion du multi-threading on bloquerai un coeur , 

// b) Mettre en œuvre l’appel système fork(), permettant à un « programme qui s’exécute », c’est à 
// dire un processus, de se dédoubler
// Comment savoir si l’on est dans le processus père ou dans le processus fils, afin d’effectuer des
// actions différentes dans l’un ou l’autre, tel que demandé dans cet exercice ?
// -> getpid et getppid

