#ifndef SPIELZUG_H
#define SPIELZUG_H

#include "DEFINE.h"

/**Diese Klasse repraesentiert einen Reversi-Spielzug.*/
class Spielzug
{
private:
    /**Um den wievielten Zug es sich handelt.*/
    int spielzugNummer;
    /**Welche Farbe hatte der Spieler der ihn durchfuehrt.*/
    SpielerFarbe farbe;
    /**Die X-Koordinate.*/
    int x;
    /**Die Y-Koordniate.*/
    int y;
public:
    Spielzug();
    Spielzug(SpielerFarbe angabeFarbe,int angabeX, int angabeY);

    void setzeZugNummer(int angabeNummer);
    void setzeX(int angabeX);
    void setzeY(int angabeY);
    void setzeFarbe(SpielerFarbe angabeFarbe);
    int liefereSpielzugnummer();
    SpielerFarbe liefereFarbe();
    int liefereXKoordinate();
    int liefereYKoordinate();
};

#endif // SPIELZUG_H
