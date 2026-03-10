#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int fd = open("soustotaux",
		O_RDWR | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP
	);
	close(fd);
	int taille = 20;
	int nb_processus = 10;
	for (int i = 0; i < nb_processus; i++) {
        int pid = fork();
        if (pid == -1) {
            exit(-1);
        }
        if (pid == 0) {
            int borne_inf = i*100+1;
            int borne_sup = (i+1)*100;
            
            
            int somme = 0;
            for (int j = borne_inf; j <= borne_sup; j++) {
                somme += j;
            }
            int f1 = open("soustotaux",
				O_RDWR,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP
			);
			flock(f1, LOCK_EX);
			lseek(f1, taille*i, SEEK_SET);
            char idk[taille];
			sprintf(idk, "%d", somme);
			//printf("gooogoogaga : %s\n", idk);
			taille = strlen(idk);
			//printf("taille : %d\n", taille);
			write(f1, &idk, taille);
			 //+1 pour laisser un espace jsp
			flock(f1, LOCK_UN);
			close(f1);
            exit(0);
        } else {
            printf("Création du porcessus %d\n", pid);
        }	

    }
     for (int i = 0; i < nb_processus; i++){
    	pid_t pid_fils = wait(NULL);
		printf("terminaison du processus fils %d\n", pid_fils);
	 }
	 printf("Tous les processus fils sont terminés\n");
	 int fs = open("soustotaux",
				O_RDWR,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP
			);
	 lseek(fs, 0, SEEK_SET);
	 char r1[taille];
	 int res_fin = 0;
	 for (int i = 0; i < nb_processus; i++){
		 int a = read(fs, &r1, taille);
		 res_fin += atoi(r1);
		 //lseek(fs, taille, SEEK_CUR);
	 }
	 printf("%d", res_fin); 
	 close(fs);
	 return -1;
}	
		 


