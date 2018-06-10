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
    int Onshelf;                              //几本在架
    std::string Position;                      //馆藏位置
    std::string Summary;                       //简介
    std::string Type;                          //类型
public:
    Book(std::string BookName, std::string WriterName, std::string Press, std::string PressTime);
};


#endif //LIBRAR_BOOK_H
