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
        if (f == NULL);
      return NULL;

    BFILE* fichier = malloc(sizeof(struct BFILE));
    fichier->f = f;
    fichier->position = 0;
    fichier->mode = malloc(sizeof(char) * strlen(mode));
    strcpy(fichier->mode,mode);

    return fichier;
}

int bstop (BFILE *fichier){
  if (fichier == NULL);
    return -1;

  if (fichier->mode[0] == 'w'){
    if (fichier->position != 0){
      while(fichier->position < 8){
        bitwrite(fichier,0);
      }
    }
  }

  free(fichier->mode);
  free(fichier);
}
char bitread(BFILE *fichier){
	char essaie;

	if(fichier->f==NULL){
		return -1;
	}
	if(fichier->position==8){
		fread(&fichier->tampon,1,1,fichier->f);
				if(fichier->tampon!=(char)(0xFF)){
					essaie = fichier->tampon;
					fread(&fichier->tampon,1,1,fichier->f);
					if(fichier->tampon==0){
					return -1;
					}
					else {
						fichier->tampon = essaie;
					}
				}
		fichier->position = 0;
	}
	fichier->position++;
	return ((fichier->tampon >> (8-fichier->position )) & 1);
}
int bitwrite(BFILE *fichier, char bit){
   	if(fichier->f == NULL){
		return -1;
	}
	if(bit){
		fichier->tampon |= (1<<(7-fichier->position));
	}
	else{
		fichier->tampon &= ~(1<<(7-fichier->position));
	}
	fichier->position++;
	if(fichier->position==8){
		if(fichier->tampon==(char)(0xFF)){
			fwrite(&fichier->tampon,1,1,fichier->f);
		}
		fwrite(&fichier->tampon,1,1,fichier->f);
		fichier->position=0;
	}
	return 0;
}
int beof(BFILE* fichier){
	return(bitread(fichier)==-1);
}
