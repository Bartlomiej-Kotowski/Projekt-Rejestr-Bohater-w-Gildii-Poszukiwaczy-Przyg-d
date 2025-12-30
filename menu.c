#include<stdio.h>
#include "menu.h"

void MenuWyswietl(){
    printf("=== Rejestr Bohaterów Gildii Poszukiwaczy Przygód ===\n");
    printf("1. Zarejestruj nowego bohatera\n");
    printf("2. Wyrejestruj bohatera\n");
    printf("3. Wyświetl listę bohaterów\n");
    printf("4. Wyszukaj bohatera\n");
    printf("5. Modyfikuj dane bohatera\n");
    printf("6. Posortuj liste bohaterów\n");
    printf("7. Wczytaj liste z pliku\n");
    printf("8. Zapisz liste do pliku\n");
    printf("0. Wyjście z programu\n");
}
int MenuWybor(){
    int wybor;
    printf("Wybierz opcję (0-8): ");
    scanf("%d", &wybor);
    return wybor;    
}

switch(wybor){
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        case 0:
            printf("Zamykanie programu...\n");
            break;
        default:
            printf("Nieprawidłowy wybór. Spróbuj ponownie.\n");
    }
