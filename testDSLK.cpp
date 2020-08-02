#include <iostream>
#include <conio.h>
#include <time.h>	// class needs this inclusion
#include <thread>
#include <iomanip> 
#include <unistd.h> 

#include "GUI.h"
using namespace std;

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

int timKiemMonHocTheoMaMonHoc(string maMonHoc){
	DSMonHoc p = docDanhSachMonHoc();
	for(int i = 0; i < p.index; i++ ){
		if(maMonHoc.compare(p.ds[i]->MAMH) == 0){
			return i;
		}
	}
	return -1;
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

ptrsv kiemTraMaSinhVien(string maSinhVien){
	//toUppercaseArray(maSinhVien);
	ptrsv First = docDanhSachSinhVien("D17CQAT01");
	for(ptrsv i = First; i != NULL; i = i->next){
		if(i->MSV.compare(maSinhVien) == 0) {
			return i;
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

	if(soLuongCauCuaMotMon == -1) return -1;
	
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
		outfile.write((char*)&diemThi.TrangThai, sizeof(bool));
		outfile.write((char*)&diemThi.ThoiGianConLai.phut, sizeof(int));
		outfile.write((char*)&diemThi.ThoiGianConLai.giay, sizeof(int));
		outfile.write((char*)&diemThi.SoCau, sizeof(int));			
		for(int i = 0; i < diemThi.SoCau; i++){
			outfile.write((char*)&(diemThi.DSCauHoi[i]), sizeof(int));
			outfile.write((char*)&(diemThi.DapAn[i]), sizeof(char));
		}
	return true;
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
		sleep(1);
        giay--; 
	}
	return true;
}

void thiTracNghiem(string maSinhVien){

	
	// in thong tin sinh vien
	ptrsv sinhVien = kiemTraMaSinhVien("N17DCAT079");
	gotoxy(1,10);
	cout << "*THONG TIN SINH VIEN*";
	gotoxy(1,12);
	cout << "MA SINH VIEN: " <<  maSinhVien;
	gotoxy(1,13);
	cout << "HO VA TEN   : " <<  sinhVien->HO << " " << sinhVien->TEN;
	
	// in thong tin lop
	gotoxy(1,14);
	cout << "MA LOP      : " <<  "D17CQAT01";
	gotoxy(1,15);
	cout << "NIEN KHOA   : " <<  "2017-2020";
	cout << "\n \n";
	
	// hien thi danh sach mon hoc
	gotoxy(40,5);
	cout << "-----> DANH SACH MON HOC <------";
	
	int i = 0, viTriMonHoc;
	string maMonHoc;
	DSMonHoc danhSachMonHoc = docDanhSachMonHoc();
	gotoxy(40,7);
	cout << "STT " << "Ma Mon Hoc  " << "Ten Mon Hoc";
	for(i = 0; i < danhSachMonHoc.index; i++){
		gotoxy(40,i+8);
		cout << i+1 <<"   "<< danhSachMonHoc.ds[i]->MAMH << "     " << danhSachMonHoc.ds[i]->TENMH;
	}
	gotoxy(40, i+9);
	cout << "Nhap ma mon hoc: ";	
	while(1){
		cin >> maMonHoc;
		viTriMonHoc = timKiemMonHocTheoMaMonHoc(maMonHoc);
		if(viTriMonHoc == -1){
			gotoxy(40, i+9);
			cout << "Ma mon hoc khong chinh xac! Moi nhap lai: ";
			gotoxy(82, i+9);
			cout << string(20, ' ');
			gotoxy(82, i+9);
		}else if(kiemTraMonSinhVienDaThi(maSinhVien, maMonHoc) == true){
			gotoxy(40, i+9);
			cout << "Mon hoc nay da duoc thi roi! Moi nhap lai: ";
			gotoxy(82, i+9);
			cout << string(20, ' ');
			gotoxy(83, i+9);
		}else if(viTriMonHoc != -1){
			gotoxy(40,5);
			cout << string(100, ' ');
			gotoxy(40,7);
			cout << string(100, ' ');
			for(i = 0; i < danhSachMonHoc.index; i++){
				gotoxy(40,i+8);
				cout << string(80, ' ');
			}
			gotoxy(40, i+9);
			cout << string(100, ' ');		
			break;
		}
	};	
	// cau hoi trac nghiem
	int thoiGianThi, soCauHoi;
	gotoxy(40, 9);
	cout << "Nhap so luong phut muon thi: ";
	cin >> thoiGianThi;
	gotoxy(40, 10);
	cout << "Nhap so cau hoi muon thi   :";
	cin >> soCauHoi;
	// lay danh sach cau hoi
	CauHoi mangCauHoi[soCauHoi];
	int checkDanhSach = layNgauNhienCauHoi(mangCauHoi, soCauHoi, maMonHoc);
	if(checkDanhSach == -1){
		gotoxy(40, 12);
		cout << "Mon hoc nay chua co cau hoi nao!";
		return;
	}else if(checkDanhSach != 1){
		gotoxy(40, 12);
		cout << "So luong cau hoi hien co san: " << checkDanhSach;
		return;
	}
	// in tong so cau hoi
	gotoxy(1,7);
	cout << "TONG SO CAU HOI: " << soCauHoi;
	// thao tac diem thi
	DT diemThi;
	diemThi.DSCauHoi = new int[soCauHoi];
	diemThi.DapAn = new char[soCauHoi];
	diemThi.SoCau = soCauHoi;
	for(int i = 0; i < soCauHoi; i++)
		diemThi.DapAn[i] = 'n';
	diemThi.TrangThai = 1; // 1 la dang thi
	
	//luu dap an
	int ch; // luu dap an sinh vien chon
	//int indexDapAn = 0; // vi tri dap an tuong ung cau hoi ma sinh vien da chon
	int indexCauHoi = 0; // vi tri cau hoi khi nhan phim -> va <-
	// thoi gian
	int giay = 0;
	
	gotoxy(40,5);
	cout << "----------------BAI THI TRAC NGHIEM----------------";
	gotoxy(40,7);		
	cout << "MON:     " << danhSachMonHoc.ds[viTriMonHoc]->TENMH; 
	gotoxy(40,10);
	cout << "---- Hay chon dap an tuong ung tu ban phim !-----: ";
	gotoxy(40,12);
	cout << "Cau " << indexCauHoi+1 << ": " << mangCauHoi[indexCauHoi].NoiDung;
	gotoxy(46,14);
	cout << "A: " << mangCauHoi[indexCauHoi].A;
	gotoxy(46,16);
	cout << "B: " << mangCauHoi[indexCauHoi].B; 
	gotoxy(46,18);
	cout << "C: " << mangCauHoi[indexCauHoi].C; 
	gotoxy(46,20);
	cout << "D: " << mangCauHoi[indexCauHoi].D;
	gotoxy(40,22);
	cout << "Dap an cua ban la: ";
	while (thoiGianThi >= 0)
    {
    	gotoxy(1,5);    	
    	setcursor(0,0);
    	// in thoi gian
    	cout << "THOI GIAN| ";
    	cout << setfill('0') << setw(2) << thoiGianThi << ":";
		cout << setfill('0') << setw(2) << giay;
		
		if(kbhit()){
			ch = getch();
			if (ch == 0 || ch == 224){
				ch = getch();
				if(ch == 77 && indexCauHoi < soCauHoi-1){ // key_right
					indexCauHoi++;
					xoaManHinhTheoToaDo(mangCauHoi[indexCauHoi].NoiDung, mangCauHoi[indexCauHoi].A,
					mangCauHoi[indexCauHoi].B, mangCauHoi[indexCauHoi].C, mangCauHoi[indexCauHoi].D);
					gotoxy(40,12);
					cout << "Cau " << indexCauHoi+1 << ": " <<mangCauHoi[indexCauHoi].NoiDung;
					gotoxy(46,14);
					cout << "A: " << mangCauHoi[indexCauHoi].A;
					gotoxy(46,16);
					cout << "B: " << mangCauHoi[indexCauHoi].B; 
					gotoxy(46,18);
					cout << "C: " << mangCauHoi[indexCauHoi].C; 
					gotoxy(46,20);
					cout << "D: " << mangCauHoi[indexCauHoi].D;
					gotoxy(40,22);
					cout << "Dap an cua ban la: ";
					gotoxy(60,22);
					if(diemThi.DapAn[indexCauHoi] == 'n')
						cout << " ";
					else
						cout << diemThi.DapAn[indexCauHoi];
					
				}else if(ch == 75 && indexCauHoi > 0){// key_left
					indexCauHoi--;
					xoaManHinhTheoToaDo(mangCauHoi[indexCauHoi].NoiDung, mangCauHoi[indexCauHoi].A,
					mangCauHoi[indexCauHoi].B, mangCauHoi[indexCauHoi].C, mangCauHoi[indexCauHoi].D);
					gotoxy(40,12);
					cout << "Cau " << indexCauHoi+1 << ": " << mangCauHoi[indexCauHoi].NoiDung;
					gotoxy(46,14);
					cout << "A: " << mangCauHoi[indexCauHoi].A;
					gotoxy(46,16);
					cout << "B: " << mangCauHoi[indexCauHoi].B; 
					gotoxy(46,18);
					cout << "C: " << mangCauHoi[indexCauHoi].C; 
					gotoxy(46,20);
					cout << "D: " << mangCauHoi[indexCauHoi].D;
					gotoxy(40,22);
					cout << "Dap an cua ban la: ";
					gotoxy(60,22);
					if(diemThi.DapAn[indexCauHoi] == 'n')
						cout << " ";
					else
						cout << diemThi.DapAn[indexCauHoi];
				}
			}else if(ch >= 97 && ch <= 100){
				gotoxy(60,22);
				setcursor(1,1);
				cout << (char)ch;
				setcursor(0,0);
				diemThi.DapAn[indexCauHoi] = (char)ch;
			}else if(ch == 13){ // xac nhan thi xong
				gotoxy(40,26);
				cout << "Thoi gian van con! Ban co chac chan muon nop bai (y|n)? ";
				if(xacNhan(thoiGianThi, giay) == true){
					gotoxy(94,27);
					cout << "NOP BAI SOM!!!";
					break;
				}else{
					gotoxy(40,26);
					cout << string(100, ' ');
				}				
				
			}
		}
        sleep(1);
        if(giay == 0){
        	thoiGianThi--;
        	if(thoiGianThi == -1){
        		gotoxy(40,28);
				cout << "------>HET THOI GIAN <------";
				break;
			}
        	giay = 60;
		}
        giay--;  
    }
    // tinh diem cho sinh vien
//    const float soDiemCuaMotCau = 10.0/soCauHoi;
//	int soCauDung = tinhDiem(diemThi.DSCauHoi, diemThi.DapAn, soCauHoi);
//	gotoxy(40,28);
//	cout << "Diem cua ban la: " << soCauDung*soDiemCuaMotCau;
//	diemThi.DIEM = soCauDung*soDiemCuaMotCau;
//	diemThi.MAMH = maMonHoc;
//	diemThi.ThoiGianConLai.phut = -1;
//	diemThi.ThoiGianConLai.giay = 0;
//	diemThi.TrangThai = 2;
//	 //luu diem cua sinh vien vao file
//	luuDiem(diemThi, maSinhVien);
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
				return true;
			}
		}
	}
	return false;
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

int main(){
//	dangNhap("N17DCAT079", "vu");
	InitWindow();
	Layout();
	TextColor(green);
	thiTracNghiem("N17DCAT079");
//	lietKeDanhSachDiemThi(docDanhSachDiemThi("N17DCAT079"));
//	"SKD1108"

}

