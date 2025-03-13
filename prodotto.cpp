#include <iostream>
#include <string.h>
#include "prodotto.hpp"

using namespace std;

void Inserisci_DatiProdotto(Prodotto &prodotto){
    cout<<"Codice: ";
    cin>>prodotto.Codice;
    cout<<"Genere: ";
    cin>>prodotto.Genere;
    cout<<"Quantità: ";
    cin>>prodotto.Qta;
    cout<<"\n";
}

void Modifica_Codice(Prodotto &prodotto, string nuovoCodice){
    prodotto.Codice = nuovoCodice;
}

string Fornisci_Codice(Prodotto prodotto){
    return prodotto.Codice;
}

void Visualizza_DatiProdotto(Prodotto &prodotto){
    cout<<"["<<prodotto.Codice<<", "<<prodotto.Genere<<", "<<prodotto.Qta<<"]";
}
