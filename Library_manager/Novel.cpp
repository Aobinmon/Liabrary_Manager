
#include "Novel.h"
using namespace std;

int Novel::SFID=0;
int Novel::RelID=0;
int Novel::WuID=0;
int Novel::DetID=0;
int Novel::HisID=0;

Novel::Novel(string bookName, string writerName, string press, string pressTime, string feature)
        :Book(bookName, writerName, press, pressTime){
    int id=0;
    if(feature == "科幻"){
        FID = 1;
        id += TID*10000+FID*100+SFID;
        ++SFID;
        this->modifyID(id);
    }
    else if(feature == "纪实"){
        FID = 2;
        id += TID*10000+FID*100+RelID;
        ++RelID;
        this->modifyID(id);
    }
    else if	(feature == "武侠"){
        FID = 3;
        id += TID*10000+FID*100+WuID;
        ++WuID;
        this->modifyID(id);
    }
    else if	(feature == "侦探"){
        FID = 4;
        id += TID*10000+FID*100+DetID;
        ++DetID;
        this->modifyID(id);
    }
    else if(feature == "历史"){
        FID = 5;
        id += TID*10000+FID*100+HisID;
        ++HisID;
        this->modifyID(id);
    }
    else cout << "!!!警告：不合法的分类输入" << endl;
    Feature = feature;
}
string Novel::getType(){
    return "小说";
}

string Novel::getFeature(){
    return Feature;
}
int Novel::getFID()
{
    return FID;
}

