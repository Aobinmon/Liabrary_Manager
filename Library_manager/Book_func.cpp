#include "Administrator.h"
#include "Guest.h"
#include "Book.h" 
#include "Novel.h"
#include "TextBook.h"
#include "Dictionary.h"
#include "Record.h"
#include "Reference.h"
#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

int Reference::SocID = 0;
int Reference::EcoID = 0;
int Reference::HisID = 0;
int Reference::MedID = 0;
int Reference::PsyID = 0;

int Novel::SFID=0;
int Novel::RelID=0;
int Novel::WuID=0;
int Novel::DetID=0;
int Novel::HisID=0;

int TextBook::MatID=0;
int TextBook::ChiID=0;
int TextBook::EngID=0;
int TextBook::PhyID=0;
int TextBook::CheID=0;

int Dictionary::EngID=0;
int Dictionary::JapID=0;
int Dictionary::FreID=0;
int Dictionary::GerID=0;
int Dictionary::ChiID=0;

Book::Book(string bookName, string writerName, string press, string pressTime){
	BookName = bookName;
	WriterName = writerName;
	Press = press;
	PressTime = pressTime;
}


Dictionary::Dictionary(string bookName, string writerName, string press, string pressTime, string feature):Book(bookName, writerName, press, pressTime){
    int id=0;
    if(feature == "英语"){
        FID = 1;
        id += TID*10000+FID*100+EngID;
        ++EngID;
        this->modifyID(id);
    }
    else if(feature == "日语"){
        FID = 2;
        id += TID*10000+FID*100+JapID;
        ++JapID;
        this->modifyID(id);
    }
    else if	(feature == "法语"){
        FID = 3;
        id += TID*10000+FID*100+FreID;
        ++FreID;
        this->modifyID(id);
    }
    else if	(feature == "德语"){
        FID = 4;
        id += TID*10000+FID*100+GerID;
        ++GerID;
        this->modifyID(id);
    }
    else if(feature == "汉语"){
        FID = 5;
        id += TID*10000+FID*100+ChiID;
        ++ChiID;
        this->modifyID(id);
    }
    else cout << "!!!警告：不合法的分类输入" << endl;
    Feature = feature;
}
string Dictionary::getType(){
    return "字典";
}

string Dictionary::getFeature(){
    return Feature;
}
int Dictionary::getFID()
{
    return FID;
}
TextBook::TextBook(string bookName, string writerName, string press, string pressTime, string feature):Book(bookName, writerName, press, pressTime){

    int id=0;
    if(feature == "数学"){
        FID = 1;
        id += TID*10000+FID*100+MatID;
        ++MatID;
        this->modifyID(id);
    }
    else if(feature == "语文"){
        FID = 2;
        id += TID*10000+FID*100+ChiID;
        ++ChiID;
        this->modifyID(id);
    }
    else if	(feature == "英语"){
        FID = 3;
        id += TID*10000+FID*100+EngID;
        ++EngID;
        this->modifyID(id);
    }
    else if	(feature == "物理"){
        FID = 4;
        id += TID*10000+FID*100+PhyID;
        ++PhyID;
        this->modifyID(id);
    }
    else if(feature == "化学"){
        FID = 5;
        id += TID*10000+FID*100+CheID;
        ++CheID;
        this->modifyID(id);
    }
    else cout << "!!!警告：不合法的分类输入" << endl;
    Feature = feature;
}
string TextBook::getType(){
    return "教材";
}

string TextBook::getFeature(){
    return Feature;
}
int TextBook::getFID()
{
    return FID;
}
Novel::Novel(string bookName, string writerName, string press, string pressTime, string feature):Book(bookName, writerName, press, pressTime){
    int id=0;
    if(feature == "科幻"){
        FID = 1;
        id += TID*10000+FID*100+SFID;
        ++SFID;
        this->modifyID(id);
    }
    else if(feature == "纪实"){
        FID = 2;
        id += TID*10000+FID*100+RelID;
        ++RelID;
        this->modifyID(id);
    }
    else if	(feature == "武侠"){
        FID = 3;
        id += TID*10000+FID*100+WuID;
        ++WuID;
        this->modifyID(id);
    }
    else if	(feature == "侦探"){
        FID = 4;
        id += TID*10000+FID*100+DetID;
        ++DetID;
        this->modifyID(id);
    }
    else if(feature == "历史"){
        FID = 5;
        id += TID*10000+FID*100+HisID;
        ++HisID;
        this->modifyID(id);
    }
    else cout << "!!!警告：不合法的分类输入" << endl;
    Feature = feature;
}
string Novel::getType(){
    return "小说";
}

string Novel::getFeature(){
    return Feature;
}
int Novel::getFID()
{
    return FID;
}
Reference::Reference(string bookName, string writerName, string press, string pressTime, string feature):Book(bookName, writerName, press, pressTime){
	int id=0;
	if(feature == "社会学"){
		FID = 1;
		id += TID*10000+FID*100+SocID;
		++SocID;
		this->modifyID(id);
	}
	else if(feature == "经济学"){
		FID = 2;
		id += TID*10000+FID*100+EcoID;
		++EcoID;
		this->modifyID(id);
	}
	else if	(feature == "历史学"){
		FID = 3;
		id += TID*10000+FID*100+HisID;
		++HisID;
		this->modifyID(id);
	}
	else if	(feature == "医学"){
		FID = 4;
		id += TID*10000+FID*100+MedID;			
		++MedID;
		this->modifyID(id);
	}
	else if(feature == "心理学"){
		FID = 5;
		id += TID*10000+FID*100+PsyID;
		++PsyID;
		this->modifyID(id);
	} 
	else cout << "!!!警告：不合法的分类输入" << endl;
	Feature = feature;
}

