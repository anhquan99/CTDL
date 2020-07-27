#include <iostream>
#include <conio.h>
#include <time.h>	// class needs this inclusion
#include <thread>
#include <iomanip> 
#include <unistd.h> 
#include "GUI.h"
using namespace std;

void count(int thoiGianThi){
	int giay = 00;
	
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
	int input;
	while(1){
		gotoxy(10,10);
		cout << "Chon dap an: ";
		cin >> input;
	}
}
int main(){
//	int thoiGian = 10;
//	thread t(count, thoiGian);
//	thread t1(nhap);
//	t.join();
//	t1.join();
	count(10);
	return 0;
}

