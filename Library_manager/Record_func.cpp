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

Record::Record(int _ID, Guest *guest, Book *book, std::string _type, std::string _result, std::string _time) {
    ID = _ID;
    _book = book;
    _guest = guest;
    type = _type;
    result = _result;
    time = _time;
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
