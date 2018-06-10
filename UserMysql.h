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
    virtual ~User();
};


#endif //LIBRAR_USER_H
