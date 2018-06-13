#ifndef TO_DOMYSQL_H
#define TO_DOMYSQL_H
#include "Mysql.h"
#include"Record.h"
#include <vector>
#include <QString>
class To_doMysql : public Mysql{
public:
    std::vector<Record*> got_all();
    bool approve_or_refuse(Record* record,int approve);//approve is 1, refuse is 0
};

#endif // TO_DOMYSQL_H
