#ifndef ADMINISTRATORMYSQL_H
#define ADMINISTRATORMYSQL_H
#include "UserMysql.h"

class AdministratorMysql : public UserMysql{
public:
    bool existUsername(QString username);
    QString getPassword(QString username);
    void modifyPassword(QString password);
};

#endif // ADMINISTRATORMYSQL_H
