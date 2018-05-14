#include "Administrator.h"
#include "Guest.h"
#include "Book.h" 
#include "Record.h"
#include <iostream>
#include <fstream>
#include <cmath>

int Record::Num = 0;

using namespace std;
string tostring(int n){                                  //转化为6位编号，不足6位则前导零
	int i;
	string str="";
	for(i=0; i<7; ++i){
		if(n/pow(10, i) == 0) break;
	}
	for(int j=0; j<6-i; ++j) str += '0';
	str += to_string(n);
	return str;
}

int Record::getNum(){return Num;}

void Record::increaseNum(){++Num;}


void find_Record_by_id(int id, int m){
	ifstream fin("Record.txt");
	string ltmp="";
	for(int i=-1; !fin.eof(); ++i){
		getline(fin, ltmp);
		int ID=0;
		if(i!=-1){
			int counter = 0;
			for(int j=0; j<ltmp.length(); ++j){
				if(ltmp[j]=='|') ++counter;
				if(counter == m){
					for(int k=j+3; k<=j+8; ++k){
						ID = ID*10 + ltmp[k] -'0';
					}
					break;
				}
			}
			if(ID == id){
				cout << ltmp << endl;
			}
		}
	}
	fin.close();
}




void Administrator::approve(Record& record, Guest& guest, Book& book){
	 ifstream fin("Record.txt");
	 int aim_rid = record.getID();
	 string tmp = "";
	 string ltmp = "";
	 string state="";
	 for(int i=-1; !fin.eof(); ++i){
	 	getline(fin, ltmp);
	 	ltmp += '\n';
	 	if(i != aim_rid){
	 		tmp += ltmp;
	 	}
	 	else if(i == aim_rid){
	 		int counter = 0;
	 		for(int j=0; j<ltmp.length(); ++j){
	 			tmp += ltmp[j];
	 			if(ltmp[j] == '|') ++counter;
	 			if(counter == 2){
	 				for(int k=j+3; ltmp[k]!='\t'; ++k) state += ltmp[k];
	 			}
	 			if(counter == 12){
	 				tmp += "      ";
					tmp += "审核通过";
					tmp += "(" + this->getName() + "  " + to_string(this->getID()) + ")\n";
					break;
	 			}
	 		}
	 	}
	 }
	 if(state == "借阅") {
	 	guest.getBook(book);
	 	cout << guest.getName() << "已经成功借阅" << book.getBookName() << endl;
	 	cout << guest.getName() << "已经借阅了" << guest.getbBook() << "本书，还可以借阅" << guest.MaxBook - guest.getbBook() << "本书" << endl;
	 }
	 else if(state == "归还"){
	 	guest.returnBook(book);
	 	cout << guest.getName() << "已经成功归还" << book.getBookName() << endl;
	 	cout << guest.getName() << "已经借阅了" << guest.getbBook() << "本书，还可以借阅" << guest.MaxBook - guest.getbBook() << "本书" << endl;
	 } 
	 fin.close();
	 ofstream fout("Record.txt");
	 fout << tmp << "\n";
	 fout.close();

}

void Administrator::refuse(Record& record, int reason){
	ifstream fin("Record.txt");
	int aim_rid = record.getID();
	string tmp = "";
	string ltmp = "";
	for(int i=-1; i<!fin.eof(); ++i){
	 	getline(fin, ltmp);
	 	ltmp += '\n';
	 	if(i != aim_rid){
	 		tmp += ltmp;
	 	}
	 	else if(i == aim_rid){
	 		int counter = 0;
	 		for(int j=0; j<ltmp.length(); ++j){
	 			tmp += ltmp[j];
	 			if(ltmp[j] == '|') ++counter;
	 			if(counter == 12){
	 				tmp += "      ";
					tmp += "申请失败";	
					if(reason == 1) tmp += ":超出借阅数量";
					else if(reason == 2) tmp += ":无权限借阅该书";
					else if(reason == 3) tmp += ":未知错误";
					tmp += "(" + this->getName() + "  " + to_string(this->getID()) + ")\n";
					break;
	 			}
	 		}
	 	}
	 }
	 fin.close();
	 ofstream fout("Record.txt");
	 fout << tmp << "\n";
	 fout.close();
}

