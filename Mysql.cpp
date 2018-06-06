#include "Mysql.h"

void Mysql::connect(){
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("Library_manager");
        db.setUserName("root");
        db.setPassword("123456");
}
