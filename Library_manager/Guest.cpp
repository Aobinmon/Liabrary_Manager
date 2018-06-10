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
    //查找书名的函数
    gm.collection(QString::fromStdString(书名));
    return;
}

void Guest::Guest(std::string name, std::string password) {
    gm.addguest(QString::fromStdString(name),QString::fromStdString(password));//bBook = 0
    return;
}

void Guest::Applyforbook(Book *book) {
    //查找书名的函数
    tm.addApplyforbook(QString::fromStdstring(书名));
    return;
}

void Guest::ApplyreturnBook(Book *book) {
    //查找书名的函数
    tm.addApplyreturnBook(QString::fromStdstring(书名));
    return;
}
