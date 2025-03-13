#ifndef magazzino_hpp
#define magazzino_hpp

#include "prodotto.hpp"
#define MAX 10

void Inizializza_Magazzino_vuoto(Prodotto []);
void Inizializza_Magazzino(int &, Prodotto [], Prodotto );
void Visualizza_Magazzino(int &, Prodotto, Prodotto []);
bool Cerca_Codice_Prodotto(Prodotto , int , Prodotto []);
void Elimina_Prodotto(int &, Prodotto []);
void Inserisci_Prodotto(int &,Prodotto , Prodotto []);

#endif /* magazzino_hpp */
