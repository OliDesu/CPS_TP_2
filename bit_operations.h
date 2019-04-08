#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t get_bit(int32_t toto, int i);
int32_t set_bit(int32_t toto, int i);
int32_t clr_bit(int32_t toto, int i);
BFILE* bstart(FILE* f, const char* mode);
int bstop (BFILE *fichier);
char bitread(BFILE *fichier);
int bitwrite(BFILE *fichier, char bit);
int beof(BFILE* fichier);
