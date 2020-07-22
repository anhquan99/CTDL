#include <iostream>
#include <fstream>
#include "Structure.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>

using namespace std;

bool themSinhVien(ptrsv &First, SV sv){ 
	ptrsv Last;
	//p->dt = NULL;
	if(First != NULL)
		for(Last = First; Last->next != NULL; Last = Last->next); // duyet den cuoi danh sach
	if (First == NULL) {
		First = &sv;
	}
	else{
		Last->next = &sv;
	}
//	cout << sv.MSV << "\n";
	return true;
}
void initialArrayRandomNumber(){
	int arrayRandomNumber[MAXQUEST];
	for(int i = 0; i < MAXQUEST; i++){  
		arrayRandomNumber[i] = i;
	}
	arrayRandomNumber[0] = MAXQUEST/2;
	arrayRandomNumber[MAXQUEST/2] = 0;
	ofstream outfile("DSRandom.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return;
	}
	int index = 1;
	outfile.write((char*) &index, sizeof(int));
	for(int i = 0; i < MAXQUEST; i++){
		outfile.write((char*)&arrayRandomNumber[i], sizeof(int));
	}
	outfile.close();
}
int generateArrayRandomNumber(){											
	int arrayRandomNumber[MAXQUEST];
	streampos size;
	ifstream infile("DSRandom.txt", ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "Loi file" << endl;
		return -1;
	}
	size = infile.tellg();
	infile.seekg(0, ios::beg);
	int index;
	infile.read((char*) &index, sizeof(int));
//	cout << "index: " << index << "\n";
	for(int i = 0; i < MAXQUEST; i++){
		infile.read((char*) &arrayRandomNumber[i], sizeof(int));
//		cout << arrayRandomNumber[i] << "\n";
	}
	infile.close();
	srand(time(NULL));
	int randomNumber = rand() % (MAXQUEST)+index;
	int temp = arrayRandomNumber[randomNumber];
	arrayRandomNumber[randomNumber] = arrayRandomNumber[index];
	arrayRandomNumber[index] = temp;
	index++;
	ofstream outfile("DSRandom.txt", ios::out | ios::binary);
	if(outfile == NULL){
		cout << "Loi file" << endl;
		return -1;
	}
	outfile.write((char*) &index, sizeof(int));
	for(int i = 0; i < MAXQUEST; i++){
		outfile.write((char*)&arrayRandomNumber[i], sizeof(int));
	}
	outfile.close();
	return temp;
}
int main(){
//	int arrayRandomNumber[MAXQUEST];
//	for(int i = 0; i < MAXQUEST; i++){  
//		arrayRandomNumber[i] = i;
//	}
//	arrayRandomNumber[0] = MAXQUEST/2;
//	arrayRandomNumber[MAXQUEST/2] = 0;
//	ofstream outfile("DSRandom.txt", ios::out | ios::binary);
//	int index = 1;
//	if(outfile == NULL){
//		cout << "Loi file" << endl;
//		return false;
//	}
//	outfile.write((char*) &index, sizeof(int));
//	for(int i = 0; i < MAXQUEST; i++){
//		outfile.write((char*)&arrayRandomNumber[i], sizeof(int));
//	}
//	outfile.close();

	int arrayRandomNumber[MAXQUEST];
	streampos size;
	ifstream infile("DSRandom.txt", ios::in | ios::binary | ios::ate);
	if(infile == NULL){
		cout << "Loi file" << endl;
		return false;
	}
	size = infile.tellg();
	infile.seekg(0, ios::beg);
	int index;
	infile.read((char*) &index, sizeof(int));
	cout << "index: " << index << "\n";
	for(int i = 0; i < MAXQUEST; i++){
		infile.read((char*) &arrayRandomNumber[i], sizeof(int));
		cout << arrayRandomNumber[i] << "\n";
	}
	infile.close();

//	cout << generateArrayRandomNumber();
	return 0;
}
