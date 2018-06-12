#include"recordmysql.h"
std::vector<Record*> RecordMysql::findRecord( QString usertype,QString infotype, QString info,QString userID)//如果是管理员的话，userID就设为-1
{
         bool found=false;
         QSqlQuery query;
         if(usertype=="administrator"){//管理员权限
           if(infotype=="ID"||infotype=="state"||infotype=="type"||infotype=="bookid"||infotype=="readerid")//int类型
           query.exec("select* from Record where"+infotype+"="+info);
           if(infotype=="time"||infotype=="bookname"||infotype=="readername")//string 类
              query.exec("select* from Record where"+infotype+"=\""+info+"\""); 
           //问题：如果输入的infotype不合法，怎么显示异常？？
           if(query.next())//如果真的查到了
               found=true;
           if(!found){//模糊查询(可以改进这个算法）
              int len=info.length();
              int len0=len/3;
              QString string0=info.mid(0,len0);
              QString string1=info.mid(len0,2*len0);
              QString string2=info.mid(2*len0);
              if(infotype=="ID"||infotype=="state"||infotype=="type"||infotype=="bookid"||infotype=="readerid")//int类型   
                  query.exec("select * from Record where "+type+" like %"+string0+"% or "+type+" like %"
                          +string1+"% or "+type+" like %"+string2+"%");
              if(infotype=="time"||infotype=="bookname"||infotype=="readername")//string 类
                  query.exec("select * from Record where "+type+" like %\""+string0+"\"% or "+type+" like %\""
                         +string1+"\"% or "+type+" like %\""+string2+"\"%");
              }
            
            }
            else if(usertype=="guest"){//用户的查询，只能看到readerID=userID的借阅信息
                if(infotype=="type"||infotype=="bookid"||infotype=="state")
                    query.exec("select * from Record where readerID="+userID+" and "+infotype+"="+info);
                if(infotype=="time"||infotype=="bookname")
                    query.exec("select * from Record where readerID="+userID+" and "+infotype+"=\""+info+"\"");
                if(query.next()) 
                    found=true;
                if(!found){//模糊查询
                    int len=info.length();
                    int len0=len/3;
                    QString string0=info.mid(0,len0);
                    QString string1=info.mid(len0,2*len0);
                    QString string2=info.mid(2*len0);
                    if(infotype=="state"||infotype=="type"||infotype=="bookid")//int类型   
                        query.exec("select * from Record where reader="+userID+" and "+type+" like %"+string0+"% or "+type+" like %"
                                +string1+"% or "+type+" like %"+string2+"%");
                    if(infotype=="time"||infotype=="bookname")//string 类
                        query.exec("select * from Record where readerID="+userID+" and "+type+" like %\""+string0+"\"% or "+type+" like %\""
                               +string1+"\"% or "+type+" like %\""+string2+"\"%");
                }
          }
         while(query.next()){
             int id=query.value(0).toInt();
             int type=query.value(1).toInt();
             std::string time=query.value(2).toString();
             int bookid=query.value(3).toInt();
             std::string bookname=query.value(4).toString();
             int readerid=query.value(5).toInt();
             std::string readername=query.value(6).toString();
             int state=query.value(7).toInt();
             recordlist.push_back(Record(id,type,time,bookid,bookname,readerid,readername,state));         
             }//需要改一下record的构造函数！
            return recordlist;
         }
