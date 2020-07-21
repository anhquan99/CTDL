#include <iostream>
#include <fstream>
#include "Structure.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
int main(){
	DSLop classList;
	Lop1 lop1 = {"at01111", "an toan 1", "2020-2029"};
	Lop1 lop2 =  {"at02", "an toan 2", "2020-2021"};
	//classList.lop[classList.index] = new Lop;
	//classList.lop[classList.index]->sv = new SV;
	//*classList.lop[classList.index] = lop1;
	//classList.index++;
	//classList.lop[classList.index] = new Lop;
	//*classList.lop[classList.index] = lop2;
	//classList.index++;
	//showClass(classList);
	ofstream outfile("classList.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	//for (int i=0; i < classList.index; i++){
		outfile.write(lop1.MALOP.c_str(), lop1.MALOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(lop1.TENLOP.c_str(), lop1.TENLOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(lop1.NK.c_str(), lop1.NK.size());
		outfile.write("\0", sizeof(char));
//		outfile.write(reinterpret_cast<char*>(&(lop1.sv)), sizeof(SV));	
		outfile.write(lop2.MALOP.c_str(), lop2.MALOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(lop2.TENLOP.c_str(), lop2.TENLOP.size());
		outfile.write("\0", sizeof(char));
		outfile.write(lop2.NK.c_str(), lop2.NK.size());
		outfile.write("\0", sizeof(char));
//		outfile.write(reinterpret_cast<char*>(&(lop2.sv)), sizeof(SV));		
	//}
	outfile.close();

//	Lop1 lop, lopf;
//	//streampos size;
//	ifstream infile("classList.txt", ios::in | ios::binary);
//	if(infile == NULL){
//		cout << "Loi file" << endl;
//		return false;
//	}
//	//size = infile.tellg();
//	//infile.seekg (0, ios::beg);
//	//while(size != infile.tellg()){
//		getline(infile, lop.MALOP, '\0');
//		getline(infile, lop.TENLOP, '\0');
//		getline(infile, lop.NK, '\0');
////		infile.read(reinterpret_cast<char*>(&lop.sv), sizeof(SV) );
//		getline(infile, lopf.MALOP, '\0');
//		getline(infile, lopf.TENLOP, '\0');
//		getline(infile, lopf.NK, '\0');
////		infile.read(reinterpret_cast<char*>(&lopf.sv), sizeof(SV) );
////		classList1.lop[classList1.index] = new Lop;
////		*classList1.lop[classList1.index] = lop;
////		classList1.index++;
//	//};
//	
//	infile.close();		
//	//showClass(classList1);
//	cout << lop.MALOP << endl << lop.TENLOP << endl << lop.NK;
//	cout << lopf.MALOP << endl << lopf.TENLOP << endl << lopf.NK;
//	//if(lop.sv == NULL) cout << "null";
////	cout << lop1.MALOP << endl << lop1.TENLOP << endl << lop1.NK;
////	if(lop1.sv == NULL) cout << "null";
////	cout << lopg.MALOP << endl << lopg.TENLOP << endl << lopg.NK;
////	if(lopg.sv == NULL) cout << "null";
	return 0;
}
