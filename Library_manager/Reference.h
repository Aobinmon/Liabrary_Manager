#ifndef REFERENCE_H
#define REFERENCE_H
#include "Book.h"

class Reference :public Book{                                                              //Feature共有社会学类、经济类、历史类、医学类、心理学类
	std::string Feature;
	int FID;
	static int SocID;
	static int EcoID;
	static int HisID;
	static int MedID;
	static int PsyID;
public:
	Reference(std::string BookName, std::string WriterName, std::string Press, std::string PressTime, std::string Feature);
	std::string getType();
	std::string getFeature();
	int getFID();
	const int TID{10};
};

#endif