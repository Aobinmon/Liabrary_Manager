#ifndef RECORD_H
#define RECORD_H
#include <string>
#include "Guest.h"
#include "Book.h"
#include "Administrator.h"
class Record{
	static int Num;
	int ID{Num};
	std::string time;
	Guest& guest;
	Book& book;
public:
	int getID();
	std::string getTime();
	Guest& getGuest();
	Book& getBook();
	static int getNum();
	static void increaseNum();
};

#endif