#include <stdio.h>
#include "menu.h"
#include "funkcje.h"
#include "pliki.h"

int MenuWybor(){
    int wybor;
    printf("Wybierz opcje (0-9): ");
    if(scanf("%d", &wybor)!=1){
		while(getchar() != '\n');
		return -1;
	}
    return wybor;    
}

void MenuWyswietl(bohater *head){
    while(1){
    printf("=== Rejestr Bohaterow Gildii Poszukiwaczy Przygod ===\n");
    printf("1. Zarejestruj nowego bohatera\n");
    printf("2. Wyrejestruj bohatera\n");
    printf("3. Wyswietl liste bohaterow\n");
    printf("4. Wyszukaj bohatera\n");
    printf("5. Modyfikuj dane bohatera\n");
    printf("6. Posortuj liste bohaterow\n");
    printf("7. Wczytaj liste z pliku bohaterowieI.txt\n");
    printf("8. Zapisz liste do pliku bohaterowieE.txt\n");
    printf("9. Zwolnij pamiec\n");
    printf("0. Wyjscie z programu\n");
    switch(MenuWybor()){
        case 1:
            head=dodaj_bohatera(head);
            continue;
        case 2:
            head=usun_bohatera(head);
            continue;
        case 3:
            wyswietl_liste(head);
            continue;
        case 4:
            wyszukaj_bohatera(head);
            continue;
        case 5:
            edytuj_bohatera(head);
            continue;
        case 6:
            int tryb;
            printf("Wybierz tryb sortowania:\n");
            printf("1. Alfabetycznie po imieniu\n");
            printf("2. Rosnaco po poziomie\n");
            if(scanf("%d", &tryb)!=1 || (tryb!=1 && tryb!=2)){
		        while(getchar() != '\n');
                printf("Nieprawidlowy wybor. Sprobuj ponownie :( \n");
		        return -1;
	        }
            sortuj_bohatera(head, tryb);
            continue;
        case 7:           
            head=wczytaj_dane("bohaterowieI.txt");
            continue;
        case 8:
            zapisz_dane("bohaterowieE.txt", head);
            continue;
        case 9:
            zwolnij_liste(head);
            head = NULL;
            continue;
        case 0:
            printf("Zamykanie programu...\n");
			zwolnij_liste(head);
			return NULL;
        default:
            printf("Nieprawidlowy wybor. Sprobuj ponownie :( \n");
            continue;
        }
        break;
    }
}



