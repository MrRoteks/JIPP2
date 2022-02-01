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
vector<string> *readFile(string file_name,vector<string> *contents);
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
bool writeRecordToFile(string file_name, string field1, string field2, string field3);
/**
 * writeRecordToFile - zapisuje linie tekstu do pliku
 * @param file_name - nazwa pliku do ktorego zapisujemy
 * @param field1 - dane/tekst na pierwszej pozycji
 * @param field2 - dane/tekst na drugiej pozycji
 * @param field3 - dane/tekst na trzeciej pozycji
 * @return - true, jeśli pomyślnie zakończono działanie
 */
bool writeRecordToFile(string file_name, int field1, string field2, int field3);

/**
 * deleteRecordFromFile - usuwa wskazana linie tekstu (osobe) z pliku
 * @param file_name - nazwa pliku
 * @param id - id osoby
 * @param content - plik w formacie wektora (dla ulatwienia obslugi danych)
 * @return - wektor z usunieta linia
 */
vector<string> deleteRecordFromFile(string file_name,int id,vector<string> content);




/**
 * split - dzieli tekst na czesci
 * @param str - linia tekstu do podzialu
 * @param seperator - znak oddzielajacy wrazy/czesci tekstu
 */
void split (string str, char seperator);

/**
 * lenght - sprawdza dlugosc tekstu (do znaku '\0', pomocnicza funkcja)
 * @param str - tekst, ktorego dlugosc sprawdzamy
 * @return - ilosc liter w tekscie
 */
int lenght(string str);


//klasy

class Osoba{
private:
    string imie,nazwisko,dataWizyty;
    int id, rokUrodzenia;
public:
    Osoba(string imie,string nazwisko,int id,int rokUrodzenia);
    Osoba();
    ~Osoba();

    string getImie();

    string getNazwisko();

    string getDataWizyty();

    int getRokUrodzenia();

    void setImie(string nImie);

    void setNazwisko(string nNazwisko);

    void setDataWizyty(string nDataWizyty);

    void setRokUrodzenia(int nRokUrodzenia);

};
class OsobaId :public Osoba{
private: int id;
public:
    OsobaId();
    OsobaId(int id);
    ~OsobaId();

    int getId();
    void setId(int nId);
};

#endif //PROJEKT1_MATRIXLIB_H
