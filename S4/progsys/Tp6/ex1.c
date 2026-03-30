#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <time.h>

const int n = 10;
const int nb_process = 2;
const char bienvenue[] = "Entrez votre nom";
const char bienvenue[] = "Entrez votre enchère";

struct sembuf P[] = { {0, -1, 0} };  // opération P sur le sémaphore n°0 : tente d'acquérir ce sémaphore
struct sembuf V[] = { {0,  1, 0} };  // opération V sur le sémaphore n°0 : incrémente ce sémaphore

struct enchere{
	double max;
	char nom[32];
};

void count(int, int);

int main() {

  int *a;

  int id_shm;
  int id_sem; // identifiant du tableau de sémaphore

  id_sem = semget(IPC_PRIVATE, 1, S_IWUSR | S_IRUSR | IPC_CREAT);
  printf("id du tableau de sémaphore = %d\n", id_sem);

  // valeur initiale du sémaphore n°0 à 1
  if (semctl(id_sem, 0, SETVAL, 1) == -1) {
    perror("semctl");
  }

  // création d'un segment de mémoire partagé contenant un entier
  id_shm = shmget(IPC_PRIVATE, sizeof(int), S_IWUSR | S_IRUSR | IPC_CREAT);
  printf("id du segment de mémoire partagé = %d\n", id_shm);

  // attache le segment de mémoire partagé
  a = (int *)shmat(id_shm, NULL, 0);
  *a = 0;

  struct enchere enchere;
  printf("Veuillez entrer votre nom :\n");
  char s[48];
  enchere.nom = scanf("%s ", &s);
  printf("-> %s",enchere.nom);
  shmctl(id_shm, IPC_RMID, NULL);


  return 0;
}

void count(int id_shm, int id_sem) {
  // exécuté par chaque processus fils

  struct timespec ts = {0, 50000};
  
  // récupère un pointeur sur le segment de mémoire partagé
  int * a = (int *)shmat(id_shm, NULL, 0);

  // incrémente n fois l'entier contenu dans le segment de mémoire partagé
  for(int i=0; i<n; i++) {
    nanosleep(&ts, NULL);
    semop(id_sem, P, 1);  // opération P, tente d'acquérir le sémaphore n°0
    *a = *a + 1;
    semop(id_sem, V, 1);  // opération V, libère le sémaphore n°0
  }
}
