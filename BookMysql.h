#ifndef BOOKMYSQL_H
#define BOOKMYSQL_H
#include "Mysql.h"
#include "Book.h"
class BookMysql : public Mysql{
    bool modifyInfo(QString column0, QString info0,QString column1,Qstring info1);
    void insertBook(Book* book);
    bool dropBook(Book* book);
};

#endif // BOOKMYSQL_H
