//
// Created by niccolo on 10/09/18.
//

#ifndef UNI_INI_INI_H
#define UNI_INI_INI_H


#include<iostream>
#include<cstring>
#include<map>
#include<fstream>


using namespace std;

enum INI_errors{not_exist, duplicate, no_error, error};

class INI {
public:
    explicit INI(const string &name,const string &path = "");

    ~INI(){
        printAll();
    };

    INI_errors addParam(const string &parameter,const string &value,const string &section);
    INI_errors addSection(const string &section);
    INI_errors getParam(string& value,const string& parameter,const string& section) const;

    INI_errors delParam(const string &parameter,const string &section);
    INI_errors delSection(const string &section);

    INI_errors addComment(const string &comment,const string &parameter,const string &section );
    INI_errors addComment(const string& comment,const string& section);
    INI_errors getComment(string& comment, const string& section, const string& parameter = "" ) const;
    INI_errors delComment(const string &section,const string &parameter="");    //elimina il commento relativo al parametro parameter della sezione section

    INI_errors renameParam(const string &parameter,const string &newParam,const string &section);
    INI_errors renameSection(const string &section,const string &newSection);

    INI_errors changeParam(const string &parameter,const string &value ,const string &section);

    void printAll() ;
    void printOnScreen() const;

private:

    map< string , map< string, string>> ini;
    string name, path;
    fstream file;
};


#endif //UNI_INI_INI_H
