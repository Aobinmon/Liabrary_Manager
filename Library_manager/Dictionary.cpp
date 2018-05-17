#include "Dictionary.h"

using namespace std;

int Dictionary::EngID=0;
int Dictionary::JapID=0;
int Dictionary::FreID=0;
int Dictionary::GerID=0;
int Dictionary::ChiID=0;
Dictionary::Dictionary(string bookName, string writerName, string press, string pressTime, string feature)
        :Book(bookName, writerName, press, pressTime){
    int id=0;
    if(feature == "英语"){
        FID = 1;
        id += TID*10000+FID*100+EngID;
        ++EngID;
        this->modifyID(id);
    }
    else if(feature == "日语"){
        FID = 2;
        id += TID*10000+FID*100+JapID;
        ++JapID;
        this->modifyID(id);
    }
    else if	(feature == "法语"){
        FID = 3;
        id += TID*10000+FID*100+FreID;
        ++FreID;
        this->modifyID(id);
    }
    else if	(feature == "德语"){
        FID = 4;
        id += TID*10000+FID*100+GerID;
        ++GerID;
        this->modifyID(id);
    }
    else if(feature == "汉语"){
        FID = 5;
        id += TID*10000+FID*100+ChiID;
        ++ChiID;
        this->modifyID(id);
    }
    else cout << "!!!警告：不合法的分类输入" << endl;
    Feature = feature;
}
string Dictionary::getType(){
    return "字典";
}

string Dictionary::getFeature(){
    return Feature;
}
int Dictionary::getFID()
{
    return FID;
}


