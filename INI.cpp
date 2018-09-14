//
// Created by niccolo on 10/09/18.
//

#include "INI.h"

INI::INI(const string &n, const string &p){

    name=n;
    path=p;
    string currentSection, currentComment;
    int control=5;
    char vetChar[1000];

    file.open(path+"/"+name, ios::in);

    if(file.is_open())
    {
        while (!file.eof()) {

            file.getline(vetChar, 1000);

            switch (vetChar[0]) {
                case '[': {
                    currentSection = vetChar;

                    currentSection.pop_back();

                    currentSection.erase(currentSection.begin());

                    addSection(currentSection);
                    if(control==1)
                        addComment(currentComment,currentSection);

                    break;
                }

                case ';': {
                    currentComment = vetChar;
                    currentComment.erase(currentComment.begin());
                    control=0;
                    break;
                }
                default: {
                    string stringa(vetChar);

                    for(auto pos = stringa.find(" "); pos!=string::npos ; pos = stringa.find(" "))   //Elimino eventuali spazi vuoti, fatto estetico e pro-ordine
                        stringa.erase(pos,1);

                    auto pos= stringa.find('=');

                    string parametro(stringa, 0, pos );
                    string valore(stringa, pos + 1, string::npos);

                    if (stringa.length() > 0)
                        addParam(parametro, valore, currentSection);
                    if(control==1)
                        addComment(currentComment,parametro,currentSection);
                    break;
                }
            }
            control++;
        }
    }
    file.close();
}

INI_errors INI::addParam(const string &parameter, const string &value, const string &section) {
    try{
        auto control = ini.at(section).insert(make_pair(parameter, value));

        if(!control.second)
            return duplicate;
        else
            return no_error;
    }
    catch(const out_of_range& err) {
        return not_exist;
    }


}

INI_errors INI::addSection(const string &section) {


    auto control = ini.find(section);
    if(control == ini.end()) {
        ini[section].insert(make_pair("",""));     // Non potendo inserire soltanto parte della mappa ho optato per aggiungere una coppia "vuota"
        return no_error;
    }else
        return duplicate;


}

INI_errors INI::delParam(const string &parameter, const string &section) {

    try {
        long int control = ini.at(section).erase(parameter);  //controllo numero di elementi cancellati

        if ((control > 0))
            return no_error;
        else
            return not_exist;
    }
    catch(const out_of_range& err) {
        return not_exist;
    }
    catch(...)
    {
        return error;
    }
}

INI_errors INI::delSection(const string &section) {

    long int control = ini.erase(section);


    if(control>0)
        return no_error;
    else
        return not_exist;

}

INI_errors INI::addComment(const string &comment, const string &parameter, const string &section) {
    try {
        INI_errors result = error;
        auto pos = ini.at(section).find(parameter);
        if(pos != ini.at(section).end()) {
            string str(parameter);
            str.pop_back();
            result = addParam(str + "$$$$", ";" + comment, section);
        } else
            result = not_exist;

        return result;
    }
    catch(out_of_range& err)
    {
        return not_exist;
    }
    catch(...)
    {
        return error;
    }
}

INI_errors INI::addComment(const string &comment, const string &section) {
    try {
        ini.at(section);
        string str(section);
        str.pop_back();
        auto control = ini[str + "$$$$"].insert(make_pair("$$$$", ";" + comment));
        if (control.second)
            return no_error;
        else
            return duplicate;
    }
    catch(out_of_range& err)
    {
        return not_exist;
    }
    catch(...)
    {
        return error;
    }


}

INI_errors INI::delComment( const string &section,const string &parameter) {
    try {
        long int control = 0;

        if (parameter == "") {
            string str(section);
            str.pop_back();
            control = ini.erase(str + "$$$$");

            if (control > 0)
                return no_error;
            else
                return not_exist;
        }else {
            string str(parameter);
            str.pop_back();
            control = ini.at(section).erase(str + "$$$$");

            if (control > 0)
                return no_error;
            else
                return not_exist;
        }
    }
    catch(out_of_range& err)
    {
        return not_exist;
    }
    catch(...)
    {
        return error;
    }
}

