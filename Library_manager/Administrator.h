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
    int ID;
    GusetMysql gm;
    AdministratorMysql am;
    RecordMysql rm;
    BookMysql bm;
    To_doMysql tm;
    std::string username;
    std::string password;
public:

    void approve(Record* record);//在库数减一
    void refuse(Record* record);                                // reason: 1--借书数目超过上限， 2---权限不够借阅该类书籍， 3---未知错误（管理员心情不好.......sorry, 身为管理员就是可以为所欲为
    std::vector<Record*> find_record(std::string type, std::string value); //type包括时间，序号，书名
    std::vector<Guest*> find_guest(std::string type, std::string value);  //type包括用户名，ID
    void addBook(Book* book);//书库中加书
    void deleteBook(Book* book);//书库中减书
    void returnBook(Record* record);//管理员同意还书申请:在库数加一
    ~Administrator();//暂时没写
};


#endif //LIBRAR_ADIMINISTRATOR_H
