#include <stdio.h>
#include <stdlib.h>

// Ecrire un programme faisant le compte et l’affichage du nombre de caractère de chaque argument en ligne de commande.

int main(int argc , char * argv[]){
	int lon = 0;
	while(argv[1][lon] != '\0'){
		lon ++;
	}
	for(int i = 0; i < lon ; i ++){
		printf("place %d du mot = %c\n",i,argv[1][i]);
	}
	return 0;
}
