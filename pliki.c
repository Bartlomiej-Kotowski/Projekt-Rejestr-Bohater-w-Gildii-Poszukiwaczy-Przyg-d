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
int wczytaj_dane(const char *nazwapliku,bohater **tablica)
{
    FILE *plik=fopen(nazwapliku,"rb");
    if(plik==NULL)
    {
        return -1;
    }
    int ilosc;
    fread(&ilosc,sizeof(int),1,plik);
    *tablica=(bohater*)malloc(ilosc*sizeof(bohater));
    fread(*tablica,sizeof(bohater),ilosc,plik);
    fclose(plik);
    return ilosc;
}
void zwolnij_dane(bohater *tablica)
{
    free(tablica);
}