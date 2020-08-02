#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <regex>
#include <C:\Users\trand\OneDrive\Máy tính\CTDL\Structure.h> 
#include <iomanip> 
#include <unistd.h> 
//#include "GUI.h"
using namespace std;

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
	int index = 0; // sua tu index = 1 sang 0;
	outfile.write((char*) &index, sizeof(int));
	for(int i = 0; i < MAXQUEST; i++){
		outfile.write((char*)&arrayRandomNumber[i], sizeof(int));
	}
	outfile.close();
}
// random 
int generateArrayRandomNumber(){	
	streampos size;										
	int arrayRandomNumber[MAXQUEST];
	ifstream infile("DSRandom.txt", ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "Loi file" << endl;
		return -1;
	}
	size = infile.tellg(); // ?????
	infile.seekg(0, ios::beg);
	int index;
	infile.read((char*) &index, sizeof(int));
	if(index == MAXQUEST) return -1; // dùng het
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

//bool luuLopVaoCuoiFile(Lop lop){ // them ve phia sau
//	ofstream outfile("danhSachLop.txt", ios::out| ios::app | ios::binary);
//	if(outfile == NULL){
//		cout << "Loi file" << endl;
//		return false;
//	}
//	outfile.write(lop.MALOP.c_str(), lop.MALOP.size());
//	outfile.write("\0", sizeof(char));
//	outfile.write(lop.TENLOP.c_str(), lop.TENLOP.size());
//	outfile.write("\0", sizeof(char));
//	outfile.write(lop.NK.c_str(), lop.NK.size());
//	outfile.write("\0", sizeof(char));
//			
//	outfile.close();
//	return true;	
//}

bool luuDanhSachLop(DSLop danhSachLop){ // ghi de len file cu
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

bool themLop(DSLop &danhSachLop, Lop lop){
	if(danhSachLop.index == MAXLOP){
		cout << "danh sach day" << endl;
		return false;
	}
	danhSachLop.lop[danhSachLop.index] = new Lop;
	*danhSachLop.lop[danhSachLop.index] = lop;
	danhSachLop.index++;
	return true;	
}

void showClass(DSLop classList){
	cout << "                     DANH SACH LOP " << endl ;
	cout <<"MaLop       Tenlop           Nien khoa" << endl;
	for (int i =0 ; i < classList.index ; i++){
		cout << classList.lop[i]->MALOP << "       " << classList.lop[i]->TENLOP << "      " 
		<<  classList.lop[i]->NK << endl;
	}
}

bool xoaLop(string maLop){
	DSLop danhSachLop = docDanhSachLop();
	int i = checkMaLop(danhSachLop, maLop);
	if(i == -1){
		 cout << "Khong tim thay lop";
		 return false;
	}
	else{
		delete danhSachLop.lop[i];
		for(int j = i+1; j < danhSachLop.index; j++){
			danhSachLop.lop[j-1] = danhSachLop.lop[j];
		}
		
		danhSachLop.index--;
	}
	luuDanhSachLop(danhSachLop); // xoa xong ghi de len file cu danh sach lop moi nay vo
	return true;
}

bool inDanhSachLopTheoNienKhoa(DSLop danhSachLop, string &nienKhoa){
	if(kiemTraCuPhapNienKhoa(nienKhoa) == false){
		cout << "cu phap khong hop le" << endl;
		return false;
	}
	bool timThayLop = false;
	for(int i = 0; i < danhSachLop.index; i++){
		if(nienKhoa.compare(danhSachLop.lop[i]->NK) == 0){
			timThayLop = true;
			inThongTinLop(danhSachLop.lop[i]);
		}
	}
	if(timThayLop == false) { // tu dong cho nguoi dung tim kiem lai
		cout << "Khong tim thay lop" << endl;
		return false;
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
	luuDanhSachLop(danhSachLop);
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

bool luuDanhSachSinhVien(string maLop, ptrsv danhSachSinhVien){
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

ptrsv kiemTraMaSinhVien(string maSinhVien){
	//toUppercaseArray(maSinhVien);
	DSLop dsl = docDanhSachLop();
	ptrsv First = docDanhSachSinhVien("D17CQAT01");
	for(ptrsv i = First; i != NULL; i = i->next){
		if(i->MSV.compare(maSinhVien) == 0) {
			return i;
		}	
	}
	return NULL;
}

bool themSinhVien(ptrsv &danhSachSinhVien, SV sinhVien){ 
	ptrsv p = new SV;
	ptrsv last;
//	p->MSV = sinhVien.MSV;
//	p->HO = sinhVien.HO;
//	p->TEN = sinhVien.TEN;
//	p->PHAI = sinhVien.PHAI;
//	p->password = sinhVien.password;
//	p->dsdiemthi = sinhVien.dsdiemthi;
	*p = sinhVien;
	p->next = NULL;
	if(danhSachSinhVien == NULL) danhSachSinhVien = p;
	else last->next = p;
	last = p;
}


void lietKeDanhSachSinhVien(ptrsv First){
	string phai;
	ptrsv p = First;
	cout << "MSV  " << "         Ho    "  << "Ten     " << "Phai  " << "PWD" << endl;
	for( p = First; p != NULL; p = p->next){
		phai = p->PHAI ? "Nam" : "Nu";
		cout << p->MSV << "  " << p->HO << "  " << p->TEN << " " << phai << " " << p->password << endl;
	}
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
			luuDanhSachSinhVien(maLop, first);
			goto xoaTiep;
		}
		else{	
			luuDanhSachSinhVien(maLop, first);
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
			luuDanhSachSinhVien(maLop, first);
			goto xoaTiep;
		}
			
		else{	
			luuDanhSachSinhVien(maLop, first);
			return true;
		}
			
	}else{
		cout << "Khong tim thay sinh vien muon xoa" << endl;
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
			luuDanhSachSinhVien(maLop, first);
			goto xoaTiep;
		}
		else{	
			luuDanhSachSinhVien(maLop, first);
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
			luuDanhSachSinhVien(maLop, first);
			goto xoaTiep;
		}
			
		else{	
			luuDanhSachSinhVien(maLop, first);
			return true;
		}
			
	}else{
		cout << "Khong tim thay sinh vien muon sua" << endl;
		return false;
	}
	return true;
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
	}
}

void lietKeDanhSachMonHoc(DSMonHoc danhSachMonHoc){
	cout << "Ma mon hoc  " << "Ten mon hoc  " << "Thoi gian" << endl;
	for(int i = 0; i < danhSachMonHoc.index; i++){
		cout << danhSachMonHoc.ds[i]->MAMH << " " << danhSachMonHoc.ds[i]->TENMH << "  ";
		cout << endl;
	}
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
		themMonHoc(danhSachMonHoc, mon);
	}
	return danhSachMonHoc;
}

