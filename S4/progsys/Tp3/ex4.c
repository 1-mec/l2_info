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
	int fd = open("fic1",
		O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP 
	);
	if (fd == -1){
		perror("Création du fichier");
		exit(-1);
	}
	unsigned char c;
	int i;
	
	for (i=0; i<256; i++){
		c=(char)i;
		write(fd,&c,1);
	}
	close(fd);

}


