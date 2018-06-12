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
    int book_id;
    int guest_id;
    std::string type;
    std::string result;
    GuestMysql gm;
    RecordMysql rm;
    BookMysql bm;
public:
    Record(Guest* _guest, Book* _book);
    Record(int _ID, int _book_id, int _guest_id, std::string _type, std::string _result);
};


#endif //LIBRAR_RECORD_H
