#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
void lend_approve(int id, int num){
	ifstream fin("Record.txt", ios::in);
	 int aim_rid = id;
	 string tmp = "";
	 string ltmp = "";
	 for(int i=-1; i<num; ++i){
	 	getline(fin, ltmp);
	 	ltmp += '\n';
	 	if(i != aim_rid){
	 		tmp += ltmp;
	 	}
	 	else if(i == aim_rid){
	 		int counter = 0;
	 		string Ad = "Administrator";
	 		for(int j=0; j<ltmp.length(); ++j){
	 			tmp += ltmp[j];
	 			if(ltmp[j] == '|') ++counter;
	 			if(counter == 8){
	 				tmp += " \t";
					tmp += "ÉóºËÍ¨¹ý";
					tmp += "(" + Ad + "123546)\n";
					break;
	 			}
	 		}
	 	}
	 }
	 cout << tmp;
	 fin.close();
	 ofstream fout("Record.txt");
	 fout << tmp << "\n";
	 fout.close();
}
void find_Record_by_BookName(string bookname){
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
}

void find_Record_by_BookID(int bid){
	ifstream fin("Record.txt");
	string ltmp="";
	for(int i=-1; !fin.eof(); ++i){
		getline(fin, ltmp);
		int bID=0; 
		if(i!=-1){
			int counter = 0;
			for(int j=0; j<ltmp.length(); ++j){
				if(ltmp[j]=='|') ++counter;
				if(counter == 10){
					for(int k=j+3; k<=j+8; ++k){
						bID = bID*10 + ltmp[k] - '0';
					}
					break;
				}
			}
			if(bID == bid){
				cout << ltmp << endl;
			}
		}
	}
}
void find_Record_by_GuestName(string guestname){
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
}
int main()
{
	ofstream fout;
	fout.open("Record.txt", ios::app);
	int counter=0, num=0;
	string rID = "00000" + to_string(num);
	string gID = "011437";
	string bID = "123456";
	string gName = "aobinmon";
	string bName = "ÂôÅ®º¢µÄÐ¡»ð²ñ";
	fout << "   " << rID << '\t' << " || \t"
	<< "½èÔÄ" << '\t' << "  " << " || \t";
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
	fout << " ||      " << "µÈ´ýÉóºË" << '\n';
	fout.close();
	find_Record_by_GuestName("aobinmon");
	return 0;
 } 
