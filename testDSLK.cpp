#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
using namespace std;

int main()
{
    int phut = 1; //amount of seconds
    int giay = 15;
	while (phut >= 0)
    {
    	system("cls");
    	if(phut < 10){
    		cout << setfill('0') << setw(2) << phut << ":";
		}
		if(giay < 10){
			cout << setfill('0') << setw(2) << giay;
		}
		if(phut >= 10) cout << phut << ":";
		if(giay >= 10) cout << giay;
		
        sleep(1);
        if(giay == 0){
        	phut--;
        	giay = 60;
		}
        giay--;
        
    }
    return 0;

}

