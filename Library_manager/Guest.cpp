//
// Created by wujiayi on 2018/5/18.
//
#include "Guest.h"
#include "User.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <cctype>
#include <QString>
using namespace std;

std::vector<Book*> Guest::findbook(std::string type, std::string value) {//type包括书名，书序号，
    return bm.findbook(QString::fromStdString(type),QString::fromStdString(value));
}

void Guest::collection(Book *book) {
    gm.collection(QString::fromStdString( book->getBookName()));
    return;
}

Guest::Guest(int id, std::string _name, std::string _password) {
    modifyid(id);
    modifyname(_name);
    modifypassword(_password);
}

Guest::Guest(int id, std::string name, std::string password, int _bbook) {
    modifyid(id);
    modifyname(name);
    modifypassword(password);
    bBook = _bbook;
}

void Guest::Applyforbook(Book *book) {
    tm.addApplyforbook(QString::fromStdstring( book->getID()));
    return;
}

void Guest::ApplyreturnBook(Book *book) {
    tm.addApplyreturnBook(QString::fromStdstring( book->getID()));
    return;
}