INI_errors INI::renameParam(const string &parameter, const string &newParam, const string &section) {

    try {
        INI_errors result ;
        auto pos = ini.at(section).find(parameter);     //utilizzo at per non creare nuovi elementi della mappa


        if (pos == ini.at(section).end())
            result = not_exist;
        else
        {
            auto control = ini.at(section).insert(make_pair(newParam, pos->second));
            if( !control.second)
                result = duplicate;
            else{
                ini[section].erase(pos);
                result = no_error;
            }
        }
        return result;
        }
    catch(const out_of_range& err)
    {
        return not_exist;
    }
    catch(...)
    {
        return error;
    }

}

INI_errors INI::renameSection(const string &section, const string &newSection) {

    auto pos = ini.find(section);

    if(pos == ini.end())
        return not_exist;

    auto control = ini.insert(make_pair(newSection, pos->second));

    if (!control.second)
        return duplicate;
    else
    {
        ini.erase(pos);
        return no_error;
    }
}

INI_errors INI::changeParam(const string &parameter,const string &value, const string &section) {
    try {
        auto pos = ini.at(section).find(parameter);
        if(pos != ini.at(section).end()) {
            pos->second = value;
            return no_error;
        }
        else
            return not_exist;

    }
    catch(out_of_range& err)
    {
        return not_exist;
    }
}

void INI::printAll() {

    file.open(path+"/"+name, ios::out);

    for (auto &it : ini) {
        if(it.first.find("$$$$") == string::npos)
            file<<"["<< it.first<<"]"<<endl;  // Stampo nome della sezione

        for(auto innerIt = it.second.begin() ; innerIt != it.second.end() ; innerIt++)
        {
            if(innerIt->first.find("$$$$") != string::npos)
                file<<innerIt->second<<endl;
            else {
                if (innerIt->first != "")
                    file << innerIt->first << " = " << innerIt->second << endl;
            }
        }

    }

    file.close();
}


void INI::printOnScreen() const {

    for (auto &it : ini) {
        if(it.first.find("$$$$") == string::npos)
            cout<<"["<< it.first<<"]"<<endl;  // Stampo nome della sezione

        for(auto innerIt = it.second.begin() ; innerIt != it.second.end() ; innerIt++)
        {
            if(innerIt->first.find("$$$$") != string::npos)
                cout<<innerIt->second<<endl;
            else {
                if (innerIt->first != "")
                    cout << innerIt->first << " = " << innerIt->second << endl;
            }
        }

    }
}

INI_errors INI::getParam(string& value, const string &parameter, const string &section) const {

    try {
        auto pos = ini.at(section).find(parameter);
        if(pos != ini.at(section).end()) {
            value = pos->second;
            return no_error;
        }
        else
            return not_exist;

    }
    catch(const out_of_range& err) {
        return not_exist;
    }
    catch(...)
    {
        return error;
    }
}

INI_errors INI::getComment(string &comment, const string &section, const string &parameter) const {
    try {
        string str;
        if(parameter == ""){
            str = section;
            str.pop_back();
            auto pos = ini.at(str+"$$$$").find("$$$$");
            if(pos == ini.at(str+"$$$$").end())
                return not_exist;
            else{
                comment = pos->second;
                return no_error;
            }

        }else
            {
                str = parameter;
                str.pop_back();
                auto pos = ini.at(section).find(str+"$$$$");
                if(pos != ini.at(section).end()) {
                    comment = pos->second;
                    return no_error;
                }
                else
                    return not_exist;

            }

    }
    catch(const out_of_range& err) {
        return not_exist;
    }
    catch(...)
    {
        return error;
    }
}
