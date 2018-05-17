//
// Created by Wanghongjun on 2018/5/17.
//

#ifndef LIABRARY_MANAGER_MASTER_NOVEL_H
#define LIABRARY_MANAGER_MASTER_NOVEL_H

#include "Book.h"


class Novel :public Book{//小说类，继承自Book类。Feature共有科幻、纪实、武侠、推理、历史
        std::string Feature;
        int FID;    //Featureid：1，2，3，4，5
        static int SFID;
        static int RelID;
        static int WuID;
        static int DetID;
        static int HisID;
    public:
        Novel(std::string BookName, std::string WriterName,
                  std::string Press, std::string PressTime, std::string Feature);
        std::string getType();
        std::string getFeature();
        int getFID();
        const int TID=12;

};


#endif //LIABRARY_MANAGER_MASTER_NOVEL_H
