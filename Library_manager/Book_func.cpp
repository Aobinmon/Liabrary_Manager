#include "Administrator.h"
#include "Guest.h"
#include "Book.h" 
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



Book::Book(string bookName, string writerName, string press, string pressTime){
	BookName = bookName;
	WriterName = writerName;
	Press = press;
	PressTime = pressTime;
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

void Book::PutonShelf(){
	this->Onshelf = true;
}

void Book::PutoffShelf(){
	this->Onshelf = false;
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
	ifstream fin("Book.txt");
}

void Guest::returnBook(Book* book){
	for(int i=0; i<getbBook(); ++i){
		if(*book == Gbook[i]){
			delete Gbook[i];
		}
	}
	this->decreaseBook();
	book->PutonShelf();
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