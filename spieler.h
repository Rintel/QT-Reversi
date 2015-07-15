#ifndef SPIELER_H
#define SPIELER_H

#include "DEFINE.h"
#include <QString>

/**
 * Diese Klasse repraesentiert einen Spieler.
 */
class Spieler
{
private:
    /**Die ID des Spielers.*/
    int spielerID;
    /**Der Name des Spielers.*/
    QString name;
    /**Die Farbe des Spielers.*/
    SpielerFarbe farbe;
    /**Die Anzahl der Punkte des Spielers.*/
    int punkte;
    /**Die Anzahl der Spielzuege*/
    int anzahlSpielzuege;
public:
    Spieler(int angabeID, QString angabeName, SpielerFarbe angabeFarbe);

    QString liefereName();
    int liefereSpielerID();
    SpielerFarbe liefereSpielerFarbe();
    int lieferePunkte();

    void setzeAnzahlZurueck();
    void erhoeheAnzahlErlaubt();
    int liefereAnzahlErlaubt();
    void aendereName(QString angabeName);
    void aenderePunkte(int angabePunkte);
    void aendereSpielerFarbe(SpielerFarbe angabeFarbe);
    void aendereSpielerID(int angabeID);
};

#endif // SPIELER_H
