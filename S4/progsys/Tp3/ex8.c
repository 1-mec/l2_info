#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <ctype.h>

#define BUF_SIZE 32

int verif(int c){
	if (!isspace(c) && !isprint(c)){
		return 0;
	}
	else {
		return 1;
	}
}

int main(int argc, char *argv[]) {
	/*
	- si existant : ouverture
	- si inexistant : création 
	*/
	// TRUNC = vider automatiquement contenu du fichier
	int fd = open(argv[1],
		O_RDONLY
	);
	if (fd == -1){
		perror("Création du fichier");
		exit(-1);
	}
	int a;
	
	do{
		char c[BUF_SIZE+1];
		a = read(fd, &c, BUF_SIZE);
		if (a >= 1){
			for (int i = 0; i < a; i++){
				if (!verif(c[i])){
					execl("/bin/hexdump", "hexdump", "-c", argv[1], NULL);
					exit(1);
				}
				else{
					printf("test");
				}
			}
		}
	} while (a > 0); //affiche trop (2 fois a)
	execl("/bin/more", "more", argv[1], NULL);
	close(fd);
}

