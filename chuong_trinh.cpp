#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
using namespace std;


int main()
{
	int phut = 10;
   int giay = 10;
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
}

