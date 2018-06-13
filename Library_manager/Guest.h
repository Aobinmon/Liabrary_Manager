//
// Created by wujiayi on 2018/5/8.
//

#ifndef LIBRAR_GUEST_H
#define LIBRAR_GUEST_H

#include "User.h"
#include "Book.h"
#include <string>
#include <vector>
#include "Administrator.h"
#include <Mysql.h>

class Guest : public User{
	int bBook{0};
    BookMysql bm;
    GuestMysql gm;
    RecordMysql rm;
    To-doMysql tm;
public:
    Guest(int id, std::string name, std::string password);//直接在创建时设置bBook = 0
    friend class Administrator;
    int get_Id();
    void Applyforbook(Book* book);//申请借书
    void ApplyreturnBook(Book* book);//申请还书
    void collection(Book* book);//收藏书
    std::vector<Book*> findbook(std::string type, std::string value);
    ~Guest();//暂时没写
};





#endif //LIBRAR_GUEST_H
