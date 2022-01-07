//
// Created by filip on 07.11.2021.
//

#include "ListNote.h"
#include "Note.h"
#include "NoteDirector.h"
#include "TextNote.h"

//////////////////////////////////NOTE///////////////////////////
Note::Note(string title)
{
this->title=title;
}

string Note:: getTitle(){
    return title;
}
void Note:: setTitle(string newTitle){
    title=newTitle;
}


/////////////////////////////////TextNOTE///////////////////////////
TextNote::TextNote(string content)
{
    this->content=content;
}
string TextNote::getContent() {
    return content;
}

void TextNote::setContent(string newContent)
{
    content=newContent;
}
/////////////////////////////////ListNOTE///////////////////////////
ListNote::ListNote(vector<string> content)
{
this->content=content;
}

vector<string> ListNote::getContent() {
    return content;
}
void ListNote ::setContent(vector<string> newContent){
    content=newContent;
}



















