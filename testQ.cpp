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
//	cout << timKiemCauHoiTheoMaMonHocInt("DADA2", dsCauHoi);
//	MonHoc mon;
//	mon.MAMH = "DADA";
//	mon.TENMH = "Daten test";
//	cout << themMonHocTheoThuTuMaMonHoc(dsMonHoc, mon);
//	for(int i = 0; i < dsMonHoc.index; i++){
//		cout << "mamh: " << dsMonHoc.ds[i]->MAMH <<endl;
//		cout << "tenmh: " << dsMonHoc.ds[i]->TENMH <<endl;
//	}
	// khoi tao sinh vien cho lop
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
	
//	tiepTucThi(dsLop, dsMonHoc, dsCauHoi);

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
