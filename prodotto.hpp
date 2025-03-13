#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <iostream>
#include <string.h>

using namespace std;

struct Prodotto{
    string Codice;
    string Genere;
    int Qta;
};

//prototipi
void Inserisci_DatiProdotto(Prodotto &);
void Modifica_Codice(Prodotto &, string );
string Fornisci_Codice(Prodotto );
void Visualizza_DatiProdotto(Prodotto &);

#endif // PRODOTTO_H


