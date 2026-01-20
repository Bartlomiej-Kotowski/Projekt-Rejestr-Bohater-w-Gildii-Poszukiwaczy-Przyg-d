#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bohater.h"

const char *klasy[]={"WOJOWNIK","MAG","KAPLAN","LOTRZYK","LOWCA","DRUID"};
const char *rasa[]={"CZLOWIEK","ELF","KRASNOLUD","ORK","TIEFLING"};
const char *status[]={"AKTYWNY","NA_MISJI","RANNY","ZAGINIONY","ZAWIESZONY"};


bohater* dodaj_bohatera(bohater *head){
    bohater *nowy=(bohater*)malloc(sizeof(bohater));
    if(nowy==NULL){
        printf("blad nie udalo sie przydzielic pamieci\n");
		return head;
    }
    printf("Podaj imie postaci:\n");
    scanf("%100s",nowy->imie);
    int r;
    printf("0-Czlowiek\n");
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
    scanf("%d",&nowy->reputacja);
    int s;
    printf("0-Aktywny\n");
    printf("1-Na_misji\n");
    printf("2-Ranny\n");
    printf("3-Zaginiony\n");
    printf("4-Zawieszony\n");
    printf("Wybierz status\n");
    scanf("%d",&s);
    nowy->status=(enum statusbohatera)s;
    nowy->next=head;
    nowy->prev=NULL;
    if(head!=NULL){
    head->prev=nowy;
    }
    printf("Bohater %s dodany do bazy pomyslnie\n",nowy->imie);
    return nowy;
}


bohater* usun_bohatera(bohater *head){
	if(head==NULL){
		printf("Baza jest pusta nie ma bohaterow do usuniecia\n");
		return NULL;
	}
	char imie_do_u[MAXIMIE];
	printf("Podaj imie bohatera do usuniecia:\n");
	scanf("%100s",imie_do_u);
	bohater *biezancy=head;
	while(biezancy!=NULL){
		if(strcmp(biezancy->imie, imie_do_u)==0){
			if(biezancy->status==NA_MISJI){
				printf("Odmowa dostepu bohater znajduje sie aktualnie na misji:\n");
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


void wyswietl_liste(bohater *head){
    if(head==NULL){
        printf("Baza jest pusta nie ma bohaterow do wyswietlenia\n");
        return;
    }
    int t=1;
    bohater *biezancy=head;
    printf("==== Lista bohaterow ====\n");
    while(biezancy!=NULL){
        printf("%d. ", t);
        printf("IMIE: %s | ",biezancy->imie);
        printf("RASA: %s | ",rasa[biezancy->rasa]);
        printf("KLASA: %s | ",klasy[biezancy->klasa]);
        printf("POZIOM: %d | ",biezancy->poziom);
        printf("REPUTACJA: %d | ",biezancy->reputacja);
        printf("STATUS: %s",status[biezancy->status]);
        printf("\n");
        t++;
        biezancy=biezancy->next;       
    }
}

void wyszukaj_bohatera(bohater *head){
	if(head==NULL){
	printf("Baza jest pusta nie ma kogo szukac\n");
		return;
	}
	char imieb[MAXIMIE];
	int minpoziom;
	int znaleziono=0;
	printf("Podaj imie badz poczatek imienia bohatera ktorego szukasz:\n");
	scanf("%100s",imieb);
	printf("Minimalny poziom bohatera\n");
	scanf("%d",&minpoziom);
	printf("---WYNIKI POSZUKIWAN (IMIE NA: '%s', POZIOM: %d+\n",imieb,minpoziom);
	bohater *biezacy=head;
	while(biezacy!=NULL){
		if(strncmp(biezacy->imie, imieb,strlen(imieb))==0&&biezacy->poziom>=minpoziom){
			printf("%-15s | Klasa: %-10s | Poz:%d | Satatus: %s\n",biezacy->imie,klasy[biezacy->klasa],biezacy->poziom,status[biezacy->status] );
			znaleziono=1;
		}
		biezacy=biezacy->next;
	}
	if(!znaleziono){
		printf("Niestety nie ma takiego bohatera ktory pasuje twoim wymaganiom");
	}
}

void sortuj_bohatera(bohater *head,int tryb){
	if(head==NULL||head->next==NULL){
		return;
	}
	int zmiana;
	bohater *ptr;
	do{
		zmiana=0;
		ptr=head;
		while(ptr->next!=NULL){
			int czyzamienic=0;
			if(tryb==1){
				if(strcmp(ptr->imie, ptr->next->imie)>0){
					czyzamienic=1;
				}
			}else{
				if(ptr->poziom>ptr->next->poziom){
					czyzamienic=1;
				}
			}
			if (czyzamienic){
				char temp_imie[MAXIMIE];
				strcpy(temp_imie, ptr->imie);
				strcpy(ptr->imie, ptr->next->imie);
				strcpy(ptr->next->imie, temp_imie);
				int t_lvl=ptr->poziom;ptr->poziom=ptr->next->poziom; ptr->next->poziom=t_lvl;
                int t_rep=ptr->reputacja;ptr->reputacja=ptr->next->reputacja;ptr->next->reputacja=t_rep;
                enum rasabohatera t_rasa = ptr->rasa; ptr->rasa = ptr->next->rasa; ptr->next->rasa = t_rasa;
                enum klasabohatera t_klas = ptr->klasa; ptr->klasa = ptr->next->klasa; ptr->next->klasa = t_klas;
                enum statusbohatera t_stat = ptr->status; ptr->status = ptr->next->status; ptr->next->status = t_stat;
				zmiana=1;
			}
			ptr=ptr->next;
		}
	}while(zmiana);
	printf("Sortowanie zakonczone sukcesem:\n");
}


void edytuj_bohatera(bohater *head) {
    char cel[MAXIMIE];
    printf("Podaj imie bohatera do edycji: ");
    scanf("%100s", cel);
    bohater *akt = head;
    while (akt != NULL) {
        if (strcmp(akt->imie, cel) == 0) {
            printf("Edytujesz: %s. (Imie pozostaje bez zmian)\n", akt->imie);
            printf("Nowy poziom: "); scanf("%d", &akt->poziom);
            printf("Nowa reputacja: "); scanf("%d", &akt->reputacja);
            printf("Nowy status (0-Aktywny, 1-Misja, 2-Ranny, 3-Zaginiony, 4-Zawieszony): ");
            int s; scanf("%d", &s); akt->status = (enum statusbohatera)s;
            return;
        }
        akt = akt->next;
    }
    printf("Nie znaleziono.\n");
}
void zwolnij_liste(bohater *head) {
    while (head) {
        bohater *tmp = head;
        head = head->next;
        free(tmp);
    }
}