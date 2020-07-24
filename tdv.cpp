#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <regex>
#include <C:\Users\trand\OneDrive\Máy tính\CTDL\Structure.h>
#include <stdlib.h> 
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
	luuDanhSachLopMoi(danhSachLop); // xoa xong ghi de len file cu danh sach lop moi nay vo
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

ptrsv kiemTraMaSinhVien(ptrsv First, string maSinhVien){
	//toUppercaseArray(maSinhVien);
	for(ptrsv i = First; i != NULL; i = i->next){
		if(i->MSV.compare(maSinhVien) == 0) {
			return i;
		}	
	}
	return NULL;
}

bool themSinhVien(string maLop){ 
	SV sinhVien;
	bool phai;
	char key_press;
	while(1){
		fflush (stdin);
		cout << "Nhap ma so sinh vien: ";
		getline(cin, sinhVien.MSV);
		
		cout << "Nhap ho: ";
		fflush (stdin);
		getline(cin, sinhVien.HO);	
			
		cout << "Nhap ten: ";
		fflush (stdin);
		getline(cin, sinhVien.TEN);	
			
		cout << "Nhap phai  0-nu  1-nam: ";
		cin >> sinhVien.PHAI;			
		
		cout << "Nhap password cua sinh vien( phan biet hoa thuong): ";
		fflush (stdin);
		getline(cin, sinhVien.password);
		luuSinhVienVaoCuoiFile(maLop, sinhVien);
		cout << "them thanh cong! them tiep hay thoi(ESC)" << endl;
		key_press = getch();
		if(key_press == 27) // For ESC
            break;
	}
	return true;
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
		outfile.write((char*)&(danhSachMonHoc.ds[i]->ThoiGianThi.gio), sizeof(int));
		outfile.write((char*)&(danhSachMonHoc.ds[i]->ThoiGianThi.phut), sizeof(int));
	}
}

void lietKeDanhSachMonHoc(DSMonHoc danhSachMonHoc){
	cout << "Ma mon hoc  " << "Ten mon hoc  " << "Thoi gian" << endl;
	for(int i = 0; i < danhSachMonHoc.index; i++){
		cout << danhSachMonHoc.ds[i]->MAMH << " " << danhSachMonHoc.ds[i]->TENMH << "  ";
		danhSachMonHoc.ds[i]->ThoiGianThi.hienThiThoiGian();
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
		infile.read((char*)&mon.ThoiGianThi.gio, sizeof(int));
		infile.read((char*)&mon.ThoiGianThi.phut, sizeof(int));
		themVaoMangConTroDSMonHoc(danhSachMonHoc, mon);
	}
	return danhSachMonHoc;
}

