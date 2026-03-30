#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define N 10


int somme_finale=0;

struct trucs{
    long res2;
    long res;
    long * sm_final;
    pthread_mutex_t locks ;
};

void * task(void * arg) {
    struct trucs * t = struct () 
    long a = (long)arg;

    for (long j = res2 ; j <= res; j++){
        subTot += j;
    }

   pthread_mutex_lock(&lock);
    
    // début section critique

    somme_finale = somme_finale + t->sm_final;

    // fin section critique

    pthread_mutex_unlock(&lock);

}


int main() {

    int x = 0;

    int sm_final = 0;

    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_t tid[N];

    struct trucs t;

    for(long i=0;i<N;i++) {
        t.res = (a+1)*100;
        t.res2 = 1*a*100;  
        t.subTot = 0;
        pthread_create(&tid[i], NULL, task,(void *)i);
    }
    
    for(int i=0;i<N;i++) {
        long subTot;
        pthread_join(tid[i], (void *)&subTot);
        //printf("chiffre récupéré =%d\n", subTot);
    }


    printf("somme truc = : %d\n",sm_final);

}

//1. oui sinon c'est comme les sleep et tt
//2 
