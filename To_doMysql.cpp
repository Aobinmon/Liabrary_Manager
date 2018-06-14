 #include "To_domysql.h"
#include<vector>
std::vector<Record*> To_doMysql::got_all()
{
    QSqlQuery query;
    std::vector<Record*> recordlist;
    query.exec("select * from waiting_record");
    while(query.next()){
        int id=query.value(0).toInt();
        QString bookid=query.value(1).toString();
        QString guestid=query.value(2).toString();
        int type=query.value(3).toInt();
        std::string Time=query.value(4).toString().toStdString();
        //用guestid查找对应的guest
        query.exec("select * from Guest where ID="+guestid);
        std::string username=query.value(1).toString().toStdString();
        std::string password=query.value(2).toString().toStdString();
        Guest* guest=new Guest(guestid.toStdString(),username,password);
        //用bookid查找对应的book
        query.exec("select * from Book where ID="+bookid);
        std::string bookname=query.value(1).toString().toStdString();
        std::string writername=query.value(2).toString().toStdString();
        std::string press=query.value(3).toString().toStdString();
        std::string presstime=query.value(4).toString().toStdString();
        std::string type=query.value(5).toString().toStdString();
        std::string position=query.value(6).toString().toStdString();
        int onshelf=query.value(7).toInt();
        std::string summary=query.value(8).toString().toStdString();
        Book* book=new Book(id2,bookname,writername,press,presstime,type,position,onshelf,summary);
        Record* record=new Record(guest,book,id,time,type,0,-1);//第id号借阅、借阅时间time、借阅类型type
        recordlist.push_back(record);
    } 
    return recordlist;
}
bool To_doMysql::approve_or_refuse(Record* record,int approve)
{
    //查找record
    std::string id=record.getID().toString();
    QSqlQuery query;
    query.exec("select * from waiting_record where id="+id);
    if(!query.next()) return false;//没有这个记录！
    
    //加到done_record里面
    QString id=query.value(0).toString();
    QString bookid=query.value(1).toString();
    QString guestid=query.value(2).toString();
    QString type=query.value(3).toString();
    QString time=query.value(4).toString();
    QString approved=approve.toString();
    
    query.exec("insert into done_record(id,bookid,guestid,type,time,result) values("+id+","
               +bookid+","+guestid+","+type+",\""+time+"\","+approved+")");
    query.exec("delete from waiting_record where id="+id);//删除在waiting_record里面的信息
    return true;
}
