#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <map>
#include <string>
#include "User.h"
#include "Guest.h"
#include "Record.h"
#include "Book.h"
class Administrator : public User{
	
public:
	void set_password(std::string pw);
	void modify_Gpassword(std::string pw, Guest* guest);
	void ban_Guest(Guest* guest);
	void start_Guest(Guest* guest);
	
	void approve(Record* record, Guest* guest, Book* book);
	void refuse(Record* record, int reason);                                // reason: 1--借书数目超过上限， 2---权限不够借阅该类书籍， 3---未知错误（管理员心情不好.......sorry, 身为管理员就是可以为所欲为
	void find_Record_by_ID(int id);
	void find_Record_by_BookName(std::string bookname);
	void find_Record_by_GuestName(std::string guestname);
	void find_Record_by_BookID(int bid);
	void find_Record_by_GuestID(int gid);

	void addBook(Book* book);
	void deleteBook(Book* book);
};
#endif