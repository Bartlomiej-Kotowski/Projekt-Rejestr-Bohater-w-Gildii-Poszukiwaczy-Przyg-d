#ifndef PLIKI_H
#define PLIKI_H
#include "bohater.h"
int zapisz_dane(const char *nazwapliku,const bohater *tablica,int ilosc );
bohater* wczytaj_dane(const char *nazwapliku,int *ilosc);
void zwolnij_dane(bohater *tablica);

#endif
