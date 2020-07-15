// ten: Do Anh Quan - Tran Dang Vu
// Mon: Cau truc du lieu
// GV: Luu Nguyen Ky Thu
// De tai: Thi trac nghiem
#ifndef _tracnghiem
#define _tracnghiem
// body
#include <iostream>
#include <string>
// create struct
#define MAXMH = 300
struct MonHoc{
	string MAMH;
	string TENMH;
};
struct DSMonHoc{
	int index = 0;
	MonHoc *ds[MAXMH]; // danh sach mon hoc
};
#define MAXLOP = 500
struct Lop{
	string MALOP;
	string TENLOP;
	string NK; // nien hkoa
	SV *sv;
};
struct DSLop{
	int index = 0;
	Lop *lop[MAXLOP];
};
struct SV{
	int MSV;
	string HO;
	string TEN;
	bool PHAI;
	string password;
	DSDiemThi *dsdiemthi; // danh sach diem thi
	SV *next; // sinh vien ke tiep
};
struct DSDiemThi{ // danh sach diem thi
	string MAMH;
	double DIEM;
	struct DT *next; // mon thi ke tiep
	bool TrangThai; // neu sinh vien bi cup dien thi co the thi lai
	time ThoiGianConLai;
	char *DapAn; // mang cap phat dong
	int *DSCauHoi;  // mang cap phat dong
};
struct DSThi{
	string MAMH;
	int *DSSV;
};
struct CauHoi{
	int ID;
	string MAMH;
	string NoiDung;
	string A;
	string B;
	string C;
	string D;
	char DapAn;
};
struct DSCauHoi{
	CauHoi cauhoi;
	struct DSCauHoi *left;
	struct DSCauHoi *right;
};
struct date{
	int gio;
	int phut;
	int ngay;
	int thang;
	int nam;
};
struct time{
	int gio;
	int phut;
};

