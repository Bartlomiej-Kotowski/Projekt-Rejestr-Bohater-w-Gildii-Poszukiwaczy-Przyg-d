#include "pliki.h"
#include <stdio.h>
int zapisz_dane(const char *nazwapliku,bohater *head)
{
    FILE *plik=fopen(nazwapliku,"w");
    if(plik==NULL)
    {
        perror("Blad otwarcia pliku");
        return -1;
    }
    int ilosc=0;
    bohater *p=head;
    while(p!=NULL)
    {
        ilosc++;
        p=p->next;
    }
    fprintf(plik,"%d\n",ilosc);
    p=head;
    while(p!=NULL)
    {
        fprintf(plik,"%s %d %d %d %d %d\n",
            p->imie,
            p->rasa,
            p->klasa,
            p->poziom,
            p->reputacja,
            p->status);
        p=p->next;
    }
    fclose(plik);
    printf("Zapisano %d bohaterow do pliku %s\n",ilosc,nazwapliku);
    return 0;
}
bohater* wczytaj_dane(const char *nazwapliku)
{
    FILE *plik=fopen(nazwapliku,"r");
    if(plik==NULL)
    {
        perror("Blad otwarcia pliku");
        return NULL;
    }
    int ilosc=0;
    if(fscanf(plik,"%d\n",&ilosc)!=1)
    {
        perror("Blad odczytu ilosci bohaterow");
        fclose(plik);
        return NULL;
    }
    bohater *head=NULL;
    bohater *tail=NULL;
    for(int i=0;i<ilosc;i++)
    {
        bohater *nowy=(bohater*)malloc(sizeof(bohater));
        if(nowy==NULL){
            perror("Blad alokacji pamieci");
            break;
        }
        int r,k,s;
        if(fscanf(plik,"%s %d %d %d %d %d\n",
            nowy->imie,
            &r,
            &k,
            &nowy->poziom,
            &nowy->reputacja,
            &s)!=6)
    {
        free(nowy);
        break;
    }
    nowy->rasa=(enum rasabohatera)r;
    nowy->klasa=(enum klasabohatera)k;
    nowy->status=(enum statusbohatera)s;
    
    nowy->next=NULL;
    nowy->prev=tail;
    if(head==NULL)
    {
        head=nowy;
        tail=nowy;
    }else
    {
        tail->next=nowy;
        nowy->prev=tail;
        tail=nowy;
    }
    fclose(plik);
    printf("Wczytano %d bohaterow z pliku %s\n",ilosc,nazwapliku);
    return head;
}
void zwolnij_dane(bohater *head)
{
    bohater *p=head;
    while(p!=NULL)
    {
        bohater *tab=p;
        p=p->next;
        free(tab);
    }
    printf("Zwolniono pamiec zajmowana przez liste bohaterow\n");
}