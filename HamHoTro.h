#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
using namespace std;

void countdown()
{
    int phut = 10; //amount of seconds
    int giay = 60;
	while (phut >= 0)
    {
    	system("cls");
    	cout << setfill('0') << setw(2) << phut << ":";
		cout << setfill('0') << setw(2) << giay;		
        sleep(1);
        if(giay == 0){
        	phut--;
        	giay = 60;
		}
        giay--;
        
    }
}

