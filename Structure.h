// ten: Do Anh Quan - Tran Dang Vu
// Mon: Cau truc du lieu
// GV: Luu Nguyen Ky Thu
// De tai: Thi trac nghiem
#ifndef Structure
#define Structure

#include <iostream>
#include <string>

//const
const int MAXMH = 300;
const int MAXLOP = 500;

// create struct
struct MonHoc{
	std::string MAMH;
	std::string TENMH;
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

struct time{
	int gio;
	int phut;
};

struct DT{ // danh sach diem thi
	std::string MAMH;
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
	std::string MAMH;
	std::string NoiDung;
	std::string A;
	std::string B;
	std::string C;
	std::string D;
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
#endif
