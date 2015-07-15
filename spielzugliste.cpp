#include "spielzugliste.h"
#include <vector>

using namespace std;

/**
 * Konstriert ein Objekt vom Typ SpielzugListe mit Hilfe der Angabe vom Aktuellen Spieler, den erlaubten Zuegen und den bereits vollzogenen Spielzuegen.
 *
 * @param angabeSpieler Angabe des Aktuellen Spielers.
 * @param angabeErlaubterSpielzuege Angabe der fuer den aktuellen Spieler erlaubten Zuege.
 * @param angabeGelegterSpielzuege Angabe der bereits getaetigten Spielzuege.
 */
SpielzugListe::SpielzugListe(int angabeSpieler, vector<Spielzug> angabeErlaubterSpielzuege, vector<Spielzug> angabeGelegterSpielzuege)
{
    aktuellerSpieler = angabeSpieler;
    erlaubteSpielzuege = angabeErlaubterSpielzuege;
    gelegteSpielsteine = angabeGelegterSpielzuege;
}

/**
 * Default-Konstruktor fuer eine SpielzugListe.
 * Setzt den aktuellen Spieler auf -1 und legt leere Vectoren fuer die erlaubten und gelegten Spielzuege an.
 */
SpielzugListe::SpielzugListe()
{
    aktuellerSpieler = -1;
    erlaubteSpielzuege.clear();
    gelegteSpielsteine.clear();
}

/**
 * Fuegt einen getaetigten Spielzug hinzu.
 *
 * @param angabeSpielzug Angabe des getaetigten Spielzug.
 */
void SpielzugListe::fuegeGelegtenSpielzugHinzu(Spielzug angabeSpielzug)
{
    gelegteSpielsteine.push_back(angabeSpielzug);
}

/**
 * Setzt die erlaubten Spielzuege.
 *
 * @param angabeSpielzuege Angabe der erlaubten Spielzuege.
 */
void SpielzugListe::speichereErlaubteZuege(vector<Spielzug> angabeSpielzuege)
{
    erlaubteSpielzuege = angabeSpielzuege;
}

/**
 * Legt den aktuellen Spieler fest.
 *
 * @param angabeSpielerID Angabe des aktuellen Spielers als Int-Wert.
 */
void SpielzugListe::setzeAktuellenSpieler(int angabeSpielerID)
{
    aktuellerSpieler = angabeSpielerID;
}

/**
 * Liefert den aktuellen Spieler als Int-Wert.
 *
 * @return Den aktuellen Spieler als Int-Wert.
 */
int SpielzugListe::liefereAktuellenSpieler()
{
    return aktuellerSpieler;
}

/**
 * Liefert die Liste der bereits gelegten Spielzuege.
 *
 * @return Die Liste der gelegten Spielzuege als Vector.
 */
vector<Spielzug> SpielzugListe::liefereGelegteSpielsteine()
{
    return gelegteSpielsteine;
}

/**
 * Liefert die erlaubten Spielzuege.
 *
 * @return Die erlaubten Spielzuege als Vector.
 */
vector<Spielzug> SpielzugListe::liefereErlaubteSpielzuege()
{
    return erlaubteSpielzuege;
}

/**
 * Liefert die Anzahl der erlaubten Spielzuege.
 *
 * @return Die Anzahl der erlaubten Spielzuege.
 */
int SpielzugListe::liefereAnzahlErlaubterSpielzuege()
{
    return erlaubteSpielzuege.size();
}

/**
 * Liefert die Anzahl der gelegten Spielzuege.
 *
 * @return Die Anzahl der gelegten Spielzuege.
 */
int SpielzugListe::liefereAnzahlGelegterSpielsteine()
{
    return gelegteSpielsteine.size();
}

/**
 * Liefert einen bestimmten erlaubten Spielzug mit Hilfe der Angabe der Spielzug-ID.
 *
 * @param angabeSpielzugID Angabe der Spielzug-ID als Int-Wert.
 * @return Den Spielzug, mit der Spielzug-ID.
 */
Spielzug SpielzugListe::liefereErlaubtenSpielzug(int angabeSpielzugID)
{
    Spielzug sp;
    if(angabeSpielzugID >= 0 && angabeSpielzugID < erlaubteSpielzuege.size())
    {
        sp = erlaubteSpielzuege[angabeSpielzugID];
    }
    return sp;
}

/**
 * Liefert einen bestimmten bereits gelegten Spielzug mit Hilfe der Angabe der Spielzug-ID.
 *
 * @param angabeSpielzugID Angabe der Spielzug-ID als Int-Wert.
 * @return Den Spielzug, mit der Spielzug-ID.
 */
Spielzug SpielzugListe::liefereGelegtenSpielzug(int angabeSpielzugID)
{
    Spielzug sp;
    if(angabeSpielzugID >= 0 && angabeSpielzugID < erlaubteSpielzuege.size())
    {
        sp = gelegteSpielsteine[angabeSpielzugID];
    }
    return sp;
}