bool themMonHoc(string maMonHoc, string tenMonHoc, thoiGian thoiGianThi){
	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
	MonHoc monHoc;
	if(danhSachMonHoc.index == MAXMH){
		cout << "Danh sach mon hoc day";
		return false;
	}
	monHoc.MAMH = maMonHoc;
	monHoc.TENMH = tenMonHoc;
	monHoc.ThoiGianThi = thoiGianThi;
	themVaoMangConTroDSMonHoc(danhSachMonHoc, monHoc);
	luuDanhSachMonHoc(danhSachMonHoc);
	return true;
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

bool suaMonHoc(string maMonHoc, string maMonHocMoi, string tenMonHocMoi, thoiGian thoiGianThiMoi){
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
	monHoc.ThoiGianThi = thoiGianThiMoi;
	// chinh sua thong tin trong danh sach mon hoc
	danhSachMonHoc.ds[viTri]->MAMH = maMonHocMoi; 
	danhSachMonHoc.ds[viTri]->TENMH = tenMonHocMoi;
	danhSachMonHoc.ds[viTri]->ThoiGianThi = thoiGianThiMoi;
	luuDanhSachMonHoc(danhSachMonHoc);
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
		cout << "a: " << danhSachCauHoi->cauhoi.A << endl;
		cout << "b: " << danhSachCauHoi->cauhoi.B << endl;
		cout << "c: " << danhSachCauHoi->cauhoi.C << endl;
		cout << "d: " << danhSachCauHoi->cauhoi.D << endl;
		cout << "dap an: " << danhSachCauHoi->cauhoi.DapAn << endl;
		duyetTienTu(danhSachCauHoi->left);
		duyetTienTu(danhSachCauHoi->right);
	}
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
		p->ThoiGianThi.hienThiThoiGian();
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

bool luuDanhSachDiemThi(string maLop, ptrDT danhSachDiemThi){
	string tenFile = maLop + "-diemThi.txt";	
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
		outfile.write((char*)&p->ThoiGianThi.gio, sizeof(int));
		outfile.write((char*)&p->ThoiGianThi.phut, sizeof(int));
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

ptrDT docDanhSachDiemThi(string maLop){
	ptrDT danhSachDiemThi = NULL;
	DT diemThi;
	streampos size;
	string tenFile = maLop + "-diemThi.txt";
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
		infile.read((char*)&diemThi.ThoiGianThi.gio, sizeof(int));
		infile.read((char*)&diemThi.ThoiGianThi.phut, sizeof(int));
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
int main(){
//	DSLop danhSachLop;
//	insertClassList(danhSachLop); // test luu mot lop vao cuoi danh sach co san trong file
//	xoaLop("d17ptit");				// test xoa file
//	showClass(docDanhSachLop());	// test doc danh sach lop tu file
//	suaThongTinLop("d17cqat");	     // test sua thong tin lop
	// thao tac voi sinh vien
	
//	DSLop danhSachLop = docDanhSachLop();
//	showClass(danhSachLop);
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
	//themSinhVien(danhSachLop.lop[viTri]->MALOP); // test them sinh vien
	//xoaSinhVien(danhSachLop.lop[viTri]->MALOP, docSinhVien(danhSachLop.lop[viTri]->MALOP));  // test xoa sinh viên
	
//	suaSinhVien(danhSachLop.lop[viTri]->MALOP,"n17cqat069", "nguyen", "minh beo", true, "fffff",
//	docSinhVien(danhSachLop.lop[viTri]->MALOP) );
//	lietKeDanhSachSinhVien(docSinhVien(danhSachLop.lop[viTri]->MALOP));  // test sua thong tin sinh vien

//==================================== mon hoc =====//
// test thêm môn hoc
//	thoiGian thoiGianThi1;
//	thoiGianThi1.gio = 1;
//	thoiGianThi1.phut = 30;
//	thoiGian thoiGianThi2;
//	thoiGianThi2.gio = 0;
//	thoiGianThi2.phut = 30;
//	thoiGian thoiGianThi3;
//	thoiGianThi3.gio = 0;
//	thoiGianThi3.phut = 50;
//	thoiGian thoiGianThi4;
//	thoiGianThi4.gio = 0;
//	thoiGianThi4.phut = 50;
//	themMonHoc("INT1154", "Tin hoc co so 1", thoiGianThi1);
//	themMonHoc( "BAS1106", "Giao duc the chat 1", thoiGianThi2);
//	themMonHoc("ELE1433", "Ky thuat so", thoiGianThi3);
//	themMonHoc("SKD1108", "Phuong phap luan ", thoiGianThi4);	
//	xoaMonHoc("SKD1108"); // test xoa mon hoc
//	suaMonHoc("BAS1106", "BAS1107", "Giao duc the thao", thoiGianThi3); // test sua mon hoc
//	lietKeDanhSachMonHoc(docDanhSachMonHoc());

	// doc day ngau nhien vao file
//	int daySoNgauNhien[MAXQUEST];
//	generateArrayRandomNumber(daySoNgauNhien);
//	luuDaySoNgauNhien();
//	docDaySoNgauNhien(daySoNgauNhien);
//	for(int i = 0; i < MAXQUEST; i++)
//		cout << daySoNgauNhien[i] << endl;
	// duyet cau hoi
//	CauHoi cauHoi1 = taoCauHoiVoiIdNgauNhien("SKD1108","chon dap an dung: 1+1 = ?","hai","mot","nam","tam",'a');
//	CauHoi cauHoi2 = taoCauHoiVoiIdNgauNhien("SKD1108","chon dap an dung: 1+2 = ?","hai","mot","ba","tam",'c');
//	CauHoi cauHoi3 = taoCauHoiVoiIdNgauNhien("SKD1108","chon dap an dung: 1+3 = ?","hai","bon","nam","tam",'b');
//	ptrDSCauHoi danhSachCauHoi = NULL;
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi1);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi2);
//	themCauHoiVaoCay(danhSachCauHoi, cauHoi3);
//	duyetTienTu(danhSachCauHoi);
//	luuDanhSachCauHoi(danhSachCauHoi); // ghi file
//	docDanhSachCauHoi(); // doc file
// 	initialArrayRandomNumber(); // khoi tao mang random

	// test chuc nang diem thi
//	thoiGian tg1;
//	tg1.phut = 30;
//	thoiGian tg2;
//	tg2.gio = 1;
//	tg2.phut = 10;
//	thoiGian tg3;
//	tg3.phut = 15;
//	int dsch1 [5] = { 16, 2, 77, 40, 12071 };
//	int dsch2 [5] = { 1, 12, 7, 10, 121 };
//	int dsch3 [5] = { 6, 22, 47, 41, 1071 };
//	char dsda1 [5] = { 'A', 'B', 'C', 'D', 'B' };
//	char dsda2 [5] = { 'B', 'A', 'C', 'D', 'C' };
//	char dsda3 [5] = { 'D', 'C', 'B', 'A', 'B' };
//	DT dt1 = {"d17cqat", 8.5, 1, tg1, NULL, 5, dsch1, dsda1};
//	DT dt2 = {"d17cqat", 1.5, 1, tg2, NULL, 5, dsch2, dsda2};
//	DT dt3 = {"d17cqat", 3, 1, tg3, NULL, 5, dsch3, dsda3};
//	ptrDT danhSachDiemThi = NULL;
//	themDiemThi(danhSachDiemThi, dt1);
//	themDiemThi(danhSachDiemThi, dt2);
//	themDiemThi(danhSachDiemThi, dt3);
//	lietKeDanhSachDiemThi(danhSachDiemThi);
//	luuDanhSachDiemThi("d17cqat", danhSachDiemThi);
//	lietKeDanhSachDiemThi(docDanhSachDiemThi("d17cqat"));
	return 0;
}
