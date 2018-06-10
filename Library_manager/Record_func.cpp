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
