#include <iostream>
#include <string.h>

/*NB: sto usando xcode ed è per questo motivo che nomino le librerie con .hpp e non .h*/
#include "prodotto.hpp"
#include "magazzino.hpp"

#define MAX 10

using namespace std;

int main() {
    
    Prodotto product;
    Prodotto magazzino[MAX];
    int dim;
    
    Inizializza_Magazzino_vuoto(magazzino);

    cout<<"Inserire dimensione del magazzino: ";
    cin>>dim;
    cout<<"\n";
    
    Inizializza_Magazzino(dim, magazzino, product);
    
    cout<<"Il magazzino contiene i seguenti elementi: "<<endl;
    Visualizza_Magazzino(dim, product, magazzino);
    cout<<endl<<endl;
    
    Elimina_Prodotto(dim, magazzino);
    if(dim == 0){
        cout<<"Il magazzino è vuoto!"<<endl;
    }else{
        cout<<"Il nuovo magazzino è: "<<endl;
        Visualizza_Magazzino(dim, product, magazzino);
        cout<<endl<<endl;
    }
    
    
    Inserisci_Prodotto(dim, product, magazzino);
    cout<<"Ora il vettore ha dimensione ["<<dim<<"]\n";
    Visualizza_Magazzino(dim, product, magazzino);
    
    
    return 0;
}
