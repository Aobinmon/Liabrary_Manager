#ifndef GUEST_H
#define GUEST_H
#include "User.h"
#include "Book.h"
#include "Administrator.h"

class Guest : public User{
	bool In_use;
	int bBook{0};
public:
	static const int MaxBook{5};
	static int Num;
	Book* Gbook[5];
	friend class Administrator;
	Guest():bBook(0){}
	void set_password(std::string pw);
	void increaseBook();
	void decreaseBook();
	void borrow(Book* book);
	void Return(Book* book);
	void getBook(Book* book);
	int getbBook();
	void returnBook(Book* book);
};

#endif