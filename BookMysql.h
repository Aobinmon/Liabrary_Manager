#ifndef BOOKMYSQL_H
#define BOOKMYSQL_H
#include "Mysql.h"
#include "Book.h"
class BookMysql : public Mysql{
    void modifyInfo(QString column, QString info);
    void insertBook(Book* book);
    void dropBook(Book* book);
    void modifyBook(Book* book);
};

#endif // BOOKMYSQL_H
