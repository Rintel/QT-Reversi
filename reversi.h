#ifndef REVERSI_H
#define REVERSI_H

#include "reversi.h"

#include "DEFINE.h"
#include <QObject>
#include <vector>
#include "spielbrett.h"
#include "spieler.h"
#include "spielzug.h"
#include "spielzugliste.h"


using namespace std;

/**Diese Klasse repraesentiert das Reversi-Spiel.*/
class Reversi : public QObject
{
    Q_OBJECT

private:
    /**Das Reversi-Spielbrett.*/
    Spielbrett* spielfeld;
    /**Die beiden Spieler.*/
    Spieler* dieSpieler[2];
    /**Liste der erlaubten Spielzuege fuer den aktuellen Spieler.*/
    vector<Spielzug> spielzugListe;
    /**Liste der erlaubten Spielzuege.*/
    vector<Spielzug> erlaubteSpielzuege;
    /**Der aktuelle Spieler.*/
    int aktuellerSpieler;
    /**Variable ob das Ende des Spiels erreicht wurde.*/
    bool ende;
    /**Attribut zum speichern der aktuellen Spielzugnummer.*/
    int spielzugNr;
    /**Liste der berets getaetigten Spielzuege.*/
    vector<SpielzugListe> alleSpielzuege;
    /**Gibt an, ob Spieler 1 durch KI gespielt wird.*/
    bool spieler1KI;
    /**Gibt an, ob Spieler 2 durch KI gespielt wird.*/
    bool spieler2KI;

public:
    Reversi(QString spielerName1 = "Spieler 1", QString spielerName2 = "Spieler 2", bool angabeSpieler2KI = false, bool angabeSpieler1KI = false);
    ~Reversi();

    void start();
    Spielbrett* liefereSpielbrett();
    Spieler* liefereSpieler(int angabeID);
    Spieler** liefereAlleSpieler();
    vector<Spielzug> liefereSpielzuege();
    vector<Spielzug> liefereErlaubteSpielzuege();
    int liefereAktuellenSpieler();
    void aendereSpielerNamen(QString spieler1Name, QString spieler2Name, bool spieler1KIx, bool spieler2KIx);

private:
    void setzeEnde(bool spielEnde);
    void aendereAktuellenSpieler();
    bool macheSpielzug(Spielzug angabeSpielzug);
    void setzeErlaubteSpielzuege();
    void updateErlaubteSpielzuege();
    bool ueberpruefeSpielzug(int angabeX, int angabeY, int i, int j);
    void fuegeSpielzugHinzu(Spielzug angabeSpielzug);
    void loescheSpielzuege();
    void erhoeheErlaubetenZug(SpielerFarbe angabeFarbe);
    void setzeNeueSpielzuege();
    int werGewinnt();

    void updateGame(Spielzug angabeSpielzug);
    void updateReihe(Spielzug angabeSpielzug);
    void updateSpalte(Spielzug angabeSpielzug);
    void updateDiagonal(Spielzug angabeSpielzug);
    void spielbrettVeraenderung();
    bool macheKIZug();

signals:
    /**Sendet ein Signal, wenn sich an dem Spiel eine Veraendeung ergibt.*/
    void spielVeraenderung();
    /**Sendet ein Signal wenn das Spiel zuende ist.*/
    void spielEnde(QString gewinnerName);
    /**Sendet ein Signal, wenn ein Spielzug akzeptiert wurde.*/
    void localMove();

public slots:
    void setzeSpielstein(int angabeX, int angabeY);
    void nextTurn();
};

#endif // REVERSI_H
