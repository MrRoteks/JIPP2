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
                        "4. Usun osobe z listy\n"
                        "------------------------------KONIEC-----------------------------\n";

    cout << opcje;
}


void showList (vector<string> lista) {
    int n;
    for (auto i = lista.begin(); i != lista.end(); ++i) {
        cout << *i << " ";
        n++;
        if (n % 3 == 0) {
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
        for (int i = 0; i < 3; i++) {
            contents.push_back(strings[i]);
        }

    }
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
        for (int i = 0; i < 3; i++) {
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
            for (int i = 0; i < 3; i++)
                record.push_back(strings[i]);
        }


    }
    if (found_record == true)
        cout << "Znaleziono: " << record[0] << " " << record[1] << " " << record[2] << endl;
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

        if (strings[0] == search_term || strings[1] == search_term || strings[2] == search_term) {
            found_record = true;
            for (int i = 0; i < 3; i++)
                record.push_back(strings[i]);
        }
    }
    if (found_record == true)
        cout << "Znaleziono: " << record[0] << " " << record[1] << " " << record[2] << endl;
    else
        cout << "Nie znaleziono wskazanej osoby.";

    return record;
}

bool writeRecordToFile (string file_name, string field1, string field2, string field3) {
    ofstream file;
    file.open(file_name,ios_base::app); // ios_base::app powoduje dopisanie do pliku (bez niego bysmy tylko nadpisywali)
    file << field1 << ";" << field2 << ";" << field3 << endl;
    file.close();
    cout << "Pomyslnie zapisano do pliku: " << field1 << ";" << field2 << ";" << field3 << endl;

    return true;

}

bool writeRecordToFile (string file_name, int field1, string field2, int field3) {
    ofstream file;
    file.open(file_name,ios_base::app); // ios_base::app powoduje dopisanie do pliku (bez niego bysmy tylko nadpisywali)
    file << field1 << ";" << field2 << ";" << field3 << endl;
    file.close();
    cout << "Pomyslnie zapisano do pliku: " << field1 << ";" << field2 << ";" << field3 << endl;

    return true;

}


vector<string> deleteRecordFromFile (string file_name, int id, vector<string> content) {
    string temp = to_string(id);
    int n = content.size(), i;
    vector<string> swap;

    for (i = 0; i < n; i++) {
        if (content[i] == temp) {
            cout << "Usunieto:" << content[i] << " " << content[i + 1] << " " << content[i + 2] << " ";
            content[i].erase();
            content[i + 1].erase();
            content[i + 2].erase();
            break;
        }
    }
    if (i == n) {
        cout << "Nie znaleziono osoby o id =" << temp << endl;
        return content;
    }
    for (int j = 0; j < n; j++) {
        if (j < i || j > i + 2)
            swap.push_back(content[j]);
    }

    n = swap.size();


    ofstream file;
    file.open(file_name);
    for (int i = 0; i < n; i++) {

        file << swap[i] << ";";
        if ((i % 3 - 2 == 0 && i != 0) || i == 2)
            file << "\n";
    }

    file.close();
    return swap;
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

Osoba::Osoba (string imie, string nazwisko, int id, int rokUrodzenia) {
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


int Osoba::getRokUrodzenia () {
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
void Osoba::setRokUrodzenia (int nRokUrodzenia) {
    this->rokUrodzenia = nRokUrodzenia;
}

OsobaId::OsobaId (int id) {
    this->id=id;
}
OsobaId::OsobaId (){}

void OsobaId::setId (int nId) {
    this->id = nId;
}
int OsobaId::getId () {
    return id ;
}
