#include <iostream>
#include <string>

using namespace std;


int main (int argc, char *argv[]) {

    //int l = stoi(_Str:argv[3]);
//        switch (argv[1]) {
//            case "add":
//                cout>>"Podaj liczby do dodania: "
//                break;
//
//            case "substract":
//                //jakiś kod
//                break;
//
//            case "volume":
//                //jakiś kod
//                break;
//
//            case "help":
//                //jakiś kod
//                break;
//
//            default:
//                //jakiś kod
//                break;
//        }



    for(int i = 0; i < argc ; ++i)
    {
        cout << argv[i] <<endl;
    }

    return 0;
}