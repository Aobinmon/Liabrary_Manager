#ifndef MYSQL_H
#define MYSQL_H
#include <QtSql/QtSql>
class Mysql{
public:
    void connect();
    virtual ~Mysql(){}
    QSqlDatabase db;
    QSqlQuery query;
};

#endif
