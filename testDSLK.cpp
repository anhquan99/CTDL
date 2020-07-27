#include <iostream>
#include <conio.h>
#include <time.h>	// class needs this inclusion
#include <thread>
#include <iomanip> 
#include <unistd.h> 
#include "GUI.h"
using namespace std;

void count(int thoiGianThi){
	int giay = 10;
	
	while (thoiGianThi >= 0)
    {
    	//cout << "\r";
    	gotoxy(0,0);
    	cout << setfill('0') << setw(2) << thoiGianThi << ":";
		cout << setfill('0') << setw(2) << giay << " ";
        sleep(1);
        if(giay == 0){
        	thoiGianThi--;
        	giay = 60;
		}
        giay--;  
    }
}

void nhap(){

}
int main(){
//	int thoiGian = 10;
//	thread t(count, thoiGian);
//	int giay = 10;
//	int thoiGianThi = 10;
//	while (thoiGianThi >= 0)
//    {
//    	//cout << "\r";
//    	gotoxy(16,4);
//    	cout << setfill('0') << setw(2) << thoiGianThi << ":";
//		cout << setfill('0') << setw(2) << giay << " ";
//        sleep(1);
//        if(giay == 0){
//        	thoiGianThi--;
//        	giay = 60;
//		}
//        giay--;
//		if(kbhit()){
//			char c = getch();
//			if(c >= 97 && c<= 100){
//				cout << "Dap an vua chon: " c << endl;
//			}			
//		}  
//    }
//	t.join();
	int c;
	while(1){
		c = getch();
		if(kbhit()){
			if(c == 0 || c == 224){
				c = getch();
				if(c == 77) cout << "right_arrow";
				else if(c == 75) cout << "left_arrow";
			}
		}
	}
	return 0;
}

