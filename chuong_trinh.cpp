#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
#include <thread>
#include "GUI.h"
using namespace std;

//void demNguoc(){
//	int thoiGianThi = 1;
//	int giay = 0;
//	char ch;
//	while(thoiGianThi >= 0){
//		gotoxy(1,1);
//		cout << setfill('0') << setw(2) << thoiGianThi << ":";
//		cout << setfill('0') << setw(2) << giay;
//		cout << endl;
//		if(kbhit()){
//			ch = getch();
//			if(ch == 13){
//				cout << "ket thuc khong y / n";
//				if(xacNhan(thoiGianThi, giay) == true){
//					cout << "\n ket thuc khi con thoi gian";
//					break;
//				}
//			}
//		}
//        if(giay == 0){
//        	thoiGianThi--;
//        	if(thoiGianThi == -1){
//				cout << "------>HET THOI GIAN <------";
//				break;
//			}
//        	giay = 60;
//		}
//		sleep(1);
//        giay--; 
//	}
//
//}

void nhap(){
	char a;

	setcursor(1,7);
	cout << "Nhap a: ";
	a = getch();
	cout << a;
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
int main()
{
	int a[2] = {1, 2};
	int b[2];
	b = a ;
	cout << b[0] << b[1];
	
	return 0;
}

