#include <stdio.h>
#include <funkcje.h>

const char *kalsa[]={"WOJOWNIK","MAG","KAPLAN","LOTRZYK","LOWCA","DRUID"};
const char *rasa[]={"CZLOWIEK","ELF","KRASNOLUD","ORK","TIEFLING"};
const char *status[]={"AKTYWNY","NA_MISJI","RANNY","ZAGINIONY","ZAWIESZONY"};


bohater* dadaj_bohatera(bohater *head){
    bohater *nowy=(bohater*)malloc(sizeof(bohater));
    if(nowy==NULL){
        printf("blad nie udalo sie przydzielic pamieci\n");
		return head;
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
    scanf("%d",&nowy->poziom);
    printf("Punkty reputacji (1-100):\n");
    scanf("%d",&nowy->punkty);
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


bohater* usun_bohatera(bohater *head){
	if(head==NULL){
		printf("Baza jest pusta nie ma bohaterów do usunięcia\n");
		return NULL;
	}
	char imie_do_u[MAXIMIE];
	printf("Podaj imie bohatera do usuniecia:\n");
	scanf("%100s",imie_do_u);
	bohater *biezancy=head;
	while(biezancy!=NULL){
		if(strcmp(biezancy->imie, imie_do_u)==0){
			if(biezancy->status==NA_MISJI){
				printf("Odmowa dostępu bohater znajduje sie aktualnie na misji:\n");
				return head;
			}
			if(biezancy->prev!=NULL){
				biezancy->prev->next=biezancy->next;

			}else{
				head=biezancy->next;
			}
			if(biezancy->next!=NULL){
				biezancy->next->prev=biezancy->prev;
			}
			printf("Bohater %s zostal wymazany z rejestru\n",imie_do_u);
			free(biezancy);
			return head;
		}
		biezancy=biezancy->next;
	}
	printf("Nie znaleziono bohatera o imieniu %s\n",imie_do_u);
	return head;
}
