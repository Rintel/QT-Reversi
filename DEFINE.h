#ifndef DEFINE_H
#define DEFINE_H

/**
 * FeldEigenschaft kann folgende Werte annehmen:
 * leer, belegt, erlaubt
 */
enum FeldEigenschaft
{
    leer,
    belegt,
    erlaubt
};

/**
 * SpielerFarbe kann folgende Werte annehmen:
 * white, black
 */
enum SpielerFarbe
{
    white,
    black
};

/**
 * Geschwindigkeit der Animation ist auf 3 festgelegt.
 */
const int animationSpeed = 3;
const float breiteSeite = 7.029;
/**
 * Die Breite eines Feldes auf dem Spielbrett ist auf 10.743 festgelegt.
 */
const float breiteQuadrat = 10.743;
/**
 * Der Radius eines Spielsteins betraegt die haelfte von einem Feld, also 5.3715.
 */
const float radiusSpielstein = 5.3715;

#endif // DEFINE_H
