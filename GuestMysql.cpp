#include <QCoreApplication>
#include "GuestMysql.h"
#include<iostream>
#include<guest.h>
#include<Qstring>
using namespace std;
int GuestMysql::existUsername(QString username){
    QSqlQuery query;
    query.exec("select * from Guest where Username=\"" + username +"\"");//用户名登录
    if(query.next()) return 1;
    query.exec("select * from Guest where ID="+username);//ID登录
    if(query.next()) return 2;
    return 0;//都不存在
}
QString GuestMysql::getPassword(QString username){
    if(!existUsername(username))
        return "";
    QSqlQuery query;
    if(existUsername(username)==1){
        query.exec("select Password from Guest where Username=\"" + username +"\"");
        if(query.next()) return query.value(0).toString();
    }
   if(existUsername(username)==2)
   {
    query.exec("select Password from Guest where ID="+username);
    if(query.next()) return query.value(0).toString();
   } 
}

bool GuestMysql::modifyPassword(QString password, QString username){
    if(!existUsername(username))
       return false;
    else{
        QSqlQuery query;
        if(existUsername(username)==1)
        query.exec("UPDATE Guest SET Password=\""+password+"\""+"WHERE Username=\""+username+"\"");
        if(existUsername(username)==2)
        query.exec("UPDATE Guest SET Password=\""+password+"\""+"WHERE ID="+username);
    }
}
vector<Guest*> GuestMysql::find_guest(Qstring type,Qstring feature){
  vector<Guest*> guestlist;
    QSqlQuery query;
    query.exec("select* from Guest where "+type+"="+feature);
    if(query.next())
    {
        while(query.next()){
        int id=query.value(0).toInt();
        std::string username=query.value(1).toString();
        std::string password=query.value(2).toString();
        std::string realname=query.value(3).toString();
        std::string email=query.value(4).toString();
        std::string sex=query.value(5).toInt();
        std::string birthday=query.value(6).toString();
        std::string bbook=query.value(7).toInt();
        guestlist.push_back(Guest(id,username,password,realname,email,sex,birthday,bbook));
        query.next();
        }
    }
    else{
        //输出？
        int len=feature.length();
        int len0=len/3;
        QString string0=feature.mid(0,len0);
        QString string1=feature.mid(len0,2*len0);
        QString string2=feature.mid(2*len0);
        query.exec("select * from Guest where "+type+"like %\""+string0+"\"% or "+type+ " like %\""
                   +string1+"\"% or "+type+" like %\""+string2+"\"%");
        while(query.next()){
        int id=query.value(0).toInt();
        std::string username=query.value(1).toString();
        std::string password=query.value(2).toString();
        std::string realname=query.value(3).toString();
        std::string email=query.value(4).toString();
        std::string sex=query.value(5).toInt();
        std::string birthday=query.value(6).toString();
        std::string bbook=query.value(7).toInt();
        guestlist.push_back(Guest(id,username,password,realname,email,sex,birthday,bbook));
        query.next();
        }
    }
    return guestlist;
}
