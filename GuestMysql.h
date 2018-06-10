#ifndef GUESTMYSQL_H
#define GUESTMYSQL_H
#include "UserMysql.h"
#include <QString>
#include "Guest.h"
class GuestMysql:public UserMysql{
public:
    void modifyPassword(QString password);
};

#endif // GUESTMYSQL_H
