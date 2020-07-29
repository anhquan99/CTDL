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
ptrDSCauHoi dsCauHoi;

int main ()
{
	// ham doc file
	dsCauHoi = docDanhSachCauHoi();
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
	Login(dsLop, dsMonHoc, dsCauHoi);

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

