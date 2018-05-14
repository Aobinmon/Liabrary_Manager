#ifndef TEXTBOOK_H
#define TEXTBOOK_H
#include "Book.h"
#include "Administrator.h"
class TextBook :public Book{
	std::string Feature;
public:
	friend Administrator;
	std::string getType();
	std::string getName();
	std::string getSummary();
	std::string getFeature();
};

#endif