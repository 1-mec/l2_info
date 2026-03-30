#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define N 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int somme_finale=0;

struct trucs{
    long born_inf;
    long born_sup;
    long * sm_final;
    pthread_mutex_t locks ;
};

void * task(void * arg) {
    long a = (long)arg;
    long res = (a+1)*100;
    long res2 = 1*a*100;  
    long subTot = 0;

    for (long j = res2 ; j <= res; j++){
        subTot += j;
    }

   // pthread_mutex_lock(&lock);
    
    // début section critique

    somme_finale = somme_finale + subTot;

    // fin section critique

    //pthread_mutex_unlock(&lock);

    return (void *)subTot;
}


int main() {

    int x = 0;

    int sm_final = 0;

    pthread_t tid[N];

    for(long i=0;i<N;i++) {
        pthread_create(&tid[i], NULL, task,(void *)i);
    }
    
    for(int i=0;i<N;i++) {
        long subTot;
        pthread_join(tid[i], (void *)&subTot);
        //printf("chiffre récupéré =%d\n", subTot);
    }


    printf("somme truc = : %d\n",somme_finale);

}

//1. oui sinon c'est comme les sleep et tt
//2 
