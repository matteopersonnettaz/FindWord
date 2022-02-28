#include <iostream>
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <windows.h>

#define dim 12

using namespace std;

char word[dim][dim];

void riempiWord()
    {
    int i,j,da=77,a=90,alfalen;
    string alfa="AAAABBCCDDEEEEFFGGHIIIIJKLLMMNNOOOOPPQRRSSTTUUUUVVWXYZ";
    alfalen=alfa.length();
    for(i=0;i<dim;i++)
        {
        for(j=0;j<dim;j++)
            {
            //! funziona ma la matrice ha troppe consonanti
                //word[i][j]=(char)rand()%((a-da)+1)+da;
            word[i][j]=alfa.at(rand()%alfalen);
            }
        }
    }
void stampaWord()
    {
    int i,j;
    for(i=0;i<dim;i++)
        {
        for(j=0;j<dim;j++)
            {
            printf("\t%c%c%c%c%c",218,196,196,196,191);
            }
        cout<<endl;
        for(j=0;j<dim;j++)
            {
            printf("\t%c %c %c",179,word[i][j],179);
            }
        cout<<endl;
        for(j=0;j<dim;j++)
            {
            printf("\t%c%c%c%c%c",192,196,196,196,217);
            }
        cout<<endl;
        }
    }
int contaPunti(string parola)
    {
    return parola.length()*2;
    }
void setDir(int &i,int &j,int &k,int &dir,int &x,int &y,bool &trovato)
    {
    //! 1 <-
    if(dir==1)
        {
        j--;
        }
    //! 2 ->
    else if(dir==2)
        {
        j++;
        }
    //! 3 up
    else if(dir==3)
        {
        i--;
        }
    //! 4 dw
    else if(dir==4)
        {
        i++;
        }
    //! se i puntatori escono dalla matrice non ho trovato la parola
    if(i<0||i==dim||j<0||j==dim)
        {
        i=x;
        j=y;
        dir++;
        //! reimposto la direzione aggiornando i puntatori
        setDir(i,j,k,dir,x,y,trovato);
        }
    //! la parola non parte da quel punto. Cerco un'altra lettera da cui partire
    if(dir==5)
        {
        trovato=false;
        k=0;
        dir=1;
        i=x;
        j=y+1;
        if(j==dim)
            {
            j=0;
            i++;
            }
        }
}
bool trovaWord(string parola) //! controllo se c'e' la parola
    {
    int i=0,j=0,k=0,dir=1,x,y;
    bool trovato=false; // la parola non c'e'
    //! finche' non trovo tutta la parola o non controllo tutta la matrice
    while((k<parola.length())&&(i<dim))
        {
        //! controllo se la lettera della parola corrisponde a quella della matrice
        if(word[i][j]==parola.at(k))
            {
            trovato=true;
            x=i;
            y=j;
            k++;
            setDir(i,j,k,dir,x,y,trovato);
            }
        else
            {
            //! se avevo gia trovato delle lettere cerco la seconda in un altra dir
            if(trovato)
                {
                k=1;
                dir++;
                i=x;
                j=y;
                setDir(i,j,k,dir,x,y,trovato);
                }
            //! se non ho trovato niente vado avanti nella matrice
            else
                {
                j++;
                if(j==dim)
                    {
                    j=0;
                    i++;
                    }
                }
            }
        }
    return trovato;
    }
