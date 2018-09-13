#include <iostream>
#include<string.h>
#include"INI.h"
#include<curses.h>

using namespace std;

enum Comandi{invalid_command, addPrm, addSct, delPrm, delSct, rnmPrm, rnmSct,addCmt, help, esc, out};
Comandi commands(const string& str);

int main() {

    string stringa, prm, val, sec;
    int prosegui;
    cout<<"Indica il nome del file che vuoi aprire (ed eventualmente il percorso)"<<endl;
    getline(cin,stringa);

    INI ini(stringa);
    do {

        system("cls");
        cout << "Se hai bisogno di ricordarti i comandi disponibili digita /help" << endl;
        getline(cin,stringa);

        switch(commands(stringa)) {

            case addPrm:
                system("cls");
                cout << "Indica in sequenza(separati da uno spazio): nome parametro, valore e sezione di appartenenza"<< endl;
                cin >> prm >> val >> sec;
                ini.addParam(prm, val, sec);

                cout << "Premi un tasto per continuare..." << endl;
                //getch();
                break;

            case addSct:
                system("cls");
                cout << "Indica il nome della sezione"<< endl;
                cin >> sec;
                ini.addSection(sec);

                cout << "Premi un tasto per continuare..." << endl;
                //getch();
                break;

            case delPrm:
                system("cls");
                cout << "Indica in sequenza(separati da uno spazio): nome parametro e sezione di appartenenza"<< endl;
                cin >> prm >> sec;
                ini.delParam(prm,sec);

                cout << "Premi un tasto per continuare..." << endl;
                //getch();
                break;

            case delSct:
                system("cls");
                cout << "Indica il nome della sezione"<< endl;
                cin >>  sec;
                ini.delSection(sec);

                cout << "Premi un tasto per continuare..." << endl;
                //getch();
                break;

            case rnmPrm:
                system("cls");
                cout << "Indica in sequenza(separati da uno spazio): nome parametro, nuovo nome e sezione di appartenenza"<< endl;
                cin >> prm >> val >> sec;
                ini.renameParam(prm,val,sec);

                cout << "Premi un tasto per continuare..." << endl;
                //prosegui = getch();
                break;
            case addCmt:
                cout<<""<<endl;
                cin >> prm >> val >> sec;
                ini.addComment(val,prm,sec);
                cout<<endl;
                break;
            case help:
                cout<<"\t/addPrm\n\t/addSct\n\t/delPrm\n\t/delSct\n\t/rnmPrm\n\t/rnmSct\n\t/esc"<<endl;
                break;

            case esc:
                cout<<"Hai scelto di uscire."<<endl;
                break;

            case out:
                ini.printOnScreen();
                break;

            default:
                cout<<"Comando non trovato!\nPremi un tasto per continuare..."<<endl;
                //noecho();
                break;
        }
    }while(stringa != "/esc");
    ini.delComment("Casa","Nicco");
    ini.delComment("Acquario");

}


Comandi commands(const string& str) {
    if(str == "/addPrm") return addPrm;
    if(str == "/addSct") return addSct;
    if(str == "/delPrm") return delPrm;
    if(str == "/delSct") return delSct;
    if(str == "/rnmPrm") return rnmPrm;
    if(str == "/rnmSct") return rnmSct;
    if(str == "/help") return help;
    if(str == "/esc") return esc;
    if(str == "/out") return out;
    if(str == "/addCmt") return addCmt;
    return invalid_command;

}