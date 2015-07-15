#ifndef SPIELBRETT_H
#define SPIELBRETT_H

#include "DEFINE.h"
#include "feld.h"

/**Diese Klasse repraesentiert ein quadratisches Spielbrett, welches aus 8 * 8 quadratischen Feldern besteht.*/
class Spielbrett
{
private:
    /**2D Array mit 8 mal 8 Feldern.*/
    Feld spielfeld[8][8];
    /**Boolsches Attribut ueber die Animation.*/
    bool animation;
public:
    Spielbrett();

    bool setzeSpielstein(SpielerFarbe angabeFarbe, int angabeX, int angabeY);
    bool setzeGueltigenSpielzug(int angabeX, int angabeY);
    bool dreheSpielstein(int angabeX, int angabeY);
    void entferneAlleDrehungen();
    void entferneAlleErlaubtenZuege();
    void setzeAnimation(bool angabeAnimation);
    bool liefereAnimation();


    FeldEigenschaft liefereFeldeigenschaft(int angabeX, int angabeY);
    SpielerFarbe liefereFarbe(int angabeX, int angabeY);
    bool liefereDrehung(int angabeX, int angabeY);

private:
    void neuesSpiel();
    void leereSpielbrett();
};

#endif // SPIELBRETT_H
