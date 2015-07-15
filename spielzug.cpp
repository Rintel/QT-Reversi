#include "spielzug.h"

/**
 * Default-Konstruktor fuer einen Spielzug.
 * X und Y werden auf -1 gesetzt, die Farbe wird mit white initialisiert und die Spielzugnummer mit 0.
 */
Spielzug::Spielzug()
{
    spielzugNummer = 0;
    farbe = white;
    x = -1;
    y = -1;
}

/**
 * Konstriert ein Objekt vom Typ Spielzug mit Hilfe der Angabe der Farbe, sowie des x und y Wertes.
 *
 * @param angabeFarbe Angabe der Farbe.
 * @param angabeX Angabe des X-Wertes.
 * @param angabeY Angabe des Y-Wertes.
 */
Spielzug::Spielzug(SpielerFarbe angabeFarbe, int angabeX, int angabeY)
{
    spielzugNummer = 0;
    farbe = angabeFarbe;
    x = angabeX;
    y = angabeY;
}

/**
 * Setzt die Farbe des Spielzugs.
 *
 * @param angabeFarbe Angabe des Spielzugs.
 */
void Spielzug::setzeFarbe(SpielerFarbe angabeFarbe)
{
    farbe = angabeFarbe;
}

/**
 * Setzt die Spielzugnummer.
 *
 * @param angabeNummer Angabe der Spielzugnummer als Int-Wert.
 */
void Spielzug::setzeZugNummer(int angabeNummer)
{
    spielzugNummer = angabeNummer;
}

/**
 * Setzt den X-Wert des Spielzugs.
 *
 * @param angabeX Angabe des X-Werts als Int-Wert.
 */
void Spielzug::setzeX(int angabeX)
{
    x = angabeX;
}

/**
 * Setzt den Y-Wert des Spielzugs.
 *
 * @param angabeY Angabe des Y-Werts als Int-Wert.
 */
void Spielzug::setzeY(int angabeY)
{
    y = angabeY;
}

/**
 * Liefert die Farbe des Spielzugs.
 *
 * @return Die Farbe des Spielzugs.
 */
SpielerFarbe Spielzug::liefereFarbe()
{
    return farbe;
}

/**
 * Liefert die Spielzugnummer.
 *
 * @return Die Spielzugnummer.
 */
int Spielzug::liefereSpielzugnummer()
{
    return spielzugNummer;
}

/**
 * Liefert die X-Koordinate des Spielzugs.
 *
 * @return Die X-Koordinate des Spielzugs.
 */
int Spielzug::liefereXKoordinate()
{
    return x;
}

/**
 * Liefert die Y-Koordinate des Spielzugs.
 *
 * @return Die Y-Koordinate des Spielzugs.
 */
int Spielzug::liefereYKoordinate()
{
    return y;
}
