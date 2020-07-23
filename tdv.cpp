#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
#include <regex>
#include <C:\Users\trand\OneDrive\M�y t�nh\CTDL\Structure.h>
#include <stdlib.h> 
using namespace std;


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

void luuDaySoNgauNhien(int daySoNgauNhien[]){
	ofstream outfile ("dayNgauNhien.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "file loi";
		return;
	}
	for(int i = 0; i < MAXQUEST; i++){
		outfile.write((char*)&(daySoNgauNhien[i]), sizeof(int));
	}
	outfile.close();
}

void docDaySoNgauNhien(int daySoNgauNhien[]){
	ifstream infile("dayNgauNhien.txt", ios::in | ios::binary);
	if(infile == NULL){
		cout << "file loi";
		return;
	}
	for(int i = 0; i < MAXQUEST; i++){
		infile.read((char*)&daySoNgauNhien[i], sizeof(int));
	}
	for(int i = 0; i < MAXQUEST; i++)
		cout << daySoNgauNhien[i] << endl;
	infile.close();
}

CauHoi themCauHoiVoiIdNgauNhien(string maMonHoc, string noiDung, string a, string b, string c, string d, char dapAn){
	int daySoNgauNhien[MAXQUEST];
	docDaySoNgauNhien(daySoNgauNhien);
	CauHoi cauHoi;
	for(int i = 0; i < MAXQUEST; i++){
		if(daySoNgauNhien[i] != -1){
			cauHoi.ID = daySoNgauNhien[i];
			daySoNgauNhien[i] = -1;
			break;
		}
	}
	cauHoi.MAMH = maMonHoc;
	cauHoi.NoiDung = noiDung;
	cauHoi.A = a;
	cauHoi.B = b;
	cauHoi.C = c;
	cauHoi.D = d;
	cauHoi.DapAn = dapAn;
	return cauHoi;
}

bool themNutVaoCay(ptrDSCauHoi &danhSachCauHoi, int id, CauHoi cauHoi){
	if(danhSachCauHoi == NULL){  // duyet den nut la
		danhSachCauHoi = new DSCauHoi;
		danhSachCauHoi->cauhoi = cauHoi; // nhap info
		danhSachCauHoi->left = NULL;
		danhSachCauHoi->right = NULL;
	}else if(id < danhSachCauHoi->cauhoi.ID){ // id nho hon id nut dang xet thi xet qua trai cua nut dang xet
		themNutVaoCay(danhSachCauHoi->left, id, cauHoi);
	}else if(id > danhSachCauHoi->cauhoi.ID){
		themNutVaoCay(danhSachCauHoi->right, id, cauHoi);
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

void duyetTienTu(ptrDSCauHoi &danhSachCauHoi){ // in danh sach c�u hoi
	if(danhSachCauHoi != NULL){
		cout <<"MaMH: " << danhSachCauHoi->cauhoi.MAMH << endl;
		cout << "id: " << danhSachCauHoi->cauhoi.ID << endl;
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

bool luuCauHoi(ptrDSCauHoi danhSachCauHoi){
	ofstream outfile("danhSachCauHoi.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "loi file";
		return false;
	}
	
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
	//xoaSinhVien(danhSachLop.lop[viTri]->MALOP, docSinhVien(danhSachLop.lop[viTri]->MALOP));  // test xoa sinh vi�n
	
//	suaSinhVien(danhSachLop.lop[viTri]->MALOP,"n17cqat069", "nguyen", "minh beo", true, "fffff",
//	docSinhVien(danhSachLop.lop[viTri]->MALOP) );
//	lietKeDanhSachSinhVien(docSinhVien(danhSachLop.lop[viTri]->MALOP));  // test sua thong tin sinh vien

//==================================== mon hoc =====//
// test th�m m�n hoc
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
	themCauHoiVoiIdNgauNhien("SKD1108","chon dap an dung: 1+1 = ?","hai","mot","nam","tam",'A');
	return 0;
}
