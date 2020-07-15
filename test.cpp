// increaser
#include <iostream>
#include <string>
#include "GUI.h"
#include <fstream>
using namespace std;
struct SV{
	string name;
	string lop;
};
int main ()
{
//	InitWindow();
//	ThemLop();
//	for(int i = 0; i <= 255; i++){
//		TextColor(i);
//		cout << i << "\n";
//	}
//	string a[2] = {"abcd", "cdfe"};
//	a[1].pop_back();
//	int size = a[1].length();
//	cout << size;
//	return 0;
	SV sv[5];
	for(int i=0;i<5;i++){
		sv[i].lop = "anhquan";
		sv[i].name = "ala";
	}
	fstream file;
	file.open("test.dat", ios::out | ios::binary);
	for(int i=0;i<5;i++){
		file.write((char*)&sv[i], sizeof(SV));
	}
	file.close();
	file.open("test.dat", ios::in | ios::binary);
	SV a[5];
	int i=0;
	while(!file.eof()){
		file.read((char*)&a[i], sizeof(SV));
		cout << "a" << i << ":\n";
		cout << a[i].lop + "    " + a[i].name << "\n";
		i++;
	}
	file.close();
	
} 
