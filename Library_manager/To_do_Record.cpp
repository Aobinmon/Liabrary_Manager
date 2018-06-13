//
// Created by wujiayi on 2018/6/10.
//

#include "To_do_Record.h"
#include <QString>

To_do_Record::To_do_Record(Guest *guest, Book *book, int _id, std::string _type, std::string _time) {
    id = _id;
    time = _time;
    type = _type;
    _guest = guest;
    _book = book;
}

Book* To_do_Record::getbook() {
    return _book;
}

Guest* To_do_Record::getguest() {
    return _guest;
}

std::string To_do_Record::gettype() {
    return type;
}

std::string To_do_Record::gettime() {
    return time;
}

int To_do_Record::getID() {
    return id;
}
