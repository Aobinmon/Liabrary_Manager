#include"recordmysql.h"
std::vector<Record*> RecordMysql::find_in_waiting_record( QString usertype,QString infotype, QString info,QString userID){//如果是管理员的话，userID就设为-1
     bool found=false;
     QSqlQuery query;
     if(usertype=="administrator"){//管理员权限
         if(infotype=="time")//string
            query.exec("select * from waiting_record where"+infotype+"=\""+info+"\"");
         else
            query.exec("select* from waiting_record where"+infotype+"="+info);  
        if(query.next())//如果真的查到了
            found=true;
        if(!found){//模糊查询(可以改进这个算法）
              int len=info.length();
              int len0=len/3;
              QString string0=info.mid(0,len0);
              QString string1=info.mid(len0,2*len0);
              QString string2=info.mid(2*len0);
              if(infotype=="time")//string 类
                  query.exec("select * from waiting_record where "+infotype+" like %\""+string0+"\"% or "+infotype+" like %\""
                         +string1+"\"% or "+infotype+" like %\""+string2+"\"%");
             else
                  query.exec("select * from waiting_record where "+infotype+" like %"+string0+"% or "+infotype+" like %"
                          +string1+"% or "+infotype+" like %"+string2+"%");
              }      
           }
        else if(usertype=="guest"){//用户的查询，只能看到guestID=userID的借阅信息
           if(infotype=="time")//string
               query.exec("select * from waiting_record where guestid="+userID+" and "+infotype+"=\""+info+"\"");
          else
              query.exec("select* from waiting_record where guestid="+userID+" and "+infotype+"="+info);  
          if(query.next()) 
                found=true;
          if(!found){//模糊查询
              int len=info.length();
              int len0=len/3;
              QString string0=info.mid(0,len0);
              QString string1=info.mid(len0,2*len0);
             QString string2=info.mid(2*len0);
               if(infotype=="time")//string 类
                  query.exec("select * from waiting_record where guestid="+userid+" and "+infotype+" like %\""+string0+"\"% or "+infotype+" like %\""
                         +string1+"\"% or "+infotype+" like %\""+string2+"\"%");
             else
                  query.exec("select * from waiting_record where guestid="+userid+" and "+infotype+" like %"+string0+"% or "+infotype+" like %"
                          +string1+"% or "+infotype+" like %"+string2+"%");
                }
          }
         while(query.next()){
             int id=query.value(0).toInt();
             int bookid=query.value(1).toInt();
             int guestid=query.value(2).toInt();
             int type=query.value(3).toInt();
             std::string time=query.value(4).toString();
            //用guestid查找对应的guest
             QSqlQuery query1;
             query1.exec("select * from Guest where ID="+guestid);
             std::string username=query1.value(1).toString();
             std::string password=query1.value(2).toString();
             Guest* guest=new Guest(guestid,username,password);
             //用bookid查找对应的book
             QSqlQuery query2;
             query2.exec("select * from Book where ID="+bookid);
             int id2=query2.value(0).toInt();
             std::string bookname=query2.value(1).toString();
             std::string writername=query2.value(2).toString();
             std::string press=query2.value(3).toString();
             std::string presstime=query2.value(4).toString();
             std::string type=query2.value(5).toString();
             std::string position=query2.value(6).toString();
             int onshelf=query2.value(7).toInt();
             std::string summary=query2.value(8).toString();
             Book* book=new Book(id2,bookname,writername,press,presstime,type,position,onshelf,summary);
             Record* record=new Record(guest,book,id,time,type,0,-1);//第id号借阅、借阅时间time、借阅类型type
             recordlist.push_back(record);         
             }
            return recordlist;
         }
     
 std::vector<Record*> RecordMysql::find_in_doneing_record( QString usertype,QString infotype, QString info,QString userID){//如果是管理员的话，userID就设为-1
     bool found=false;
     QSqlQuery query;
     if(usertype=="administrator"){//管理员权限
         if(infotype=="time")//string
            query.exec("select * from done_record where"+infotype+"=\""+info+"\"");
         else
            query.exec("select* from done_record where"+infotype+"="+info);  
        if(query.next())//如果真的查到了
            found=true;
        if(!found){//模糊查询(可以改进这个算法）
              int len=info.length();
              int len0=len/3;
              QString string0=info.mid(0,len0);
              QString string1=info.mid(len0,2*len0);
              QString string2=info.mid(2*len0);
              if(infotype=="time")//string 类
                  query.exec("select * from done_record where "+infotype+" like %\""+string0+"\"% or "+infotype+" like %\""
                         +string1+"\"% or "+infotype+" like %\""+string2+"\"%");
             else
                  query.exec("select * from done_record where "+infotype+" like %"+string0+"% or "+infotype+" like %"
                          +string1+"% or "+infotype+" like %"+string2+"%");
              }      
           }
        else if(usertype=="guest"){//用户的查询，只能看到guestID=userID的借阅信息
           if(infotype=="time")//string
               query.exec("select * from done_record where guestid="+userID+" and "+infotype+"=\""+info+"\"");
          else
              query.exec("select* from done_record where guestid="+userID+" and "+infotype+"="+info);  
          if(query.next()) 
                found=true;
          if(!found){//模糊查询
              int len=info.length();
              int len0=len/3;
              QString string0=info.mid(0,len0);
              QString string1=info.mid(len0,2*len0);
             QString string2=info.mid(2*len0);
               if(infotype=="time")//string 类
                  query.exec("select * from done_record where guestid="+userid+" and "+infotype+" like %\""+string0+"\"% or "+infotype+" like %\""
                         +string1+"\"% or "+infotype+" like %\""+string2+"\"%");
             else
                  query.exec("select * from done_record where guestid="+userid+" and "+infotype+" like %"+string0+"% or "+infotype+" like %"
                          +string1+"% or "+infotype+" like %"+string2+"%");
                }
          }
         while(query.next()){
             int id=query.value(0).toInt();
             int bookid=query.value(1).toInt();
             int guestid=query.value(2).toInt();
             int type=query.value(3).toInt();
             std::string time=query.value(4).toString();
             int result=query.value(5).toInt();
            //用guestid查找对应的guest
             QSqlQuery query1;
             query1.exec("select * from Guest where ID="+guestid);
             std::string username=query1.value(1).toString();
             std::string password=query1.value(2).toString();
             Guest* guest=new Guest(guestid,username,password);
             //用bookid查找对应的book
             QSqlQuery query2;
             query2.exec("select * from Book where ID="+bookid);
             int id2=query2.value(0).toInt();
             std::string bookname=query2.value(1).toString();
             std::string writername=query2.value(2).toString();
             std::string press=query2.value(3).toString();
             std::string presstime=query2.value(4).toString();
             std::string type=query2.value(5).toString();
             std::string position=query2.value(6).toString();
             int onshelf=query2.value(7).toInt();
             std::string summary=query2.value(8).toString();
             Book* book=new Book(id2,bookname,writername,press,presstime,type,position,onshelf,summary);
             Record* record=new Record(guest,book,id,time,type,1,result);//第id号借阅、借阅时间time、借阅类型type
             recordlist.push_back(record);         
             }
            return recordlist;
         }
         

#endif // RECORDMYSQL_H
