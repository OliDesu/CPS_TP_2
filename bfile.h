#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct fichier{
   // A FAIRE
}BFILE;

BFILE* bstart(FILE* f, const char* mode);
int bstop(BFILE* fichier);
char bitread(BFILE *fichier);
int bitwrite(BFILE *fichier, char bit);
int beof(BFILE *fichier);