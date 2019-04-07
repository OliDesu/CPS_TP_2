#include "bit_operations.h"
#include "bfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int32_t get_bit(int32_t toto, int i){
   if(toto & (1<< i)){
       return 1;
   }
   else{
       return 0;
   }
}
int32_t set_bit(int32_t toto, int i){
   return toto  |= (1<< i);
}
int32_t clr_bit(int32_t toto, int i){
    return toto &=~(1<< i);
}

BFILE* bstart(FILE* f, const char* mode){
    if(f == NULL || mode == NULL) return NULL;
    BFILE* b = malloc(sizeof(BFILE));
    b->mode = malloc(sizeof((strlen(mode)+1)) * sizeof(char));
    b->indice =0;

    strcpy(b->mode,mode);
    if(b->mode[0]== 'r'){
        b->ouverture = 'r';
    }
    else{
        b->ouverture ='w';
    }
    return b;
}
int bstop(BFILE* fichier){
    if(fichier==NULL){
            return 0;
    }
        free(fichier->mode);
        free(fichier);
        return 0;
    
}
char bitread(BFILE *fichier){
	if(fichier->f==NULL){
		return -1;
	}
    if(fichier->ouverture == 'w') return -1;
	if(fichier->indice==8){
		fread(&fichier->caracterecourant,1,1,fichier->f);
		if(fichier->caracterecourant==(char)(0xFF)){
			fread(&fichier->caracterecourant,1,1,fichier->f);
			if(fichier->caracterecourant!=(char)(0xFF)){
				if(fichier->caracterecourant==0){
					return -1;
				}
				fread(&fichier->caracterecourant,1,1,fichier->f);
			}
		}
		
	}
	fichier->indice++;
	return ((fichier->caracterecourant>> (8-fichier->indice)) & 1);
}
int bitwrite(BFILE *fichier, char bit){
    if(fichier->ouverture == 'r') return -1;
    if(fichier->f == NULL){
		return -1;
	}
	if(bit){
		fichier->caracterecourant |= (1<<(7-fichier->indice));
	}
	else{
		fichier->caracterecourant &= ~(1<<(7-fichier->indice));
	}
	fichier->indice++;
	if(fichier->indice==8){
		if(fichier->caracterecourant==(char)(0xFF)){
			fwrite(&fichier->caracterecourant,1,1,fichier->f);
		}
		fwrite(&fichier->caracterecourant,1,1,fichier->f);
		fichier->indice=0;
	}
	return 0;
}
int beof(BFILE* fichier){
	return(bitread(fichier)==-1);
}