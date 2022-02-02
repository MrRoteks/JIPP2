#ifndef PROJEKT1_MATRIXLIB_H
#define PROJEKT1_MATRIXLIB_H

#include <iostream>
#include <iomanip>
#include<fstream>
#include<string>
#include <cstring>
#include<vector>

//dorobić wyjątki (exeptions)

using namespace std;

/**
 * wyswietlOpcje - wypisze dostepne, ponumerowane operacje dostepne dla urzytkownika
 */
void wyswietlOpcje();

/**
 * checkInput - sprawdza poprawnosc podanych danych przez "cin"
 */
void checkInput();


/**
 * readFile - czyta caly podany plik
 * @param file_name - nazwa pliku do przeczytania
 * @return - wektor z zawartoscia pobrana z pliku
 */


vector<string> *readFile(string file_name, vector<string> *contents);

/**
 * readFile - czyta caly podany plik
 * @param file_name - nazwa pliku do przeczytania
 * @return - wektor z zawartoscia pobrana z pliku
 */
vector<string> readFile(string file_name);

/**
 * showList - wyswietla zawartosc wektora
 * @param lista - wektor z zawartoscia
 */

void showList(vector<string> lista);

/**
 * readRecordFromFile - czyta linie z pliku po wskazanych wzorcach
 * @param file_name - nazwa pliku do przeszukania
 * @param search_term -ciag znakow do wyszukania w pliku
 * @return - zwraca linie tekstu z pliku (szukane dane)
 */
vector<string> readRecordFromFile(string file_name, string search_term);

/**
 * readRecordFromFile - czyta linie z pliku po wskazanych wzorcach
 * @param file_name - nazwa pliku do przeszukania
 * @param search_term -ciag znakow do wyszukania w pliku
 * @return - zwraca linie tekstu z pliku (szukane dane)
 */
vector<string> readRecordFromFile(string file_name, int id);

/**
 * writeRecordToFile - zapisuje linie tekstu do pliku
 * @param file_name - nazwa pliku do ktorego zapisujemy
 * @param field1 - dane/tekst na pierwszej pozycji
 * @param field2 - dane/tekst na drugiej pozycji
 * @param field3 - dane/tekst na trzeciej pozycji
 * @return - true, jeśli pomyślnie zakończono działanie
 */
bool writeRecordToFile (string file_name, string field1, string field2, string field3, string field4, string field5, string field6) ;

/**
 * writeRecordToFile - zapisuje linie tekstu do pliku
 * @param file_name - nazwa pliku do ktorego zapisujemy
 * @param field1 - dane/tekst na pierwszej pozycji
 * @param field2 - dane/tekst na drugiej pozycji
 * @param field3 - dane/tekst na trzeciej pozycji
 * @return - true, jeśli pomyślnie zakończono działanie
 */
bool writeRecordToFile (string file_name, int field1, string field2,string field3, string field4, string field5, int field6) ;

/**
 * deleteRecordFromFile - usuwa wskazana linie tekstu (osobe) z pliku
 * @param file_name - nazwa pliku
 * @param id - id osoby
 * @param content - plik w formacie wektora (dla ulatwienia obslugi danych)
 * @return - wektor z usunieta linia
 */
vector<string> deleteRecordFromFile(string file_name, int id, vector<string> content);

/**
 * changeRecordFromFile - zamienia podane przez urzytkownika dane w pliku
 * @param file_name - nazwa pliku
 * @param id -id os do zmiany
 * @param content - wektor z osoba
 * @param newId -id os do zmiany
 * @param newName -Imie os do zmiany
 * @param newSurname -Nazwisko os do zmiany
 * @param newBirthDate -data urodzenia os do zmiany
 * @param newVisit -data wizyty os do zmiany
 * @param newPrice -kwota os do zmiany
 * @return
 */
vector<string> changeRecordFromFile (string file_name, int id, vector<string> content,int newId,string newName,string newSurname,string newBirthDate,string newVisit,int newPrice) ;
/**
 * split - dzieli tekst na czesci
 * @param str - linia tekstu do podzialu
 * @param seperator - znak oddzielajacy wrazy/czesci tekstu
 */
void split(string str, char seperator);

/**
 * lenght - sprawdza dlugosc tekstu (do znaku '\0', pomocnicza funkcja)
 * @param str - tekst, ktorego dlugosc sprawdzamy
 * @return - ilosc liter w tekscie
 */
int lenght(string str);


//klasy

class Osoba {
private:
    string id;
protected:
    string imie, rokUrodzenia;
    string nazwisko;
    string dataWizyty;

public:
    int kwota;

    Osoba(string imie, string nazwisko, string id, string rokUrodzenia);

    Osoba();

    virtual ~Osoba();

    string getImie();

    string getNazwisko();

    string getDataWizyty();

    string getRokUrodzenia();

    void setImie(string nImie);

    void setNazwisko(string nNazwisko);

    void setDataWizyty(string nDataWizyty);

    void setRokUrodzenia(string nRokUrodzenia);

    void setKwota(int kwota);

    virtual int getId();

    virtual void setId(int nId);

    virtual void showAll();

    Osoba operator+(Osoba &obj) {
        Osoba wynik;
        wynik.kwota=kwota + obj.kwota;
        return wynik;
    }


};

class OsobaId : public Osoba {
private:
    int id;
public:
    OsobaId();

    OsobaId(int id);

    ~OsobaId();

    virtual int getId();

    virtual void setId(int nId);

    virtual void showAll();
};


template<typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}

#endif //PROJEKT1_MATRIXLIB_H
