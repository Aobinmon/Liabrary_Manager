#ifndef RECORD_H
#define RECORD_H
#include <string>
#include "Guest.h"
#include "Book.h"
#include "Administrator.h"
class Record{
	int ID{Num};
	std::string time;
	Guest* guest;
	Book* book;
public:
	static int Num;
	Record(Guest* _guest, Book* _book);
	int getID();
	std::string getTime();
	Guest& getGuest();
	Book& getBook();
	static int getNum();
	static void increaseNum();
};

#endif