int kiemTraMaMonHoc(string maMonHoc){
	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
	for( int i = 0; i < danhSachMonHoc.index; i++){
		if(danhSachMonHoc.ds[i]->MAMH.compare(maMonHoc) == 0){
			return i;
		}
	}
	return -1;
}

bool xoaMonHoc(string maMonHoc){
	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
	int viTri = kiemTraMaMonHoc(maMonHoc);
	if( viTri == -1) {
		cout << "Khong tim thay mon hoc";
		return false;
	}else{
		delete danhSachMonHoc.ds[viTri];
		for(int j = viTri+1; j < danhSachMonHoc.index; j++){
			danhSachMonHoc.ds[j-1] = danhSachMonHoc.ds[j];
		}		
		danhSachMonHoc.index--;
	}
	//lietKeDanhSachMonHoc(danhSachMonHoc);
	luuDanhSachMonHoc(danhSachMonHoc);
	return true;
}

bool suaMonHoc(string maMonHoc, string maMonHocMoi, string tenMonHocMoi){
	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
	MonHoc monHoc;
	if(danhSachMonHoc.index == MAXMH){
		cout << "Danh sach mon hoc day";
		return false;
	}
	int viTri = kiemTraMaMonHoc(maMonHoc);
	if(viTri == -1){
		cout << "Khong tim thay ma mon hoc";
		return false;
	}
	monHoc.MAMH = maMonHocMoi;
	monHoc.TENMH = tenMonHocMoi;

	// chinh sua thong tin trong danh sach mon hoc
	danhSachMonHoc.ds[viTri]->MAMH = maMonHocMoi; 
	danhSachMonHoc.ds[viTri]->TENMH = tenMonHocMoi;
	luuDanhSachMonHoc(danhSachMonHoc);
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

bool themMonHocTheoThuTuMaMonHoc(DSMonHoc &danhSachMonHoc, MonHoc monHoc){
	int j;
	if(danhSachMonHoc.index == MAXMH) return false;
	for(j=0; j < danhSachMonHoc.index && monHoc.MAMH.compare(danhSachMonHoc.ds[j]->MAMH) == 1; j++);
	for(int i = danhSachMonHoc.index-1; i >= j; i--)
		danhSachMonHoc.ds[i+1] = danhSachMonHoc.ds[i];
	danhSachMonHoc.ds[j] = new MonHoc;
	*danhSachMonHoc.ds[j] = monHoc;
	danhSachMonHoc.index++;
	return true;
}
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
	ofstream outfile("danhSachCauHoi.txt", ios::out | ios::app | ios::binary );
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
		infile.read((char*)&diemThi.TrangThai, sizeof(bool));
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



// thi trac ngiem

bool demNguoc(int phut){
    int giay = 0;
	while (phut >= 0)
    {
    	cout << "\r";
    	cout << setfill('0') << setw(2) << phut << ":";
		cout << setfill('0') << setw(2) << giay;		
        sleep(1);
        if(giay == 0){
        	phut--;
        	giay = 60;
		}
        giay--;
        
    }
    return false;
}

int tinhDiem(int* danhSachIdCauHoi, char* danhSachDapAn, int soLuongCau){
	int soCauDung = 0;
	CauHoi cauHoi;
	ptrDSCauHoi p = docDanhSachCauHoi();
	for(int i = 0; i < soLuongCau; i++){
		ptrDSCauHoi cauHoiTam= timKiemCauHoiTheoId(danhSachIdCauHoi[i], p);
		cauHoi = cauHoiTam->cauhoi;
		if(cauHoi.DapAn == danhSachDapAn[i])
			soCauDung++;
	}
	return soCauDung;
}




//void thiTracNghiem(string maSinhVien, string maMonHoc ,int thoiGianThi, int soCauHoi){
//	DT diemThi;
//	diemThi.DSCauHoi = new int[soCauHoi];
//	diemThi.DapAn = new char[soCauHoi];
//	diemThi.TrangThai = 1; // 1 la dang thi
//	int viTriMonHoc = timKiemMonHocTheoMaMonHoc(maMonHoc);
//	DSMonHoc dsmh = docDanhSachMonHoc();
//	// lay danh sach cau hoi
//	ifstream docIndex("DSRandom.txt", ios::in | ios::binary);
//	if(docIndex == NULL){
//		cout << "Loi file" << endl;
//	}
//	int index;
//	docIndex.read((char*) &index, sizeof(int));
//	CauHoi mangCauHoi[index];
//	napCauHoiVaoMang(mangCauHoi);
//	// nap id cau hoi vao danh sach cau hoi dung cho viec tinh diem 
//	for(int i = 0; i < soCauHoi; i++){
//		diemThi.DSCauHoi[i] = mangCauHoi[i].ID;
//	}
//	
//	
//	//luu dap an
//	int ch; // luu dap an sinh vien chon
//	int indexDapAn = 0; // vi tri dap an tuong ung cau hoi ma sinh vien da chon
//	int indexCauHoi = 0; // vi tri cau hoi khi nhan phim -> va <-
//	// thoi gian
//	int giay = 0;
//	cout << "------------BAI THI TRAC NGHIEM---------------" << endl;
//			
//		cout << "MON:     " << dsmh.ds[viTriMonHoc]->TENMH << endl; 
//		cout << "---- Cau hoi trac nghiem: " << endl;
//		cout << "Cau " << indexCauHoi+1 << ": " << mangCauHoi[indexCauHoi].NoiDung << endl;
//		cout << "a. " << mangCauHoi[indexCauHoi].A << "  b. " << mangCauHoi[indexCauHoi].B << "  c. " 
//		<< mangCauHoi[indexCauHoi].C << " d. " << mangCauHoi[indexCauHoi].D << endl;
//		cout << "Dap an cua ban la: ";
//	while (thoiGianThi >= 0)
//    {
//    	gotoxy(50,20);
//    	setcursor(0,0);
//    	cout << setfill('0') << setw(2) << thoiGianThi << ":";
//		cout << setfill('0') << setw(2) << giay;
//		
//		if(kbhit()){
//			ch = getch();
//			if(ch >= 97 && ch <= 100){
//				gotoxy(20,47);
//				setcursor(1,1);
//				cout << (char)ch;
//				setcursor(0,0);
//				diemThi.DapAn[indexDapAn++] = (char)ch;
//			}else if(ch == 13){ // xac nhan thi xong
//					if(indexDapAn < soCauHoi-1){
//						while(indexDapAn != (soCauHoi-1)){
//							diemThi.DapAn[indexDapAn++] = 'n';
//						}
//					}
//					diemThi.TrangThai = 2; // da thi xong
//					thoiGianThi = -1;
//				}
//			if (ch == 0 || ch == 224){
//				ch = getch();
//				if(ch == 77 && indexCauHoi < soCauHoi-1){ // key_right
//					indexCauHoi++;
//					gotoxy(5,52);
//					cout << "Cau " << indexCauHoi+1 << ": " << mangCauHoi[indexCauHoi].NoiDung << endl;
//					cout << "a. " << mangCauHoi[indexCauHoi].A << "  b. " << mangCauHoi[indexCauHoi].B << "  c. " 
//					<< mangCauHoi[indexCauHoi].C << " d. " << mangCauHoi[indexCauHoi].D << endl;
//				}else if(ch == 75 && indexCauHoi > 0){// key_left
//					indexCauHoi--;
//					gotoxy(5,52); // ghi de len cau hoi 
//					cout << "Cau " << indexCauHoi+1 << ": " << mangCauHoi[indexCauHoi].NoiDung << endl;
//					cout << "a. " << mangCauHoi[indexCauHoi].A << "  b. " << mangCauHoi[indexCauHoi].B << "  c. " 
//					<< mangCauHoi[indexCauHoi].C << " d. " << mangCauHoi[indexCauHoi].D << endl;
//				}
//			}
//		}
//        sleep(1);
//        if(giay == 0){
//        	thoiGianThi--;
//        	giay = 60;
//		}
//        giay--;  
//    }
//    // tinh diem cho sinh vien
//    const float soDiemCuaMotCau = 10/soCauHoi;
//	int soCauDung = tinhDiem(diemThi.DSCauHoi, diemThi.DapAn, soCauHoi);
//	gotoxy(5,55);
//	cout << "Diem cua ban la: " << soCauDung*soDiemCuaMotCau;
//	// luu diem cua sinh vien vao file
//	ptrDT danhSachDiemThi = NULL;
//	themDiemThi(danhSachDiemThi, diemThi);
//	luuDanhSachDiemThi(maSinhVien, danhSachDiemThi);
//}
int main(){
//	CauHoi danhSachCauHoiTheoMaMonHoc[500];
//	timKiemCauHoiTheoMaMonHoc("INT1154", docDanhSachCauHoi(), danhSachCauHoiTheoMaMonHoc);
//	cout << danhSachCauHoiTheoMaMonHoc[0].NoiDung << endl;
//	cout << danhSachCauHoiTheoMaMonHoc[1].NoiDung<< endl;
//	cout << danhSachCauHoiTheoMaMonHoc[2].NoiDung<< endl;
//	cout << danhSachCauHoiTheoMaMonHoc[3].NoiDung<< endl;
//	cout << danhSachCauHoiTheoMaMonHoc[4].NoiDung<< endl;
//	DSLop danhSachLop;
//	Lop lop1 = {"D17CQAT01", "An toan thong tin", "2017-2022", NULL};
//	Lop lop2 = {"D17CQCN02", "Cong nghe thong tin", "2015-2020", NULL};
//	Lop lop3 = {"D17CQKT01", "Kinh te", "2017-2022", NULL};
//	themLop(danhSachLop, lop1);
//	themLop(danhSachLop, lop2);
//	themLop(danhSachLop, lop3);
//	luuDanhSachLop(danhSachLop);
//		showClass(docDanhSachLop());	// test doc danh sach lop tu file
//	xoaLop("d17ptit");				// test xoa file

//	suaThongTinLop("d17cqat");	     // test sua thong tin lop
	// thao tac voi sinh vien
	
//	DSLop danhSachLop = docDanhSachLop();
//	showClass(docDanhSachLop());
//	string maLop;
//	int viTri;
//	while(1){
//		cout << "Nhap ma lop: ";
//		cin >> maLop;
//		viTri = checkMaLop(danhSachLop, maLop);
//		if(viTri == -1 ) {
//			cout << "lop khong ton tai";
//		}else break;
//	}
//	lietKeDanhSachSinhVien(docSinhVien(danhSachLop.lop[viTri]->MALOP));
	//cout << "------------------D17CQAT01----------------------------------------" << endl;
//	ptrsv dsat = NULL;
//	SV at1 = {"N17DCAT079", "tran", "dang vu", 1, "vu", NULL};
//	SV at2 = {"N17DCAT049", "nguyen", "hoang thong", 1, "thong", NULL};
//	SV at3 = {"N17DCAT089", "hoang", "my nhu", 0, "nhu", NULL};
//	SV at4 = {"N17DCAT015", "do", "anh quan", 1, "quan", NULL};
//	themSinhVien(dsat, at1);
//	themSinhVien(dsat, at2);
//	themSinhVien(dsat, at3);
//	themSinhVien(dsat, at4);
//	luuDanhSachSinhVien("D17CQAT01", dsat);	
//		lietKeDanhSachSinhVien(docDanhSachSinhVien("D17CQAT01"));
	//xoaSinhVien(danhSachLop.lop[viTri]->MALOP, docSinhVien(danhSachLop.lop[viTri]->MALOP));  // test xoa sinh viên
	
//	suaSinhVien(danhSachLop.lop[viTri]->MALOP,"n17cqat069", "nguyen", "minh beo", true, "fffff",
	
//	lietKeDanhSachSinhVien(docSinhVien(danhSachLop.lop[viTri]->MALOP));  // test sua thong tin sinh vien

//==================================== mon hoc =====//
// test thêm môn hoc
//	thoiGian thoiGianThi1;
//	thoiGianThi1.phut = 14;
//	thoiGianThi1.giay = 60;
//	thoiGian thoiGianThi2;
//	thoiGianThi2.phut = 29;
//	thoiGianThi2.giay = 60;
//	thoiGian thoiGianThi3;
//	thoiGianThi3.phut = 49;
//	thoiGianThi3.giay = 60;
//	thoiGian thoiGianThi4;
//	thoiGianThi4.phut = 44;
//	thoiGianThi4.giay = 60;
//	MonHoc mh1 = {"INT1154", "Tin hoc co so 1"};
//	MonHoc mh2= { "BAS1106", "Giao duc the chat 1"};
//	MonHoc mh3= {"ELE1433", "Ky thuat so"};
//	MonHoc mh4= {"SKD1108", "Phuong phap luan "};
//	DSMonHoc dsmh;	
//	themMonHoc(dsmh, mh1);
//	themMonHoc(dsmh, mh2);
//	themMonHoc(dsmh, mh3);
//	themMonHoc(dsmh, mh4);
//
//	luuDanhSachMonHoc(dsmh);
//	xoaMonHoc("SKD1108"); // test xoa mon hoc
//	suaMonHoc("BAS1106", "BAS1107", "Giao duc the thao", thoiGianThi3); // test sua mon hoc
	//	cout << "---------------Danh sach mon hoc--------------" << endl;
	//	lietKeDanhSachMonHoc(docDanhSachMonHoc());
	
	// duyet cau hoi
//	CauHoi cauHoi1 = taoCauHoiVoiIdNgauNhien("INT1154","He thong nho cua may tinh bao gom ?","Bo nho trong, bo nho ngoai","cache, bo nho ngoai","Bo nho ngoai, rom","dia quang, bo nho trong",'a');
//	CauHoi cauHoi2 = taoCauHoiVoiIdNgauNhien("INT1154","Bo nho RAM va ROM la bo nho gi","Primary memory","Receive memory","Secondary memory","Random access memory",'a');
//	CauHoi cauHoi3 = taoCauHoiVoiIdNgauNhien("INT1154","Thiet bi nao sau day dung de ket noi mang","Ram","Rom","Router","CPU",'c');
//	CauHoi cauHoi4 = taoCauHoiVoiIdNgauNhien("INT1154","Dich vu luu tru dam may cua Microsoft la gi","Google Driver","Mediafire","OneDrive","Ca 3 dap an",'d');
//	CauHoi cauHoi5 = taoCauHoiVoiIdNgauNhien("INT1154","Trong Excel ham nao sau day dung de tim kiem","IF","Vlookup","left","sum",'b');
//	
//	CauHoi cauHoi6 = taoCauHoiVoiIdNgauNhien("INT1154","Cong dung cua phim Print Screen","quay video man hinh","chup man hinh","tat may tinh","khoi dong lai may",'b');
//	CauHoi cauHoi7 = taoCauHoiVoiIdNgauNhien("INT1154","Trong Word, to hop phim nao cho phep dua con tro ve cuoi file"," Shift + End","Alt + End ","Alt + End ","Ctrl + Alt + End",'c');
//	CauHoi cauHoi8 = taoCauHoiVoiIdNgauNhien("INT1154","Thiet bi nao sau day dung de ket noi mang","ram","rom","router","cpu",'c');
//	CauHoi cauHoi9 = taoCauHoiVoiIdNgauNhien("INT1154","Danh sach cac muc chon trong muc don","Menu pad","Menu options","Menu bar","tat ca deu si",'c');
//	CauHoi cauHoi10 = taoCauHoiVoiIdNgauNhien("INT1154","Trong may tinh thuat ngu share co nghia la gi","chia se tai nguyen","Nhan hieu thiet bi ket noi","Lenh in trong mang cuc bo","phan mem ho tro mang cuc bo",'a');
//
//	CauHoi cauHoi6 = taoCauHoiVoiIdNgauNhien("BAS1106","Thoi gian tot nhat de tap the duc?","sang","trua","chieu","toi",'a');
//	CauHoi cauHoi7 = taoCauHoiVoiIdNgauNhien("BAS1106","Mot ngay nen van dong toi thieu bao nhieu phut","15","25","30","60",'b');
//	CauHoi cauHoi8 = taoCauHoiVoiIdNgauNhien("BAS1106","Ai la nguoi doat huan chuong vang 10m ngan tai Rio 2016?","Trinh Thang Bang","Tran Thien Thanh Bao","Hoai Lam","Hoang Xuan Vinh",'d');
//	CauHoi cauHoi9 = taoCauHoiVoiIdNgauNhien("BAS1106","Cong Vinh giai nghe bong da vao nam bao nhieu","2015","2014","2016","2020",'c');
//	CauHoi cauHoi10 = taoCauHoiVoiIdNgauNhien("BAS1106","Ki luc cu ta the gioi la bao nhieu kg","210","310","410","400",'c');
////	
//	CauHoi cauHoi11 = taoCauHoiVoiIdNgauNhien("SKD1108","Doi tuong nghien cuu cua Triet hoc Mac-Lenin la","Nhung van de chung nhat cua the gioi","Su phat trien duong dai","Nhung van de can thiet cua xa hoi","Nhung van de ve xa hoi",'a');
//	CauHoi cauHoi12 = taoCauHoiVoiIdNgauNhien("SKD1108","Su phat trien cua loai nguoi la doi tuong nghien cuu cua","Mon xa hoi hoc","Mon lich su","Mon chinh tri hoc","Mon sinh hoc",'b');
//	CauHoi cauHoi13 = taoCauHoiVoiIdNgauNhien("SKD1108","Tranh luan la cuoc doi thoai cua it nhat bao nhieu nguoi","2","3","4","5",'a');
//	CauHoi cauHoi14 = taoCauHoiVoiIdNgauNhien("SKD1108","Hoc sinh can phai co thai do gi khi tranh luan thua nguoi khac","Noi nong","Xau ho","Binh tinh","Giu im lang",'c');
//	CauHoi cauHoi15 = taoCauHoiVoiIdNgauNhien("SKD1108","Van de co ban cua triet hoc hien dai la","Tu duy va vat chat","Tu duy va ton tai","Duy vat va duy tam","su vat va hien tuong",'b');
////	
//	ptrDSCauHoi danhSachCauHoi = NULL;
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi1);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi2);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi3);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi4);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi5);
//
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi6);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi7);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi8);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi9);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi10);
//	
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi11);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi12);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi13);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi14);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi15);
//	
//	luuDanhSachCauHoi(danhSachCauHoi); // ghi file
	//initialArrayRandomNumber(); // khoi tao mang random
	//cout << "--------------Cau hoi thi trac nghiem---------------" << endl;
