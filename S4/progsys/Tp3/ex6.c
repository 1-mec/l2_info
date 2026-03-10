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
	int fd = open("fic2",
		O_WRONLY | O_CREAT | O_TRUNC | O_EXCL,
		S_IRUSR | S_IWUSR | S_IRGRP 
	);
	if (fd == -1){
		perror("Le fichier fic2 existe déjà.");
		exit(-1);
	}
	unsigned char c;
	int i;
	lseek(fd, 768, SEEK_SET);
	for (i=0; i<256; i++){
		c=(char)i;
		write(fd,&c,1);
	}
	close(fd);
	return 0;
	//ex6 : 1) 768 + 256 octets
	// 2) des caractères vides 
}


