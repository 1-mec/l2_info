#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>

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
	unsigned char c;
	int a;
	
	do{
		a = read(fd, &c, 1);
		if (a == 1){
			printf("%x\n", c);
		}
	} while (a > 0); //affiche trop (2 fois a)
	close(fd);

}
