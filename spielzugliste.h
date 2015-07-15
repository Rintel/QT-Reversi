#ifndef SPIELZUGLISTE_H
#define SPIELZUGLISTE_H

#include "spielzug.h"
#include <vector>

using namespace std;

/**Diese Klasse repraesentiert eine Liste von Spielzuegen.*/
class SpielzugListe
{
private:
    /**Die bereits durchgefuehrten Spielzuege.*/
    vector<Spielzug> gelegteSpielsteine;
    /**Die zu einem Zeitpunkt erlaubten Spielzuege.*/
    vector<Spielzug> erlaubteSpielzuege;
    /**ID des aktuellen Spielers.*/
    int aktuellerSpieler;
public:
    SpielzugListe();
    SpielzugListe(int angabeSpieler, vector<Spielzug> angabeErlaubterSpielzuege, vector<Spielzug> angabeGelegterSpielzuege);

    void fuegeGelegtenSpielzugHinzu(Spielzug angabeSpielzug);
    void speichereErlaubteZuege(vector<Spielzug> angabeSpielzuege);
    void setzeAktuellenSpieler(int angabeSpielerID);
    int liefereAktuellenSpieler();
    vector<Spielzug> liefereGelegteSpielsteine();
    vector<Spielzug> liefereErlaubteSpielzuege();
    int liefereAnzahlGelegterSpielsteine();
    int liefereAnzahlErlaubterSpielzuege();
    Spielzug liefereErlaubtenSpielzug(int angabeSpielzugID);
    Spielzug liefereGelegtenSpielzug(int angabeSpielzugID);

};

#endif // SPIELZUGLISTE_H
