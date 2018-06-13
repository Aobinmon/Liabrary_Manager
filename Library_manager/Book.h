//
// Created by wujiayi on 2018/5/8.
//

#ifndef LIBRAR_BOOK_H
#define LIBRAR_BOOK_H

#include "Administrator.h"
#include <string>
class Book {
    BookMysql bm;
    std::string BookName;
    int ID;                                                      //6位，前两位代表类型，中间两位代表特点，最后两位代表编号
    std::string WriterName;
    std::string Press;                         //出版社
    std::string PressTime;                     //出版时间
    bool Onshelf;                              //是否在架，同样名字的书有不同的ID
    std::string Position;                      //馆藏位置
    std::string Summary;                       //简介
    std::string Type;                          //类型
public:
    Book(int id ,std::string _BookName, std::string _WriterName, std::string _Press, std::string _PressTime);//是否在架，馆藏位置，简介，类型？
    int getID();
    std::string getBookName();
    std::string getWriterName();
    std::string getPress();
    std::string getPressTime();
    bool getOnshelf();
    std::string getPosition();
    std::string getSummary();
    std::string getType();
};


#endif //LIBRAR_BOOK_H
