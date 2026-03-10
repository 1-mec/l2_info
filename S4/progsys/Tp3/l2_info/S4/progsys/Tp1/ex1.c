#include <stdio.h>
#include <stdlib.h>

int main(int arg , char * argw[]){
	if ( arg != 2 ){
		printf("Entrez un mot\nPar exemple %s\n","Hello");
		return -1;
	}
	
	int vrai = 1;
	int length = 0;
	while (argw[1][length] != '\0'){
		length ++;
	}
	printf("============================================================\nla taille du mot == %d\n",length);
	
	for(int i = 0; i < length/2 ; i++){
		if (argw[1][i] != argw[1][length-1-i]){
			printf("Ce n'est pas un palyndrome\n");
			return 0;
		} 
	}
	printf("C'est un palyndrome\n");
	return 0;
}
