#include <iostream>
#include<conio.h>
const int MAXQUEST = 10;
using namespace std;

struct SinhVienA{
	string MSV;
	string HO;
	string TEN;
	bool PHAI;
	string password;
	SinhVienA *next;
};

typedef struct SinhVienA* ptrsv;

bool them(ptrsv &first){
	ptrsv p, last;
	string msv, ten, ho, password;
	bool phai;
	char key_press;
	if(first != NULL)
    	for ( last = first ; last->next !=NULL; last=last->next) ;
	while(1){
		fflush (stdin);
		cout <<"Nhap ma sinh vien: ";
		getline(cin, msv);
		
		cout << "Nhap ho sinh vien: ";
		fflush (stdin);
		getline(cin, ho);
		
		cout << "Nhap ten sinh vien: ";
		fflush (stdin);
		getline(cin, ten);
		
		cout << "Nhap phai sinh vien: ";
		cin >> phai;
		
		cout << "Nhap pasword sinh vien: ";
		fflush (stdin);
		getline(cin, password);
		
		p = new SinhVienA;
		p->MSV = msv;
		p->TEN = ten;
		p->HO = ho;
		p->PHAI = phai;
		p->password = password;
		p->next = NULL;
		
		if(first == NULL) first = p;
		
		else last->next = p;
		last = p;
		cout <<"Bam phim bat ki" << endl;
		key_press = getch();
		if(key_press == 27) // ESC
			break;
	}
}

ptrsv inRa(ptrsv first){
	for(ptrsv i = first; i != NULL; i = i->next){
		string phai = i->PHAI ? "Nam" : "Nu";
		cout << " ma: " << i->MSV << " ten: " << i->TEN  << " ho: " << i->HO << " Phai: " << phai << " pwd: "
		<< i->password << endl;
	}
	
}

int main(){
	ptrsv first;
	first = NULL;
	them(first);
	inRa(first);
}
