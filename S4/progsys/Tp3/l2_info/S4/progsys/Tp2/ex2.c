#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define N 10
#define NS_ATTENTE 500000000

struct timespec attente = {0, NS_ATTENTE};

void compter(int n) {
    int i =0;
    while( i <= n){
        nanosleep(&attente, 0);
        printf("%d pid = %d\n",i,getpid());
        i++;
    }
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Veuillez entrer 2 entiers positifs en arguments\n");
        exit(-1);
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    if (x<=0 || y<=0) {
        printf("Veuillez entrer 2 entiers positifs en arguments\n");
        exit(-1);
    }
    //a
    printf("============================================\n\tbase :\n");
    if(fork() != 0){
        wait(NULL);
        printf("comptage de x\n");
        compter(x);
    }else {
        printf("comptage de y\n");
        compter(y);
    }
    
}

// a
//  Que constatez-vous quand vous lancer le programme avec y > x ?
// -> ça s'exécute après le shell sans wait
// 
// Que faut-il faire pour que le processus père affiche un message après avoir affiché tous les
// entiers de 1 à x et que le processus fils se soit terminé (indépendamment les valeurs de x et y) ?
// -> Quand x < y, comptage(y) se relance de 0