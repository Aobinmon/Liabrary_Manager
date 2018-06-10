+#include "GuestMysql.h"
 +
 +bool GuestMysql::existUsername(QString username){
 +    query.exec(QString::fromStdString("select * from Guest where Username=\"" + username +"\""));
 +    if(query.next()) return true;
 +    query.exec(QString::fromStdString("select * from Guest where ID="+username));
 +    if(query.next()) return true;
 +    return false;
 +}
 +
 +QString GuestMysql::getPassword(QString username){
 +    if(existUsername()){
 +        query.exec(QString::fromStdString("select Password from Guest where Username=\"" + username +"\""));
 +        if(query.next()) return query.value(0).toString();
 +        query.exec(QString::fromStdString("select Password from Guest where ID="+username));
 +        if(query.next()) return query.value(0).toString();
 +    }
 +}
