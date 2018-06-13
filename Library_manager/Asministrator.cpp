//
// Created by wujiayi on 2018/6/10.
//

#include "Administrator.h"
#include <QString>

bool Administrator::approve(Record *record) {
    if (tm.find_record(QString::fromStdString(record))){
        rm.add_record(QString::fromStdString(record));
        tm.delete_record(record(QString::fromStdString(record)));
        return true;
    }
    else return false;
}

bool Administrator::refuse(Record *record, int reason) {
    if (tm.find_record(QString::fromStdString(record)){
        tm.delete_record(record(QString::fromStdString(record)));
        return true;
    }
    else return false;
}

void Administrator::addBook(Book *book) {
    bm.add_book(QString::fromStdString(book));
    return;
}

void Administrator::deleteBook(Book *book) {
    bm.delete_book(QString::fromStdString(book));
    return;
}

std::vector<Guest*> Administrator::find_guest(std::string type, std::string value) {
    return gm.find_guest(QString::fromStdString(type),QString::fromStdString(value));
}

std::vector<Record*> Administrator::find_record(std::string type, std::string value) {
    return rm.find_record(QString::fromStdString(type),QString::fromStdString(value));
}

bool Administrator::returnBook(Record *record) {
    if(tm.find_record(QString::fromStdString(record))){
        rm.add_record(QString::fromStdString(record));
        tm.delete_record(record(QString::fromStdString(record)));
        return true;
    }
    else return false;
}
