#include "pliki.h"
#include <stdio.h>
int zapisz_dane(const char *nazwapliku,const bohater *tablica,int ilosc)
{
    FILE *plik=fopen(nazwapliku,"wb");
    if(plik==NULL)
    {
        return -1;
    }
    fwrite(&ilosc,sizeof(int),1,plik);
    fwrite(tablica,sizeof(bohater),ilosc,plik);
    fclose(plik);
    return 0;
}
