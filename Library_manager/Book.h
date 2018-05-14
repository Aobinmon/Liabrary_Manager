#ifndef BOOK_H
#define BOOK_H
#include "Administrator.h"
#include <string>
class Book{
	std::string BookName;
	int ID;                                                      //6位，前两位代表类型，中间两位代表特点，最后两位代表编号
	std::string WriterName;
	std::string Press;
	std::string PressTime;
	bool Onshelf;
	std::string Position;
	std::string Summary;
	std::string Type;
public:
	Book(std::string BookName, std::string WriterName, std::string Press, std::string PressTime);
	int getID();
	std::string getWriterName();
	std::string getPress();
	std::string getPressTime();
	std::string getPosition();
	std::string getSummary();
	std::string getBookName();
	bool operator== (Book& book);
	void PutonShelf();
	void PutoffShelf();
	void modifyID(int id);
	bool getOnshelf();
	virtual std::string getType() = 0;
	virtual std::string getFeature() = 0;
	virtual ~Book() {};
};

#endif