void Administrator::find_Record_by_ID(int id){
	ifstream fin("Record.txt");
	string tmp = "";
	string ltmp="";
	for(int i=-1; i<=id; ++i){
		getline(fin, ltmp);
		if(i == id){
			tmp = ltmp;
			break;
		}
	}
	fin.close();
	cout << tmp << endl;
}

void Administrator::find_Record_by_BookName(string bookname){
	ifstream fin("Record.txt");
	string ltmp="";
	for(int i=-1; !fin.eof(); ++i){
		getline(fin, ltmp);
		string bName="";
		if(i!=-1){
			int counter = 0;
			int f1=0;
			for(int j=0; j<ltmp.length(); ++j){
				if(ltmp[j]=='|') ++counter;
				if(counter == 8){
					if(ltmp[j]=='>') break;
					if(f1==2) bName += ltmp[j];
					if(ltmp[j]=='<') ++f1; 
				}
			}
			if(bookname == bName){
				cout << ltmp << endl;
			}
		}
	}
	fin.close();
}

void Administrator::find_Record_by_GuestName(string guestname){
	ifstream fin("Record.txt");
	string ltmp="";
	for(int i=-1; !fin.eof(); ++i){
		getline(fin, ltmp);
		string gName="";
		if(i!=-1){
			int counter = 0;
			int f1=0;
			for(int j=0; j<ltmp.length(); ++j){
				if(ltmp[j]=='|') ++counter;
				if(counter == 4){
					for(int k=j+3; ltmp[k]!=' '; ++k){
						gName += ltmp[k];
					}
					break; 
				}
			}
			if(guestname == gName){
				cout << ltmp << endl;
			}
		}
	}
	fin.close();
}

void Administrator::find_Record_by_BookID(int bid){
	find_Record_by_id(bid, 10);
}

void Administrator::find_Record_by_GuestID(int gid){
	find_Record_by_id(gid, 6);
}



void Guest::borrow(Book& book){                                       //提出借阅申请
	ofstream fout;
	fout.open("Record.txt", ios::app);
	int counter=0, num=0;
	string rID = tostring(book.getID());
	int gID = this->getID();
	int bID = book.getID();
	string gName = this->getName();
	string bName = book.getBookName();
	fout << "   " << rID << '\t' << " || \t"
	<< "借阅" << '\t' << "  " << " || \t";
	fout << gName;
	counter += gName.length(); 
	for(; counter<12; ++counter)
		fout << " ";
	fout << " ||  ";
	fout << gID << "\t|| \t";
	fout << '<'<< '<' << bName << '>' << '>';
	counter += bName.length()+4;
	for(; counter<40; ++counter)
		fout << " ";
	fout << " ||  " << bID;
	fout << " ||      " << "等待审核" << '\n';
	fout.close();
	Record::increaseNum();
}

void Guest::Return(Book& book){                                     //提出归还申请
	ofstream fout;
	fout.open("Record.txt", ios::app);
	int counter=0, num=0;
	string rID = tostring(book.getID());
	int gID = this->getID();
	int bID = book.getID();
	string gName = this->getName();
	string bName = book.getBookName();
	fout << "   " << rID << '\t' << " || \t"
	<< "借阅" << '\t' << "  " << " || \t";
	fout << gName;
	counter += gName.length(); 
	for(; counter<12; ++counter)
		fout << " ";
	fout << " ||  ";
	fout << gID << "\t|| \t";
	fout << '<'<< '<' << bName << '>' << '>';
	counter += bName.length()+4;
	for(; counter<40; ++counter)
		fout << " ";
	fout << " ||  " << bID;
	fout << " ||      " << "等待审核" << '\n';
	fout.close();
	Record::increaseNum();
}

