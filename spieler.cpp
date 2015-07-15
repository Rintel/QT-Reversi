#include "spieler.h"

/**
 *
 * Konstruiert ein Objekt vom Typ Spieler mit hilfe der Angabe von
 * der SpielerID, des Namens und der Spielerfarbe.
 *
 * @param angabeID Die SpielerID als Int-Wert.
 * @param angabeName Angabe des Spielernamens.
 * @param angabeFarbe Angabe der Spielerfarbe.
 */
Spieler::Spieler(int angabeID, QString angabeName, SpielerFarbe angabeFarbe)
{
    spielerID = angabeID;
    name = angabeName;
    farbe = angabeFarbe;
    punkte = 0;
    anzahlSpielzuege = 0;
}

/**
 * Liefert den Punktestand des einzelnen Spielers als Int-Wert.
 *
 * @return Liefert den Punktestand des Spielers als Int-Wert.
 */
int Spieler::lieferePunkte()
{
    return punkte;
}

/**
 * Liefert den Namen des Spielers als QString.
 *
 * @return Den Namen des Spielers als QString.
 */
QString Spieler::liefereName()
{
    return name;
}

/**
 * Liefert die Farbe des Spielers.
 *
 * @return Die Farbe des Spielers.
 */
SpielerFarbe Spieler::liefereSpielerFarbe()
{
    return farbe;
}

/**
 * Liefert die ID des Spielers als Int-Wert.
 *
 * @return Die ID des Spielers als Int-Wert.
 */
int Spieler::liefereSpielerID()
{
    return spielerID;
}

/**
 * Aendert den Namen des Spielers.
 *
 * @param angabeName Der neue Name fuer den Spieler.
 */
void Spieler::aendereName(QString angabeName)
{
    name = angabeName;
}

/**
 * Aendert den Punktestand des Spielers.
 *
 * @param angabePunkte Der neue Punktestand des Spielers.
 */
void Spieler::aenderePunkte(int angabePunkte)
{
    punkte = angabePunkte;
}

/**
 * Aendert die Farbe des Spielers.
 *
 * @param angabeFarbe Die neue Spielerfarbe.
 */
void Spieler::aendereSpielerFarbe(SpielerFarbe angabeFarbe)
{
    farbe = angabeFarbe;
}

/**
 * Aendert die ID des Spielers.
 *
 * @param angabeID Die neue ID des Spielers.
 */
void Spieler::aendereSpielerID(int angabeID)
{
    spielerID = angabeID;
}

/**
 * Setzt die Anzahl der Spielzuege fuer diesen Spieler auf 0.
 */
void Spieler::setzeAnzahlZurueck()
{
    anzahlSpielzuege = 0;
}

/**
 *  Erhoeht die Anzahl der erlaubten Spielzuege um 1.
 */
void Spieler::erhoeheAnzahlErlaubt()
{
    anzahlSpielzuege++;
}

/**
 * Liefert die Anzahl der erlaubten Spielzuege als Int-Wert.
 *
 * @return Die Anzahl der erlaubten Spielzuege als Int-Wert.
 */
int Spieler::liefereAnzahlErlaubt()
{
    return anzahlSpielzuege;
}
