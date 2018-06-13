//
// Created by wujiayi on 2018/6/10.
//

#ifndef LIBRAR_TO_DO_RECORD_H
#define LIBRAR_TO_DO_RECORD_H

#include <string>
#include "Guest.h"
#include "Book.h"
#include <Mysql.h>

class To_do_Record {
    int id;
    Guest* _guest;
    Book* _book;
    std::string type;
    std::string time;
    To_doMysql tm;
    GuestMysql gm;
    BookMysql bm;
public:
    To_do_Record(Guest* guest, Book* book, int _id, std::string _type, std::string _time);
    int getID();
    std::string gettime();
    Guest* getguest();
    Book* getbook();
    std::string gettype();
};


#endif //LIBRAR_TO_DO_RECORD_H
