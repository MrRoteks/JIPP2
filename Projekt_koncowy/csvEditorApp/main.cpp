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
    string search_term,newName;
    int opcja,n,check,id,newID,newBirthDate;
    vector<string> lista;

    OsobaId *os1=new OsobaId();
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
                lista=readFile("dane.csv");
                showList(lista);
                break;

            case 2:                 //searches for record with specified word/number
                cout<<"Szukac po id[1] czy imieniu[2]? ";
                cin>>check;
                checkInput();
                if(check==1){
                    cout << "Podaj id wg ktorego chcesz szukac"<<endl;
                    cin>>id;       checkInput();

                    readRecordFromFile("dane.csv",id);
                }
                else if(check==2){
                    cout << "Podaj wyraz wg ktorego chcesz szukac"<<endl;
                    cin >> search_term; checkInput();
                    readRecordFromFile("dane.csv", search_term);
                    }
                else
                    cout<<"Dostepne opcje to [1] lub [2]. Sproboj ponownie od nowa.";
                break;

            case 3:                 //adds new record
                cout << "Ile osob chcesz dodac: "<<endl;
                cin>>n;     checkInput();
                while (n>0){
                    cout << "Podaj [id] [Imie] [RokUrodzenia]: "<<endl;
                    cin >> newID >> newName >> newBirthDate;    checkInput();
                    os1->setImie(newName);
                    os1->setId(newID);
                    os1->setRokUrodzenia(newBirthDate);

                    writeRecordToFile("dane.csv", os1->getId(),os1->getImie(),  os1->getRokUrodzenia());
                    n--;
                }
                break;

            case 4:
                cout << "Podaj id osoby do usuniecia: ";
                cin>>id;  checkInput();

                lista=readFile("dane.csv");
                deleteRecordFromFile("dane.csv",id,lista);
                break;
            default:
                cout << "Nie istnieje taka opcja.";
                break;
        }
        cout<<"\n\n---------------------------------------- "<<endl;
        cout<<"Podaj dzialanie jakie chcesz wykonac: ";
        cin>>opcja;  checkInput();
    }while(true);   //repeats app untill user goes into "case 0"

    return 0;
}

