#ifndef RECORDMYSQL_H
#define RECORDMYSQL_H
#include "Mysql.h"
#include "Record.h"
#include <vector>
#include <QString>

 class RecordMysql : public Mysql{
 public:
     std::vector<Record*> findRecord( QString usertype,QString infotype, QString info,QString userID);
 };

#endif // RECORDMYSQL_H
