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
    Guest* guest;
    Book * book;
    std::string type;//借阅还是归还
    int result;
    int state;
    connect GuestMysql* gm;
    connect RecordMysql* rm;
    connect BookMysql* bm;
public:
    Record(Guest* _guest, Book* _book, int _ID, std::string _time, std::string _type, int _result, int _state);
    int getID();
    std::string gettime();
    Guest* getguest();
    Book* getbook();
    std::string gettype();
    std::string getresult();
};


#endif //LIBRAR_RECORD_H
