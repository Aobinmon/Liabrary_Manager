
#ifndef LIABRARY_MANAGER_MASTER_DICTIONARY_H
#define LIABRARY_MANAGER_MASTER_DICTIONARY_H
#include "Book.h"
using namespace std;

class Dictionary :public Book{//字典类，继承自Book类。Feature共有英语、日语、法语、德语、汉语
    std::string Feature;
    int FID;    //Featureid：1，2，3，4，5
    static int EngID;
    static int JapID;
    static int FreID;
    static int GerID;
    static int ChiID;
public:
    Dictionary(std::string BookName, std::string WriterName,
          std::string Press, std::string PressTime, std::string Feature);
    std::string getType();
    std::string getFeature();
    int getFID();
    const int TID=13;

};



#endif //LIABRARY_MANAGER_MASTER_DICTIONARY_H
