//
// Created by wujiayi on 2018/5/8.
//

#ifndef LIBRAR_USER_H
#define LIBRAR_USER_H
#include <string>
#include <map>

class User {
    int ID;
    std::string Password;
    std::string Name;
public:
    void modifyid(int id);
    void modifypassword(std::string _password);
    void modifyname(std::string _name);
    virtual User() = 0;
};


#endif //LIBRAR_USER_H
