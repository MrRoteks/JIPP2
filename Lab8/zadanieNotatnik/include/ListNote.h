//
// Created by Roteks on 29.11.2021.
//

#ifndef LAB7_NOTELIST_H
#define LAB7_NOTELIST_H


#include "Note.h"
#include <string>
#include <vector>

class ListNote: public Note{
private:
    vector<string> content;

public:
    ListNote();
    ListNote(vector<string> content);
    string getContent();
    void setContent(vector<string> newContent);
};




#endif //LAB7_NOTELIST_H
