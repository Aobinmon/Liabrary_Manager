//
// Created by wujiayi on 2018/5/8.
//

#ifndef LIBRAR_RECORD_H
#define LIBRAR_RECORD_H

#include <string>
#include "Guest.h"
#include "Book.h"
#include "vector"
#include <Mysql.h>
#include "Administrator.h"

class Record {
    int ID;
    std::string time;
    Guest* _guest;
    Book * _book;
    std::string type;
    std::string result;
    GuestMysql gm;
    RecordMysql rm;
    BookMysql bm;
public:
    Record(int _ID, Guest* _guest, Book* _book, std::string _type, std::string _result, std::string _time);
    int getID();
    std::string gettime();
    Guest* getguest();
    Book* getbook();
    std::string gettype();
    std::string getresult();
};


#endif //LIBRAR_RECORD_H
