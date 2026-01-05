#include <stdio.h>

const char *kalsa[]={"WOJOWNIK","MAG","KAPLAN","LOTRZYK","LOWCA","DRUID"};
const char *rasa[]={"CZLOWIEK","ELF","KRASNOLUD","ORK","TIEFLING"};
const char *status[]={"AKTYWNY","NA_MISJI","RANNY","ZAGINIONY","ZAWIESZONY"};


bohater* dadaj_bohatera(bohater *head){
    bohater *nowy=(bohater*)malloc(sizeof(bohater));
    if(nowy==NULL){
        print("blad nie udalo sie przydzielic pamieci\n"
    }
    printf("Podaj imie postaci:\n");
    scanf("%100s",nowy->imie);
    int r;
    printf("0-Człowiek\n");
    printf("1-Elf\n");
    printf("2-Krasnolud\n");
    printf("3-Ork\n");
    printf("4-Tiefling\n");
    printf("Wybierz rase\n");
    scanf("%d",&r);
    nowy->rasa=(enum rasabohatera)r;
    int k;
    printf("0-Wojownik\n");
    printf("1-Mag\n");
    printf("2-Kaplan\n");
    printf("3-Lotrzyk\n");
    printf("4-Lowca\n");
    printf("5-Druid\n");
    printf("Wybierz klase\n");
    scanf("%d",&k);
    nowy->klasa=(enum klasabohatera)k;
    printf("Podaj poziom bohatera:\n");
    scanf("%lf",&nowy->poziom);
    printf("Punkty reputacji (1-100):\n");
    scanf("%lf",&nowy->pukty);
    int s;
    printf("0-Aktywny\n");
    printf("1-Na_misji\n");
    printf("2-Ranny\n");
    printf("3-Zaginiony\n");
    printf("4-Zawieszony\n");
    printf("Wybierz status\n");
    scanf("%d",&s);
    nowy->status=(enum statusbohater)s;
    nowy->next=head;
    nowy->prev=NULL;
    if(head!=NULL){
    head->prev=nowy;
    }
    printf("Bohater %s dodany do bazy pomysnie\n",nowy->imie);
    return nowy;
}
