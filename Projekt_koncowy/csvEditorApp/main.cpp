#include <iostream>
#include <iomanip>
#include "../include/csvEditorLib.h"
#include<fstream>
#include<string>
#include <cstring>
#include<vector>


string strings[10];

void split (string str, char seperator);
vector<string> readRecordFromFile(string file_name, string search_term);
int lenght(string str);

int main()
{

    vector<string> data = readRecordFromFile("dane.txt","2");

    return 0;
}

vector<string> readRecordFromFile(string file_name, string search_term)
{
    vector<string> record;

    ifstream file;
    file.open(file_name);

    bool found_record =false;

    string temp;
    string current_line;


    while(getline(file,current_line) && !found_record)
    {

        split(current_line,',');

        if(strings[0] == search_term)
        {
            found_record=true;
            for (int i=0;i<3;i++)
                record.push_back(strings[i]);
        }


    }
    if(found_record==true)
        cout<<"Znaleziono: "<<record[0]<<" "<<record[1]<<" "<<record[2]<<endl;
    else
       cout<<"Nie znaleziono wskazanej osoby.";

    return record;
}

void split (string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= lenght(str))
    {
        if (str[i] == seperator || i == lenght(str))
        {
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

int lenght(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;

    }
    return length;
}