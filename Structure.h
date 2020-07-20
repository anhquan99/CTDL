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

struct time{
	int gio;
	int phut;
};

struct date{
	int gio;
	int phut;
	int ngay;
	int thang;
	int nam;
};
// create struct
struct MonHoc{
	std::string MAMH;
	std::string TENMH;
	time ThoiGianThi;
};

struct DSMonHoc{
	int index = 0;
	MonHoc *ds[MAXMH]; // danh sach mon hoc
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
struct SV{
	string MSV;
	std::string HO;
	std::string TEN;
	bool PHAI;
	std::string password;
	DT *dsdiemthi; // danh sach diem thi
	SV *next; // sinh vien ke tiep
};
struct Lop{
	std::string MALOP;
	std::string TENLOP;
	std::string NK; // nien hkoa
	SV *sv;
};
struct DSLop{
	int index = 0;
	Lop *lop[MAXLOP];
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
#endif
