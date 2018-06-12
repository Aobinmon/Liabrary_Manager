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

Record::Record(Guest *_guest, Book *_book) {
    //查找guestID、bookID
    return rm.addrecord(QString::fromStdString(guestID),QString::fromStdString(bookID));
}

Record::Record(int _ID, int _book_id, int _guest_id, std::string _type, std::string _result) {
    ID = _ID;
    book_id = _book_id;
    guest_id = _guest_id;
    type = _type;
    result = _result;
}
