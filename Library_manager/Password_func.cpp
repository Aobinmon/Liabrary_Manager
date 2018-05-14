#include "Administrator.h"
#include "Guest.h"
#include "Book.h" 
#include "Record.h"
#include <iostream>
#include <fstream>
#include <cmath>

int Guest::Num = 201800;

using namespace std;

void User::modify_password(string pw){
	this->Password = pw;
}
void Administrator::ban_Guest(Guest* guest){
	guest->In_use = false;
}

void Administrator::start_Guest(Guest* guest){
	guest->In_use = true;
}

void Administrator::set_password(string pw){
	modify_password(pw);
}

void Administrator::modify_Gpassword(string pw, Guest* guest){
	guest->set_password(pw);
	U_IP[guest->getID()] = pw;
}





void Guest::set_password(string pw){
	modify_password(pw);
	U_IP[getID()] = pw;
}