#ifndef FELD_H
#define FELD_H

#include "DEFINE.h"

/**
 * Diese Klasse repraesentiert ein Feld auf einem Spielbrett.
 */
class Feld
{
private:
    /**Eigenschaft des Feldes (leer, belegt, erlaubt).*/
    FeldEigenschaft feld;
    /**Farbe des Spielers der das Feld belegt (wenn es belegt ist).*/
    SpielerFarbe farbe;
    /**Gibt an ob eine Aenderung der Farbe durchgefuehrt wird.*/
    bool drehung;
public:
    Feld();

    FeldEigenschaft liefereFeldeigenschaft();
    SpielerFarbe liefereFarbe();
    bool liefereDrehung();

    void aendereEigenschaft(FeldEigenschaft neueEigenschaft);
    void aendereFarbe(SpielerFarbe neueFarbe);
    void aendereDrehung(bool drehen);
    void aendereFarbeUndEigenschaft(SpielerFarbe neueFarbe, FeldEigenschaft neueEigenschaft);

};

#endif // FELD_H
