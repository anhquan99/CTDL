#include <iostream>
#include <fstream>
#include "Structure.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
const int MAXQUEST = 10;
using namespace std;

//***************************************************************************************************
void generateArrayRandomNumber(int arrayRandomNumber[]){											
	int randomNumber;
	srand(time(NULL));
	int temp;
	for(int i = 0; i < MAXQUEST; i++){  
		arrayRandomNumber[i] = i;
	}
	arrayRandomNumber[0] = MAXQUEST/2;
	arrayRandomNumber[MAXQUEST/2] = 0;
	for(int i = 1; i < MAXQUEST-1; i++){
		randomNumber = rand() % (MAXQUEST - i)+1;
		//cout << "randomNumber = " << randomNumber << endl;
		temp = arrayRandomNumber[MAXQUEST-i];
		arrayRandomNumber[MAXQUEST-i] = arrayRandomNumber[randomNumber];
		//cout <<"arrayRandomNumber[MAXQUEST-i] = " << arrayRandomNumber[MAXQUEST-i] << endl;	
		arrayRandomNumber[randomNumber] = temp;		
		//cout <<"arrayRandomNumber[randomNumber] = " << arrayRandomNumber[randomNumber] << endl;	
	}
}
//***************************************************************************************************
//***********************            HAM HO TRO         *********************************************

void toUppercaseArray(string &s){
	string temp = "";
	for(int i = 0; i < s.length(); i++){
		temp += toupper(s[i]);
	}
	s = temp;
	return;
}

bool laKiTuVaLaSoNguyen(string s){
	// khong chap nhan space
	// xem co phai so va chu khong
	for(int i = 0; i < s.length(); i++){
		if((isalpha(s[i]) || isdigit(s[i])) == false) 
			return false;
	}
	return true;
	
}

bool kiemTraCuPhapTenLop(string tenLop){
	
}
////************************        MANG TUYEN TINH       *********************************************
void xoaPhanTuMangTuyenTinh(string &s, int viTri){
	string mangTam = "";
	int newSize = s.length();
	for(int i = viTri; i < s.length(); i++)
		s[i] = s[i+1];

}


////***************************************************************************************************
////*********************** HAM THAO TAC VOI LOP VA DSLOP *********************************************
//
int checkMaLop(DSLop classList, string &maLop){
	toUppercaseArray(maLop);
	for(int i = 0; i < classList.index; i++)
		if(classList.lop[i]->MALOP.compare(maLop) == 0)
			return i;
	return -1;
}

