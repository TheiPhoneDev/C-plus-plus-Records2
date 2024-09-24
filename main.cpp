#include <iostream>

using namespace std;

struct Prodotti {
    string codice;
    string nome;
    string categoria;
    float prezzo;
    
};

const int dimensionMax=100;

//prototipi
void carica(Prodotti v[], int &n);
float media(Prodotti v[], int n);
void mediaCatgoria(Prodotti v[], int n);
void ordinaRecord(Prodotti v[], int n);
void stampa(Prodotti v[], int n);
int Menu();


int main() {
    
    int n;
    Prodotti prod[dimensionMax];
    int scelta;
    float m=0.00;
    
    carica(prod,n);

    do {
        scelta=Menu();
        switch(scelta) {
            case 1:
                stampa(prod,n);
            break;
            case 2:
                mediaCatgoria(prod,n);
            break;
            case 3:
                m=media(prod,n);
                cout<<"La media dei prodotti e' : "<<m<<endl;
            break;
            case 4:
                ordinaRecord(prod,n);
            break;
            case 5:
                stampa(prod,n);
            break;
        }
    }while(scelta!=0);

    return 0;
}

int Menu () {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Visualizza prodotti"<<endl;
  cout<<"2-Calcola media per categoria"<<endl;
  cout<<"3-Calcola media di tutti i prodotti"<<endl;
  cout<<"4-Ordina prodotti in ordine crescente di codice"<<endl;
  cout<<"5-Stampa tabella ordinata"<<endl;

  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}

void carica(Prodotti v[], int &n) {
    
    cout<<"Quanti prodotti vuoi registrare ? : ";
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cout<<endl;
        cout<<"Inserisci il codice del prodotto: ";
        cin>>v[i].codice;
        cout<<"Inserisci il nome del prodotto: ";
        cin>>v[i].nome;
        cout<<"Inserisci la categoria del prodotto: ";
        cin>>v[i].categoria;
        cout<<"Inserisci il prezzo del prodotto: ";
        cin>>v[i].prezzo;
        cout<<endl;
    }
    
    cout<<"Caricamento completato!"<<endl;
    
}

void stampa(Prodotti v[], int n) {
    
    cout<<endl;
    
    cout<<"Prodotti: "<<endl;
    
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        cout<<endl;
        cout<<"Codice prodotto: "<<v[i].codice<<endl;
        cout<<"Nome prodotto: "<<v[i].nome<<endl;
        cout<<"Categoria prodotto: "<<v[i].categoria<<endl;
        cout<<"Prezzo prodotto: "<<v[i].prezzo<<" euro"<<endl;
        cout<<endl;
    }
    
    cout<<endl;
    
}



float media(Prodotti v[], int n) {
   
   float m=0.00;
   float s=0.00;
   
   for(int i=0; i<n; i++) {
       s=s+v[i].prezzo;
   }
   
   m=s/n;
   
   return m;
   
    
}

void mediaCatgoria(Prodotti v[], int n) {
    
    string categoria;
    float s=0.00;
    float m=0.00;
    int k=0;
    
    cout<<"Inserisci la categoria: ";
    cin>>categoria;
    
    for(int i=0; i<n; i++) {
        if(v[i].categoria == categoria) {
            s=s+v[i].prezzo;
            k++;
        }
    }
    
    m=s/k;
    
    cout<<"La media dei prodotti appartenenti alla categoria "<<categoria<<" e' : "<<m<<endl;
    
}

void ordinaRecord(Prodotti v[], int n) {
    
    Prodotti temp;
    
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(v[i].codice>v[j].codice) {
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
    
    cout<<endl;
    
    stampa(v,n);
    
    cout<<endl;
    
    
}
