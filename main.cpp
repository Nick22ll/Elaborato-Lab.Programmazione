//
// Created by niccolo on 13/09/18.
//
#include"INI.h"

using namespace std;

int main()
{

    INI file("/home/niccolo/CLionProjects/Uni_INI/Testo.txt"); //Il file Testo.txt simula un inventario di un piccolo minimarket

    //Aggiungiamo la sezione [Carni]
    file.addSection("Carni");

    //Aggiungiamo quindi qualche merce
    file.addParam("Bistecca","20","Carni");

    if(file.addParam("Rosticciana","35","Cani") == not_exist)   // Se si commette qualche errore verrà restituito un valore INI_errors che aiuterà a capire l'errore(vale per tutti i metodi in INI.h
            cout<<"Sembra che la sezione non esista!"<<endl;

    //Possiamo aggiungere commenti...
    file.addComment("Solo di mucche italiane","Bistecca","Carni");

    //rinominare sezioni e parametri...
    file.renameSection("Carni","Macelleria");

    //cambiare parametri...
    file.changeParam("Bistecca","34","Macelleria");

    //o  eliminare ciò che abbiamo aggiunto...
    file.delSection("Macelleria");
    file.printOnScreen();

    return 0;

}