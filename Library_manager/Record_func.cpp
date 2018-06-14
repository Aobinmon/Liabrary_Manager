//
// Created by wujiayi on 2018/5/15.
//
#include "Administrator.h"
#include "Guest.h"
#include "Book.h"
#include "Record.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include<QString>

using namespace std;
Record::Record(Guest *_guest, Book *_book, int _ID, std::string _time, std::string _type, int _result, int _state) {
    ID = _ID;
    book = _book;
    guest = _guest;
    type = _type;
    result = _result;
    time = _time;
    state = _state;
}

int Record::getID() {
    return ID;
}

Guest* Record::getguest() {
    return _guest;
}

Book* Record::getbook() {
    return _book;
}

std::string Record::getresult() {
    return result;
}

std::string Record::gettime() {
    return time;
}

std::string Record::gettype() {
    return type;
}