//	duyetTienTu(docDanhSachCauHoi()); // doc file
//	InitWindow();
//	Layout();
//	thiTracNghiem("N17dcat079", "SKD1108", 3, 4);
	// lam bai thi


	// test chuc nang diem thi
//	thoiGian tg1;
//	tg1.phut = 30;
//	thoiGian tg2;
//	tg2.phut = 10;
//	thoiGian tg3;
//	tg3.phut = 15;
//	int dsch1 [5] = { 500, 348, 37, 443, 945 };
//	int dsch2 [5] = { 182, 157, 605, 914, 639 };
//	int dsch3 [5] = { 140, 441, 485, 750, 670 };
//	char dsda1 [5] = { 'a', 'b', 'c', 'd', 'b' };
//	char dsda2 [5] = { 'b', 'a', 'c', 'd', 'c' };
//	char dsda3 [5] = { 'a', 'b', 'b', 'a', 'c' };
//	DT dt1 = {"INT1154", 4, 1, tg1, NULL, 5, dsch1, dsda1};
//	DT dt2 = {"BAS1106", 2 , 1, tg2, NULL, 5, dsch2, dsda2};
//	DT dt3 = {"SKD1108", 10, 1, tg3, NULL, 5, dsch3, dsda3};
//	ptrDT danhSachDiemThi = NULL;
//	themDiemThi(danhSachDiemThi, dt1);
//	themDiemThi(danhSachDiemThi, dt2);
//	themDiemThi(danhSachDiemThi, dt3);
//	lietKeDanhSachDiemThi(danhSachDiemThi);
//	luuDanhSachDiemThi("n17dcat079", danhSachDiemThi);
//	lietKeDanhSachDiemThi(docDanhSachDiemThi("n17dcat079"));
	return 0;
}
