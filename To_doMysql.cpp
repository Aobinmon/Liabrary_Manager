 #include "To_domysql.h"
#include<vector>
std::vector<Record*> To_doMysql::got_all()
{
    QSqlQuery query;
    std::vector<Record*> recordlist;
    query.exec("select * from waiting_record");
    while(query.next()){
        std::string id=query.value(0).toString();
        std::string bookid=query.value(1).toString();
        std::string guestid=query.value(2).toString();
        std::string type=query.value(3).toString();
        std::string time=query.value(4).toString();
        //用guestid查找对应的guest
        query.exec("select * from Guest where ID="+guestid);
        std::string id1=query.value(0).toString();
        std::string username=query.value(1).toString();
        std::string password=query.value(2).toString();
        Guest* guest=new Guest(id1,username,password);
        //用bookid查找对应的book
        query.exec("select * from Book where ID="+bookid);
        int id2=query.value(0).toInt();
        std::string bookname=query.value(1).toString();
        std::string writername=query.value(2).toString();
        std::string press=query.value(3).toString();
        std::string presstime=query.value(4).toString();
        std::string type=query.value(5).toString();
        std::string position=query.value(6).toString();
        int onshelf=query.value(7).toInt();
        std::string summary=query.value(8).toString();
        Book* book=new Book(id2,bookname,writername,press,presstime,type,position,onshelf,summary);
        Record* record=new Record(guest,book,id,time,type);//第id号借阅、借阅时间time、借阅类型type
        recordlist.push_back(record);
    } 
    return recordlist;
}
bool To_doMysql::approve_or_refuse(Record* record,int approve)//问题：record的构造函数只有guest*和book*，是不是需要加一个ID？？
{
    //查找record
    std::string id=record.getID().toString();
    QSqlQuery query;
    query.exec("select * from waiting_record where id="+id);
    if(!query.next()) return false;//没有这个记录！
    
    //加到done_record里面
    std::string id=query.value(0).toString();
    std::string bookid=query.value(1).toString();
    std::string guestid=query.value(2).toString();
    std::string type=query.value(3).toString();
    std::string time=query.value(4).toString();
    std::string approved=approve.toString();
    
    query.exec("insert into done_record(id,bookid,guestid,type,time,result) values("+id+","
               +bookid+","+guestid+","+type+",\""+time+"\","+approved+")");
    query.exec("delete from waiting_record where id="+id);//删除在waiting_record里面的信息
    return true;
}
