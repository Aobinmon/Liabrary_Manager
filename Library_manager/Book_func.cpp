#include "Administrator.h"
#include "Guest.h"
#include "Book.h"
#include "Record.h"
#include "Reference.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

Book::Book(int id, std::string _BookName, std::string _WriterName, std::string _Press, std::string _PressTime) {
    ID = id;
    BookName = _BookName;
    WriterName = _WriterName;
    Press = _Press;
    PressTime = _PressTime;
}

int Book::getID() {
    return ID;
}

std::string Book::getBookName() {
    return BookName;
}

bool Book::getOnshelf() {
    return Onshelf;
}

std::string Book::getPosition() {
    return Position;
}

std::string Book::getPress() {
    return Press;
}

std::string Book::getPressTime() {
    return PressTime;
}

std::string Book::getSummary() {
    return Summary;
}

std::string Book::getType() {
    return Type;
}

std::string Book::getWriterName() {
    return WriterName;
}
