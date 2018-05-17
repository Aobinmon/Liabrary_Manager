#include "TextBook.h"
using namespace std;

int TextBook::MatID=0;
int TextBook::ChiID=0;
int TextBook::EngID=0;
int TextBook::PhyID=0;
int TextBook::CheID=0;

TextBook::TextBook(string bookName, string writerName, string press, string pressTime, string feature)
        :Book(bookName, writerName, press, pressTime){

    int id=0;
    if(feature == "数学"){
        FID = 1;
        id += TID*10000+FID*100+MatID;
        ++MatID;
        this->modifyID(id);
    }
    else if(feature == "语文"){
        FID = 2;
        id += TID*10000+FID*100+ChiID;
        ++ChiID;
        this->modifyID(id);
    }
    else if	(feature == "英语"){
        FID = 3;
        id += TID*10000+FID*100+EngID;
        ++EngID;
        this->modifyID(id);
    }
    else if	(feature == "物理"){
        FID = 4;
        id += TID*10000+FID*100+PhyID;
        ++PhyID;
        this->modifyID(id);
    }
    else if(feature == "化学"){
        FID = 5;
        id += TID*10000+FID*100+CheID;
        ++CheID;
        this->modifyID(id);
    }
    else cout << "!!!警告：不合法的分类输入" << endl;
    Feature = feature;
}
string TextBook::getType(){
    return "教材";
}

string TextBook::getFeature(){
    return Feature;
}
int TextBook::getFID()
{
    return FID;
}
