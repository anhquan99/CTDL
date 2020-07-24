#ifndef _GUI
#define _GUI
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "Structure.h"
#include <fstream>
#include <time.h>
using namespace std;

// constant
static int green = 10;
static int blue = 11;
static int yellow = 14;
static int red = 12;
static int redWrapper = 192;
//layout
void Layout();
void InnerLayout();
// login form
void Login();
// main menu
void MainMenuGV();
void MainMenuSV();
// create update delete lop
void ThemLop();
void DSLopHoc();
void SuaLop();
void DSSVCuaLop(Lop lop);
// create update delete SV
void ThongTinSV();
void ThemSV();
void SuaSV();
// create udpate mon hoc
void TaoMonHoc();
void SuaMonHoc();
void DSMonHocUI();
// create cau hoi
void TaoCauHoi();
// Thi trac nghiem
void Thi();

// ham giao dien
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void setcursor(bool visible, DWORD size);
void TextColor(int x);
void gotoxy(int x, int y);
void InitWindow();

// ham kiem tra
string kiemtraLop(string maLop, string tenLop, string nienkhoa);
string kiemtraCauHoi(string NoiDung, string A, string B, string C, string D, string DapAn);
// hien hoac an con tro 
void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if(size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
 //set mau
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x, int y) //set vi tri
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

