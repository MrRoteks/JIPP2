//
// Created by Roteks on 29.11.2021.
//

#ifndef LAB7_TEXTNOTE_H
#define LAB7_TEXTNOTE_H
#include "Note.h"

class TextNote:public Note{
private:
    string content;
    string getContent();
    void setContent(string newContent);

public:
    TextNote();
    TextNote(string content);
};

#endif //LAB7_TEXTNOTE_H
