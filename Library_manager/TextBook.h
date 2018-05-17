#ifndef TEXTBOOK_H
#define TEXTBOOK_H
#include "Book.h"
#include <iostream>
#include <cstring>
using namespace std;
class TextBook :public Book{//数学，语文，英语，物理，化学
    std::string Feature;
    int FID;        //Featureid：1，2，3，4，5
    static int MatID;
    static int ChiID;
    static int EngID;
    static int PhyID;
    static int CheID;
public:
    TextBook(std::string BookName, std::string WriterName,
             std::string Press, std::string PressTime, std::string Feature);
    std::string getType();
    std::string getFeature();
    int getFID();
    const int TID=11;
};

#endif