int main()
    {
    srand(time(NULL));
    int scelta;
    cout<<endl<<endl;
    cout<<"\t ======================================================================= "<<endl;
    cout<<"\t|\t    __             __   ____     _____   ____                   |\n";
    cout<<"\t|\t    \\ \\    ___    / /  / __ \\   / __  / |  _ \\                  |\n";
    cout<<"\t|\t     \\ \\  / _ \\  / /  / / / /  / /_/_/  | | \\ |                 |\n";
    cout<<"\t|\t      \\ \\/ / \\ \\/ /  / /_/ /  / /| |    | |_/ |                 |\n";
    cout<<"\t|\t       \\__/   \\__/   \\____/  /_/ |_|    |____/                  |\n";
    cout<<"\t|\t                                                                |\n";
    cout<<"\t|\t          'Parole a colpo d'occhio'                             |\n";
    cout<<"\t|\t                                                By Matteo       |\n";
    cout<<"\t ======================================================================= \n\n\n";
    //system("pause");
    do
    {
        string parola;
        int P1,P2;
        cout<<"**************"<<endl;
        cout<<"*    Menu'   *"<<endl;
        cout<<"**************"<<endl;
        cout<<"1. Gioca\n2. Info e regole\n0. Esci"<<endl<<endl<<"Scelta: ";
        cin>>scelta;
        switch(scelta)
        {
        case 1:
            {
            system("cls");
            riempiWord();
            stampaWord();
            cout<<endl<<endl<<endl<<"\t\t*************************************************************************************"<<endl;
            cout<<"\t\t*  Da ORA ti rimangono 90 secondi per cercare la parola piu' lunga. Buona fortuna!  *"<<endl;
            cout<<"\t\t*************************************************************************************"<<endl<<endl;
            cout<<endl<<endl<<"\t\t\t\t|Turno del GIOCATORE 1|"<<endl;
//            Sleep(90000);
            system("cls");
            cout<<"\t\t|Giocatore 1|"<<endl<<endl<<"Inserisci la parola: ";
            cin>>parola;
            if(trovaWord(parola)==true)
                {
                P1=contaPunti(parola);
                cout<<"Complimenti! Hai totalizzato "<<P1<<" punti."<<endl<<endl;
                }
            else
                {
                P1=0;
                cout<<endl<<endl<<"Beccato! Hai inserito una parola che non e' presente. "<<endl<<endl;
                cout<<"Hai totalizzato "<<P1<<" punti."<<endl<<endl;
                }
            cout<<endl<<"\t\t\t\t|Turno del GIOCATORE 2|"<<endl;
//            Sleep(3000);
            system("cls");
            cout<<"\t|Giocatore 2|"<<endl<<endl<<"Inserisci la parola: ";
            cin>>parola;
            if(trovaWord(parola)==true)
                {
                P2=contaPunti(parola);
                cout<<"Complimenti! Hai totalizzato "<<P2<<" punti."<<endl<<endl;
                }
            else
                {
                P2=0;
                cout<<endl<<endl<<"Beccato! Hai inserito una parola che non e' presente. "<<endl<<endl;
                cout<<"Hai totalizzato "<<P2<<" punti."<<endl<<endl;
                }
            if(P1>P2)
                {
                cout<<"\t\t\t\t*************************************"<<endl;
                cout<<"\t\t\t\t*  Il vincitore e' il GIOCATORE 1!  *"<<endl;
                cout<<"\t\t\t\t*************************************"<<endl;
                }
            else if(P1==P2)
                {
                cout<<"\t\t\t\t**************"<<endl;
                cout<<"\t\t\t\t*  PAREGGIO  *"<<endl;
                cout<<"\t\t\t\t**************"<<endl;
                }
            else
                {
                cout<<"\t\t\t\t*************************************"<<endl;
                cout<<"\t\t\t\t*  Il vincitore e' il GIOCATORE 2!  *"<<endl;
                cout<<"\t\t\t\t*************************************"<<endl;
                }
            }
        break;
        case 2:
            {
            system("cls");
            cout<<endl<<"\t\t\t\t|Regole del gioco|"<<endl<<endl;
            cout<<"- Lo scopo di questo gioco e' di cercare nel cruciverva la parola col maggior numero di lettere.\n- Le parole possono essere cercare nelle 4 direzioni:\n\t*Destra-Sinistra\n\t*Sinistra-Destra\n\t*Basso-Alto\n\t*Alto-Basso\n- Per ogni lettera che inserisci corretta, il giocatore guadagna 2 punti."<<endl<<endl<<endl;
            }
        break;
        }
    }while(scelta!=0);
    cout<<endl<<"Arrivederci!";
    return 0;
    }
