#include <iostream>
#include <string>
#include <conio.h>
#include "GUI.h"
#include "TDV.h"
#include <fstream>
#include <unistd.h>
#include <time.h>
using namespace std;
DSLop dsLop;
DSMonHoc dsMonHoc;
ptrDSCauHoi dsCauHoi;

int * randomCauHoi(int arrayCauHoi[], int soCauHoi){ 
	cout << (int) sizeof(arrayCauHoi) << endl;
	int *randomResult = new int[soCauHoi];
	if(soCauHoi == (int) sizeof(arrayCauHoi)){
		cout << "tra ve het mang" << endl;
		return arrayCauHoi;
	}
	else if(soCauHoi >  (int) sizeof(arrayCauHoi) || soCauHoi <= 0){
		cout << "NULL" <<endl;
		return NULL;
	}
	else{
		int temp;
		srand(time(NULL));
		for(int i = 0; i < soCauHoi; i++){
			int randomNumber = rand() % ((int) sizeof(arrayCauHoi) - 1) + i;
			temp = arrayCauHoi[randomNumber];
			arrayCauHoi[randomNumber] = arrayCauHoi[i];
			arrayCauHoi[i] = temp;
			randomResult[i] = temp;	
		}
	}
	return randomResult;
}
int main ()
{
//	// ham doc file
//	dsCauHoi = docDanhSachCauHoi();
//	dsLop = docDanhSachLop();
//	dsMonHoc = docDanhSachMonHoc();
//	for(int i = 0; i < dsLop.index; i++){
//		dsLop.lop[i]->sv =  docSinhVien(dsLop.lop[i]->MALOP);
//		ptrsv temp = dsLop.lop[i]->sv;
//		while(temp != NULL){
//			temp->dsdiemthi = docDanhSachDiemThi(temp->MSV);
//			temp = temp->next;
//		}
//	}
//	InitWindow();
//	Login(dsLop, dsMonHoc, dsCauHoi);
	int *a = new int[15];
	cout << sizeof(a) << endl;
	int *b = new int[10];
//	randomCauHoi(a,10);
//	for(int i=0;i<10;i++){
//		cout << b[i] << endl;
//	}
//	showClass(dsLop);
//	DSLop danhSachLop;
//	streampos size;
//	Lop lop;
//	ifstream infile("danhSachLop.txt", ios::in | ios::binary | ios::ate);
//	if(infile == NULL){
//		cout << "Loi file" << endl;
//		exit(0);
//	}
//	size = infile.tellg();v
//	infile.seekg (0, ios::bgeg);
//	while(size != infile.tellg()){
//		getline(infile, lop.MALOP, '\0');
//		getline(infile, lop.TENLOP, '\0');
//		getline(infile, lop.NK, '\0');
//		danhSachLop.lop[danhSachLop.index] = new Lop;
//		*danhSachLop.lop[danhSachLop.index] = lop;
//		danhSachLop.index++;
//	};
//	cout << danhSachLop.index;
//	infile.close();	

} 
