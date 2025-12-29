#ifndef BOHATER_H
#define BOHATER_H

#define MAXIMIE 101

enum klasabohatera{
    WOJOWNIK,
    MAG,
    KAPLAN,
    LOTRZYK,
    LOWCA,
    DRUID
    };

enum rasabohatera {
    CZLOWIEK,
    ELF,
    RASNOLUD,
    ORK,
    TIEFLING
};
enum statusbohatera{
    AKTYWNY,
    NA_MISJI,
    RANNY,
    ZAGINIONY,
    ZAWIESZONY
    };

typedef struct bohater{
    char imie[MAXIMIE];
    enum rasabohatera rasa;
    enum klasabohatera klasa;
    int poziom;
    int reputacja;
    enum statusbohatera status;
    struct bohater *next;
    struct bohater *prev;
} bohater;

#endif