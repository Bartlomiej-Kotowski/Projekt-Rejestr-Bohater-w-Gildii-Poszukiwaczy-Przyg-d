#ifndef PLIKI_H
#define PLIKI_H
#include "bohater.h"
int zapisz_dane(const char *nazwapliku,bohater *head);
bohater* wczytaj_dane(const char *nazwapliku);
void zwolnij_dane(bohater *head);

#endif
