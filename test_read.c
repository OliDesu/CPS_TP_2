#include "bfile.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	BFILE *bfichier;
	char bit;
		FILE* f = fopen(argv[1],"r");
		bfichier = bstart(f,"r");
	if (bfichier == NULL){
		fprintf(stderr,"Erreur d'ouverture d'acces binaire en lecture\n");
		exit(3);
	}
	bit = bitread(bfichier);
	while (bit!=-1){
		switch (bit){
		case 0:
			printf("0");
			break;
		case 1:
			printf("1");
			break;
		default:
			printf("?");
		}
		bit = bitread(bfichier);
	}
	printf("\n");
	bstop(bfichier);
	return 0;
}
