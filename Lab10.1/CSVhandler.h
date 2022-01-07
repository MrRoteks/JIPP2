//
// Created by Pc on 03.01.2022.
//

#ifndef LAB9_CSVHANDLER_H
#define LAB9_CSVHANDLER_H

#include<iostream>
#include<exeption>
#include<fstream>

class Csv_handler
{
private:
    std::string file_name;
    std::string file_path;
    char separator;
    std::fsteram plik;
public:
    Csv_handler(std::string file_name, std::string file_path) : file_name(file_name),file_path(file_path){}
    Csv_handler(std::string file_name) : file_name(file_name){}
    Csv_handler(std::string file_path) : file_path(file_path){}
    Csv_handler() {};

    std::string get_separator();



};

class MyException : public std::exception
        {

};

#endif //LAB9_CSVHANDLER_H
