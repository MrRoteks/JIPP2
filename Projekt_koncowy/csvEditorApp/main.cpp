#include <iostream>
#include "../include/csvEditorLib.h"
#include<string>
#include<vector>


int main(int argc, char *argv[]) {
    if (argc>2) {                       //check for too many arg
        cout<<"Zla ilosc argumentow.";
        exit(-1);
    }
    string arg1=argv[1];
    if(arg1!="nohelp")              //when 1st arg is "nohelp" don't show help info
    {
        wyswietlOpcje();
    }
//variables
    string search_term,newName,defFileName="dane.csv",newBirthDate,newSurname,newVisit;
    int opcja,n,check,id,newID,newPrice;
    vector<string> lista;

    Osoba *os1=new OsobaId();

        //przykladowe urzycie szablonu dla funkcji zwracajacej np najwieksza kwote (za zabieg)
     //cout << myMax<int>(100, 300) << endl;  // max z int
    //cout << myMax<double>(553.3, 212.2) << endl; // max z double

        //przykladowe urzycie przeciarzania operatorow
        /*
        Osoba os2,os3,sumaKwot;
        os2.setKwota(200);
        os3.setKwota(300);
        sumaKwot=os2+os3;

        cout<<"Wyplata: "<<sumaKwot.kwota;
         */
//Get user to choose an option to execute
    cout<<"Podaj dzialanie jakie chcesz wykonac: ";
    cin>>opcja;     checkInput();
                    //check for wrong input
    do {
        switch (opcja) {
            case -1:                //shows help
                wyswietlOpcje();
                break;
            case 0:                 //exits program
                cout << "Zamykam program...";
                exit(0);
            case 1:                 //reads whole file and displays it in console
                lista=readFile(defFileName);
                showList(lista);
                break;

            case 2:                 //searches for record with specified word/number
                cout<<"Szukac po id[1] czy imieniu[2]? ";
                cin>>check;
                checkInput();
                if(check==1){
                    cout << "Podaj id wg ktorego chcesz szukac"<<endl;
                    cin>>id;       checkInput();
                    readRecordFromFile(defFileName,id);
                }
                else if(check==2){
                    cout << "Podaj wyraz wg ktorego chcesz szukac"<<endl;
                    cin >> search_term; checkInput();
                    readRecordFromFile(defFileName, search_term);
                    }
                else
                    cout<<"Dostepne opcje to [1] lub [2]. Sproboj ponownie od nowa.";
                break;

            case 3:                 //adds new record
                cout << "Ile osob chcesz dodac: "<<endl;
                cin>>n;     checkInput();
                while (n>0){
                    cout << "Podaj [id] [Imie][Nazwisko] [RokUrodzenia] [DataWizyty] [Kwota]: "<<endl;
                    cin >> newID >> newName >>newSurname>> newBirthDate>>newVisit>>newPrice;    checkInput();
                    os1->setImie(newName);
                    os1->setNazwisko(newSurname);
                    os1->setId(newID);
                    os1->setRokUrodzenia(newBirthDate);
                    os1->setDataWizyty(newVisit);
                    os1->setKwota(newPrice);
                    cout<<"Podales/as : \n"; os1->showAll(); cout<<endl;
                    writeRecordToFile(defFileName, os1->getId(),os1->getImie(),os1->getNazwisko(),  os1->getRokUrodzenia(), os1->getDataWizyty(),os1->kwota);
                    n--;
                }
                break;

            case 4:             //deletes record by id
                cout << "Podaj id osoby do edycji: ";
                cin>>id;  checkInput();

                lista=readFile(defFileName);
                cout<<"Podaj nowe dane: "<<endl;
                cin >> newID >> newName >>newSurname>> newBirthDate>>newVisit>>newPrice;    checkInput();

                changeRecordFromFile(defFileName,id,lista,newID,newName,newSurname,newBirthDate,newVisit,newPrice);
                break;
            default:
                cout << "Nie istnieje taka opcja.";
                break;

            case 5:             //deletes record by id
                cout << "Podaj id osoby do usuniecia: ";
                cin>>id;  checkInput();

                lista=readFile(defFileName);
                deleteRecordFromFile(defFileName,id,lista);
                break;
        }
        cout<<"\n\n---------------------------------------- "<<endl;
        cout<<"Podaj dzialanie jakie chcesz wykonac: ";
        cin>>opcja;  checkInput();
    }while(true);   //repeats app untill user goes into "case 0"

    return 0;
}