int Book::getID(){
	return ID;
}

void Book::modifyID(int id){
	ID = id;
}

bool Book::operator== (Book* book){
	if(book->getID() == this->ID) return true;
	else return false;
}

void Book::PutonShelf(string position){
	this->Onshelf = true;
	ifstream fin("Book.txt");
	string ltmp= "";
	string tmp;
	for(; !fin.eof();){
		getline(fin, ltmp);
		int id=0;
		for(int i=3; i<=8; ++i) id = id*10+ltmp[i]-'0';
		if(id == this->getID()){
			int counter=0;
			for(int i=0; i<ltmp.length()&&counter<10; ++i){
				tmp += ltmp[i];
				if(ltmp[i]=='|') ++counter;
			}
			tmp += "    是    ||    " + position + '\n';
		}
		else{
			tmp += ltmp + '\n';
		}
	}
	ofstream fout("Book.txt");
	fout << tmp;
	fin.close();
	fout.close();
}

void Book::PutoffShelf(){
	this->Onshelf = false;
	ifstream fin("Book.txt");
	string ltmp= "";
	string tmp;
	for(; !fin.eof();){
		getline(fin, ltmp);
		int id=0;
		for(int i=3; i<=8; ++i) id = id*10+ltmp[i]-'0';
		if(id == this->getID()){
			int counter=0;
			for(int i=0; i<ltmp.length()&&counter<10; ++i){
				tmp += ltmp[i];
				if(ltmp[i]=='|') ++counter;
			}
			tmp += "    否" + '\n';
		}
		else{
			tmp += ltmp + '\n';
		}
	}
	ofstream fout("Book.txt");
	fout << tmp;
	fin.close();
	fout.close();
}

string Book::getBookName(){
	return this->BookName;
}

string Book::getPress(){
	return this->Press;
}

string Book::getPressTime(){
	return this->PressTime;
}

string Book::getSummary(){
	return this->Summary;
}

bool Book::getOnshelf(){
	return this->Onshelf;
}

string Book::getPosition(){
	return this->Position;
}


string Reference::getType(){
	return "参考资料";
}

string Reference::getFeature(){
	return Feature;
}



void User::find_book_by_ID(int id){
	ifstream fin("Book.txt");
	string ltmp = "";
	while(!fin.eof()){
		getline(fin, ltmp);
		int id_ = 0;
		for(int i=3; i<=8; ++i) id_ = id_*10 + ltmp[i]-'0';
		if(id == id_){
			cout << ltmp << endl;
			break;
		}
	}
	fin.close();
}

void User::find_book_by_BookName(string bookName){
	ifstream fin("Book.txt");
	string ltmp = "";
	while(!fin.eof()){
		getline(fin, ltmp);
		string bookName_ = "";
		int counter = 0;
		for(int i=0; ltmp[i]!='>'; ++i){
			if(ltmp[i] == '<') ++counter;
			if(counter == 2){
				bookName_ += ltmp[i];
			}  
		}
		if(bookName == bookName_){
			cout << ltmp << endl;
			break;
		}
	}	
}

void Guest::increaseBook(){
	this->bBook ++;
}
void Guest::decreaseBook(){
	this->bBook --;
}

int Guest::getbBook(){
	return bBook;
}

void Guest::getBook(Book* book){
	this->increaseBook();
	string bookName = book->getBookName();
	string writerName = book->getWriterName();
	string press = book->getPress();
	string pressTime = book->getPressTime();
	string feature = book->getFeature();
	if(book->getType() == "参考资料")
	Gbook[getbBook()] = new Reference(bookName, writerName, press, pressTime, feature);
	book->PutoffShelf();
}

void Guest::returnBook(Book* book){
	for(int i=0; i<getbBook(); ++i){
		if(*book == Gbook[i]){
			delete Gbook[i];
		}
	}
	this->decreaseBook();
	book->PutonShelf(book->getPosition());
}







void Administrator::addBook(Book* book){
	ofstream fout("Book.txt", ios::app);
	int counter=0;
	fout << "  " << book->getID() << "  ||  ";
	fout << "<<" << book->getBookName() << ">>";
	counter += book->getBookName().length()+4;
	for(; counter<20; ++counter) fout << " ";
		fout << "||  " << book->getType();
	fout << "(" << book->getFeature() << ")";
	counter += book->getFeature().length() + 2 + book->getType().length();
	for(; counter<40; ++counter) fout << " ";
		fout << "||  " << book->getWriterName();
	counter += book->getWriterName().length();
	for(; counter<50; ++counter) fout << " ";
		fout << "||  " << book->getPress() << "(" << book->getPressTime() << ")";
	counter += book->getPressTime().length() + 2 + book->getPress().length();
	for(; counter<75; ++counter) fout << " ";
		fout << "||    ";
	if(book->getOnshelf()) {
		fout << "是    ||    ";
		fout << book->getPosition() << endl;
	}
	else fout << "否" << endl;
	fout.close();
}

void Administrator::deleteBook(Book* book){
	ifstream fin("Book.txt");
	string ltmp="";
	string tmp="";
	int aimID = book->getID();
	while(!fin.eof()){
		getline(fin, ltmp);
		int id=0;
		for(int i=3; i<=8; ++i){
			id = id*10 + ltmp[i] - '0';
		}
		if(aimID != id){
			tmp += ltmp + "\n";
		}
	}
	fin.close();
	ofstream fout("Book.txt");
	fout << tmp;
	fout.close();
}