#include <stdio.h>
#include <pthread.h>

#define N 10

const struct timespec ts = {0,  200000};

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * task(void * arg) {
  int * p = (int *)arg;
  for(int i=0;i<1000;i++) {
    nanosleep(&ts, NULL);

    pthread_mutex_lock(&lock);
    
    // début section critique

    *p = *p + 1;

    // fin section critique

    pthread_mutex_unlock(&lock);

  }
}

int main() {

  int x = 0;

  pthread_t tid[N];

  for(int i=0;i<N;i++) {
    pthread_create(&tid[i], NULL, task, &x);
  }

  for(int i=0;i<N;i++) {
    pthread_join(tid[i], NULL);
  }

  printf("x=%d\n", x);
}
