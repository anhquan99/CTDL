// increaser
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
// input array id cau hoi
// so cau hoi
//int * randomCauHoi(int arrayCauHoi[], int soCauHoi){ 
//	int *randomResult = new int[soCauHoi];
//	if(soCauHoi == (int) sizeof(arrayCauHoi)) return arrayCauHoi;
//	else if(soCauHoi >  (int) sizeof(arrayCauHoi) || soCauHoi <= 0) return NULL;
//	else{
//		int temp;
//		srand(time(NULL));
//		for(int i = 0; i < soCauHoi; i++){
//			int randomNumber = rand() % ((int) sizeof(arrayCauHoi) - 1) + i;
//			temp = arrayCauHoi[randomNumber];
//			arrayCauHoi[randomNumber] = arrayCauHoi[i];
//			arrayCauHoi[i] = temp;
//			randomResult[i] = temp;	
//		}
//	}
//	return randomResult;
//}
int main ()
{
	// ham doc file
	dsLop = docDanhSachLop();
	dsMonHoc = docDanhSachMonHoc();
	for(int i = 0; i < dsLop.index; i++){
		dsLop.lop[i]->sv =  docSinhVien(dsLop.lop[i]->MALOP);
		ptrsv temp = dsLop.lop[i]->sv;
		while(temp != NULL){
			temp->dsdiemthi = docDanhSachDiemThi(temp->MSV);
			temp = temp->next;
		}
	}
	InitWindow();
	Login(dsLop, dsMonHoc);

//	showClass(dsLop);
//	DSLop danhSachLop;
//	streampos size;
//	Lop lop;
//	ifstream infile("danhSachLop.txt", ios::in | ios::binary | ios::ate);
//	if(infile == NULL){
//		cout << "Loi file" << endl;
//		exit(0);
//	}
//	size = infile.tellg();
//	infile.seekg (0, ios::beg);
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