void insertClass(Lop &classroom, DSLop classlist){
	classroom.sv = NULL; // tam thoi gan bang null
	string maLop;
	bool check;
	do{
		check = true;
		cout << "Nhap ma lop: ";
		getline(cin, maLop);
		if(laKiTuVaLaSoNguyen(maLop) == false) {
			cout << "Nhap sai cu phap" << endl << "Hay nhap lai" << endl;
			check = false;
		} 
		if(checkMaLop(classlist, maLop) >= 0 ){
			cout << "Ma lop da ton tai" << endl << "Nhap ma lop khac"<< endl;
			check = false;
		}
	}while(check == false);
	classroom.MALOP = maLop;
	cout << "Nhap ten lop: ";
	getline(cin, classroom.TENLOP);
	cout << "Nhap nien khoa: ";
	getline(cin, classroom.NK);
}
////---------------------------------------------------------------------------------------------------
void insertClassList(DSLop &classList){
	Lop classroom;
	char key_press;
	while(classList.index < MAXLOP){
		insertClass(classroom, classList);
		classList.lop[classList.index] = new Lop;
		*classList.lop[classList.index] = classroom;
		classList.index++;
		cout << "them thanh cong! them tiep hay thoi(ESC)" << endl;
		key_press = getch();
		if(key_press == 27) // For ESC
            break;
	}
	if(classList.index == MAXLOP)
		cout << "danh sach day" << endl;
}
//
//bool xoaLop(string maLop){
//	
//}
////---------------------------------------------------------------------------------------------------
void showClass(DSLop classList){
	system("cls") ;
	cout << "                     DANH SACH LOP " << endl ;
	cout <<"MaLop       Tenlop           Nien khoa" << endl;
	for (int i =0 ; i < classList.index ; i++){
		cout << classList.lop[i]->MALOP << "       " << classList.lop[i]->TENLOP << "      " 
		<<  classList.lop[i]->NK << endl << classList.lop[i]->sv << endl;
	}
}
////---------------------------------------------------------------------------------------------------
bool saveFile(DSLop classList){
	ofstream outfile("classList.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	for (int i=0; i < classList.index; i++){
		outfile.write(classList.lop[i]->MALOP.c_str(), classList.lop[i]->MALOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(classList.lop[i]->TENLOP.c_str(), classList.lop[i]->TENLOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(classList.lop[i]->NK.c_str(), classList.lop[i]->NK.size());
		outfile.write("\0", sizeof(char));
		outfile.write(reinterpret_cast<char*>(&(classList.lop[i]->sv)), sizeof(SV));	
	}

	outfile.close();
	return true;	
}
////---------------------------------------------------------------------------------------------------
bool openFile(){ // se co truyen vao tham so la ten file muon mo

	DSLop classList1;
	Lop lop;
	streampos size;
	ifstream infile("classList.txt", ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	size = infile.tellg();
	infile.seekg (0, ios::beg);
	while(size != infile.tellg()){
		cout << "loi 1 ";
		getline(infile, lop.MALOP, '\0');
		getline(infile, lop.TENLOP, '\0');
		getline(infile, lop.NK, '\0');
//		cout << "loi 2 ";
		infile.read(reinterpret_cast<char*>(&lop.sv), sizeof(SV) );
//		cout << "loi 3 ";
		classList1.lop[classList1.index] = new Lop;
//		cout << "loi 4 ";
		*classList1.lop[classList1.index] = lop;
//		cout << "loi 5 ";
		classList1.index++;
//		cout << "loi 6 ";
	};
	infile.close();	
	showClass(classList1);
	return true;
}

//***************************************************************************************************



//***************************************************************************************************
struct Lop1{
	string MALOP;
	string TENLOP;
	string NK;
};
int main(){
	DSLop classList;
	Lop1 lop1 = {"at01111", "an toan 1", "2020-2029"};
	Lop1 lop2 =  {"at02", "an toan 2", "2020-2021"};
	//classList.lop[classList.index] = new Lop;
	//classList.lop[classList.index]->sv = new SV;
	//*classList.lop[classList.index] = lop1;
	//classList.index++;
	//classList.lop[classList.index] = new Lop;
	//*classList.lop[classList.index] = lop2;
	//classList.index++;
	//showClass(classList);
	ofstream outfile("classList.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	//for (int i=0; i < classList.index; i++){
		outfile.write(lop1.MALOP.c_str(), lop1.MALOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(lop1.TENLOP.c_str(), lop1.TENLOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(lop1.NK.c_str(), lop1.NK.size());
		outfile.write("\0", sizeof(char));
//		outfile.write(reinterpret_cast<char*>(&(lop1.sv)), sizeof(SV));	
		outfile.write(lop2.MALOP.c_str(), lop2.MALOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(lop2.TENLOP.c_str(), lop2.TENLOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(lop2.NK.c_str(), lop2.NK.size());
		outfile.write("\0", sizeof(char));
//		outfile.write(reinterpret_cast<char*>(&(lop2.sv)), sizeof(SV));		
	//}
	outfile.close();

//	Lop1 lop, lopf;
//	//streampos size;
//	ifstream infile("classList.txt", ios::in | ios::binary);
//	if(infile == NULL){
//		cout << "Loi file" << endl;
//		return false;
//	}
//	//size = infile.tellg();
//	//infile.seekg (0, ios::beg);
//	//while(size != infile.tellg()){
//		getline(infile, lop.MALOP, '\0');
//		getline(infile, lop.TENLOP, '\0');
//		getline(infile, lop.NK, '\0');
////		infile.read(reinterpret_cast<char*>(&lop.sv), sizeof(SV) );
//		getline(infile, lopf.MALOP, '\0');
//		getline(infile, lopf.TENLOP, '\0');
//		getline(infile, lopf.NK, '\0');
////		infile.read(reinterpret_cast<char*>(&lopf.sv), sizeof(SV) );
////		classList1.lop[classList1.index] = new Lop;
////		*classList1.lop[classList1.index] = lop;
////		classList1.index++;
//	//};
//	
//	infile.close();		
//	//showClass(classList1);
//	cout << lop.MALOP << endl << lop.TENLOP << endl << lop.NK;
//	cout << lopf.MALOP << endl << lopf.TENLOP << endl << lopf.NK;
//	//if(lop.sv == NULL) cout << "null";
////	cout << lop1.MALOP << endl << lop1.TENLOP << endl << lop1.NK;
////	if(lop1.sv == NULL) cout << "null";
////	cout << lopg.MALOP << endl << lopg.TENLOP << endl << lopg.NK;
////	if(lopg.sv == NULL) cout << "null";
	return 0;
}
