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
const int MAXQUEST = 10;
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
		for(int j = i+1; j < danhSachLop.index; j++){
			danhSachLop.lop[j-1] = danhSachLop.lop[j];
		}
		delete danhSachLop.lop[danhSachLop.index-1];
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



ptrsv kiemTraMaSinhVien(ptrsv First, string &maSinhVien){
	toUppercaseArray(maSinhVien);
	for(ptrsv i = First; i != NULL; i = i->next){
		if(i->MSV.compare(maSinhVien) == 0) {
			return i;
		}	
	}
	return NULL;
}

bool themSinhVien(ptrsv &First, string MSV, string ho, string ten, bool phai, string password){ 
	ptrsv p , Last;
	char key_press;
	p->dsdiemthi = NULL;
	if(First != NULL)
		for(Last = First; Last->next != NULL; Last = Last->next); // duyet den cuoi danh sach
	while(1){
		fflush (stdin);
		cout << "Nhap ma so sinh vien: ";
		getline(cin, MSV);
		if(kiemTraMaSinhVien(First, MSV) != NULL){
			cout <<"Ma sinh vien trung";
			continue;
		}
		cout << "Nhap ho: ";
		fflush (stdin);
		getline(cin, ho);	
			
		cout << "Nhap ten: ";
		fflush (stdin);
		getline(cin, ten);	
			
		cout << "Nhap phai  0-nu  1-nam: ";
		cin >> phai;			
		
		cout << "Nhap password cua sinh vien( phan biet hoa thuong): ";
		fflush (stdin);
		getline(cin, password);
		
		p = new SV;
		p->MSV = MSV;
		p->HO = ho;
		p->TEN = ten;
		p->PHAI = phai;
		p->password = password;
		p->next = NULL;
		if (First == NULL) {
			First = p;
		}
		else{
			Last->next = p;
		}
		Last = p;
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

bool xoaSinhVien(ptrsv &first){
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
	toUppercaseArray(maSinhVien);
	loaiBoKhoangTrangCuaChuoi(maSinhVien);
	 //xoa o dau danh sach
	if(first->MSV.compare(maSinhVien) == 0){
		ptrsv f = first;
		first = f->next;
		delete f;
		cout << "Bam 'y' de xoa tiep: ";
		keyPress = getch();
		if(keyPress == 'y')
			goto xoaTiep;
		else
			return true;
	}
	
	for(p = first; p->next != NULL && (p->next->MSV.compare(maSinhVien) != 0); p = p->next);
	if(p->next!=NULL){
		ptrsv q = p->next;
		p->next = q->next;
		delete q;
		cout << "Bam 'y' de xoa tiep: ";
		keyPress = getch();
		if(keyPress == 'y')
			goto xoaTiep;
		else
			return true;
	}else{
		cout << "Khong tim thay sinh vien muon xoa";
		return false;
	}
	
}
int main(){
//	DSLop danhSachLop;
//	insertClassList(danhSachLop); // test luu mot lop vao cuoi danh sach co san trong file
//	xoaLop("d17ptit");				// test xoa file
//	showClass(docDanhSachLop());	// test doc danh sach lop tu file
//	suaThongTinLop("d17cqat");	     // test sua thong tin lop
	
//	ptrsv first;
//	first = NULL;
//	Lop lop2 = {"BT02", "an toan 2", "2030-2035", NULL};
//	themSinhVien(lop2.SinhVien);
//	lietKeDanhSachSinhVien(lop2.SinhVien);
//	xoaSinhVien(lop2.SinhVien);
//	lietKeDanhSachSinhVien(lop2.SinhVien);
//	SV sv2 = {"A2", "nguyen", "van a", false, "123", NULL, NULL};
//	SV sv1 = {"A1", "tran", "dang vu", true, "abc", NULL, NULL};
//	lop1.sv = &sv1;
//	sv1.next = &sv2;
	
//	Lop lop3 = {"FT04", "an toan 3", "2035-2040", NULL};
//	Lop lop4 = {"GT05", "an toan 4", "2040-2045", NULL};
//	classList.lop[classList.index] = new Lop;
//	*classList.lop[classList.index++] = lop1;	
//	classList.lop[classList.index] = new Lop;
//	*classList.lop[classList.index++] = lop2;
//	classList.lop[classList.index] = new Lop;
//	*classList.lop[classList.index++] = lop3;	
//	classList.lop[classList.index] = new Lop;
//	*classList.lop[classList.index++] = lop4;
	
//	string maSinhVien = "bd3";
//	if(kiemTraMaSinhVien(lop1, maSinhVien) != NULL) cout << "khac null";
//	else cout << "bang null";
	return 0;
}
