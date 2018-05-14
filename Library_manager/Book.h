#ifndef BOOK_H
#define BOOK_H
#include "Administrator.h"
#include <string>
class Book{
	std::string BookName;
	int ID;                                                      //6位，前两位代表类型，中间两位代表特点，最后两位代表编号
	std::string WriterName;
	std::string Press;                         //出版社  
	std::string PressTime;                     //出版时间
	bool Onshelf;                              //是否在架
	std::string Position;                      //馆藏位置
	std::string Summary;                       //简介
	std::string Type;                          //类型
public:
	Book(std::string BookName, std::string WriterName, std::string Press, std::string PressTime);
	int getID();
	std::string getWriterName();
	std::string getPress();
	std::string getPressTime();
	std::string getPosition();
	std::string getSummary();
	std::string getBookName();
	bool operator== (Book* book);
	void PutonShelf();
	void PutoffShelf();
	void modifyID(int id);
	bool getOnshelf();
	virtual std::string getType() = 0;
	virtual std::string getFeature() = 0;
	virtual ~Book() {};
};

#endif