#ifndef _TDV
#define _TDV
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <regex>
#include "Structure.h"
#include <stdlib.h> 
#include <windows.h>
#include <iomanip>
using namespace std;

// ham giao dien
void gotoxy(int x, int y);
void xoaManHinhTheoToaDo(string nd, string a, string b, string c, string d);

// ham khoi tao so ngau nhien cho cau hoi
void initialArrayRandomNumber();
int generateArrayRandomNumber();

// viet ho tro 
void toUppercaseArray(string &s);
bool laKiTuVaLaSoNguyen(string s);
void loaiBoKhoangTrangCuaChuoi(string &chuoi);
void xoaPhanTuMangTuyenTinh(string &s, int viTri);

// thao tac voi lop
bool inThongTinLop(Lop *lop);
bool luuLopVaoCuoiFile(Lop lop);
bool luuDanhSachLopMoi(DSLop danhSachLop);
DSLop docDanhSachLop();
int checkMaLop(DSLop danhSachLop, string &maLop);
int checkMaLopKhongCoMaLopCu(DSLop danhSachLop, string &maLop, string maLopCu);
bool kiemTraCuPhapNienKhoa(string &nienKhoa);
void insertClass(Lop &classroom, DSLop classlist);
bool insertClassList(DSLop &danhSachLop);
string insertClassListQ(Lop classrom, DSLop &danhSachLop);
void showClass(DSLop classList);
bool xoaLop(DSLop &dsLop, Lop lop);
bool themLopTheoThuTuMaLop(DSLop &danhSachLop);
DSLop inDanhSachLopTheoNienKhoa(DSLop danhSachLop, string &nienKhoa);
bool suaThongTinLop(string maLop);
Lop* timKiemLop(string maLop);

// thao tac voi sinh vien
void inThongTinSinhVien(SV sinhVien);
bool luuSinhVienVaoCuoiFile(string maLop, SV sinhVien);
bool luuDanhSachSinhVienMoi(string maLop, ptrsv danhSachSinhVien);
ptrsv docSinhVien(string maLop);
ptrsv kiemTraMaSinhVien(ptrsv First, string maSinhVien);
bool kiemTraMaSinhVienTatCa(string maSinhVien, DSLop dsLop);
ptrsv laySVTruoc(Lop lop, ptrsv sv);
void themSinhVien(ptrsv &danhSachSinhVien, SV sinhVien);
void lietKeDanhSachSinhVien(ptrsv First);
bool dangNhapSinhVien(ptrsv first, string msv, string password);
bool xoaSinhVien(string maLop, ptrsv first);
bool suaSinhVien(string maLop, string s_maSinhVien, string s_ho, string s_ten, bool s_phai, string s_password, ptrsv first);
ptrDT layDTTruoc(SV sv, ptrDT dt);
bool kiemTraMonSinhVienDaThi(string maSinhVien, string maMonHoc);
ptrsv docDanhSachSinhVien(string maLop);
ptrsv kiemTraMaSinhVien(string maSinhVien, DSLop dsLop);
Lop* timLopTheoMaSinhVien(string maSinhVien, DSLop dsLop);

//thao tac voi diem thi
bool themDiemThi(ptrDT &danhSachDiemThi, DT diemThi);
void lietKeDanhSachDiemThi(ptrDT danhSachDiemThi);
ptrDT docDanhSachDiemThi(string maSinhVien);
bool luuDanhSachDiemThi(string maSinhVien, ptrDT danhSachDiemThi);

// thao tac voi mon hoc
bool luuDanhSachMonHoc(DSMonHoc danhSachMonHoc);
void lietKeDanhSachMonHoc(DSMonHoc danhSachMonHoc);
void themVaoMangConTroDSMonHoc(DSMonHoc &danhSachMonHoc, MonHoc mon);
DSMonHoc docDanhSachMonHoc();
int kiemTraMaMonHoc(string maMonHoc, DSMonHoc dsMonHoc);
bool themMonHocTheoThuTuMaMonHoc(DSMonHoc &danhSachMonHoc, MonHoc monHoc);
bool themMonHoc(DSMonHoc &danhSachMonHoc, MonHoc monHoc);

// thao tac voi cau hoi
CauHoi taoCauHoiVoiIdNgauNhien(string maMonHoc, string noiDung, string a, string b, string c, string d, char dapAn);
bool themCauHoiVaoCay(ptrDSCauHoi &danhSachCauHoi, CauHoi cauHoi);
void duyetTrungTu(ptrDSCauHoi &danhSachCauHoi);
void duyetTienTu(ptrDSCauHoi danhSachCauHoi);
void napCauHoiVaoMang(CauHoi mangCauHoi[]);
bool luuDanhSachCauHoi(ptrDSCauHoi danhSachCauHoi);
ptrDSCauHoi docDanhSachCauHoi();
ptrDSCauHoi timKiemCauHoiTheoId(int id, ptrDSCauHoi p);
void timKiemCauHoiTheoMaMonHoc(string maMonHoc, ptrDSCauHoi danhSachCauHoi, CauHoi danhSachCauHoiTheoMaMonHoc[] );
int timKiemCauHoiTheoMaMonHocInt(string maMonHoc, ptrDSCauHoi danhSachCauHoi );
int laySoLuongCauHoiCoSan();
int *randomCauHoi(int arrayCauHoi[], int soCauHoi);
int timKiemCauHoiTheoMaMonHoc(string maMonHoc, CauHoi danhSachCauHoiTheoMaMonHoc[] );
int layNgauNhienCauHoi(CauHoi danhSachCauHoiDanhChoSinhVien[], int soCauHoi, string maMonHoc);

// ham khac
bool xacNhan(int &thoiGianThi, int &giay);
bool luuDiem(DT diemThi, string maSinhVien);
int timKiemMonHocTheoMaMonHoc(string maMonHoc);
int tinhDiem(int* danhSachIdCauHoi, char* danhSachDapAn, int soLuongCau);
bool demNguoc(int phut);
bool isFileExist(string tenFile);
bool dangNhap(string maSinhVien, string password);
bool luuSinhVienDangThi(string maSinhVien, DT diemThi);
void docSinhVienDangThi(string &maSinhVien, DT &diemThi);
void cleanContenAboutInterrupt();

// thoi gian doc lap
bool stop = 1;
struct Hour {
	int hour;
	int minute;
	int second;
};
char inToA(int k) ;
void insertarray(char *h, Hour j);
bool changetime(Hour &h);
//dung de in ra mot chuoi thay the ham cout
void WriteBlockChar(char * Arraych,	int row, int col, int x, int y, int color);
void printClock(Hour &h);
void close(DWORD evt);
bool kiemTraSinhVienThiLai(string maSinhVien);


void gotoxy(int x, int y) //set vi tri
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
//khoi tao random
void initialArrayRandomNumber(){
	int arrayRandomNumber[MAXQUEST];
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
	ofstream outfile("DSRandom.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return;
	}
	int index = 1;
	outfile.write((char*) &index, sizeof(int));
	for(int i = 0; i < MAXQUEST; i++){
		outfile.write((char*)&arrayRandomNumber[i], sizeof(int));
	}
	outfile.close();
}

// random 
int generateArrayRandomNumber(){											
	int arrayRandomNumber[MAXQUEST];
	streampos size;
	ifstream infile("DSRandom.txt", ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "Loi file" << endl;
		return -1;
	}
	size = infile.tellg();
	infile.seekg(0, ios::beg);
	int index;
	infile.read((char*) &index, sizeof(int));
	if(index == MAXQUEST) return -1;
//	cout << "index: " << index << "\n";
	for(int i = 0; i < MAXQUEST; i++){
		infile.read((char*) &arrayRandomNumber[i], sizeof(int));
//		cout << arrayRandomNumber[i] << "\n";
	}
	infile.close();
	int temp = arrayRandomNumber[index];
	index++;
	ofstream outfile("DSRandom.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return -1;
	}
	outfile.write((char*) &index, sizeof(int));
	for(int i = 0; i < MAXQUEST; i++){
		outfile.write((char*)&arrayRandomNumber[i], sizeof(int));
	}
	outfile.close();
	return temp;
}

