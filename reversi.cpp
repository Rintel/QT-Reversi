#include "reversi.h"
#include <stdio.h>
#include <iostream>
#include <QSound>

using namespace std;

/**
 * Konstruiert ein Objekt vom Typ Reversi mit Hilfe der Angabe der beiden Spielernamen.
 * Dabei werden alle Reversi-Start Optionen festgelegt. z.B. Erlaubte Spielzuege der beiden Spieler,
 * sowie die Namen und Anzahl der Spielzuege etc...
 *
 * @param spielerName1
 * @param spielerName2
 */
Reversi::Reversi(QString spielerName1, QString spielerName2)
{
    spielzugNr = 1;
    spielfeld = new Spielbrett();
    dieSpieler[0] = new Spieler(1, spielerName1, black);
    dieSpieler[1] = new Spieler(2, spielerName2, white);
    spielzugListe.clear();
    erlaubteSpielzuege.clear();
    aktuellerSpieler = 0;
    ende = false;
    alleSpielzuege.clear();

    erlaubteSpielzuege.push_back(Spielzug(black, 2, 3));
    erlaubteSpielzuege.push_back(Spielzug(black, 3, 2));
    erlaubteSpielzuege.push_back(Spielzug(black, 4, 5));
    erlaubteSpielzuege.push_back(Spielzug(black, 5, 4));

    erlaubteSpielzuege.push_back(Spielzug(white, 5, 3));
    erlaubteSpielzuege.push_back(Spielzug(white, 4, 2));
    erlaubteSpielzuege.push_back(Spielzug(white, 2, 4));
    erlaubteSpielzuege.push_back(Spielzug(white, 3, 5));
}

/**
 * Destruktor fuer die Reversi-Klasse.
 */
Reversi::~Reversi()
{
    delete spielfeld;
    delete dieSpieler[0];
    delete dieSpieler[1];
}

/**
 * Liefert das Spielfeld-Objekt.
 *
 * @return Das Spielfeld-Objekt.
 */
Spielbrett* Reversi::liefereSpielbrett()
{
    return spielfeld;
}

/**
 * Liefert den einen Spieler, mit Hilfe der Angabe seiner ID.
 *
 * @param angabeID Die Angabe der ID des Spielers.
 * @return Spieler, mit angegebener ID.
 */
Spieler* Reversi::liefereSpieler(int angabeID)
{
    if(angabeID == 0 || angabeID == 1)
        return dieSpieler[angabeID];
}

/**
 * Liefert alle Spieler des Spiels.
 *
 * @return Alle Spieler des Spiels.
 */
Spieler** Reversi::liefereAlleSpieler()
{
    return dieSpieler;
}

/**
 * Liefert allegetaetigten Spielzuege.
 *
 * @return Alle getaetigten Spielzuege.
 */
vector<Spielzug> Reversi::liefereSpielzuege()
{
    return spielzugListe;
}

/**
 * Liefert die erlaubten Spielzuege.
 *
 * @return Die erlaubten Spielzuege.
 */
vector<Spielzug> Reversi::liefereErlaubteSpielzuege()
{
    return erlaubteSpielzuege;
}

/**
 * Liefert den aktuellen Spieler als ID.
 *
 * @return Die ID des aktuellen Spielers.
 */
int Reversi::liefereAktuellenSpieler()
{
    return aktuellerSpieler;
}

/**
 * Setzt das Ende des Spiels als boolschen Wert.
 *
 * @param spielEnde Angabe ob Ende erreicht.
 */
void Reversi::setzeEnde(bool spielEnde)
{
    ende = spielEnde;
}

/**
 * Wechselt den aktuellen Spieler.
 */
void Reversi::aendereAktuellenSpieler()
{
    if(aktuellerSpieler == 0)
        aktuellerSpieler = 1;
    else if(aktuellerSpieler == 1)
        aktuellerSpieler = 0;
}

