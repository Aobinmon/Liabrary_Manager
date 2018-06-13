//
// Created by wujiayi on 2018/5/8.
//

#ifndef LIBRAR_ADIMINISTRATOR_H
#define LIBRAR_ADIMINISTRATOR_H

#include <string>
#include "User.h"
#include "Guest.h"
#include "Record.h"
#include "Book.h"
#include <vector>
#include "Mysql.h"
class Administrator : public User{
    GusetMysql gm;
    AdministratorMysql am;
    RecordMysql rm;
    BookMysql bm;
    To_doMysql tm;
public:
    Administrator(int id, std::string _username, std::string _password);
    bool approve_or_refuse(Record* record,int approve);
    std::vector<Record*> find_record(std::string type, std::string value); //type包括时间，序号，书名
    std::vector<Guest*> find_guest(std::string type, std::string value);  //type包括用户名，ID
    void addBook(Book* book);//书库中加书
    void deleteBook(Book* book);//书库中减书
    bool returnBook(Record* record);//管理员同意还书申请:在库数加一
    ~Administrator();//暂时没写
};


#endif //LIBRAR_ADIMINISTRATOR_H
