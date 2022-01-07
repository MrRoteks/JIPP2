//
// Created by Roteks on 29.11.2021.
//

#ifndef LAB7_NOTE_H
#define LAB7_NOTE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Note{
private:
    string title;
public:
    Note();
    Note(string title);

    string getTitle();
    void setTitle(string newTitle);
    virtual string getContent();
    virtual void setContent();
};

#endif //LAB7_NOTE_H
