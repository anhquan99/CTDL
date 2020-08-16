#include <iostream>
#include <ofstream>
using namespace std;
int main(){
	bool a = 1;
	ofstream outfile( "test", ios::out | ios::app | ios::binary);
	outfile.write((char*)&a)
}
