#include <iostream>
#include <fstream>
#include "Structure.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
using namespace std;
int main(){
	DSLop classList;
	ofstream outfile("classList1.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	string lop = "lop";
	string sv = "sv";
	string dt = "dt";
	for(int i=0; i < classList.index; i++){
		outfile.write( lop.c_str(), lop.size());
		outfile.write("\0", sizeof(char));
		outfile.write( lop, lop.size());
		outfile.write("\0", sizeof(char));
		for( int o = 0; )
	}
	outfile.close();

//	//streampos size;
//	ifstream infile("classList1.txt", ios::in | ios::binary);
//	if(infile == NULL){
//		cout << "Loi file" << endl;
//		return false;
//	}
//	for(int i= 0 ; i < 2; i++){
//		string lop;
//		string sv;
//		string dt;
//		getline(infile, lop, '\0');
//		getline(infile, sv, '\0');
//		getline(infile, dt, '\0');
//		cout << lop << " " << sv << " " << dt << "\n";
//	}
//	infile.close();	
	return 0;
}
