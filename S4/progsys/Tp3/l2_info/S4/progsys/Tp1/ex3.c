#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int nb_ligne;
	int nb_col;
	int **m;
}Matrice;

// a

Matrice alloue(int nb_ligne, int nb_col){
	Matrice m1;
	m1.nb_ligne = nb_ligne;
	m1.nb_col = nb_col;
	m1.m = malloc(sizeof(int *) * nb_ligne);
	for (int i = 0; i < nb_col ; i ++){
			m1.m[i] = malloc(sizeof(int) * nb_col );
			printf("c'est bon pour nb_ligne %d\n",i+1);
	}
	return m1;
}

// b

void aff_mat( Matrice mat){
	printf("mat.nb_col %d\n",mat.nb_col);
	printf("mat.nb_ligne %d\n",mat.nb_ligne);
	for(int i = 0; i < mat.nb_ligne ; i++){
		for(int y= 0; y < mat.nb_col;y++){
			printf ("[%d]",mat.m[i][y]);
		}
		printf("\n");
	}
}
//c
void libere(Matrice mat) {
	for (int i = 0 ; i<mat.nb_ligne; i++) {
		free(mat.m[i]);
	}
	free(mat.m);
	mat.nb_col = 0;
	mat.nb_ligne = 0;
}
//d

Matrice calc(Matrice m1,Matrice m2) {
	Matrice m3 = alloue(m1.nb_ligne,m2.nb_col);

	for (int i = 0; i < m1.nb_ligne; ++i) {
		for (int j = 0; j < m2.nb_col ; ++j) {
			m3.m[i][j] = 0;
			for (int z = 0; z< m1.nb_col; z++) {
				m3.m[i][j]+=m1.m[i][z]*m2.m[z][j];
			}
		}
	}
	return m3;
}

int main(){
	Matrice mat1 = alloue(2,2);
	mat1.m[0][0] = 1;
	mat1.m[0][1] = 2;
	mat1.m[1][0] = 3;
	mat1.m[1][1] = 4;
	printf("=================================\n");
	Matrice mat2 = alloue(2,2);
	mat2.m[0][0] = 2;
	mat2.m[0][1] = 1;
	mat2.m[1][0] = 5;
	mat2.m[1][1] = 3;
	/*
	printf("=================================\nMat1 :\n");
	aff_mat(mat1);
	printf("=================================\nMat2 :\n");
	aff_mat(mat2);*/
	printf("=================================\n");
	Matrice mat3 = calc(mat1,mat2);
	printf("=================================\nMat3:\n");
	aff_mat(mat3);
	printf("=================================\nFree\n");
	libere(mat3);
	aff_mat(mat3);
	return 0;
}