/**
 * Versucht einen Spielzug nach den Regeln von Reversi anzuwenden.
 * Gibt True zurueck wenn er gueltig ist und ausgefuehrt werden konnte, False wenn nicht.
 *
 * @param angabeSpielzug Die Angabe des auszufuehrenden Spielzugs.
 * @return True wenn erfolgeich durchgefuehrt | False wenn nicht.
 */
bool Reversi::macheSpielzug(Spielzug angabeSpielzug)
{
    bool ok = false;
    angabeSpielzug.setzeFarbe(dieSpieler[aktuellerSpieler]->liefereSpielerFarbe());
    ok = spielfeld->setzeSpielstein(dieSpieler[aktuellerSpieler]->liefereSpielerFarbe(), angabeSpielzug.liefereXKoordinate(), angabeSpielzug.liefereYKoordinate());
    if(ok)
    {
        fuegeSpielzugHinzu(angabeSpielzug);
        updateGame(angabeSpielzug);
        aendereAktuellenSpieler();
        setzeErlaubteSpielzuege();
        if(dieSpieler[aktuellerSpieler]->liefereAnzahlErlaubt() == 0)
        {
            aendereAktuellenSpieler();
            if(dieSpieler[aktuellerSpieler]->liefereAnzahlErlaubt() == 0)
                ende = true;
        }
        if(!ende)
        {
            spielfeld->entferneAlleErlaubtenZuege();
            setzeNeueSpielzuege();
            spielzugNr++;
        }
        spielbrettVeraenderung();
    }
    else
    {
        QSound *sound = new QSound("no.wav");
        sound->play();
        localMove();
    }
    return ok;
}

//0 wenn schwarzer spieler gewinnt
//1 wenn weisser gewinnt
//2 wenn unendschieden
/**
 * Prueft welcher Spieler mehr Spielsteine besitzt.
 * @return 0 wenn schwarzer Spieler mehr nesitzt | 1 wenn weißer Spieler mehr besitzt | 2 wenn beide gleich viele besitzen
 */
int Reversi::werGewinnt()
{
    int ergebnis;
    int spielerblack = 0;
    int spielerwhite = 0;
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            SpielerFarbe q = spielfeld->liefereFarbe(x, y);
            if(q == black)
                spielerblack++;
            else
                spielerwhite++;
        }
    }
    if(spielerblack > spielerwhite)
        ergebnis = 0;
    else if(spielerblack < spielerwhite)
        ergebnis = 1;
    else
        ergebnis = 2;
    return ergebnis;
}

/**
 * Setzt die neuen erlaubten Spielzuege auf dem Spielbrett.
 */
void Reversi::setzeNeueSpielzuege()
{
    for(int i = 0; i < erlaubteSpielzuege.size(); i++)
    {
        if(erlaubteSpielzuege[i].liefereFarbe() == dieSpieler[aktuellerSpieler]->liefereSpielerFarbe())
            spielfeld->setzeGueltigenSpielzug(erlaubteSpielzuege[i].liefereXKoordinate(), erlaubteSpielzuege[i].liefereYKoordinate());
    }
}

/**
 * Ermittelt die neuen zugelassenen Spielzuege des aktuellen Spielers und speichert diese im Array erlaubteSpielzuege[].
 */
