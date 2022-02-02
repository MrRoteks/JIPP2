#include <iostream>
#include "../include/csvEditorLib.h"

string strings[10];

void wyswietlOpcje () {

    const char *opcje = "-------------------------CSV File Editor-------------------------\n"
                        "-----------------------------------------------------------------\n"
                        "                              Opcje:                             \n"
                        "-1. Wyswietl dostepne opcje\n"
                        "0. Zakoncz program\n"
                        "1. Wyswietl zawartosc pliku \n"
                        "2. Znajdz dane wg. podanego wzorca\n"
                        "3. Zapisz nowe dane do pliku\n"
                        "4. Edytuj dane osoby\n"
                        "5. Usun osobe z listy\n"
                        "------------------------------KONIEC-----------------------------\n";

    cout << opcje;
}


void showList (vector<string> lista) {
    vector<string> temp;
    int n;
    for (auto i = lista.begin(); i != lista.end(); ++i) {
        cout << *i << " ";
        temp.push_back(*i);
        n++;
        if (n % 6 == 0) {
            cout << endl;
        }
    }

}

vector<string> readFile (string file_name) {
    vector<string> contents;

    ifstream file;
    file.open(file_name);


    string temp;
    string current_line;

    while (getline(file, current_line)) {
        split(current_line, ';');
        //cout<<strings[0]<<" "<<strings[1]<<" "<<strings[2]<<endl;
        for (int i = 0; i < 6; i++) {
            contents.push_back(strings[i]);
        }

    }
    file.close();
    return contents;
}

vector<string> *readFile (string file_name, vector<string> *contents) {


    ifstream file;
    file.open(file_name);


    string temp;
    string current_line;

    while (getline(file, current_line)) {
        split(current_line, ';');
        //cout<<strings[0]<<" "<<strings[1]<<" "<<strings[2]<<endl;
        for (int i = 0; i < 6; i++) {
            contents->push_back(strings[i]);
        }

    }
    return contents;
}

vector<string> readRecordFromFile (string file_name, int id) {
    vector<string> record;

    ifstream file;
    file.open(file_name);

    bool found_record = false;

    string temp = to_string(id);
    string current_line;


    while (getline(file, current_line) && !found_record) {

        split(current_line, ';');

        if (strings[0] == temp) {
            found_record = true;
            for (int i = 0; i < 6; i++)
                record.push_back(strings[i]);
        }


    }
    if (found_record == true)
        cout << "Znaleziono: " << record[0] << " " << record[1] << " " << record[2]<< " " << record[3]<< " " << record[4]<< " " << record[5] << endl;
    else
        cout << "Nie znaleziono wskazanej osoby.";

    return record;
}

vector<string> readRecordFromFile (string file_name, string search_term) {
    vector<string> record;

    ifstream file;
    file.open(file_name);

    bool found_record = false;

    string temp;
    string current_line;


    while (getline(file, current_line) && !found_record) {

        split(current_line, ';');

        if (strings[0] == search_term || strings[1] == search_term || strings[2] == search_term|| strings[3] == search_term|| strings[4] == search_term|| strings[5] == search_term) {
            found_record = true;
            for (int i = 0; i < 6; i++)
                record.push_back(strings[i]);
        }
    }
    if (found_record == true)
        cout << "Znaleziono: " << record[0] << " " << record[1] << " " << record[2]<< " " << record[3]<< " " << record[4]<< " " << record[5] << endl;
    else
        cout << "Nie znaleziono wskazanej osoby.";

    return record;
}
//writeRecordToFile(defFileName, os1->getId(),os1->getImie(),os1->getNazwisko(),  os1->getRokUrodzenia(), os1->getDataWizyty(),os1->kwota);

bool writeRecordToFile (string file_name, string field1, string field2, string field3, string field4, string field5, string field6) {
    ofstream file;
    file.open(file_name,ios_base::app); // ios_base::app powoduje dopisanie do pliku (bez niego bysmy tylko nadpisywali)
    file << field1 << ";" << field2 << ";" << field3 <<";" << field4<<";" << field5<<";" << field6<< endl;
    file.close();
    cout << "Pomyslnie zapisano do pliku: " << field1 << ";" << field2 << ";" << field3 <<";" << field4<<";" << field5<<";" << field6<< endl;

    return true;

}

bool writeRecordToFile (string file_name, int field1, string field2,string field3, string field4, string field5, int field6) {
    ofstream file;
    file.open(file_name,ios_base::app); // ios_base::app powoduje dopisanie do pliku (bez niego bysmy tylko nadpisywali)
    file << field1 << ";" << field2 << ";" << field3 <<";" << field4<<";" << field5<<";" << field6<< endl;
    file.close();
    cout << "Pomyslnie zapisano do pliku: " << field1 << ";" << field2 << ";" << field3 <<";" << field4<<";" << field5<<";" << field6<< endl;

    return true;

}


