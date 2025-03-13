#include "magazzino.hpp"

void Inizializza_Magazzino_vuoto(Prodotto vettore[]){
    for(int i=0; i<MAX; i++){
        vettore[i].Codice = "";
        vettore[i].Genere = "";
        vettore[i].Qta = 0;
    }
}

bool Cerca_Codice_Prodotto(Prodotto prodotto, int dimensione, Prodotto vettore[]){
    
    int i = 0;
    bool trovato=false;
    
    while(i<dimensione && trovato == false){
        if(prodotto.Codice == vettore[i].Codice){
            trovato = true;
            cout<<"Prodotto già presente in magazzino in posizione ["<<i<<"]\n- - - RIPROVARE! - - - \n"<<endl;
            
        }else{
            i++;
        }
    }
    return trovato;
}

void Inizializza_Magazzino(int &dimensione, Prodotto vettore[], Prodotto prodotto){
    
    bool found = false;
    
    for(int i=0; i<dimensione; i++){
        
        do{
            cout<<"Inserire CODICE, GENERE e QUANTITÀ del prodotto in posizione ["<<i<<"]\n";
            Inserisci_DatiProdotto(prodotto);
            found = Cerca_Codice_Prodotto(prodotto, dimensione, vettore);
        }while(found == true);
        
        vettore[i].Codice = prodotto.Codice;
        vettore[i].Genere = prodotto.Genere;
        vettore[i].Qta = prodotto.Qta;
        
        cout<<"\n";
    }
}

void Visualizza_Magazzino(int &dimensione, Prodotto prodotto, Prodotto vettore[]){
    
    for(int i=0; i<dimensione; i++){
        
        prodotto.Codice = vettore[i].Codice;
        prodotto.Genere = vettore[i].Genere;
        prodotto.Qta = vettore[i].Qta;
        
        Visualizza_DatiProdotto(prodotto);
        cout<<"\t";
    }
}

void Elimina_Prodotto(int &dimensione, Prodotto vettore[]){
    
    int posizione;
//    validazione indice
    posizione = -1;
    do{
        cout<<"Inserire indice in cui eliminare il prodotto: ";
        cin>>posizione;
        cout<<endl;
        if(posizione<0 || posizione > dimensione -1){
            cout<<"POSIZIONE NON VALIDA: la posizione deve essere un numero >=0 e <="<<dimensione-1<<endl;
        }
    }while(posizione<0 || posizione > dimensione -1);
    
//    eliminazione  elemento (shift a sx)
    for(int i=posizione; i<dimensione-1; i++){
        vettore[i].Codice = vettore[i+1].Codice;
        vettore[i].Genere = vettore[i+1].Genere;
        vettore[i].Qta = vettore[i+1].Qta;
    }
    dimensione--;//importante
    
}


void Inserisci_Prodotto(int &dimensione,Prodotto prodotto, Prodotto vettore[]){
    
    //bug: la prima volta che provo a mettere un codice uguale a un altro elemento esistente, funziona tutto
    //ma la seconda volta no: prova a inserire questi dati in ordine: 3 (a a 1) (b b 2) (c c 1) 2 [RISOLTO]
    
    int posizione;
    bool trovato;
    
    trovato = Cerca_Codice_Prodotto(prodotto, dimensione, vettore);
    
    if((dimensione < MAX && dimensione > 0) && trovato == false){
        do{
            cout<<"Inserire indice in cui inserire il nuovo prodotto: ";
            cin>>posizione;
            cout<<endl;
            if(posizione<0 || posizione > MAX){
                cout<<"POSIZIONE NON VALIDA: la posizione deve essere un numero >=0 e <="<<dimensione-1<<endl<<endl;
            }else if(trovato == true){
                cout<<"TROVATO!"<<endl;
            }else{
                for(int i=posizione; i>1; i--){
                    vettore[i].Codice = vettore[i-1].Codice;
                    vettore[i].Genere = vettore[i-1].Genere;
                    vettore[i].Qta = vettore[i-1].Qta;
                }
                dimensione++;
                
                do{
                    cout<<"Inserire CODICE, GENERE e QUANTITÀ del prodotto:\n";
                    Inserisci_DatiProdotto(prodotto);
                    trovato = Cerca_Codice_Prodotto(prodotto, dimensione, vettore);
                    
                    vettore[posizione].Codice = prodotto.Codice;
                    vettore[posizione].Genere = prodotto.Genere;
                    vettore[posizione].Qta = prodotto.Qta;
                    
                }while(trovato == true);
            }
        }while((posizione<0 || posizione > MAX) /*&& trovato == true*/); //solved
    }else if (trovato == true){
        cout<<"Il magazzino contiene già quel prodotto!"<<endl;
    }
}