void Reversi::setzeErlaubteSpielzuege()
{
    SpielerFarbe farbeTemp;
    bool whiteErlaubt = false;
    bool blackErlaubt = false;
    dieSpieler[0]->setzeAnzahlZurueck();
    dieSpieler[1]->setzeAnzahlZurueck();
    erlaubteSpielzuege.clear();

    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            if(spielfeld->liefereFeldeigenschaft(x, y) == leer)
            {
                whiteErlaubt = false;
                blackErlaubt = false;
                for(int j = -1; j < 2; j++)
                {
                    if((y + j) >= 0 && (y + j) < 8)
                    {
                        for(int i = -1; i < 2; i++)
                        {
                            if((x+i) >= 0 && (x+i) < 8)
                            {
                                if(!(i == 0 && j == 0))
                                {
                                    if(ueberpruefeSpielzug(x, y, i, j))
                                    {
                                        farbeTemp = spielfeld->liefereFarbe(x+i, y+j);
                                        if(farbeTemp == white && !blackErlaubt)
                                        {
                                            blackErlaubt = true;
                                            erhoeheErlaubetenZug(black);
                                            erlaubteSpielzuege.push_back(Spielzug(black, x, y));
                                        }
                                        else if(farbeTemp == black && !whiteErlaubt)
                                        {
                                            whiteErlaubt = true;
                                            erhoeheErlaubetenZug(white);
                                            erlaubteSpielzuege.push_back(Spielzug(white, x, y));
                                        }

                                        if(blackErlaubt && whiteErlaubt)
                                        {
                                            i = 2;
                                            j = 2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

/**
 * Ueberprueft einen Spielzug auf seine Gueltigkeit innerhalb der Regeln von Reversi.
 *
 * @param angabeX Die Angabe der X-Koordinate.
 * @param angabeY Die Angabe der Y-Koordinate.
 * @param i Angabe der Hilfvariable i zum Navigieren durch das Spielfeld.
 * @param j Angabe der Hilfvariable j zum Navigieren durch das Spielfeld.
 * @return True wenn es sich um einen gueltigen Spielzug handelt | False wenn nicht.
 */
bool Reversi::ueberpruefeSpielzug(int angabeX, int angabeY, int i, int j)
{
    bool ok = false;
    bool rdy = false;
    int x = angabeX + i;
    int y = angabeY + j;

    if(spielfeld->liefereFeldeigenschaft(x, y) == belegt)
    {
        SpielerFarbe farbeTmp = spielfeld->liefereFarbe(x, y);
        x += i;
        y += j;
        while( x >= 0 && x < 8 && y >= 0 && y < 8 && !rdy)
        {
            if(spielfeld->liefereFeldeigenschaft(x, y) == belegt)
            {
                if(spielfeld->liefereFarbe(x, y) == farbeTmp)
                {
                    x += i;
                    y += j;
                }
                else
                {
                    ok = true;
                    rdy = true;
                }
            }
            else
                rdy = true;
        }
    }
    return ok;
}

/**
 * Erhoeht die Anzahl der erlaubten Spielzuege eines Spielers um 1.
 *
 * @param angabeFarbe Die Angabe der Farbe des Spielers.
 */
void Reversi::erhoeheErlaubetenZug(SpielerFarbe angabeFarbe)
{
    if( dieSpieler[0]->liefereSpielerFarbe() == angabeFarbe )
    {
        dieSpieler[0]->erhoeheAnzahlErlaubt();
    }
    else
    {
        dieSpieler[1]->erhoeheAnzahlErlaubt();
    }
}

/**
 * Fuehrt alle Drehungen der Spielsteine auf dem Spielfeld aus, abhaengig vom angegeben Spielzug.
 *
 * @param angabeSpielzug Die Angabe eines Spielzuges.
 */
void Reversi::updateGame(Spielzug angabeSpielzug)
{
    updateReihe(angabeSpielzug);
    updateSpalte(angabeSpielzug);
    updateDiagonal(angabeSpielzug);
}

/**
 * Erkennt alle diagonalen Aenderungen nach einem Spielzug und fuehrt die daruas folgenden Drehungen aus.
 *
 * @param angabeSpielzug Die Angabe des Spielzuges.
 */
void Reversi::updateDiagonal(Spielzug angabeSpielzug)
{
    int x = angabeSpielzug.liefereXKoordinate();
    int y = angabeSpielzug.liefereYKoordinate();
    SpielerFarbe farbe = angabeSpielzug.liefereFarbe();
    int i;
    int j;

    i = x - 1;
    j = y - 1;
    while(i >= 0 && j >= 0 && spielfeld->liefereFeldeigenschaft(i, j) == belegt && spielfeld->liefereFarbe(i, j) != farbe)
    {
        i--;
        j--;
    }
    if(i >= 0 && j >= 0)
    {
        if(spielfeld->liefereFeldeigenschaft(i, j) == belegt && spielfeld->liefereFarbe(i, j) == farbe)
        {
            i++;
            j++;
            while(i < x && j < y)
            {
                spielfeld->dreheSpielstein(i, j);
                i++;
                j++;
            }
        }
    }

    i = x + 1;
    j = y + 1;
    while(i < 8 && j < 8 && spielfeld->liefereFeldeigenschaft(i, j) == belegt && spielfeld->liefereFarbe(i, j) != farbe)
    {
        i++;
        j++;
    }
    if(i < 8 && j < 8)
    {
        if(spielfeld->liefereFeldeigenschaft(i, j) == belegt && spielfeld->liefereFarbe(i, j) == farbe)
        {
            i--;
            j--;
            while(i > x && j > y)
            {
                spielfeld->dreheSpielstein(i, j);
                i--;
                j--;
            }
        }
    }

    i = x + 1;
    j = y - 1;
    while(i < 8 && j >= 0 && spielfeld->liefereFeldeigenschaft(i, j) == belegt && spielfeld->liefereFarbe(i, j) != farbe)
    {
        i++;
        j--;
    }
    if(i < 8 && j >= 0)
    {
        if(spielfeld->liefereFeldeigenschaft(i, j) == belegt && spielfeld->liefereFarbe(i, j) == farbe)
        {
            i--;
            j++;
            while(i > x && j < y)
            {
                spielfeld->dreheSpielstein(i, j);
                i--;
                j++;
            }
        }
    }

    i = x - 1;
    j = y + 1;
    while(i >= 0 && j < 8 && spielfeld->liefereFeldeigenschaft(i, j) == belegt && spielfeld->liefereFarbe(i, j) != farbe)
    {
        i--;
        j++;
    }
    if(i >= 0 && j < 8)
    {
        if(spielfeld->liefereFeldeigenschaft(i, j) == belegt && spielfeld->liefereFarbe(i, j) == farbe)
        {
            i++;
            j--;
            while(i < x && j > y)
            {
                spielfeld->dreheSpielstein(i, j);
                i++;
                j--;
            }
        }
    }

}

/**
 * Erkennt alle senkrechten Aenderungen nach einem Spielzug und fuehrt die daruas folgenden Drehungen aus.
 *
 * @param angabeSpielzug Die Angabe des Spielzuges.
 */
void Reversi::updateSpalte(Spielzug angabeSpielzug)
{
    int x = angabeSpielzug.liefereXKoordinate();
    int y = angabeSpielzug.liefereYKoordinate();
    SpielerFarbe farbe = angabeSpielzug.liefereFarbe();
    int i;

    i = y - 1;
    while(i >= 0 && spielfeld->liefereFeldeigenschaft(x, i) == belegt && spielfeld->liefereFarbe(x, i) != farbe)
    {
        i--;
    }
    if(i >= 0)
    {
        if(spielfeld->liefereFeldeigenschaft(x, i) == belegt && spielfeld->liefereFarbe(x, i) == farbe)
        {
            i++;
            while(i < y)
            {
                spielfeld->dreheSpielstein(x, i);
                i++;
            }
        }
    }

    i = y + 1;
    while(i < 8 && spielfeld->liefereFeldeigenschaft(x, i) == belegt && spielfeld->liefereFarbe(x, i) != farbe)
    {
        i++;
    }
    if(i < 8)
    {
        if(spielfeld->liefereFeldeigenschaft(x, i) == belegt && spielfeld->liefereFarbe(x, i) == farbe)
        {
            i--;
            while(i > y)
            {
                spielfeld->dreheSpielstein(x, i);
                i--;
            }
        }
    }
}

/**
 * Erkennt alle waagerechten Aenderungen nach einem Spielzug und fuehrt die daruas folgenden Drehungen aus.
 *
 * @param angabeSpielzug Die Angabe des Spielzuges.
 */
void Reversi::updateReihe(Spielzug angabeSpielzug)
{
    int x = angabeSpielzug.liefereXKoordinate();
    int y = angabeSpielzug.liefereYKoordinate();
    SpielerFarbe farbe = angabeSpielzug.liefereFarbe();
    int i;

    i = x - 1;
    while(i >= 0 && spielfeld->liefereFeldeigenschaft(i, y) == belegt && spielfeld->liefereFarbe(i, y) != farbe)
    {
        i--;
    }
    if(i >= 0)
    {
        if (spielfeld->liefereFeldeigenschaft(i, y) == belegt && spielfeld->liefereFarbe(i, y) == farbe)
        {
            i++;
            while(i < x)
            {
                spielfeld->dreheSpielstein(i, y);
                i++;
            }
        }
    }

    i = x + 1;
    while(i < 8 && spielfeld->liefereFeldeigenschaft(i, y) == belegt && spielfeld->liefereFarbe(i, y) != farbe)
    {
        i++;
    }
    if(i < 8)
    {
        if(spielfeld->liefereFeldeigenschaft(i, y) == belegt && spielfeld->liefereFarbe(i, y) == farbe)
        {
            i--;
            while( i > x)
            {
                spielfeld->dreheSpielstein(i, y);
                i--;
            }
        }
    }
}

/**
 * Fuegt einen Spielzug, der Liste mit den getaetigten Spielzuegen hinzu.
 *
 * @param angabeSpielzug Die Angabe eines Spielzuges.
 */
void Reversi::fuegeSpielzugHinzu(Spielzug angabeSpielzug)
{
    if(spielzugListe.empty())
        angabeSpielzug.setzeZugNummer(1);
    else
        angabeSpielzug.setzeZugNummer(spielzugListe.back().liefereSpielzugnummer() + 1);
    spielzugListe.push_back(angabeSpielzug);
}

/**
 * Sendet ein Signal zur Spielfeldveraenderung.
 */
void Reversi::spielbrettVeraenderung()
{
    emit spielVeraenderung();
}

/**
 * Setzt einen Spielstein auf das Spielbrett.
 *
 * @param angabeX Die Angabe der X-Koordinate.
 * @param angabeY Die Angabe der Y-Koordinate.
 */
void Reversi::setzeSpielstein(int angabeX, int angabeY)
{
    macheSpielzug(Spielzug(dieSpieler[aktuellerSpieler]->liefereSpielerFarbe(), angabeX, angabeY));
}

/**
 * Prueft das Spiel auf ein Ende. Wenn dieses nicht erreicht ist, wird der naechste Zug eingeleitet.
 */
void Reversi::nextTurn()
{
    if(ende)
    {
        QString gewinnerName;
        int wer = werGewinnt();
        if(wer == 0 || wer == 1)
            gewinnerName = dieSpieler[wer]->liefereName();
        else
            gewinnerName = QString("UNENDSCHIEDEN!");
        emit spielEnde(gewinnerName);
    }
    else
    {
        emit localMove();
    }
}

/**
 * Aendert die Namen beider Spieler, mit der Hilfe der Angabe der neuen Spielernamen.
 *
 * @param spieler1Name Die Angabe des Spielernamens.
 * @param spieler2Name Die Angabe des Spielernamens.
 */
void Reversi::aendereSpielerNamen(QString spieler1Name, QString spieler2Name)
{
    dieSpieler[0]->aendereName(spieler1Name);
    dieSpieler[1]->aendereName(spieler2Name);
}






















