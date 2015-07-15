#include "feld.h"

/**
 * Konstruiert ein Objekt vom Typ Feld, als leeres Feld,
 * ohne drehung und mit der Spielerfarbe weiss.
 */
Feld::Feld()
{
    feld = leer;
    farbe = white;
    drehung = false;
}

/**
 * Liefert die Feldeigenschaft.
 * (leer, belegt oder erlaubt)
 *
 * @return Die Feldeigenschaft.
 */
FeldEigenschaft Feld::liefereFeldeigenschaft()
{
    return feld;
}

/**
 * Liefert die Farbe.
 *
 * @return Die Farbe.
 */
SpielerFarbe Feld::liefereFarbe()
{
    return farbe;
}

/**
 * Liefert die Drehung (true | false).
 *
 * @return Die Drehung.
 */
bool Feld::liefereDrehung()
{
    return drehung;
}

/**
 * Aendert die Feldeigenschaft.
 *
 * @param neueEigenschaft Die neue FeldEigenschaft.
 */
void Feld::aendereEigenschaft(FeldEigenschaft neueEigenschaft)
{
    feld = neueEigenschaft;
}

/**
 * Aendert die Farbe.
 *
 * @param neueFarbe Die neue Farbe.
 */
void Feld::aendereFarbe(SpielerFarbe neueFarbe)
{
    farbe = neueFarbe;
}

/**
 * Aendert die Drehung.
 *
 * @param drehen (True | False)
 */
void Feld::aendereDrehung(bool drehen)
{
    drehung = drehen;
}

/**
 * Aendert sowohl die Feldeigenschaft, als auch die Farbe des Feldes.
 *
 * @param neueFarbe Die neue Farbe.
 * @param neueEigenschaft Die neue Feldeigenschaft.
 */
void Feld::aendereFarbeUndEigenschaft(SpielerFarbe neueFarbe, FeldEigenschaft neueEigenschaft)
{
    farbe = neueFarbe;
    feld = neueEigenschaft;
}