vector<string> deleteRecordFromFile (string file_name, int id, vector<string> content) {
    string temp = to_string(id);
    int n = content.size(), i;
    vector<string> swap;

    for (i = 0; i < n; i++) {
        if (content[i] == temp) {
            cout << "Usunieto:" << content[i] << " " << content[i + 1] << " " << content[i + 2] << " " << content[i + 3]<< " " << content[i + 4] <<" "<< content[i + 5];
            content[i].erase();
            content[i + 1].erase();
            content[i + 2].erase();
            content[i + 3].erase();
            content[i + 4].erase();
            content[i + 5].erase();
            break;
        }
    }
    if (i == n) {
        cout << "Nie znaleziono osoby o id =" << temp << endl;
        return content;
    }
    for (int j = 0; j < n; j++) {
        if (j < i || j > i + 5)
            swap.push_back(content[j]);
    }

    n = swap.size();


    ofstream file;
    file.open(file_name);
    for (int i = 0; i < n; i++) {

        file << swap[i] << ";";
        if ((i % 6 - 5 == 0 && i != 0) || i == 5)
            file << "\n";
    }

    file.close();
    return swap;
}

vector<string> changeRecordFromFile (string file_name, int id, vector<string> content,int newId,string newName,string newSurname,string newBirthDate,string newVisit,int newPrice) {
    string temp = to_string(id);
    int n = content.size(), i;
    vector<string> swap;
    string newId1= to_string(newId);
    string newPrice1= to_string(newPrice);
    for (i = 0; i < n; i++) {
        if (content[i] == temp) {
            cout << "Zmieniono:" << content[i] << " " << content[i + 1] << " " << content[i + 2] << " " << content[i + 3]<< " " << content[i + 4] <<" "<< content[i + 5];
            content[i]= newId1;
            content[i + 1]= newName;
            content[i + 2]= newSurname;
            content[i + 3]= newBirthDate;
            content[i + 4]= newVisit;
            content[i + 5]= newPrice1;
            cout << "\nna:" << content[i] << " " << content[i + 1] << " " << content[i + 2] << " " << content[i + 3]<< " " << content[i + 4] <<" "<< content[i + 5];


            break;
        }
    }
    if (i == n) {
        cout << "\nNie znaleziono osoby o id =" << temp << endl;
        return content;
    }


    ofstream file;
    file.open(file_name);
    for (int i = 0; i < n; i++) {

        file << content[i] << ";";
        if ((i % 6 - 5 == 0 && i != 0) || i == 5)
            file << "\n";
    }

    file.close();
    cout<<"\nPomyslne zapisano zmiany."<<endl;
    return content;
}

//supporting functions
void split (string str, char seperator) {
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= lenght(str)) {
        if (str[i] == seperator || i == lenght(str)) {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

int lenght (string str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;

    }
    return length;
}

void checkInput () {
    if (cin.fail() == 1) {
        cout << "Bledna wartosc/typ danych.";
        exit(6);
    }
}

Osoba::Osoba () {}

Osoba::Osoba (string imie, string nazwisko, string id, string rokUrodzenia) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->rokUrodzenia = rokUrodzenia;
    this->dataWizyty = dataWizyty;
    cout << "Zapisano osobe: " << imie << " " << nazwisko << " " << id << " " << rokUrodzenia << " " << dataWizyty
         << endl;
}

Osoba::~Osoba () {
    cout << "Usunieto osobe: " << imie << " " << nazwisko << " " << id << " " << rokUrodzenia << " " << dataWizyty
         << endl;
}

string Osoba::getImie () {
    return imie;
}

string Osoba::getNazwisko () {
    return nazwisko;
}

string Osoba::getDataWizyty () {
    return dataWizyty;
}


string Osoba::getRokUrodzenia () {
    return rokUrodzenia;
}

void Osoba::setImie (string nImie) {
    this->imie = nImie;

}

void Osoba::setNazwisko (string nNazwisko) {
    this->nazwisko = nNazwisko;

}

void Osoba::setDataWizyty (string nDataWizyty) {
    this->dataWizyty = nDataWizyty;
}
void Osoba::setRokUrodzenia (string nRokUrodzenia) {
    this->rokUrodzenia = nRokUrodzenia;
}

void Osoba::setId (int nId) {
    this->id = nId;
}
int Osoba::getId () {
    return 1 ;
}

OsobaId::OsobaId (int id) {
    this->id=id;
}
OsobaId::OsobaId (){}
OsobaId::~OsobaId(){}
void OsobaId::setId (int nId) {
    this->id = nId;
}
int OsobaId::getId () {
    return id ;
}

 void Osoba::showAll(){
cout<<"Informacje o zapisanej osobie w pamieci: "<<endl;
cout<<" "<<imie<<" "<<nazwisko<<" "<<rokUrodzenia<<" "<<dataWizyty;
}
void Osoba :: setKwota(int kwota){
    this->kwota=kwota;
}

void OsobaId::showAll() {
    cout<<"Informacje o zapisanej osobie w pamieci: "<<endl;
    cout<<id<<" "<<imie<<" "<<nazwisko<<" "<<rokUrodzenia<<" "<<dataWizyty;

}


