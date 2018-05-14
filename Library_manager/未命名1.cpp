#include <iostream>
#include <fstream>
using namespace std;
void addBook(int ID, string BookName, string WriterName, string Type, string Feature, string Press, string PressTime, bool Onshelf, string Position){
	ofstream fout("Book.txt", ios::app);
	int counter=0;
	fout << "  " << ID << "  ||  ";
	fout << "<<" << BookName << ">>";
	counter += BookName.length()+4;
	for(; counter<20; ++counter) fout << " ";
		fout << "||  " << Type;
	fout << "(" << Feature << ")";
	counter += Feature.length() + 2 + Type.length();
	for(; counter<40; ++counter) fout << " ";
		fout << "||  " << WriterName;
	counter += WriterName.length();
	for(; counter<50; ++counter) fout << " ";
		fout << "||  " << Press << "(" << PressTime << ")";
	counter += PressTime.length() + 2 + Press.length();
	for(; counter<75; ++counter) fout << " ";
		fout << "||    ";
	if(Onshelf) fout << "��    ||   " << Position << endl;
	else fout << "��" << endl;
	fout.close();
}
int main(){
	addBook(123456, "��Ů����С���", "ͼ����", "��ʷ����", "������", "28���ͳ�����", "2600.2.30", true, "A��C��301");
	return 0;
}
