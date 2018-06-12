#include"BookMysql.h"

using namespace std;

bool BookMysql::modifyInfo(QString column0, QString info0,QString column1,Qstring info1){
    //找到column0是info0的地方，修改column1为info1
    QSqlQuery query;
    if(column0=="ID"&&column1=="ID")//因为要区分int型和string型的写法
        query.exec("update Books set "+column1+"="+info1+" where"+column0+"="+info0);
    if(column0=="ID"&&column1!="ID")
        query.exec("update Books set "+column1+"=\""+info1+"\" where"+column0+"="+info0);
    if(column0!="ID"&&column1=="ID")
        query.exec("update Books set "+column1+"="+info1+" where"+column0+"=\""+info0+"\"");
    else 
        query.exec("update Books set "+column1+"=\""+info1+"\" where"+column0+"=\""+info0+"\"");
    
    if(query.next()) return true;
    else return false;
}

void BookMysql::insertBook(Book *book){
    Qstring id=book->getID();
    Qstring bookname=book->getBookName();
    Qstring writername=book->getWriterName();
    Qstring press=book->getPress();
    Qstring presstime=book->getPressTime();
    Qstring type=book->getType();
    Qstring position=book->getPosition();
    bool onshelf=book->getOnshelf().toString();
    Qstring summary=book->getSummary();
    QSqlQuery query;
    query.exec("INSERT INTO Books(ID,Bookname,Writername,Press,Presstime,Type,Position,Onshelf,Summary)"
               "VALUES("+id+",\""+bookname+"\",\""+writername+"\",\""+press+"\",\""+presstime+"\",\""+type+"\",\""+position+"\",\""+onshelf+"\",\""+summary+"\")");
}
bool BookMysql::dropBook(Book *book){
    Qstring id=book->getID();
    QSqlQuery query;
    query.exec("DELETE from Books where ID="+id);
    if(query.next()) return true;
    else return false;
}
