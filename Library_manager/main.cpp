#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>


#include "Administrator.h"
#include "Guest.h"
#include "Textbook.h"
#include "Fiction.h"

using namespace std;


Book* book[1000];

int main()
{
	int typeofUser;
	int k=3;
	cout << "\t\t\t欢迎使用strange图书管理系统~\n";
	cout << "\t\t\t请选择您要登录的账号类型：\n";
	cout << "-------1 管理员-------\n";
	cout << "-------2 普通读者------\n";
	cin >> typeofUser;
	using User::U_IP;
	if(typeofUser==1){
		int Aid;
		string Apassword;
		for(int i=1; i<=k; ++i){
			cout << "请输入您的ID："；
			cin >> Aid;
			cout << "请输入您的密码："；
			cin >> Apassword;
			if(U_IP[Aid]==Apassword){
				break; 
			}	
		}
		
	}
	else if(typeofUser==2){

	}
	else{
		cout << "错误的账号类型，请重新输入\n";
	}
	return 0;
}