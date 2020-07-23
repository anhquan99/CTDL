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
const int MAXQUEST = 1000;

struct date{
	int gio;
	int phut;
	int ngay;
	int thang;
	int nam;
};

struct thoiGian{
	int gio = 0;
	int phut = 0;
	
	void nhapThoiGian(){
		std::cout << "gio: ";
		std::cin >> gio;
		std::cout << std::endl << "phut: ";
		std::cin >> phut;
	}
	void hienThiThoiGian(){
		std::cout << gio << ":" << phut;
	}
};
// create struct
struct MonHoc{
	std::string MAMH;
	std::string TENMH;
	thoiGian ThoiGianThi;
};

struct DSMonHoc{
	int index = 0;
	MonHoc *ds[MAXMH]; // danh sach mon hoc
};

struct DT{ // danh sach diem thi
	std::string MAMH;
	double DIEM;
	bool TrangThai; // neu sinh vien bi cup dien thi co the thi lai
	thoiGian ThoiGianConLai;
	struct DT *next; // mon thi ke tiep
	char *DapAn; // mang cap phat dong
	int *DSCauHoi;  // mang cap phat dong
};

struct SV{
	std::string MSV;
	std::string HO;
	std::string TEN;
	bool PHAI;
	std::string password;
	DT *dsdiemthi; // danh sach diem thi
	SV *next; // sinh vien ke tiep
};

typedef struct SV* ptrsv;

struct Lop{
	std::string MALOP;
	std::string TENLOP;
	std::string NK; // nien hkoa/ si so sinh vien
	ptrsv sv;
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

typedef struct DSCauHoi* ptrDSCauHoi;
#endif
