#include "spielbrett.h"

/**
 * Konstruiert ein Objekt Spielbrett, mit den Startoptionen von Reversi.
 */
Spielbrett::Spielbrett()
{
    //animation = true;
    leereSpielbrett();
    neuesSpiel();
}

/**
 * Setzt einen Spielstein an eine Position des Spielbretts.
 * @param angabeFarbe Angabe der Farbe des Spielsteins.
 * @param angabeX Angabe der X-Koordinate.
 * @param angabeY Angabe der Y-Koordinate.
 * @return True wenn setzten erfolgreich | False wenn nicht erlaubt.
 */
bool Spielbrett::setzeSpielstein(SpielerFarbe angabeFarbe, int angabeX, int angabeY)
{
    bool ok = false;
    if(angabeX >= 0 && angabeX< 8 && angabeY >= 0 && angabeY < 8)
    {
        if (spielfeld[angabeX][angabeY].liefereFeldeigenschaft() == erlaubt)
        {
            spielfeld[angabeX][angabeY].aendereFarbeUndEigenschaft(angabeFarbe, belegt);
            entferneAlleErlaubtenZuege();
            ok = true;
        }
    }
    return ok;
}

/**
 * Entfernt alle festgelegten Drehungen aller Spielfelder des Spielbretts.
 */
void Spielbrett::entferneAlleDrehungen()
{
    animation = false;
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            spielfeld[x][y].aendereDrehung(false);
        }
    }
}

/**
 * Setzt mit der Hilfe der Angabe von X- und Y-Koordinate einen gueltigen Spielzug fest.
 *
 * @param angabeX Angabe der X-Koordinate.
 * @param angabeY Angabe der Y-Koordinate.
 * @return True wenn erfolgreich festgelegt | False wenn nicht moeglich.
 */
bool Spielbrett::setzeGueltigenSpielzug(int angabeX, int angabeY)
{
    bool ok = false;
    if(angabeX >= 0 && angabeX< 8 && angabeY >= 0 && angabeY < 8)
    {
        if(spielfeld[angabeX][angabeY].liefereFeldeigenschaft() == leer)
        {
            spielfeld[angabeX][angabeY].aendereEigenschaft(erlaubt);
            ok = true;
        }
    }
    return ok;
}

/**
 * Wechselt mit der Hilfe der Angabe von X- und Y-Koordinate die Farbe eines Spielsteins.
 *
 * @param angabeX Angabe der X-Koordinate.
 * @param angabeY Angabe der Y-Koordinate.
 * @return True wenn erfolgreich | False wenn nicht moeglich.
 */
bool Spielbrett::dreheSpielstein(int angabeX, int angabeY)
{
    bool ok = false;
    if(angabeX >= 0 && angabeX< 8 && angabeY >= 0 && angabeY < 8)
    {
        if(spielfeld[angabeX][angabeY].liefereFeldeigenschaft() == belegt)
        {
            if(spielfeld[angabeX][angabeY].liefereFarbe() == white)
            {
                spielfeld[angabeX][angabeY].aendereFarbe(black);
            }
            else
            {
                spielfeld[angabeX][angabeY].aendereFarbe(white);
            }
            spielfeld[angabeX][angabeY].aendereDrehung(true);
            animation = true;
            ok = true;
        }
    }
    return ok;
}

/**
 * Entfernt alle erlaubten Spielzuege von den einzelnen Spielfeldern und ersetzt diese durch "leer".
 */
void Spielbrett::entferneAlleErlaubtenZuege()
{
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            if(spielfeld[x][y].liefereFeldeigenschaft() == erlaubt)
                spielfeld[x][y].aendereEigenschaft(leer);
        }
    }
}

/**
 * Initialisiert das Spielfeld mit den Starteigenschaften eines Reversispiel.
 * Das bedeutet 2 schwarze und 2 weiße Spielsteine in den Startpositionen und setzt die erlaubten Spielzuege.
 */
void Spielbrett::neuesSpiel()
{
    leereSpielbrett();
    spielfeld[3][3].aendereFarbeUndEigenschaft(white, belegt);
    spielfeld[4][4].aendereFarbeUndEigenschaft(white, belegt);
    spielfeld[4][3].aendereFarbeUndEigenschaft(black, belegt);
    spielfeld[3][4].aendereFarbeUndEigenschaft(black, belegt);
    spielfeld[3][2].aendereEigenschaft(erlaubt);
    spielfeld[2][3].aendereEigenschaft(erlaubt);
    spielfeld[5][4].aendereEigenschaft(erlaubt);
    spielfeld[4][5].aendereEigenschaft(erlaubt);
}

/**
 * Entfernt alle Spielsteine vom Spielbrett und setzt alle Felder auf die Eigenschaft "leer";
 */
void Spielbrett::leereSpielbrett()
{
    for(int x = 0; x < 8; x++)
    {
        for(int y; y < 8; y++)
        {
            spielfeld[x][y].aendereFarbeUndEigenschaft(white, leer);
            spielfeld[x][y].aendereDrehung(false);
        }
    }
}

/**
 * Liefert die Eigenschaft eines Feldes auf dem Spielbrett.
 *
 * @param angabeX Die Angabe der X-Koordinate.
 * @param angabeY Die Angabe der Y-Koordinate.
 * @return Die Feldeigenschaft des Feldes mit der Position von X und Y.
 */
FeldEigenschaft Spielbrett::liefereFeldeigenschaft(int angabeX, int angabeY)
{
    if(angabeX >= 0 && angabeX< 8 && angabeY >= 0 && angabeY < 8)
        return spielfeld[angabeX][angabeY].liefereFeldeigenschaft();
}

/**
 * Liefert die Farbe eines Feldes auf dem Spielbrett.
 *
 * @param angabeX Die Angabe der X-Koordinate.
 * @param angabeY Die Angabe der Y-Koordinate.
 * @return Die Farbe des Feldes mit der Position von X und Y.
 */
SpielerFarbe Spielbrett::liefereFarbe(int angabeX, int angabeY)
{
    if(angabeX >= 0 && angabeX< 8 && angabeY >= 0 && angabeY < 8)
        return spielfeld[angabeX][angabeY].liefereFarbe();
}

/**
 * Liefert die Drehung(ob der Stein an dieser Position gedreht wird) eines Feldes auf dem Spielbrett.
 *
 * @param angabeX Die Angabe der X-Koordinate.
 * @param angabeY Die Angabe der Y-Koordinate.
 * @return Die Drehung des Feldes mit der Position von X und Y.
 */
bool Spielbrett::liefereDrehung(int angabeX, int angabeY)
{
    if(angabeX >= 0 && angabeX< 8 && angabeY >= 0 && angabeY < 8)
        return spielfeld[angabeX][angabeY].liefereDrehung();
}

/**
 * Setzt die Animation des Spielbretts.
 *
 * @param angabeAnimation Angabe der Animation als boolschen Wert.
 */
void Spielbrett::setzeAnimation(bool angabeAnimation)
{
    animation = angabeAnimation;
}

/**
 * Liefert die Animation(boolscher Wert) des Spielbretts.
 *
 * @return Die Animation des Spielbretts als bool.
 */
bool Spielbrett::liefereAnimation()
{
    return animation;
}


































