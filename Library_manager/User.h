#ifndef USER_H
#define USER_H
#include <string>
#include <map>
class User{
	int ID;
	std::string Password;
	std::string Name;
public:
	static std::map<int, std::string> U_IP;
	virtual ~User();
	int getID();
	std::string getName();
	void modify_password(std::string pw);
	virtual void set_password(std::string pw) = 0;
	

	void find_book_by_ID(int id);
	void find_book_by_BookName(std::string bookName);
	void find_book_by_WriterName(std::string writerName);
	void find_book_by_feature(std::string feature);
};

#endif