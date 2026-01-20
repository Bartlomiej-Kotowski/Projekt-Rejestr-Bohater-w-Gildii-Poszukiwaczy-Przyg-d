#include <stdio.h>
#include "menu.h"
#include "funkcje.h"
#include "pliki.h"

int MenuWybor(){
    int wybor;
    printf("Wybierz opcję (0-8): ");
    scanf("%d", &wybor);
    return wybor;    
}

void MenuWyswietl(){
    while(1){
    printf("=== Rejestr Bohaterów Gildii Poszukiwaczy Przygód ===\n");
    printf("1. Zarejestruj nowego bohatera\n");
    printf("2. Wyrejestruj bohatera\n");
    printf("3. Wyświetl listę bohaterów\n");
    printf("4. Wyszukaj bohatera\n");
    printf("5. Modyfikuj dane bohatera\n");
    printf("6. Posortuj liste bohaterów\n");
    printf("7. Wczytaj liste z pliku\n");
    printf("8. Zapisz liste do pliku\n");
    printf("9. Zwolnij pamięć\n");
    printf("0. Wyjście z programu\n");
    switch(MenuWybor()){
        case 1:
            
            continue;
        case 2:
            
            continue;
        case 3:
            
            continue;
        case 4:
            
            continue;
        case 5:
            
            continue;
        case 6:
            
            continue;
        case 7:
            
            continue;
        case 8:
            
            continue;
        case 0:
            printf("Zamykanie programu...\n");
            break;
        default:
            printf("Nieprawidłowy wybór. Spróbuj ponownie.\n");
            continue;
        }
        break;
    }
}