//khoi tao random
void initialArrayRandomNumber(){
	int arrayRandomNumber[MAXQUEST];
	int randomNumber;
	srand(time(NULL));
	int temp;
	for(int i = 0; i < MAXQUEST; i++){  
		arrayRandomNumber[i] = i;
	}
	arrayRandomNumber[0] = MAXQUEST/2;
	arrayRandomNumber[MAXQUEST/2] = 0;
	for(int i = 1; i < MAXQUEST-1; i++){
		randomNumber = rand() % (MAXQUEST - i)+1;
		//cout << "randomNumber = " << randomNumber << endl;
		temp = arrayRandomNumber[MAXQUEST-i];
		arrayRandomNumber[MAXQUEST-i] = arrayRandomNumber[randomNumber];
		//cout <<"arrayRandomNumber[MAXQUEST-i] = " << arrayRandomNumber[MAXQUEST-i] << endl;	
		arrayRandomNumber[randomNumber] = temp;		
		//cout <<"arrayRandomNumber[randomNumber] = " << arrayRandomNumber[randomNumber] << endl;	
	}
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
// random 
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
	if(index == MAXQUEST) return -1;
//	cout << "index: " << index << "\n";
	for(int i = 0; i < MAXQUEST; i++){
		infile.read((char*) &arrayRandomNumber[i], sizeof(int));
//		cout << arrayRandomNumber[i] << "\n";
	}
	infile.close();
	int temp = arrayRandomNumber[index];
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

void InitWindow(){		//set vi tri va chieu dai, rong cua window
	HWND consoleWindow = GetConsoleWindow();
	system("mode 150");
	SetWindowPos( consoleWindow, 0, 30, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
}
void Layout(){
	system("cls");
	setcursor(0,0);
	TextColor(12);
	gotoxy(40,0);
	printf("DUNG PHIM LEN XUONG DE DIEU HUONG  ||  ENTER DE NHAP || ESC DE QUAY LAI");
	gotoxy(50,1);
	printf("-------------------------------------");
	gotoxy(40,2);
	printf("POSTS AND TELECOMMUNICATIONS INSTITUTE OF TECHNOLOGY");
	
}
void InnerLayout(){
	system("cls");
	setcursor(0,0);
	TextColor(12);
	gotoxy(30,0);
	printf("DUNG PHIM LEN XUONG DE DIEU HUONG  ||  ENTER DE CHON || ESC DE QUAY LAI || N DE THEM || X DE XOA || F DE SUA ");
	gotoxy(50,1);
	printf("-------------------------------------");
	gotoxy(40,2);
	printf("POSTS AND TELECOMMUNICATIONS INSTITUTE OF TECHNOLOGY");
	
}
void Login(){
	gotoTop:
	Layout();
	setcursor(1,1);
	string UserAndPass[2] = {""};// [0] : username; [1]: password
	int row = 4;
	int col[2] = {45,45};
	int size[2] = {0};
	TextColor(red);
	gotoxy(60,3);
	printf("DANG NHAP");
	TextColor(blue);
	gotoxy(35,4);
	printf("USERNAME:");
	gotoxy(35,5);
	printf("PASSWORD:");
	gotoxy(col[row - 4] + size[row -4], row);
	TextColor(green);
	while(1){
		int input = getch();
		if(input == 72){	//up
			if(row>4){
				row--;
				gotoxy(col[0] + size[0], 4);
			}
		}
		else if(input == 80){	//down
			if(row<5){
				row++;
				gotoxy(col[1] + size[1], 5);
			}
		}
		else if( input == 13 ){ //enter
			if( UserAndPass[0] == "GV" && UserAndPass[1] == "gv"){
				MainMenuGV();
				goto gotoTop;
			}
//			else{
//				// duyet qua tat ca sinh vien tim ra sinh vien khop voi username va password
//				// neu khong khop thi bung ra cai bang khong tim thay
//				goto gotoTop;
//			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,"XIN DANG NHAP LAI!!!","THONG BAO",0);
		}
		else if( input == 8 ){ //backspace
			if( UserAndPass[row-4].length() > 0){
				gotoxy(col[row - 4]+ size[row - 4]-1,row);
				printf(" ");
				size[row - 4]--;
				UserAndPass[row - 4].pop_back();
				gotoxy(col[row - 4]+ size[row - 4],row);
			}
		}
		else if( input == 27 ){ //thoat 
			return ;
		}
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
		// username
			if(((input>=48&&input<=57)||(input>=97&&input<=122))&& UserAndPass[row - 4].length() < 50 && row  == 4){
					gotoxy(col[row-4]+size[row-4],row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					UserAndPass[row-4].push_back(ch);
					size[row-4]++;
				}
			// password
			if(((input>=48&&input<=57)|| (input>=65&&input<=90) ||(input>=97&&input<=122)) && UserAndPass[row - 4].length() < 50 && row  == 5){
					gotoxy(col[row-4]+size[row-4],row);
					char ch = (char) input;
					printf("*");
					UserAndPass[row-4].push_back(ch);
					size[row-4]++;
				}
		}
	}
}
void MainMenuGV(){
	gotoTop:
	InnerLayout();
	string func[2] = {"LOP", "MON HOC"};
	int row = 4;
	int x = 55;
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("DANG NHAP");
	gotoxy(x,row);
	TextColor(192);
	cout << func[0] << "\n";
	TextColor(blue);
	for(int i=1;i<2;i++){
		gotoxy(x,row + i);
		cout  << func[i] << "\n";
	}	
	TextColor(green);
	while(1){
		int input;
		input  = getch();
		switch(input){
			case 72:
				if(row>4){
					gotoxy(x,row);
					TextColor(blue);
					cout  << func[row -4] << "\n";
//					printf("%s\n",func[row-2]);
					row--;
					gotoxy(x,row);
					TextColor(redWrapper);
					cout  << func[row -4] << "\n";
//					printf("%s\n",func[row-2]);
					TextColor(green);
				}
				break;
			case 80:
			if(row<5){
					gotoxy(x,row);
					TextColor(blue);
					cout  << func[row -4] << "\n";
//					printf("%s\n",func[row-2]);
					row++;
					gotoxy(x,row);
					TextColor(redWrapper);
					cout  << func[row -4] << "\n";
//					printf("%s\n",func[row-2]);
					TextColor(green);
				}
				break;	
			case 13:
				switch(row){
					case 4:	//lop 
						DSLopHoc();
						goto gotoTop;
					case 5:	//mon hoc
						DSMonHocUI();
						goto gotoTop;			
				}	
				break;
			case 27:
				return;		
		}
	}	
}
void DSLopHoc(){
	gotoTop:
	InnerLayout();
	int row = 4;
	int x = 40;
	string lop[3] = {"MA LOP", "TEN LOP", "NIEN KHOA"};
	int col = 10;
	string nk = "";
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("DANH SACH LOP");
	TextColor(green);
	gotoxy(40, row);
	cout << "NIEN KHOA:";
	for( int i = 0; i < 3; i++){
		gotoxy((i+1)*30, 5);
		cout << lop[i];
	}
	gotoxy(50, row);
	setcursor(1,1);
	// load danh sach lop theo mang de len xuong cho de dang
	// tao 1 cai filter de search	
	while(1){
		int input = getch();
		if(input == 72){	//	up
			if(row>4){
				row--;
				if(row == 5){
					setcursor(1,1);
					row--;
					gotoxy( x + col + nk.length(), row);
				}
			}
			// else load the list should be index
			else{
				
			}
		}
		else if(input == 80){	// down
			if(row<6){ // if row < array.length
				row++;
				setcursor(0,0);
				if(row == 5){
					row++;
				}
				//	load the list should be index
			}
		}
		else if( input == 13 ){ //enter
			if(row == 4){
				//	iterate throught the array to search the right element
			}
			else{
				// move to deatil view
			}
		}
		else if( input == 8 ){ //backspace
			if( row == 4){
				if( nk.length() > 0){
					gotoxy( x + col+ nk.length(),row);
					printf(" ");
					nk.pop_back();
					gotoxy( x + col + nk.length() + 1,row);
				}
			}
		}
		else if( input == 102){ // sua
			
		}
		else if( input == 120){	// xoa
			MessageBox(0,"XIN DANG NHAP LAI!!!","THONG BAO",0);
		}
		else if( input == 110){// them moi
			ThemLop();
			goto gotoTop;
		}
		else if( input == 27){
			return;
		}
		else{ // input char 
			if(((input>=48&&input<=57)||(input == 45)) && nk.length() < 9){
					gotoxy( x + col+ nk.length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					nk.push_back(ch);
			}
		}	
	}
}
void ThemLop(){
	Layout();
	int row = 4;
	int x = 30;
	string lop[3] = {"MA LOP:", "TEN LOP:", "NIEN KHOA:"};
	int col[3] ={7, 8, 10 };
	string inputLop[3] = {""}; // [0]: ma lop; [1]: ten lop; [2]: nien khoa
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("THEM LOP");
	TextColor(blue);
	for( int i = 0; i < 3; i++){
		gotoxy(x, row + i);
		cout << lop[i];
	}
	setcursor(1,1);
	gotoxy(x + col[row - 4] + inputLop[ row - 4].length() + 1, row);
	TextColor(green);
	while(1){
		int input = getch();
		if(input == 72){	//up
			if(row>4){
				row--;
				gotoxy( x + col[row -4] + inputLop[row - 4].length() + 1, row);
			}
		}
		else if(input == 80){	//down
			if(row<6){
				row++;
				gotoxy( x + col[row - 4 ] + inputLop[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			string flag = kiemtraLop( inputLop[0], inputLop[1], inputLop[2]);
			if(flag == "true"){
				// ham them lop
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,"XIN DANG NHAP LAI!!!","THONG BAO",0);
		}
		else if( input == 8 ){ //backspace
			if( inputLop[row-4].length() > 0){
				gotoxy( x+ col[row - 4]+ inputLop[row - 4].length(),row);
				printf(" ");
				inputLop[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputLop[row - 4].length() + 1,row);
			}
		}
		else if( input == 27){
			return;
		}
		else{ // input char 
			if(((input>=48&&input<=57)||(input>=97&&input<=122)) && inputLop[row - 4].length() < 50 && row != 6){
					gotoxy( x + col[row-4]+inputLop[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputLop[row-4].push_back(ch);
			}
			else if(((input>=48&&input<=57)||(input == 45)) && inputLop[row - 4].length() < 9 && row == 6){
					gotoxy( x + col[row-4]+inputLop[row - 4].length() + 1,row);
					char ch = (char) input;
//					ch = toupper(ch);
					printf("%c",ch);
					inputLop[row - 4].push_back(ch);
			}
		}
	}
}
void SuaLop(int id){
	//tim kiem xong hien thi thong tin cua lop
	//---------------------------------------//
	//---------------------------------------//
	Layout();
	int row = 4;
	int x = 30;
	string lop[3] = {"MA LOP:", "TEN LOP:", "NIEN KHOA:"};
	int col[3] ={7, 8, 10 };
	string inputLop[3] = {""}; // [0]: ma lop; [1]: ten lop; [2]: nien khoa
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("THEM LOP");
	TextColor(blue);
	for( int i = 0; i < 3; i++){
		gotoxy(x, row + i);
		cout << lop[i];
	}
	setcursor(1,1);
	gotoxy(x + col[row - 4] + inputLop[ row - 4].length() + 1, row);
	TextColor(green);
	while(1){
		int input = getch();
		if(input == 72){	//up
			if(row>4){
				row--;
				gotoxy( x + col[row -4] + inputLop[row - 4].length() + 1, row);
			}
		}
		else if(input == 80){	//down
			if(row<6){
				row++;
				gotoxy( x + col[row - 4 ] + inputLop[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			string flag = kiemtraLop( inputLop[0], inputLop[1], inputLop[2]);
			if(flag == "true"){
				// ham them lop
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,"XIN DANG NHAP LAI!!!","THONG BAO",0);
		}
		else if( input == 8 ){ //backspace
			if( inputLop[row-4].length() > 0){
				gotoxy( x+ col[row - 4]+ inputLop[row - 4].length(),row);
				printf(" ");
				inputLop[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputLop[row - 4].length() + 1,row);
			}
		}
		else{ // input char 
			if(((input>=48&&input<=57)||(input>=97&&input<=122)) && inputLop[row - 4].length() < 50 && row != 6){
					gotoxy( x + col[row-4]+inputLop[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputLop[row-4].push_back(ch);
			}
			else if(((input>=48&&input<=57)||(input == 45)) && inputLop[row - 4].length() < 9 && row == 6){
					gotoxy( x + col[row-4]+inputLop[row - 4].length() + 1,row);
					char ch = (char) input;
//					ch = toupper(ch);
					printf("%c",ch);
					inputLop[row - 4].push_back(ch);
			}
		}
	}
}
void DSSVCuaLop(Lop lop){
	InnerLayout();
	int row = 4;
	int x = 55;
	string sv[4] = {"MSV", "HO", "TEN", "PHAI"};
	//create banner
	TextColor(red);
	gotoxy(50,3);
	cout << "DANH SACH SINH VIEN CUA LOP " << lop.TENLOP;
	TextColor(blue);
	for( int i = 0; i < 4; i++){
		gotoxy((i+1)*25, row);
		cout << sv[i];
	}
	setcursor(1,1);
	// load danh sach sinh vien cua lop theo mang de len xuong cho de dang
	while(1){
		int input;
		input  = getch();
		switch(input){
				
		}		
	}
}
void ThemSV(){
	Layout();
	int row = 4;
	int x = 30;
	string sv[4] = {"HO:", "TEN:", "PHAI:", "PASSWORD:"};
	int col[4] ={3, 4, 5, 9 };
	string inputSV[4] = {""}; // [0]: HO; [1]: TEN; [2]: PHAI; [3]: PASSWORD
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("THEM SINH VIEN");
	TextColor(blue);
	for( int i = 0; i < 4; i++){
		gotoxy(x, row + i);
		cout << sv[i];
	}
	setcursor(1,1);
	gotoxy(x + col[row - 4] + inputSV[ row - 4].length() + 1, row);
	TextColor(green);
	while(1){
		int input = getch();
		if(input == 72){	//up
			if(row>4){
				row--;
				gotoxy( x + col[row -4] + inputSV[row - 4].length() + 1, row);
			}
		}
		else if(input == 80){	//down
			if(row<7){
				row++;
				gotoxy( x + col[row - 4 ] + inputSV[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			MessageBox(0,"XIN DANG NHAP LAI!!!","THONG BAO",0);
		}
		else if( input == 8 ){ //backspace
			if( inputSV[row-4].length() > 0){
				gotoxy( x+ col[row - 4]+ inputSV[row - 4].length(),row);
				printf(" ");
				inputSV[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputSV[row - 4].length() + 1,row);
			}
		}
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if((input>=48&&input<=57)||(input>=97&&input<=122) && inputSV[row - 4].length() < 50){
					gotoxy( x + col[row-4]+inputSV[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputSV[row-4].push_back(ch);
				}
		}
	}
}
void TaoMonHoc(){
	Layout();
	int row = 4;
	int x = 30;
	string mh[3] = {"MA MON HOC:", "TEN MON HOC:", "THOI GIAN THI:"};
	int col[3] ={11, 12, 14};
	string inputMH[4] = {""}; // [0]: MA MON HOC; [1]: TEN MON HOC; [2]: THOI GIAN THI
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("THEM MON HOC");
	TextColor(blue);
	for( int i = 0; i < 3; i++){
		gotoxy(x, row + i);
		cout << mh[i];
	}
	setcursor(1,1);
	gotoxy(x + col[row - 4] + inputMH[ row - 4].length() + 1, row);\
	TextColor(green);
	while(1){
		int input = getch();
		if(input == 72){	//up
			if(row>4){
				row--;
				gotoxy( x + col[row -4] + inputMH[row - 4].length() + 1, row);
			}
		}
		else if(input == 80){	//down
			if(row<6){
				row++;
				gotoxy( x + col[row - 4 ] + inputMH[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			MessageBox(0,"XIN DANG NHAP LAI!!!","THONG BAO",0);
		}
		else if( input == 8 ){ //backspace
			if( inputMH[row-4].length() > 0){
				gotoxy( x+ col[row - 4]+ inputMH[row - 4].length(),row);
				printf(" ");
				inputMH[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputMH[row - 4].length() + 1,row);
			}
		}
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if((input>=48&&input<=57)||(input>=97&&input<=122) && inputMH[row - 4].length() < 50){
					gotoxy( x + col[row-4]+inputMH[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputMH[row-4].push_back(ch);
				}
		}
	}
}
void SuaMonHoc(){
	
}
void DSMonHocUI(){
	gotoTop:
	InnerLayout();
	int row = 4;
	int x = 40;
	string mon[3] = {"MA MON HOC", "TEN MON HOC", "THOI GIAN THI"};
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("DANH SACH MON HOC");
	TextColor(blue);
	for( int i = 0; i < 3; i++){
		gotoxy((i+1)*30, row);
		cout << mon[i];
	}
	// load danh sach mon hoc theo mang de len xuong cho de dang
	// bat dau to mau cho dau danh sach 
	while(1){
		int input = getch();
		if(input == 72){	//	up
			if(row>6){
				row--;
			}
			// else load the list should be index
			else{
				
			}
		}
		else if(input == 80){	// down
			if(row<6){ // if row < array.length
				row++;
				setcursor(0,0);
				if(row == 5){
					row++;
				}
				//	load the list should be index
			}
		}
		else if( input == 13 ){ //enter
			if(row == 4){
				//	iterate throught the array to search the right element
			}
			else{
				// move to deatil view
			}
		}
		else if( input == 102){ // sua
			
		}
		else if( input == 120){	// xoa
			MessageBox(0,"XIN DANG NHAP LAI!!!","THONG BAO",0);
		}
		else if( input == 110){// them moi
			TaoMonHoc();
			goto gotoTop;
		}
		else if( input == 27){	//ESC
			return;
		}	
	}
}

// chon mon hoc roi moi tao cau hoi
void TaoCauHoi(string maMH){
	Layout();
	int row = 4;
	int x = 30;
	string cauhoi[7] = {"MA MON HOC:", "NOI DUNG:", "A:", "B:", "C:", "D:", "DAP AN:"};
	int col[7] ={11, 9, 2, 2, 2, 2, 7};
	string inputCauHoi[6] = {""}; // [0]: MA MON HOC; [1]: NOI DUNG; [2]: A; [3]: B; [4]: C; [5]: D; [6]: DAP AN
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("THEM MON HOC");
	TextColor(blue);
	for( int i = 0; i < 7; i++){
		gotoxy(x, row + i);
		cout << cauhoi[i];
	}
	setcursor(1,1);
	gotoxy(x + col[row - 4] + inputCauHoi[ row - 4].length() + 1, row);
	TextColor(green);
	while(1){
		int input = getch();
		if(input == 72){	//up
			if(row>4){
				row--;
				gotoxy( x + col[row -4] + inputCauHoi[row - 4].length() + 1, row);
			}
		}
		else if(input == 80){	//down
			if(row<10){
				row++;
				gotoxy( x + col[row - 4 ] + inputCauHoi[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			string flag = kiemtraCauHoi(inputCauHoi[1], inputCauHoi[2], inputCauHoi[3], inputCauHoi[4], inputCauHoi[5], inputCauHoi[6]);
			if(flag == "true"){
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,"XIN NHAP LAI!!!","THONG BAO",0);	
		}
		else if( input == 8 ){ //backspace
			if( inputCauHoi[row-4].length() > 0){
				gotoxy( x+ col[row - 4]+ inputCauHoi[row - 4].length(),row);
				printf(" ");
				inputCauHoi[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputCauHoi[row - 4].length() + 1,row);
			}
		}
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if((input>=48&&input<=57)||(input>=97&&input<=122) && inputCauHoi[row - 4].length() < 50){
					gotoxy( x + col[row-4]+inputCauHoi[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputCauHoi[row-4].push_back(ch);
				}
		}
	}
}
void MainMenuSV(){
	InnerLayout();
	// load tat ca mon thi vao trong array roi bat dau in no ra 
	string func[3] = {"LOP", "MON HOC", "LICH THI"};
	int row = 4;
	int x = 55;
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("DANG NHAP");
	gotoxy(x,row);
	TextColor(redWrapper);
	cout << func[0] << "\n";
	TextColor(blue);
	for(int i=1;i<3;i++){
		gotoxy(x,row + i);
		cout  << func[i] << "\n";
	}	
//	while(1){
//		int input;
//		input  = getch();
//		switch(input){
//			case 72:
//				if(row>4){
//					gotoxy(x,row);
//					TextColor(2);
//					cout  << func[row -4] << "\n";
////					printf("%s\n",func[row-2]);
//					row--;
//					gotoxy(x,row);
//					TextColor(192);
//					cout  << func[row -4] << "\n";
////					printf("%s\n",func[row-2]);
//					TextColor(2);
//				}
//				break;
//			case 80: 
//			if(row<6){
//					gotoxy(x,row);
//					TextColor(2);
//					cout  << func[row -4] << "\n";
////					printf("%s\n",func[row-2]);
//					row++;
//					gotoxy(x,row);
//					TextColor(192);
//					cout  << func[row -4] << "\n";
////					printf("%s\n",func[row-2]);
//					TextColor(2);
//				}
//				break;	
//			case 13:
//				switch(row){
//					case 2:	//cap nhap danh sach may bay
////						goto gototop;
//						break;
//					case 3:	//cap nhap chuyen bay
////						goto gototop;
//						break;
//					case 4:	//dat ve
////						goto gototop;
//						break;
//					case 5:	//huy ve
////						goto gototop;
//						break;
//					case 6: //danh sach khach hang trong chuyen bay
////						goto gototop;
//						break;
//					case 7:	//danh sach cac chuyen bay con trong cho
//						setcursor(1,1);
////						goto gototop;
//						break;
//					case 8:	//thong ke
////						goto gototop;
//						break;
//					case 9:	//exit
//						return;
//						break;
//						
//				}			
//		}
//	}	
}

// ham kiem tra
string kiemtraLop(string maLop, string tenLop, string nienkhoa){
	return "true";
}
string kiemtraCauHoi(string NoiDung, string A, string B, string C, string D, string DapAn){
	return "true";
}
//-----

#endif
