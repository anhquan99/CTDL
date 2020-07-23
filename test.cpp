// increaser
#include <iostream>
#include <string>
#include <conio.h>
#include "GUI.h"
#include <fstream>
#include <unistd.h>

using namespace std;

int main ()
{
	initialArrayRandomNumber();
	
	for(int i=0 ;i < 1000 ;i ++){
		cout << generateArrayRandomNumber() << "\n";
	}
//	int arrayRandomNumber[MAXQUEST];
//	streampos size;
//	ifstream infile("DSRandom.txt", ios::in | ios::binary | ios::ate);
//	if(infile == NULL){
//		cout << "Loi file" << endl;
//		return false;
//	}
//	size = infile.tellg();
//	infile.seekg(0, ios::beg);
//	int index;
//	infile.read((char*) &index, sizeof(int));
//	cout << "index: " << index << "\n";
//	for(int i = 0; i < MAXQUEST; i++){
//		infile.read((char*) &arrayRandomNumber[i], sizeof(int));
//		cout << arrayRandomNumber[i] << "\n";
//	}
//	infile.close();
} 