void toUppercaseArray(string &s){
	string temp = "";
	for(int i = 0; i < s.length(); i++){
		temp += toupper(s[i]);
	}
	s = temp;
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

void loaiBoKhoangTrangCuaChuoi(string &chuoi){
	string temp = "";
	int demSo = 0;
	for(int i = 0; i < chuoi.length(); i++){
		if(chuoi[i] != ' '){
			temp += chuoi[i];
		}
	}
	chuoi = temp;
	return;
}

void xoaPhanTuMangTuyenTinh(string &s, int viTri){
	string mangTam = "";
	int newSize = s.length();
	for(int i = viTri; i < s.length(); i++)
		s[i] = s[i+1];

}

bool inThongTinLop(Lop *lop){
	cout << "ma lop :" << lop->MALOP << endl;
	cout << "ten lop :" << lop->TENLOP << endl;
	cout << "nien khoa :" << lop->NK << endl;
}

bool luuLopVaoCuoiFile(Lop lop){ // them ve phia sau
	ofstream outfile("danhSachLop.txt", ios::out| ios::app | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	outfile.write(lop.MALOP.c_str(), lop.MALOP.size());
	outfile.write("\0", sizeof(char));
	outfile.write(lop.TENLOP.c_str(), lop.TENLOP.size());
	outfile.write("\0", sizeof(char));
	outfile.write(lop.NK.c_str(), lop.NK.size());
	outfile.write("\0", sizeof(char));
			
	outfile.close();
	return true;	
}

bool luuDanhSachLopMoi(DSLop danhSachLop){ // ghi de len file cu
	ofstream outfile("danhSachLop.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	for(int i = 0; i < danhSachLop.index; i++){
		outfile.write(danhSachLop.lop[i]->MALOP.c_str(), danhSachLop.lop[i]->MALOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(danhSachLop.lop[i]->TENLOP.c_str(), danhSachLop.lop[i]->TENLOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(danhSachLop.lop[i]->NK.c_str(), danhSachLop.lop[i]->NK.size());
		outfile.write("\0", sizeof(char));	
	}
	outfile.close();
	return true;
}

DSLop docDanhSachLop(){ // se co truyen vao tham so la ten file muon mo
	DSLop danhSachLop;
	streampos size;
	Lop lop;
	ifstream infile("danhSachLop.txt", ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "Loi file" << endl;
		exit(0);
	}
	size = infile.tellg();
	infile.seekg (0, ios::beg);
	while(size != infile.tellg()){
		getline(infile, lop.MALOP, '\0');
		getline(infile, lop.TENLOP, '\0');
		getline(infile, lop.NK, '\0');
		danhSachLop.lop[danhSachLop.index] = new Lop;
		*danhSachLop.lop[danhSachLop.index] = lop;
		danhSachLop.index++;
	};
	infile.close();	
	return danhSachLop;
}

int checkMaLop(DSLop danhSachLop, string &maLop){
	toUppercaseArray(maLop);
	for(int i = 0; i < danhSachLop.index; i++)
		if(danhSachLop.lop[i]->MALOP.compare(maLop) == 0)
			return i;
	return -1;
}

int checkMaLopKhongCoMaLopCu(DSLop danhSachLop, string &maLop, string maLopCu){
	toUppercaseArray(maLop);
	for(int i = 0; i < danhSachLop.index; i++){
		if(danhSachLop.lop[i]->MALOP.compare(maLopCu) == 0) continue;
		if(danhSachLop.lop[i]->MALOP.compare(maLop) == 0) return i;
	}	
	return -1;
}

bool kiemTraCuPhapNienKhoa(string &nienKhoa){
	loaiBoKhoangTrangCuaChuoi(nienKhoa);
	regex b("^[2-3][0-9]{3}[/-][2-3][0-9]{3}"); // thoa man regex = "2020-2025"
	if(regex_match(nienKhoa, b) == false){
		return false;
	}
	string namTruoc = nienKhoa.substr(0,4);
	string namSau = nienKhoa.substr(5,4);
	int truoc = stoi(namTruoc);
	int sau = stoi(namSau);
	if(truoc >= sau || sau - truoc > 7)  return false; // nien khoa chenh lech duoi 7
	return true;
}

void insertClass(Lop &classroom, DSLop classlist){
	classroom.sv = NULL; // tam thoi gan bang null
	string maLop;
	//DSLop danhSachLopTuFile = docDanhSachLop();
	bool check, check1;
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
	string nienKhoa;
	do{
		check1 = true;
		cout << "Nhap nien khoa: ";
		getline(cin, nienKhoa);
		if(kiemTraCuPhapNienKhoa(nienKhoa) == false){
			cout << "Nien khoa nhap vao khong hop le" << endl;
			check1 = false;
		}
	}while(check1 == false);
	classroom.NK = nienKhoa;
}

bool insertClassList(DSLop &danhSachLop){
	Lop lop;
	char key_press;
	while(danhSachLop.index < MAXLOP){
		insertClass(lop, danhSachLop);
	//	luuLopVaoCuoiFile(classroom);
		danhSachLop.lop[danhSachLop.index] = new Lop;
		*danhSachLop.lop[danhSachLop.index] = lop;
		danhSachLop.index++;
		cout << "them thanh cong! them tiep hay thoi(ESC)" << endl;
		key_press = getch();
		if(key_press == 27) // For ESC
            break;
	}
	if(danhSachLop.index == MAXLOP){
		cout << "danh sach day" << endl;
		return false;
	}
	return true;
		
}

string insertClassListQ(Lop classrom, DSLop &danhSachLop){
	if(danhSachLop.index == MAXLOP){	
		return "DANH SACH LOP DA DAY!!!";
	}
	danhSachLop.lop[danhSachLop.index] = new Lop;
	*danhSachLop.lop[danhSachLop.index] = classrom, 
	danhSachLop.index++;
	return "true";
		
}

void showClass(DSLop classList){
	cout << "                     DANH SACH LOP " << endl ;
	cout <<"MaLop       Tenlop           Nien khoa" << endl;
	for (int i =0 ; i < classList.index ; i++){
		cout << classList.lop[i]->MALOP << "       " << classList.lop[i]->TENLOP << "      " 
		<<  classList.lop[i]->NK << endl;
	}
}

bool xoaLop(DSLop &dsLop, Lop lop){
	int i = checkMaLop(dsLop, lop.MALOP);
	if(i == -1){
		 return false;
	}
	else{
		delete dsLop.lop[i];
		for(int j = i+1; j < dsLop.index; j++){
			dsLop.lop[j-1] = dsLop.lop[j];
		}
		dsLop.index--;
	}
	luuDanhSachLopMoi(dsLop); // xoa xong ghi de len file cu danh sach lop moi nay vo
	return true;
}

bool themLopTheoThuTuMaLop(DSLop &danhSachLop){
	Lop lop;
	int j;
	insertClass(lop, danhSachLop);
	if (danhSachLop.index == MAXLOP ) return false;
	for (j = 0; j < danhSachLop.index && (lop.MALOP.compare(danhSachLop.lop[j]->MALOP) == 1 ); j++ );
	for (int i = danhSachLop.index-1; i >= j; i--)
		danhSachLop.lop[i+1] = danhSachLop.lop[i];
	danhSachLop.lop[j] = new Lop;
	*danhSachLop.lop[j] = lop;
	danhSachLop.index++;
	cout << danhSachLop.index;
	return true;
}

DSLop inDanhSachLopTheoNienKhoa(DSLop danhSachLop, string &nienKhoa){
	if(nienKhoa == ""){
		return danhSachLop;
	}
	else{
		DSLop subList;
		for(int i = 0; i < danhSachLop.index; i++){
			if(nienKhoa.compare(danhSachLop.lop[i]->NK) == 0){
				subList.lop[subList.index] = new Lop;
				subList.lop[subList.index] = danhSachLop.lop[i];
				subList.index++;
			}
		}
		return subList;
	}
}

bool suaThongTinLop(string maLop){
	string maLopTam;
	string tenLop;
	string nienKhoa;
	DSLop danhSachLop = docDanhSachLop();
	int viTri = checkMaLop(danhSachLop, maLop);
	if( viTri == -1) return false; // khong tim thay lop trong danh sach lop
	else{
		inThongTinLop(danhSachLop.lop[viTri]);
		cout << "Nhap cac thong tin muon thay doi " << endl;
		bool checkML, checkNK;
		do{
			checkML = true;
			cout << "Nhap ma lop: ";
			getline(cin, maLopTam);
			loaiBoKhoangTrangCuaChuoi(maLopTam);
			if(laKiTuVaLaSoNguyen(maLopTam) == false) {
				cout << "Nhap sai cu phap" << endl << "Hay nhap lai" << endl;

				checkML = false;
			} 
			if(checkMaLop(danhSachLop, maLopTam) >= 0 ){
				cout << "Ma lop da ton tai" << endl << "Nhap ma lop khac"<< endl;
				checkML = false;
			}
		}while(checkML == false);
		danhSachLop.lop[viTri]->MALOP = maLopTam;
		cout << "Nhap ten lop: ";
		getline(cin, tenLop);
		danhSachLop.lop[viTri]->TENLOP = tenLop;
		do{
			checkNK = true;
			cout << "Nhap nien khoa: ";
			getline(cin, nienKhoa);
			if(kiemTraCuPhapNienKhoa(nienKhoa) == false){
				cout << "Nhap sai cu phap" << endl << "Hay nhap lai" << endl;
				checkNK = false;
			}
		}while(checkNK == false);	
		danhSachLop.lop[viTri]->NK = nienKhoa;
	}
	showClass(danhSachLop);
	luuDanhSachLopMoi(danhSachLop);
}

// thao tac voi sinh vien

void inThongTinSinhVien(SV sinhVien){
	string phai = sinhVien.PHAI ? "Nam" : "Nu";
	cout << sinhVien.HO << " " << sinhVien.TEN << " " << sinhVien.MSV << " " << phai << " " << sinhVien.password << endl;
}

bool luuSinhVienVaoCuoiFile(string maLop, SV sinhVien){
	string tenFile = maLop + ".txt";
	ofstream outfile( tenFile, ios::out | ios::app | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	outfile.write(sinhVien.MSV.c_str(), sinhVien.MSV.size());
	outfile.write("\0", sizeof(char));
	outfile.write(sinhVien.HO.c_str(), sinhVien.HO.size());
	outfile.write("\0", sizeof(char));
	outfile.write(sinhVien.TEN.c_str(), sinhVien.TEN.size());
	outfile.write("\0", sizeof(char));
	outfile.write((char*)&sinhVien.PHAI, sizeof(bool)); // day 
	outfile.write(sinhVien.password.c_str(), sinhVien.password.size());
	outfile.write("\0", sizeof(char));	
	outfile.close();
	return true;
}

bool luuDanhSachSinhVienMoi(string maLop, ptrsv danhSachSinhVien){
	ptrsv p;
	string tenFile = maLop + ".txt";
	ofstream outfile( tenFile, ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	for(p = danhSachSinhVien; p != NULL; p = p->next){
		outfile.write(p->MSV.c_str(), p->MSV.size());
		outfile.write("\0", sizeof(char));
		outfile.write(p->HO.c_str(), p->HO.size());
		outfile.write("\0", sizeof(char));
		outfile.write(p->TEN.c_str(), p->TEN.size());
		outfile.write("\0", sizeof(char));
		outfile.write((char*)&p->PHAI, sizeof(bool)); // day 
		outfile.write(p->password.c_str(), p->password.size());
		outfile.write("\0", sizeof(char));	
	}
	outfile.close();
	return true;
}

ptrsv docSinhVien(string maLop){
	ptrsv p;
	ptrsv danhSachSinhVien = NULL;
	ptrsv last = NULL;
	string tenFile = maLop + ".txt";
	streampos size;
	Lop lop;
	ifstream infile(tenFile , ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "Loi file" << endl;
		exit(0);
	}
	size = infile.tellg();
	infile.seekg (0, ios::beg);
	while(size != infile.tellg()){
		p = new SV;
		getline(infile, p->MSV, '\0');
		getline(infile, p->HO, '\0');
		getline(infile, p->TEN, '\0');
		infile.read((char*) &p->PHAI, sizeof(bool));
		getline(infile, p->password, '\0');
		p->next = NULL;
		if (danhSachSinhVien == NULL) {
			danhSachSinhVien = p;
		}
		else{
			last->next = p;
		}
		last = p;
	};
	infile.close();	
	return danhSachSinhVien;
}

ptrsv kiemTraMaSinhVien(ptrsv First, string maSinhVien){
	
	for(ptrsv i = First; i != NULL; i = i->next){
		if(i->MSV.compare(maSinhVien) == 0) {
			return i;
		}	
	}
	return NULL;
}

bool kiemTraMaSinhVienTatCa(string maSinhVien, DSLop dsLop){
	for(int i = 0; i < dsLop.index; i++){
		ptrsv temp = dsLop.lop[i]->sv;
		if(kiemTraMaSinhVien(temp, maSinhVien) != NULL){
			return false;
		}
	}
	return true;
}

ptrsv laySVTruoc(Lop lop, ptrsv sv){
	if( lop.sv == NULL || sv == lop.sv){
		return NULL;
	}
	else{
		ptrsv temp = lop.sv;
		ptrsv beforeTemp = NULL;
		while(temp != sv){
			beforeTemp = temp;
			temp = temp->next;
		}
		return beforeTemp;
	}
}

void themSinhVien(ptrsv &danhSachSinhVien, SV sinhVien){ 
	ptrsv p = new SV;
	ptrsv last;
	if (danhSachSinhVien!=NULL ) 
    	for ( last = danhSachSinhVien ; last->next !=NULL; last=last->next) ;
	p->MSV = sinhVien.MSV;
	p->HO = sinhVien.HO;
	p->TEN = sinhVien.TEN;
	p->PHAI = sinhVien.PHAI;
	p->password = sinhVien.password;
	p->dsdiemthi = sinhVien.dsdiemthi;
	p->next = NULL;
	if(danhSachSinhVien == NULL) danhSachSinhVien = p;
	else last->next = p;
	last = p;
}

void lietKeDanhSachSinhVien(ptrsv First){
	string phai;
	ptrsv p = First;
	cout << "MSV  " << "Ho    "  << "Ten     " << "Phai  " << "PWD" << endl;
	for( p = First; p != NULL; p = p->next){
		phai = p->PHAI ? "Nam" : "Nu";
		cout << p->MSV << "  " << p->HO << "  " << p->TEN << " " << phai << " " << p->password << endl;
	}
	getch();
}

bool dangNhapSinhVien(ptrsv first, string msv, string password){ // nen luu pwd theo ma hoa
	ptrsv p = first;
	toUppercaseArray(msv);
	for( p = first; p != NULL; p = p->next){
		if(p->MSV.compare(msv) == 0 && p->password.compare(password) == 0) return true;
	}
	return false;
}

bool xoaSinhVien(string maLop, ptrsv first){
	ptrsv p; string maSinhVien;
	char keyPress;
xoaTiep:
	if(first == NULL){
		cout <<"danh sach rong" << endl;
		return false;
	}
	cout << "Nhap ma sinh vien muon xoa: ";
	fflush(stdin);
	getline(cin, maSinhVien); //chua bat chuoi rong, bat ki tu dac biet;
	//toUppercaseArray(maSinhVien);
	loaiBoKhoangTrangCuaChuoi(maSinhVien);
	 //xoa o dau danh sach
	if(first->MSV.compare(maSinhVien) == 0){
		ptrsv f = first;
		first = f->next;
		delete f;
		cout << "Bam 'y' de xoa tiep: " << endl;
		keyPress = getch();
		if(keyPress == 'y'){
			luuDanhSachSinhVienMoi(maLop, first);
			goto xoaTiep;
		}
		else{	
			luuDanhSachSinhVienMoi(maLop, first);
			return true;
		}
	}
	
	for(p = first; p->next != NULL && (p->next->MSV.compare(maSinhVien) != 0); p = p->next);
	if(p->next!=NULL){
		ptrsv q = p->next;
		p->next = q->next;
		delete q;
		cout << "Bam 'y' de xoa tiep: " << endl;
		keyPress = getch();
		if(keyPress == 'y'){
			luuDanhSachSinhVienMoi(maLop, first);
			goto xoaTiep;
		}
			
		else{	
			luuDanhSachSinhVienMoi(maLop, first);
			return true;
		}
			
	}else{
		cout << "Khong tim thay sinh vien muon xoa" << endl;
		return false;
	}
	return true;
}

bool xoaSinhVienCuaQ( Lop &lop, ptrsv current){
	string tenFile = current->MSV + ".txt";
	if(current == NULL){
		return false;
	}
	ptrsv before = laySVTruoc(lop, current);
	if( before == NULL){
		lop.sv = NULL;
		return true;
	}
	else{
		before->next = current->next;
		delete current;
	}
	if(remove(tenFile.c_str()) != 0){
		return false;
	}
	return true;
}

bool suaSinhVien(string maLop, string s_maSinhVien, string s_ho, string s_ten, bool s_phai, string s_password, ptrsv first){
	ptrsv p; string maSinhVien;
	char keyPress;
xoaTiep:
	if(first == NULL){
		cout <<"danh sach rong" << endl;
		return false;
	}
	cout << "Nhap ma sinh vien muon sua: ";
	fflush(stdin);
	getline(cin, maSinhVien); //chua bat chuoi rong, bat ki tu dac biet;
	//toUppercaseArray(maSinhVien);
	loaiBoKhoangTrangCuaChuoi(maSinhVien);
	 //xoa o dau danh sach
	if(first->MSV.compare(maSinhVien) == 0){
		first->MSV = s_maSinhVien;
		first->HO = s_ho;
		first->TEN = s_ten;
		first->PHAI = s_phai;
		first->password = s_password;
		cout << "Bam 'y' de sua tiep: " << endl;
		keyPress = getch();
		if(keyPress == 'y'){
			luuDanhSachSinhVienMoi(maLop, first);
			goto xoaTiep;
		}
		else{	
			luuDanhSachSinhVienMoi(maLop, first);
			return true;
		}
	}
	
	for(p = first; p->next != NULL && (p->next->MSV.compare(maSinhVien) != 0); p = p->next);
	if(p->next!=NULL){
		p->MSV = s_maSinhVien;
		p->HO = s_ho;
		p->TEN = s_ten;
		p->PHAI = s_phai;
		p->password = s_password;
		cout << "Bam 'y' de sua tiep: " << endl;
		keyPress = getch();
		if(keyPress == 'y'){
			luuDanhSachSinhVienMoi(maLop, first);
			goto xoaTiep;
		}
			
		else{	
			luuDanhSachSinhVienMoi(maLop, first);
			return true;
		}
			
	}else{
		cout << "Khong tim thay sinh vien muon sua" << endl;
		return false;
	}
	return true;
}

ptrDT layDTTruoc(SV sv, ptrDT dt){
	if( sv.dsdiemthi == NULL || dt == sv.dsdiemthi){
		return NULL;
	}
	else{
		ptrDT temp = sv.dsdiemthi;
		ptrDT beforeTemp = NULL;
		while(temp != dt){
			beforeTemp = temp;
			temp = temp->next;
		}
		return beforeTemp;
	}
}
// thao tac voi diem thi
bool themDiemThi(ptrDT &danhSachDiemThi, DT diemThi){
	ptrDT p, last;
	p = new DT;
	*p = diemThi; p->next = NULL;
	if(danhSachDiemThi != NULL)
		for(last = danhSachDiemThi; last->next != NULL; last = last->next);
	if(danhSachDiemThi == NULL) danhSachDiemThi = p;
	else last->next = p;
	last = p;
	return true;
}

void lietKeDanhSachDiemThi(ptrDT danhSachDiemThi){
	for(ptrDT p = danhSachDiemThi; p != NULL; p = p->next){
		cout << "ma mon hoc: " << p->MAMH << endl;
		cout << "diem: " << p->DIEM << endl;
		cout << "trang thai: " << p->TrangThai << endl;
		p->ThoiGianConLai.hienThiThoiGian();
		cout << "so cau: " << p->SoCau << endl;
		if(p->SoCau > 0){
			for(int i = 0; i < p->SoCau; i++){
				cout << "id cau hoi: " << p->DSCauHoi[i] <<  endl;
				cout << "dap an: " << p->DapAn[i] << endl;
			}
		}else cout << "sinh vien chua thi" << endl ;
		cout <<"---------------------" << endl;
	}
	
}

// bool luuDanhSachDiemThi(string maSinhVien, ptrDT danhSachDiemThi){
// 	string tenFile = maSinhVien + ".txt";	
// 	ofstream outfile(tenFile, ios::out | ios::binary);
// 	if(outfile == NULL){
// 		cout << "loi file";
// 		return false;
// 	}
// 	for(ptrDT p = danhSachDiemThi; p != NULL; p = p->next){
// 		outfile.write(p->MAMH.c_str(), p->MAMH.size());
// 		outfile.write("\0", sizeof(char));
// 		outfile.write((char*)&p->DIEM, sizeof(double));
// 		outfile.write((char*)&p->TrangThai, sizeof(bool));
// 		outfile.write((char*)&p->ThoiGianConLai.phut, sizeof(int));
// 		outfile.write((char*)&p->ThoiGianConLai.giay, sizeof(int));
// 		outfile.write((char*)&p->SoCau, sizeof(int));	
// 		if(p->SoCau > 0){	// da thi		
// 			for(int i = 0; i < p->SoCau; i++){
// 				outfile.write((char*)&(p->DSCauHoi[i]), sizeof(int));
// 				outfile.write((char*)&(p->DapAn[i]), sizeof(char));
// //				cout << "p->DSCauHoi[i]: " << p->DSCauHoi[i] << endl;
// //				cout << "p->DapAn[i]: " << p->DapAn[i] << endl;
// 			}
// 		}
// 	}
// }

ptrDT docDanhSachDiemThi(string maSinhVien){
	ptrDT danhSachDiemThi = NULL;
	DT diemThi;
	streampos size;
	string tenFile = maSinhVien + ".txt";
	ifstream infile(tenFile, ios::in | ios::binary | ios::ate);
	if(infile == NULL) {
		cout << "loi file";
		return danhSachDiemThi;
	}
	size = infile.tellg();
	infile.seekg (0, ios::beg);
	while(infile.tellg() != size){
		getline(infile, diemThi.MAMH, '\0');
		infile.read((char*)&diemThi.DIEM, sizeof(double));
		infile.read((char*)&diemThi.TrangThai, sizeof(int));
		infile.read((char*)&diemThi.ThoiGianConLai.phut, sizeof(int));
		infile.read((char*)&diemThi.ThoiGianConLai.giay, sizeof(int));
		infile.read((char*)&diemThi.SoCau, sizeof(int));
		if(diemThi.SoCau > 0){
			diemThi.DSCauHoi = new int[diemThi.SoCau];
			diemThi.DapAn = new char[diemThi.SoCau];
			for(int i = 0; i < diemThi.SoCau; i++){
				infile.read((char*)&diemThi.DSCauHoi[i], sizeof(int));
				infile.read((char*)&diemThi.DapAn[i], sizeof(char));
			}
		}
		themDiemThi(danhSachDiemThi, diemThi);
	}
	return danhSachDiemThi;
}

// thao tac voi mon hoc


bool luuDanhSachMonHoc(DSMonHoc danhSachMonHoc){
	ofstream outfile("danhSachMonHoc.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file";
		return false;
	}
	for(int i = 0; i < danhSachMonHoc.index; i++){
		outfile.write(danhSachMonHoc.ds[i]->MAMH.c_str(), danhSachMonHoc.ds[i]->MAMH.size());
		outfile.write("\0", sizeof(char));
		outfile.write(danhSachMonHoc.ds[i]->TENMH.c_str(), danhSachMonHoc.ds[i]->TENMH.size());
		outfile.write("\0", sizeof(char));
//		outfile.write((char*)&(danhSachMonHoc.ds[i]->ThoiGianThi.gio), sizeof(int));
//		outfile.write((char*)&(danhSachMonHoc.ds[i]->ThoiGianThi.phut), sizeof(int));
	}
}

void lietKeDanhSachMonHoc(DSMonHoc danhSachMonHoc){
	cout << "Ma mon hoc  " << "Ten mon hoc  " << "Thoi gian" << endl;
	for(int i = 0; i < danhSachMonHoc.index; i++){
		cout << danhSachMonHoc.ds[i]->MAMH << " " << danhSachMonHoc.ds[i]->TENMH << "  ";
//		danhSachMonHoc.ds[i]->ThoiGianThi.hienThiThoiGian();
		cout << endl;
	}
}

void themVaoMangConTroDSMonHoc(DSMonHoc &danhSachMonHoc, MonHoc mon){
	danhSachMonHoc.ds[danhSachMonHoc.index] = new MonHoc;
	*danhSachMonHoc.ds[danhSachMonHoc.index] = mon;
	danhSachMonHoc.index++;
}

DSMonHoc docDanhSachMonHoc(){
	streampos size;
	DSMonHoc danhSachMonHoc;
	MonHoc mon;
	ifstream infile("danhSachMonHoc.txt", ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "Loi file";
		exit(0);
	}
	size = infile.tellg();
	infile.seekg (0, ios::beg);
	while(infile.tellg() != size){
		getline(infile, mon.MAMH, '\0');
		getline(infile, mon.TENMH, '\0');
//		infile.read((char*)&mon.ThoiGianThi.gio, sizeof(int));
//		infile.read((char*)&mon.ThoiGianThi.phut, sizeof(int));
		themVaoMangConTroDSMonHoc(danhSachMonHoc, mon);
	}
	return danhSachMonHoc;
}

// bool themMonHoc(string maMonHoc, string tenMonHoc, DSMonHoc &dsMonHoc){
// 	// DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
// 	MonHoc monHoc;
// 	if(danhSachMonHoc.index == MAXMH){
// 		cout << "Danh sach mon hoc day";
// 		return false;
// 	}
// 	monHoc.MAMH = maMonHoc;
// 	monHoc.TENMH = tenMonHoc;
// //	themVaoMangConTroDSMonHoc(danhSachMonHoc, monHoc);
// 	luuDanhSachMonHoc(danhSachMonHoc);
// 	return true;
// }

int kiemTraMaMonHoc(string maMonHoc, DSMonHoc dsMonHoc){
	// DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
	for( int i = 0; i < dsMonHoc.index; i++){
		if(dsMonHoc.ds[i]->MAMH.compare(maMonHoc) == 0){
			return i;
		}
	}
	return -1;
}

bool themMonHocTheoThuTuMaMonHoc(DSMonHoc &danhSachMonHoc, MonHoc monHoc){
	int j;
	if(danhSachMonHoc.index == MAXMH) return false;
	for(j=0; (j < danhSachMonHoc.index) && (monHoc.MAMH.compare(danhSachMonHoc.ds[j]->MAMH) == 1); j++);
	for(int i = danhSachMonHoc.index-1; i >= j; i--)
		danhSachMonHoc.ds[i+1] = danhSachMonHoc.ds[i];
	danhSachMonHoc.ds[j] = new MonHoc;
	*danhSachMonHoc.ds[j] = monHoc;
	danhSachMonHoc.index++;
	return true;
}

//bool xoaMonHoc(string maMonHoc){
//	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
//	int viTri = kiemTraMaMonHoc(maMonHoc);
//	if( viTri == -1) {
//		cout << "Khong tim thay mon hoc";
//		return false;
//	}else{
//		delete danhSachMonHoc.ds[viTri];
//		for(int j = viTri+1; j < danhSachMonHoc.index; j++){
//			danhSachMonHoc.ds[j-1] = danhSachMonHoc.ds[j];
//		}		
//		danhSachMonHoc.index--;
//	}
//	//lietKeDanhSachMonHoc(danhSachMonHoc);
//	luuDanhSachMonHoc(danhSachMonHoc);
//	return true;
//}

bool suaMonHoc(string maMonHoc, string maMonHocMoi, string tenMonHocMoi, thoiGian thoiGianThiMoi){
//	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
//	MonHoc monHoc;
//	if(danhSachMonHoc.index == MAXMH){
//		cout << "Danh sach mon hoc day";
//		return false;
//	}
//	int viTri = kiemTraMaMonHoc(maMonHoc);
//	if(viTri == -1){
//		cout << "Khong tim thay ma mon hoc";
//		return false;
//	}
//	monHoc.MAMH = maMonHocMoi;
//	monHoc.TENMH = tenMonHocMoi;
////	monHoc.ThoiGianThi = thoiGianThiMoi;
//	// chinh sua thong tin trong danh sach mon hoc
//	danhSachMonHoc.ds[viTri]->MAMH = maMonHocMoi; 
//	danhSachMonHoc.ds[viTri]->TENMH = tenMonHocMoi;
////	danhSachMonHoc.ds[viTri]->ThoiGianThi = thoiGianThiMoi;
//	luuDanhSachMonHoc(danhSachMonHoc);
	return true;
}

//bool luuDanhSachMonHoc(DSMonHoc danhSachMonHoc){
//	ofstream outfile("danhSachMonHoc.txt", ios::out | ios::binary);
//	if(outfile == NULL){
//		cout << "Loi file";
//		return false;
//	}
//	for(int i = 0; i < danhSachMonHoc.index; i++){
//		outfile.write(danhSachMonHoc.ds[i]->MAMH.c_str(), danhSachMonHoc.ds[i]->MAMH.size());
//		outfile.write("\0", sizeof(char));
//		outfile.write(danhSachMonHoc.ds[i]->TENMH.c_str(), danhSachMonHoc.ds[i]->TENMH.size());
//		outfile.write("\0", sizeof(char));
////		outfile.write((char*)&(danhSachMonHoc.ds[i]->ThoiGianThi.gio), sizeof(int));
//		outfile.write((char*)&(danhSachMonHoc.ds[i]->ThoiGianThi.phut), sizeof(int));
//	}
//}
//
//void lietKeDanhSachMonHoc(DSMonHoc danhSachMonHoc){
//	cout << "Ma mon hoc  " << "Ten mon hoc  " << "Thoi gian" << endl;
//	for(int i = 0; i < danhSachMonHoc.index; i++){
//		cout << danhSachMonHoc.ds[i]->MAMH << " " << danhSachMonHoc.ds[i]->TENMH << "  ";
//		danhSachMonHoc.ds[i]->ThoiGianThi.hienThiThoiGian();
//		cout << endl;
//	}
//}
//
// void themVaoMangConTroDSMonHoc(DSMonHoc &danhSachMonHoc, MonHoc mon){
// 	danhSachMonHoc.ds[danhSachMonHoc.index] = new MonHoc;
// 	*danhSachMonHoc.ds[danhSachMonHoc.index] = mon;
// 	danhSachMonHoc.index++;
// }
//
//DSMonHoc docDanhSachMonHoc(){
//	streampos size;
//	DSMonHoc danhSachMonHoc;
//	MonHoc mon;
//	ifstream infile("danhSachMonHoc.txt", ios::in | ios::binary | ios::ate);
//	if(infile == NULL){
//		cout << "Loi file";
//		exit(0);
//	}
//	size = infile.tellg();
//	infile.seekg (0, ios::beg);
//	while(infile.tellg() != size){
//		getline(infile, mon.MAMH, '\0');
//		getline(infile, mon.TENMH, '\0');
//		themVaoMangConTroDSMonHoc(danhSachMonHoc, mon);
//	}
//	return danhSachMonHoc;
//}
//
//bool themMonHoc(string maMonHoc, string tenMonHoc, thoiGian thoiGianThi){
//	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
//	MonHoc monHoc;
//	if(danhSachMonHoc.index == MAXMH){
//		cout << "Danh sach mon hoc day";
//		return false;
//	}
//	monHoc.MAMH = maMonHoc;
//	monHoc.TENMH = tenMonHoc;
//	monHoc.ThoiGianThi = thoiGianThi;
//	themVaoMangConTroDSMonHoc(danhSachMonHoc, monHoc);
//	luuDanhSachMonHoc(danhSachMonHoc);
//	return true;
//}
//
//int kiemTraMaMonHoc(string maMonHoc){
//	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
//	for( int i = 0; i < danhSachMonHoc.index; i++){
//		if(danhSachMonHoc.ds[i]->MAMH.compare(maMonHoc) == 0){
//			return i;
//		}
//	}
//	return -1;
//}
//
//bool xoaMonHoc(string maMonHoc){
//	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
//	int viTri = kiemTraMaMonHoc(maMonHoc);
//	if( viTri == -1) {
//		cout << "Khong tim thay mon hoc";
//		return false;
//	}else{
//		delete danhSachMonHoc.ds[viTri];
//		for(int j = viTri+1; j < danhSachMonHoc.index; j++){
//			danhSachMonHoc.ds[j-1] = danhSachMonHoc.ds[j];
//		}		
//		danhSachMonHoc.index--;
//	}
//	//lietKeDanhSachMonHoc(danhSachMonHoc);
//	luuDanhSachMonHoc(danhSachMonHoc);
//	return true;
//}
//
//bool suaMonHoc(string maMonHoc, string maMonHocMoi, string tenMonHocMoi, thoiGian thoiGianThiMoi){
//	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
//	MonHoc monHoc;
//	if(danhSachMonHoc.index == MAXMH){
//		cout << "Danh sach mon hoc day";
//		return false;
//	}
//	int viTri = kiemTraMaMonHoc(maMonHoc);
//	if(viTri == -1){
//		cout << "Khong tim thay ma mon hoc";
//		return false;
//	}
//	monHoc.MAMH = maMonHocMoi;
//	monHoc.TENMH = tenMonHocMoi;
//	monHoc.ThoiGianThi = thoiGianThiMoi;
//	// chinh sua thong tin trong danh sach mon hoc
//	danhSachMonHoc.ds[viTri]->MAMH = maMonHocMoi; 
//	danhSachMonHoc.ds[viTri]->TENMH = tenMonHocMoi;
//	danhSachMonHoc.ds[viTri]->ThoiGianThi = thoiGianThiMoi;
//	luuDanhSachMonHoc(danhSachMonHoc);
//	return true;
//}

// cay nhi phan tim kiem - cau hoi

CauHoi taoCauHoiVoiIdNgauNhien(string maMonHoc, string noiDung, string a, string b, string c, string d, char dapAn){
	int random = generateArrayRandomNumber();
	CauHoi cauHoi;
	cauHoi.ID = random;
	cauHoi.MAMH = maMonHoc;
	cauHoi.NoiDung = noiDung;
	cauHoi.A = a;
	cauHoi.B = b;
	cauHoi.C = c;
	cauHoi.D = d;
	cauHoi.DapAn = dapAn;
	return cauHoi;
}

bool themCauHoiVaoCay(ptrDSCauHoi &danhSachCauHoi, CauHoi cauHoi){
	if(danhSachCauHoi == NULL){  // duyet den nut la
		danhSachCauHoi = new DSCauHoi;
		danhSachCauHoi->cauhoi = cauHoi; // nhap info
		danhSachCauHoi->left = NULL;
		danhSachCauHoi->right = NULL;
	}else if(cauHoi.ID < danhSachCauHoi->cauhoi.ID){ // id nho hon id nut dang xet thi xet qua trai cua nut dang xet
		themCauHoiVaoCay(danhSachCauHoi->left, cauHoi);
	}else if(cauHoi.ID > danhSachCauHoi->cauhoi.ID){
		themCauHoiVaoCay(danhSachCauHoi->right, cauHoi);
	}
}

void duyetTrungTu(ptrDSCauHoi &danhSachCauHoi){
	CauHoi mangCauHoi[MAXQUEST];
	int i = 0;
	const int STACKSIZE = 500;
	ptrDSCauHoi stack[STACKSIZE];
	ptrDSCauHoi p = danhSachCauHoi;
	int sp = -1; // con tro stack;
	do{
		while(p != NULL){
			stack[++sp] = p;
			p = p->left;
		}
		if(sp != -1){
			p = stack[sp--];
			mangCauHoi[i++] = p->cauhoi;
			p = p->right;
		}else
			break;
	}while(1);
}

void duyetTienTu(ptrDSCauHoi danhSachCauHoi){ // in danh sach câu hoi
	if(danhSachCauHoi != NULL){
		cout << "id: " << danhSachCauHoi->cauhoi.ID << endl;
		cout <<"MaMH: " << danhSachCauHoi->cauhoi.MAMH << endl;
		cout << "noi dung: " << danhSachCauHoi->cauhoi.NoiDung << endl;
		cout << "a: " << danhSachCauHoi->cauhoi.A << "  ";
		cout << "b: " << danhSachCauHoi->cauhoi.B << "  ";
		cout << "c: " << danhSachCauHoi->cauhoi.C << "  ";
		cout << "d: " << danhSachCauHoi->cauhoi.D << endl;
		cout << "dap an: " << danhSachCauHoi->cauhoi.DapAn << endl;
		cout << "=============================" << endl;
		duyetTienTu(danhSachCauHoi->left);
		duyetTienTu(danhSachCauHoi->right);
	}
}

void napCauHoiVaoMang(CauHoi mangCauHoi[]){
	streampos size;
	int i = 0;
	CauHoi cauHoi;
	// doc index trong file ngau nhien de biet co bao nhieu cau

	//---------------------------------------------------------------------||
	// cap phat mot mang tuyen tinh de chua cau hoi de dung cho viec lay ngau nhien cau hoi tu ds cau hoi
	ifstream infile("danhSachCauHoi.txt", ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "loi file";
		exit(0);
	}
	size = infile.tellg();
	infile.seekg (0, ios::beg);
	while(infile.tellg() != size){
		infile.read((char*)&cauHoi.ID, sizeof(int));
		getline(infile, cauHoi.MAMH, '\0');
		getline(infile, cauHoi.NoiDung, '\0');
		getline(infile, cauHoi.A, '\0');
		getline(infile, cauHoi.B, '\0');
		getline(infile, cauHoi.C, '\0');
		getline(infile, cauHoi.D, '\0');
		infile.read((char*)&cauHoi.DapAn, sizeof(char));
		mangCauHoi[i++] = cauHoi; 
	}
	return;
}

bool luuDanhSachCauHoi(ptrDSCauHoi danhSachCauHoi){
	const int STACKSIZE = 500;
	ptrDSCauHoi Stack[STACKSIZE];
	int sp = -1;
	ptrDSCauHoi p = danhSachCauHoi;
	ofstream outfile("danhSachCauHoi.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "loi file";
		return false;
	}
	while(p != NULL){
		outfile.write((char*)&p->cauhoi.ID, sizeof(int));
		
		outfile.write(p->cauhoi.MAMH.c_str(), p->cauhoi.MAMH.size());
		outfile.write((char*)"\0", sizeof(char));
		
		outfile.write(p->cauhoi.NoiDung.c_str(), p->cauhoi.NoiDung.size());
		outfile.write((char*)"\0", sizeof(char));
		
		outfile.write(p->cauhoi.A.c_str(), p->cauhoi.A.size());
		outfile.write((char*)"\0", sizeof(char));
		
		outfile.write(p->cauhoi.B.c_str(), p->cauhoi.B.size());
		outfile.write((char*)"\0", sizeof(char));
		
		outfile.write(p->cauhoi.C.c_str(), p->cauhoi.C.size());
		outfile.write((char*)"\0", sizeof(char));
		
		outfile.write(p->cauhoi.D.c_str(), p->cauhoi.D.size());
		outfile.write((char*)"\0", sizeof(char));
		
		outfile.write((char*)&p->cauhoi.DapAn, sizeof(char));
		
		if(p->right != NULL)
			Stack[++sp] = p->right;
		if(p->left != NULL)
			p= p->left;
		else if(sp == -1)
			break;
		else p = Stack[sp--];
	}
	outfile.close();
}

ptrDSCauHoi docDanhSachCauHoi(){
	streampos size;
	ptrDSCauHoi danhSachCauHoi = NULL;
	CauHoi cauHoi;
	ifstream infile("danhSachCauHoi.txt", ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "loi file";
		exit(0);
	}
	size = infile.tellg();
	infile.seekg (0, ios::beg);
	while(infile.tellg() != size){
		infile.read((char*)&cauHoi.ID, sizeof(int));
		
		getline(infile, cauHoi.MAMH, '\0');
		
		getline(infile, cauHoi.NoiDung, '\0');
		
		getline(infile, cauHoi.A, '\0');
		
		getline(infile, cauHoi.B, '\0');
		
		getline(infile, cauHoi.C, '\0');
		
		getline(infile, cauHoi.D, '\0');
		
		infile.read((char*)&cauHoi.DapAn, sizeof(char));
		
		themCauHoiVaoCay(danhSachCauHoi, cauHoi);
	}
	return danhSachCauHoi;
}

ptrDSCauHoi timKiemCauHoiTheoId(int id, ptrDSCauHoi p){
	while(p != NULL && id!= (p->cauhoi.ID) ){
		if(id < p->cauhoi.ID)
		{
			p = p->left;	
		}else{
			p = p->right;
		}
   }
	return p; 
}

void timKiemCauHoiTheoMaMonHoc(string maMonHoc, ptrDSCauHoi danhSachCauHoi, CauHoi danhSachCauHoiTheoMaMonHoc[] ){
	const int STACKSIZE = 500;
	ptrDSCauHoi Stack[STACKSIZE];
	int sp = -1, i = 0;
	ptrDSCauHoi p = danhSachCauHoi;
	while(p != NULL){
		if(maMonHoc.compare(p->cauhoi.MAMH) == 0){
			danhSachCauHoiTheoMaMonHoc[i++] = p->cauhoi;
		}
		if(p->right != NULL)
			Stack[++sp] = p->right;
		if(p->left != NULL)
			p= p->left;
		else if(sp == -1)
			break;
		else p = Stack[sp--];
	}
}

int timKiemCauHoiTheoMaMonHocInt(string maMonHoc, ptrDSCauHoi danhSachCauHoi ){
	const int STACKSIZE = 500;
	ptrDSCauHoi Stack[STACKSIZE];
	int sp = -1, i = 0;
	int cout = 0;
	ptrDSCauHoi p = danhSachCauHoi;
	while(p != NULL){
		if(maMonHoc.compare(p->cauhoi.MAMH) == 0){
			cout++;
		}
		if(p->right != NULL)
			Stack[++sp] = p->right;
		if(p->left != NULL)
			p= p->left;
		else if(sp == -1)
			break;
		else p = Stack[sp--];
	}
	return cout;
}
// VU
bool kiemTraMonSinhVienDaThi(string maSinhVien, string maMonHoc){
	ptrDT danhSachDiemThi = docDanhSachDiemThi(maSinhVien);
	for(ptrDT p = danhSachDiemThi; p != NULL; p = p->next){
		if(p->MAMH.compare(maMonHoc) == 0)
			return true;
	}
	return false;
}

bool xacNhan(int &thoiGianThi, int &giay){
	char c;
	while(thoiGianThi >= 0){
		if(kbhit()){
			c = getch();
			if(c == 121){
				return true;
			}else if(c == 110){
				return false;
			}
		}
        if(giay == 0){
        	thoiGianThi--;
        	if(thoiGianThi == -1){
        		gotoxy(40,28);
				cout << "------>HET THOI GIAN <------";
				break;
			}
        	giay = 60;
		}
		Sleep(1000);
        giay--; 
	}
	return true;
}
bool luuDanhSachDiemThi(string maSinhVien, ptrDT danhSachDiemThi){
	string tenFile = maSinhVien + ".txt";	
	ofstream outfile(tenFile, ios::out | ios::binary);
	if(outfile == NULL){
		cout << "loi file";
		return false;
	}
	for(ptrDT p = danhSachDiemThi; p != NULL; p = p->next){
		outfile.write(p->MAMH.c_str(), p->MAMH.size());
		outfile.write("\0", sizeof(char));
		outfile.write((char*)&p->DIEM, sizeof(double));
		outfile.write((char*)&p->TrangThai, sizeof(bool));
		outfile.write((char*)&p->ThoiGianConLai.phut, sizeof(int));
		outfile.write((char*)&p->ThoiGianConLai.giay, sizeof(int));
		outfile.write((char*)&p->SoCau, sizeof(int));	
		if(p->SoCau > 0){	// da thi		
			for(int i = 0; i < p->SoCau; i++){
				outfile.write((char*)&(p->DSCauHoi[i]), sizeof(int));
				outfile.write((char*)&(p->DapAn[i]), sizeof(char));
//				cout << "p->DSCauHoi[i]: " << p->DSCauHoi[i] << endl;
//				cout << "p->DapAn[i]: " << p->DapAn[i] << endl;
			}
		}
	}
}

void xoaManHinhTheoToaDo(string nd, string a, string b, string c, string d){
	gotoxy(40,12);
	cout << string(100, ' ');
	gotoxy(40,14);
	cout << string(100, ' ');
	gotoxy(40,16);
	cout << string(100, ' ');
	gotoxy(40,18);
	cout << string(100, ' ');
	gotoxy(40,20);
	cout << string(100, ' ');
}

ptrsv docDanhSachSinhVien(string maLop){
	ptrsv p;
	ptrsv danhSachSinhVien = NULL;
	ptrsv last = NULL;
	string tenFile = maLop + ".txt";
	streampos size;
	Lop lop;
	ifstream infile(tenFile , ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "Loi file" << endl;
		exit(0);
	}
	size = infile.tellg();
	infile.seekg (0, ios::beg);
	while(size != infile.tellg()){
		p = new SV;
		getline(infile, p->MSV, '\0');
		getline(infile, p->HO, '\0');
		getline(infile, p->TEN, '\0');
		infile.read((char*) &p->PHAI, sizeof(bool));
		getline(infile, p->password, '\0');
		p->next = NULL;
		if (danhSachSinhVien == NULL) {
			danhSachSinhVien = p;
		}
		else{
			last->next = p;
		}
		last = p;
	};
	infile.close();	
	return danhSachSinhVien;
}

ptrsv kiemTraMaSinhVien(string maSinhVien, 	DSLop dsLop){ //vu 11/8: sua tu co dinh "D17CQAT01" thanh doc danhsachsinhvien
	//toUppercaseArray(maSinhVien);
	for(int i = 0; i < dsLop.index; i++){
		if(isFileExist(dsLop.lop[i]->MALOP) == true){
			ptrsv First = docDanhSachSinhVien(dsLop.lop[i]->MALOP);
			for(ptrsv j = First; j != NULL; j = j->next){
				if(j->MSV.compare(maSinhVien) == 0){
					return j;
				}	
			}
		}
		
	}
	return NULL;
}

int *randomCauHoi(int arrayCauHoi[], int soCauHoi){ 
	int *randomResult = new int[soCauHoi];
	if(soCauHoi == (int) sizeof(arrayCauHoi)) return arrayCauHoi;
	else if(soCauHoi >  (int) sizeof(arrayCauHoi) || soCauHoi <= 0) return NULL;
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

int laySoLuongCauHoiCoSan(){
	ifstream docIndex("DSRandom.txt", ios::in | ios::binary);
	if(docIndex == NULL){
		cout << "Loi file" << endl;
		return -1;
	}
	int index;
	docIndex.read((char*) &index, sizeof(int));
	return index;
}

int timKiemCauHoiTheoMaMonHoc(string maMonHoc, CauHoi danhSachCauHoiTheoMaMonHoc[] ){
	const int STACKSIZE = 500;
	ptrDSCauHoi Stack[STACKSIZE];
	int sp = -1, soLuongCau = 0;
	ptrDSCauHoi p = docDanhSachCauHoi();
	while(p != NULL){
		if(maMonHoc.compare(p->cauhoi.MAMH) == 0){
			danhSachCauHoiTheoMaMonHoc[soLuongCau++] = p->cauhoi;
		}
		if(p->right != NULL)
			Stack[++sp] = p->right;
		if(p->left != NULL)
			p= p->left;
		else if(sp == -1)
			break;
		else p = Stack[sp--];
	}
	if(soLuongCau == 0){ // khong tim thay cau hoi thuoc ma mon hoc truyen vao
		return -1;
	}
	return soLuongCau;
}

int layNgauNhienCauHoi(CauHoi danhSachCauHoiDanhChoSinhVien[], int soCauHoi, string maMonHoc){
	
	int tongSoCauHoi = laySoLuongCauHoiCoSan();

	CauHoi danhSachCauHoiCuaMotMon[tongSoCauHoi];
	
	int soLuongCauCuaMotMon = timKiemCauHoiTheoMaMonHoc(maMonHoc, danhSachCauHoiCuaMotMon);

	if(soCauHoi > soLuongCauCuaMotMon) return soLuongCauCuaMotMon;
	
	if(soCauHoi == soLuongCauCuaMotMon){
		for(int i = 0; i < soCauHoi; i++){
			danhSachCauHoiDanhChoSinhVien[i] = danhSachCauHoiCuaMotMon[i];
		}
		return 1;
	}
	CauHoi temp;
	srand(time(NULL));
	for(int i = 0; i < soCauHoi; i++){
		int randomNumber = rand() % (soLuongCauCuaMotMon -i) + i;
		temp = danhSachCauHoiCuaMotMon[randomNumber];
		danhSachCauHoiCuaMotMon[randomNumber] = danhSachCauHoiCuaMotMon[i];
		danhSachCauHoiCuaMotMon[i] = temp;
		danhSachCauHoiDanhChoSinhVien[i] = temp;	
	}
	return 1;	
}


Lop* timKiemLop(string maLop){
	toUppercaseArray(maLop);
	DSLop danhSachLop = docDanhSachLop();
	for(int i = 0; i < danhSachLop.index; i++)
		if(danhSachLop.lop[i]->MALOP.compare(maLop) == 0)
			return danhSachLop.lop[i];
	return NULL;
}

bool luuDiem(DT diemThi, string maSinhVien){
	string tenFile = maSinhVien + ".txt";	
	ofstream outfile(tenFile, ios::out | ios::binary | ios::app);
	if(outfile == NULL){
		cout << "loi file";
		return false;
	}
		outfile.write(diemThi.MAMH.c_str(), diemThi.MAMH.size());
		outfile.write("\0", sizeof(char));
		outfile.write((char*)&diemThi.DIEM, sizeof(double));
		outfile.write((char*)&diemThi.TrangThai, sizeof(int));
		outfile.write((char*)&diemThi.ThoiGianConLai.phut, sizeof(int));
		outfile.write((char*)&diemThi.ThoiGianConLai.giay, sizeof(int));
		outfile.write((char*)&diemThi.SoCau, sizeof(int));			
		for(int i = 0; i < diemThi.SoCau; i++){
			outfile.write((char*)&(diemThi.DSCauHoi[i]), sizeof(int));
			outfile.write((char*)&(diemThi.DapAn[i]), sizeof(char));
		}
	return true;
}
int timKiemMonHocTheoMaMonHoc(string maMonHoc){
	DSMonHoc p = docDanhSachMonHoc();
	for(int i = 0; i < p.index; i++ ){
		if(maMonHoc.compare(p.ds[i]->MAMH) == 0){
			return i;
		}
	}
	return -1;
}
int tinhDiem(int* danhSachIdCauHoi, char* danhSachDapAn, int soLuongCau){
	int soCauDung = 0;
	CauHoi cauHoi;
	ptrDSCauHoi p = docDanhSachCauHoi();
	for(int i = 0; i < soLuongCau; i++){
		ptrDSCauHoi cauHoiTam= timKiemCauHoiTheoId(danhSachIdCauHoi[i], p);
		cauHoi = cauHoiTam->cauhoi;
		if(cauHoi.DapAn == danhSachDapAn[i]) soCauDung++;
			
	}
	return soCauDung;
}

bool themMonHoc(DSMonHoc &danhSachMonHoc, MonHoc monHoc){
	if(danhSachMonHoc.index == MAXMH){
		cout << "Danh sach mon hoc day";
		return false;
	}
	danhSachMonHoc.ds[danhSachMonHoc.index] = new MonHoc;
	*danhSachMonHoc.ds[danhSachMonHoc.index] = monHoc;
	danhSachMonHoc.index++;
	return true;
}
bool demNguoc(int phut){
    int giay = 0;
	while (phut >= 0)
    {
    	cout << "\r";
    	cout << setfill('0') << setw(2) << phut << ":";
		cout << setfill('0') << setw(2) << giay;		
        Sleep(1000);
        if(giay == 0){
        	phut--;
        	giay = 60;
		}
        giay--;
        
    }
    return false;
}

bool isFileExist(string tenFile){
	string ten = tenFile + ".txt";
	ifstream infile(ten, ios::in | ios::binary | ios::ate);
	streampos size = infile.tellg();
	if(size == 0) return false;
	return true;
}

bool dangNhap(string maSinhVien, string password){	
	DSLop danhSachLop = docDanhSachLop();
	ptrsv danhSachSinhVien;
	for(int i = 0; i < danhSachLop.index; i++){
		if(isFileExist(danhSachLop.lop[i]->MALOP) == true){
			danhSachSinhVien = docDanhSachSinhVien(danhSachLop.lop[i]->MALOP);
			for(ptrsv i = danhSachSinhVien; i != NULL; i = i->next){
				if(i->MSV.compare(maSinhVien) == 0 && i->password.compare(password) == 0){
					return true;
				}
				
			}
		}
	}
	return false;
}

bool luuSinhVienDangThi(string maSinhVien, DT diemThi){
	ofstream outfile("sinhVienDangThi.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "loi file";
		return false;
	}
	// luu ma sinh vien
	outfile.write(maSinhVien.c_str(), maSinhVien.size());
	outfile.write("\0", sizeof(char));
	// luu thong tin lop
//	outfile.write(lop->MALOP.c_str(), lop->MALOP.size());
//	outfile.write("\0", sizeof(char));
//	outfile.write(lop->TENLOP.c_str(), lop->TENLOP.size());	
//	outfile.write("\0", sizeof(char));
//	outfile.write(lop->NK.c_str(), lop->NK.size());	
//	outfile.write("\0", sizeof(char));
	// luu diem thi
	outfile.write(diemThi.MAMH.c_str(), diemThi.MAMH.size());
	outfile.write("\0", sizeof(char));
	outfile.write((char*)&diemThi.TrangThai, sizeof(int));
	outfile.write((char*)&diemThi.ThoiGianConLai.phut, sizeof(int));
	outfile.write((char*)&diemThi.ThoiGianConLai.giay, sizeof(int));
	outfile.write((char*)&diemThi.SoCau, sizeof(int));			
	for(int i = 0; i < diemThi.SoCau; i++){
		outfile.write((char*)&(diemThi.DSCauHoi[i]), sizeof(int));
		outfile.write((char*)&(diemThi.DapAn[i]), sizeof(char));
	}
	outfile.close();
	return true;
}

void docSinhVienDangThi(string &maSinhVien, DT &diemThi){
	ifstream infile("sinhVienDangThi.txt", ios::in | ios::binary);
	if(infile == NULL) {
		cout << "loi file";
		return;
	}
	getline(infile, maSinhVien, '\0');
	getline(infile, diemThi.MAMH, '\0');
	infile.read((char*)&diemThi.TrangThai, sizeof(int));
	infile.read((char*)&diemThi.ThoiGianConLai.phut, sizeof(int));
	infile.read((char*)&diemThi.ThoiGianConLai.giay, sizeof(int));
	infile.read((char*)&diemThi.SoCau, sizeof(int));
	if(diemThi.SoCau > 0){
		diemThi.DSCauHoi = new int[diemThi.SoCau];
		diemThi.DapAn = new char[diemThi.SoCau];
		for(int i = 0; i < diemThi.SoCau; i++){
			infile.read((char*)&diemThi.DSCauHoi[i], sizeof(int));
			infile.read((char*)&diemThi.DapAn[i], sizeof(char));
		}
	}
	infile.close();
	return;
}
void cleanContenAboutInterrupt(){
	ofstream outfile("sinhVienDangThi.txt", ios::out | ios::binary | ios::trunc);
	if(outfile == NULL){
		cout << "loi file";
		return;
	}
	outfile.close();
	return;
}
// thoi gian doc lap
char inToA(int k) {
	switch (k)
	{
	case 0:return '0';
	case 1:return '1';
	case 2:return '2';
	case 3:return '3';
	case 4:return '4';
	case 5:return '5';
	case 6:return '6';
	case 7:return '7';
	case 8:return '8';
	case 9:return '9';
	default:
		break;
	}
}

void insertarray(char *h, Hour j) {
	int bait = 0;
	bait = j.second;
	h[7] = inToA(bait % 10);
	h[6] = inToA(bait /= 10);

	bait = j.minute;
	h[4] = inToA(bait % 10);
	h[3] = inToA(bait /= 10);

	bait = j.hour;
	h[1] = inToA(bait % 10);
	h[0] = inToA(bait /= 10);

}

bool changetime(Hour &h) {
	if (h.second > 0) --h.second;
	else if (h.minute > 0) {
		h.second = 59;
		--h.minute;
	}
	else if (h.hour > 0)
	{
		--h.hour;
		h.minute = 59;
		h.second = 59;
	}
	else return 0;
	return 1;
}

//dung de in ra mot chuoi thay the ham cout
void WriteBlockChar(char * Arraych,	int row, int col, int x, int y, int color)
{
	CHAR_INFO *charater = new CHAR_INFO[row*col];
	for (int i = 0; i < row*col; i++) {
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = { col,row };
	COORD pos = { 0,0 };
	SMALL_RECT earea = { x,y,x + col - 1,y + row - 1 };
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}

void printClock(Hour &h) {
		char a[8] = { '0','0',':','0','0',':','0','0'};
		while (stop)
		{
			if (!changetime(h)) stop = 0;
			insertarray(a, h);
			WriteBlockChar(a, 1, 8, 12, 5, 0x004|0x060);
			Sleep(900);
		}

		return;
}

void close(DWORD evt) {
	if (evt == CTRL_CLOSE_EVENT) stop = 0;
}

Lop* timLopTheoMaSinhVien(string maSinhVien, DSLop dsLop){
	for(int i = 0; i < dsLop.index; i++){
		if(isFileExist(dsLop.lop[i]->MALOP) == true){
			ptrsv First = docDanhSachSinhVien(dsLop.lop[i]->MALOP);
			for(ptrsv j = First; j != NULL; j = j->next){
				if(j->MSV.compare(maSinhVien) == 0){
					return dsLop.lop[i];
				}	
			}
		}
	}
	return NULL;
}

bool kiemTraSinhVienThiLai(string maSinhVien){
	string maSinhVienTiepTucThi;
	ifstream infile("sinhVienDangThi.txt", ios::in | ios::binary);
	if(infile == NULL) {
		cout << "loi file";
		return false;
	}
	getline(infile, maSinhVienTiepTucThi, '\0');
	infile.close();
	if(maSinhVien.compare(maSinhVienTiepTucThi) == 0) return true;
	return false;
}
#endif
