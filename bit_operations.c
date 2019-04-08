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
    //CODE
}

int bstop (BFILE *fichier){
  
}
char bitread(BFILE *fichier){
	//CODE
}
int bitwrite(BFILE *fichier, char bit){
    //CODE
}
int beof(BFILE* fichier){
	//CODE
}
