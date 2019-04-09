#include "bfile.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  BFILE *bfichier;
  int c;
  int stop = 0;

  FILE* f = fopen("test.txt","w");

  bfichier = bstart(f,"w");
  if (bfichier == NULL)
    {
      fprintf(stderr,"Erreur d'ouverture d'acces binaire en ecriture\n");
      exit(3);
    }
  c = getchar();
  while (!stop)
    {
      switch (c)
        {
        case '0':
          bitwrite(bfichier,0);
          break;
        case '1':
          bitwrite(bfichier,1);
          break;
        case 'e':
          stop = 1;
          break;
        }
      c = getchar();
    }
  bstop(bfichier);
  return 0;
}
