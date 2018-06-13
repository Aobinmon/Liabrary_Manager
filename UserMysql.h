#ifndef USERMYSQL_H
#define USERMYSQL_H
#include "Mysql.h"
#include <vector>
#include <QString>

class UserMysql : public Mysql{
public:
    virtual bool existUsername(QString username) = 0;
    virtual QString getPassword(QString username) = 0;
    virtual ~UserMysql(){}
 virtual void modifyPassword(QString password) = 0;
};

#endif // USERMYSQL_H
