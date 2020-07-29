#ifndef _GUI
#define _GUI
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "Structure.h"
#include <fstream>
#include <time.h>
#include "TDV.h"
using namespace std;

// constant
static int green = 10;
static int blue = 11;
static int yellow = 14;
static int red = 12;
static int redWrapper = 192;
static string pass = "THANH CONG";
//layout
void Layout();
void InnerLayout();
void ChitietDemLayout();
// login form
void Login(DSLop &dsLop, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi);
// main menu
void MainMenuGV(DSLop &dsLop, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi);
void MainMenuSV();
// create update delete lop
void ThemLop(DSLop &dsLop);
void DSLopHoc(DSLop &dsLop, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi);
void SuaLop(Lop &lop, DSLop dsLop);
void DSSVCuaLop(Lop &lop, DSLop dsLop, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi);
// create update delete SV
//void ThongTinSV();
void ThemSV(Lop &lop, DSLop dsLop);
void SuaSV(ptrsv &sv);
void DSDiemCuaSV(ptrsv sv, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi);
void ChiTietDT(ptrDT dt, ptrDSCauHoi dsCauHoi);
// create udpate mon hoc
void TaoMonHoc(DSMonHoc &dsMonHoc);
void SuaMonHoc(MonHoc &monHoc);
void DSMonHocUI(DSMonHoc &dsMonHoc, ptrDSCauHoi &dsCauHoi);
// create cau hoi
void TaoCauHoi(MonHoc monHoc, ptrDSCauHoi &dsCauHoi);
void DSCauHoiTheoMonHoc(MonHoc monHoc, ptrDSCauHoi &dsCauHoi);
void SuaCauHoi(ptrDSCauHoi &CauHoi);
// Thi trac nghiem
void Thi();

// ham giao dien
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void setcursor(bool visible, DWORD size);
void TextColor(int x);
void gotoxy(int x, int y);
void InitWindow();

// ham kiem tra
string kiemtraLop(string maLop, string tenLop, string nienkhoa, DSLop classlist);
string kiemtraSuaLop(string maLop, string maLopCu, string tenLop, string nienkhoa, DSLop classlist);
string kiemtraCauHoi(string NoiDung, string A, string B, string C, string D, string DapAn);
string kiemtraSinhVien(string inputSV[5], DSLop dsLop);
string kiemtraSuaSinhVien(string inputSV[5]);
string kiemtraMonHoc(string inputMH[2], DSMonHoc dsMonHoc);
string kiemtraSuaMonHoc(string inputMH[2]);
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
void ChitietDemLayout(){
	system("cls");
	setcursor(0,0);
	TextColor(12);
	gotoxy(30,0);
	printf("DUNG PHIM < > DE DIEU HUONG  || ESC DE QUAY LAI ");
	gotoxy(50,1);
	printf("-------------------------------------");
	gotoxy(40,2);
	printf("POSTS AND TELECOMMUNICATIONS INSTITUTE OF TECHNOLOGY");
}
void Login(DSLop &dsLop, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi){
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
				MainMenuGV(dsLop, dsMonHoc, dsCauHoi);
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
void MainMenuGV(DSLop &dsLop, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi){
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
						DSLopHoc(dsLop, dsMonHoc, dsCauHoi);
						goto gotoTop;
					case 5:	//mon hoc
						DSMonHocUI(dsMonHoc, dsCauHoi);
						goto gotoTop;			
				}	
				break;
			case 27:
				return;		
		}
	}	
}
void DSLopHoc(DSLop &dsLop, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi){
	gotoTop:
	InnerLayout();
	int row = 4;
	int x = 40;
	string lop[3] = {"MA LOP", "TEN LOP", "NIEN KHOA"};
	int col = 10;
	string nk = "";
	gotoCurrent:
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("DANH SACH LOP");
	TextColor(green);
	gotoxy(40, row);
	cout << "NIEN KHOA: " << nk;
	TextColor(blue);
	for( int i = 0; i < 3; i++){
		gotoxy((i+1)*30, 5);
		cout << lop[i];
	}
	TextColor(green);
	DSLop subList = inDanhSachLopTheoNienKhoa(dsLop, nk);
	for(int i = 0; i < subList.index; i++){
		gotoxy(30, 6 + i);
		cout << subList.lop[i]->MALOP;
		gotoxy(60, 6 + i);
		cout << subList.lop[i]->TENLOP;
		gotoxy(90, 6 + i);
		cout << subList.lop[i]->NK;
	}
	gotoxy(50 + nk.length() + 1, row);
	setcursor(1,1);
	// load danh sach lop theo mang de len xuong cho de dang
	// tao 1 cai filter de search	
	while(1){
		int input = getch();
		if(input == 72){	//	up
			if(row>4){
				TextColor(green);
				gotoxy(30, row);
				cout << subList.lop[row - 6]->MALOP;
				gotoxy(60, row);
				cout << subList.lop[row - 6]->TENLOP;
				gotoxy(90, row);
				cout << subList.lop[row - 6]->NK;
				row--;
				if( row == 5){
					row--;
					setcursor(1,1);
					gotoxy(50 + nk.length() + 1, row);
				}
				else{
					TextColor(redWrapper);
					gotoxy(30, row);
					cout << subList.lop[row - 6]->MALOP;
					gotoxy(60, row);
					cout << subList.lop[row - 6]->TENLOP;
					gotoxy(90, row);
					cout << subList.lop[row - 6]->NK;
					TextColor(green);
				}
			}
			// else load the list should be index
		}
		else if(input == 80){	// down
			if(subList.index > 0){
				if(row + 1 < subList.index + 6){ // if row < array.length
					if( row == 4){
						row = 6;
						setcursor(0,0);
						TextColor(redWrapper);
						gotoxy(30, row);
						cout << subList.lop[row - 6]->MALOP;
						gotoxy(60, row);
						cout << subList.lop[row - 6]->TENLOP;
						gotoxy(90, row);
						cout << subList.lop[row - 6]->NK;
						TextColor(green);
					}
					else{
						TextColor(green);
						gotoxy(30, row);
						cout << subList.lop[row - 6]->MALOP;
						gotoxy(60, row);
						cout << subList.lop[row - 6]->TENLOP;
						gotoxy(90, row);
						cout << subList.lop[row - 6]->NK;
						row++;
						TextColor(redWrapper);
						gotoxy(30, row);
						cout << subList.lop[row - 6]->MALOP;
						gotoxy(60, row);
						cout << subList.lop[row - 6]->TENLOP;
						gotoxy(90, row);
						cout << subList.lop[row - 6]->NK;
						TextColor(green);
					}
					//	load the list should be index
					
				}
			}
		}
		else if( input == 13 ){ //enter
			if(row == 4){
				//	iterate throught the array to search the right element
				system("cls");
				InnerLayout();
				goto gotoCurrent;
			}
			else{
				DSSVCuaLop(*subList.lop[row-6], dsLop, dsMonHoc, dsCauHoi);
				goto gotoTop;
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
		else if( input == 102 && row != 4){ // sua
			SuaLop(*subList.lop[row - 6], dsLop);
			goto gotoTop;
		}
		else if( input == 120 && row != 4){	// xoa
			if(subList.lop[row - 6]->sv == NULL){
				int temp = MessageBox(0,"BAN CO CHAC CHAN MUON XOA KHONG ?", "XAC NHAN", MB_YESNO);	//pop up 1 message box
				string maLop = subList.lop[row - 6]->MALOP + ".txt";
				if(temp == 6 && xoaLop(dsLop, *subList.lop[row - 6]) && remove(maLop.c_str()) == 0){
					MessageBox(0,"THANH CONG!!!","THONG BAO",0);
				}
				else{
					MessageBox(0,"KHONG THANH CONG!!!","THONG BAO",0);
				}
				goto gotoTop;
			}
			else{
				MessageBox(0,"KHONG THE XOA LOP!!!","THONG BAO",0);
			}
			
		}
		else if( input == 110){// them lop
			ThemLop(dsLop);
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
void ThemLop(DSLop &dsLop){
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
			string flag = kiemtraLop( inputLop[0], inputLop[1], inputLop[2], dsLop);
			if(flag == pass){
				// ham them lop
				Lop classroom = {inputLop[0], inputLop[1], inputLop[2], NULL};
				insertClassListQ(classroom, dsLop);
				ofstream outfile( inputLop[0] + ".txt", ios::out| ios::app | ios::binary);
				outfile.close();
				// save lop
				// luu danh sach lop moi
				luuDanhSachLopMoi(dsLop);
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,flag.c_str(),"THONG BAO",0);
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
			if(((input>=48&&input<=57)||(input>=97&&input<=122)||(input==32)) && inputLop[row - 4].length() < 50 && row != 6){
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
void SuaLop(Lop &lop, DSLop dsLop){
	Layout();
	int row = 4;
	int x = 30;
	string lopBanner[3] = {"MA LOP:", "TEN LOP:", "NIEN KHOA:"};
	int col[3] ={7, 8, 10 };
	string inputLop[3] = {""}; // [0]: ma lop; [1]: ten lop; [2]: nien khoa
	inputLop[0] = lop.MALOP;
	inputLop[1] = lop.TENLOP;
	inputLop[2] = lop.NK;
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("SUA LOP");
	TextColor(blue);
	for( int i = 0; i < 3; i++){
		gotoxy(x, row + i);
		cout << lopBanner[i];
	}
	// in thong tin cua lop
	setcursor(1,1);
	TextColor(green);
	gotoxy(x + col[0] + 1, 4);
	cout << inputLop[0];
	gotoxy(x + col[1] + 1, 5);
	cout << inputLop[1];
	gotoxy(x + col[2] + 1, 6);
	cout << inputLop[2];
	//
	
	gotoxy(x + col[row - 4] + inputLop[ row - 4].length() + 1, row);
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
			string flag = kiemtraSuaLop( inputLop[0], lop.MALOP, inputLop[1], inputLop[2], dsLop);
			string oldFile = lop.MALOP + ".txt";
			string newFile = inputLop[0] + ".txt";
			int result = rename( oldFile.c_str() , newFile.c_str() );
			if(flag == pass && result == 0){
				// sua lop
				lop.MALOP = inputLop[0];
				lop.TENLOP = inputLop[1];
				lop.NK = inputLop[2];
				luuDanhSachLopMoi(dsLop);
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,flag.c_str(),"THONG BAO",0);
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
			if(((input>=48&&input<=57)||(input>=97&&input<=122)||(input==32)) && inputLop[row - 4].length() < 50 && row != 6){
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
void DSSVCuaLop(Lop &lop, DSLop dsLop, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi) {
	gotoTop:
	InnerLayout();
	setcursor(0,0);
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
	TextColor(green);
	ptrsv current = lop.sv;
	row++;
	while(current != NULL){
		if(current == lop.sv){
			TextColor(redWrapper);
		}
		else{
			TextColor(green);
		}
		gotoxy(25, row);
		cout << current->MSV;
		gotoxy(50, row);
		cout << current->HO;
		gotoxy(75, row);
		cout << current->TEN;
		gotoxy(100, row);
		cout << current->PHAI;
		current = current->next;
		row++;
	}
	ptrsv beforeCurrent = NULL;
	current = lop.sv;
	row = 5;
	// load danh sach sinh vien cua lop theo mang de len xuong cho de dang
	while(1){
		int input = getch();
		if(input == 72){	//	up
			if(beforeCurrent != NULL){
				TextColor(green);
				gotoxy(25, row);
				cout << current->MSV;
				gotoxy(50, row);
				cout << current->HO;
				gotoxy(75, row);
				cout << current->TEN;
				gotoxy(100, row);
				cout << current->PHAI;
				row--;
				current = beforeCurrent;
				beforeCurrent = laySVTruoc(lop, current);
				TextColor(redWrapper);
				gotoxy(25, row);
				gotoxy(25, row);
				cout << current->MSV;
				gotoxy(50, row);
				cout << current->HO;
				gotoxy(75, row);
				cout << current->TEN;
				gotoxy(100, row);
				cout << current->PHAI;
				TextColor(green);
			}
			// else load the list should be index
		}
		else if(input == 80){	// down
			if(current != NULL){
				if(current->next != NULL){
				TextColor(green);
				gotoxy(25, row);
				cout << current->MSV;
				gotoxy(50, row);
				cout << current->HO;
				gotoxy(75, row);
				cout << current->TEN;
				gotoxy(100, row);
				cout << current->PHAI;
				row++;
				current = current->next;
				beforeCurrent = laySVTruoc(lop, current);
				TextColor(redWrapper);
				gotoxy(25, row);
				cout << current->MSV;
				gotoxy(50, row);
				cout << current->HO;
				gotoxy(75, row);
				cout << current->TEN;
				gotoxy(100, row);
				cout << current->PHAI;
				TextColor(green);
			}
			}
		}
		else if( input == 102 && current != NULL){ // sua
			SuaSV(current);
			luuDanhSachSinhVienMoi(lop.MALOP, lop.sv);
			goto gotoTop; 
		}
		else if( input == 120 && current != NULL){	// xoa
			if(current->dsdiemthi == NULL){
				int temp = MessageBox(0,"BAN CO CHAC CHAN MUON XOA KHONG ?", "XAC NHAN", MB_YESNO);	//pop up 1 message box
//				string maLop = subList.lop[row - 6]->MALOP + ".txt";
				if(temp == 6 && xoaSinhVienCuaQ(lop, current)){
					luuDanhSachSinhVienMoi(lop.MALOP, lop.sv);
					MessageBox(0,"THANH CONG!!!","THONG BAO",0);
					goto gotoTop;
				}
				else{
					MessageBox(0,"KHONG THANH CONG!!!","THONG BAO",0);
				}
			}
			else{
				MessageBox(0,"KHONG THE XOA SINH VIEN!!!","THONG BAO",0);
			}
		}
		else if( input == 13 && current != NULL){ //enter
			//ds diem cua sinh vien
			DSDiemCuaSV(current, dsMonHoc, dsCauHoi);
			goto gotoTop;
		}
		else if( input == 110){// them moi
			ThemSV(lop, dsLop);
			goto gotoTop;
		}
		else if( input == 27){
			return;
		}
	}
}
void ThemSV(Lop &lop, DSLop dsLop){
	Layout();
	int row = 4;
	int x = 30;
	string sv[5] = {"MA SINH VIEN:", "HO:", "TEN:", "PHAI:", "PASSWORD:"};
	int col[5] ={13, 3, 4, 5, 9 };
	string inputSV[5] = {""}; // [0]: MSV;[1]: HO; [2]: TEN; [3]: PHAI; [4]: PASSWORD
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("THEM SINH VIEN");
	TextColor(blue);
	for( int i = 0; i < 5; i++){
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
			if(row<8){
				row++;
				gotoxy( x + col[row - 4 ] + inputSV[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			string flag = kiemtraSinhVien(inputSV, dsLop);
			if(flag == pass){
				// ham them lop
				bool phai;
				if(inputSV[3] == "NAM"){
					phai = true;
				}
				else phai = false;
				SV sv = {inputSV[0], inputSV[1], inputSV[2], phai, inputSV[4], NULL, NULL};
				ptrsv temp = lop.sv;
				themSinhVien(temp, sv);
				ofstream outfile( inputSV[0] + ".txt", ios::out| ios::app | ios::binary);
				outfile.close();
				// save lop
				// luu danh sach lop moi
				luuDanhSachSinhVienMoi(lop.MALOP, temp);
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,flag.c_str(),"THONG BAO",0);
			
		}
		else if( input == 8 ){ //backspace
			if( inputSV[row-4].length() > 0){
				gotoxy( x+ col[row - 4]+ inputSV[row - 4].length(),row);
				printf(" ");
				inputSV[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputSV[row - 4].length() + 1,row);
			}
		}
		else if( input == 27){ // esc
			return;
		}
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if(((input>=97&&input<=122)||(input==32)) && inputSV[row - 4].length() < 50 && row != 8 && row != 4){
					gotoxy( x + col[row-4]+inputSV[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputSV[row-4].push_back(ch);	
				}
			if(((input>=48&&input<=57)|| (input>=65&&input<=90) ||(input>=97&&input<=122)) && inputSV[row - 4].length() < 50 && row != 8 && row == 4){
					gotoxy( x + col[row-4]+inputSV[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputSV[row-4].push_back(ch);	
				}
			// password
			if(((input>=48&&input<=57)|| (input>=65&&input<=90) ||(input>=97&&input<=122)) && inputSV[row - 4].length() < 50 && row  == 8){
					gotoxy( x + col[row-4]+ inputSV[row - 4].length() + 1,row);
					char ch = (char) input;
					printf("*");
					inputSV[row-4].push_back(ch);
			}
		}
	}
}

void SuaSV(ptrsv &sv){
	Layout();
	int row = 4;
	int x = 30;
	string svLabel[5] = {"MA SINH VIEN:", "HO:", "TEN:", "PHAI:", "PASSWORD:"};
	int col[5] ={13, 3, 4, 5, 9 };
	string inputSV[5] = {""}; // [0]: MSV;[1]: HO; [2]: TEN; [3]: PHAI; [4]: PASSWORD
	inputSV[0] = sv->MSV;
	inputSV[1] = sv->HO;
	inputSV[2] = sv->TEN;
	if( sv->PHAI){
		inputSV[3] = "NAM";
	}
	else{
		inputSV[3] = "NU";
	}
	inputSV[4] = sv->password;
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("THEM SINH VIEN");
	TextColor(blue);
	for( int i = 0; i < 5; i++){
		gotoxy(x, row + i);
		cout << svLabel[i];
	}
	TextColor(green);
	gotoxy( x + col[0] + 1, 4);
	cout << inputSV[0];
	gotoxy( x + col[1] + 1, 5);
	cout << inputSV[1];
	gotoxy( x + col[2] + 1, 6);
	cout << inputSV[2];
	gotoxy( x + col[3] + 1, 7);
	cout << inputSV[3];
	gotoxy( x + col[4] + 1, 8);
	for(int i = 0; i < inputSV[4].length(); i++){
		cout << "*";
	}
	setcursor(1,1);
	row = 5;
	gotoxy(x + col[row - 4] + inputSV[ row - 4].length() + 1, row);
	while(1){
		int input = getch();
		if(input == 72){	//up
			if(row>5){
				row--;
				gotoxy( x + col[row -4] + inputSV[row - 4].length() + 1, row);
			}
		}
		else if(input == 80){	//down
			if(row<8){
				row++;
				gotoxy( x + col[row - 4 ] + inputSV[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			int temp = MessageBox(0,"BAN CO CHAC CHAN MUON SUA KHONG ?", "XAC NHAN", MB_YESNO);	//pop up 1 message box
			if(temp == 6){
				string flag = kiemtraSuaSinhVien(inputSV);
				if(flag == pass){
					// ham them lop
					bool phai;
					if(inputSV[3] == "NAM"){
						phai = true;
					}
					else phai = false;
					sv->HO = inputSV[1];
					sv->TEN = inputSV[2];
					sv->PHAI = phai;
					sv->password = inputSV[4];
	//				SV sv = {inputSV[0], inputSV[1], inputSV[2], phai, inputSV[4], NULL, NULL};
	//				ptrsv temp = lop.sv;
	//				themSinhVien(temp, sv);
	//				ofstream outfile( inputSV[0] + ".txt", ios::out| ios::app | ios::binary);
	//				outfile.close();
					// save lop
					// luu danh sach lop moi
	//				luuDanhSachSinhVienMoi(lop.MALOP, temp);
					return;
				}
				MessageBeep(MB_ICONWARNING);
				MessageBox(0,flag.c_str(),"THONG BAO",0);
			}
		}
		else if( input == 8 ){ //backspace
			if( inputSV[row-4].length() > 0){
				gotoxy( x+ col[row - 4]+ inputSV[row - 4].length(),row);
				printf(" ");
				inputSV[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputSV[row - 4].length() + 1,row);
			}
		}
		else if( input == 27){ // esc
			return;
		}
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if(((input>=97&&input<=122)||(input==32)) && inputSV[row - 4].length() < 50 && row != 8 && row != 4){
					gotoxy( x + col[row-4]+inputSV[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputSV[row-4].push_back(ch);	
				}
			if(((input>=48&&input<=57)|| (input>=65&&input<=90) ||(input>=97&&input<=122)) && inputSV[row - 4].length() < 50 && row != 8 && row == 4){
					gotoxy( x + col[row-4]+inputSV[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputSV[row-4].push_back(ch);	
				}
			// password
			if(((input>=48&&input<=57)|| (input>=65&&input<=90) ||(input>=97&&input<=122)) && inputSV[row - 4].length() < 50 && row  == 8){
					gotoxy( x + col[row-4]+ inputSV[row - 4].length() + 1,row);
					char ch = (char) input;
					printf("*");
					inputSV[row-4].push_back(ch);
			}
		}
	}
}
void DSDiemCuaSV(ptrsv sv, DSMonHoc dsMonHoc, ptrDSCauHoi dsCauHoi) {
	gotoTop:
	InnerLayout();
	setcursor(0,0);
	int row = 4;
	int x = 55;
	string dtLabel[3] = {"MA MON HOC", "SO CAU HOI", "DIEM"};
	//create banner
	TextColor(red);
	gotoxy(50,3);
	cout << "DANH SACH DIEM THI CUA SINH VIEN: " << sv->MSV;
	TextColor(blue);
	for( int i = 0; i < 3; i++){
		gotoxy((i+1)*25, row);
		cout << dtLabel[i];
	}
	TextColor(green);
	ptrDT current = sv->dsdiemthi;
	row++;
	while(current != NULL){
		if(current == sv->dsdiemthi){
			TextColor(redWrapper);
		}
		else{
			TextColor(green);
		}
		gotoxy(25, row);
		cout << current->MAMH;
		gotoxy(50, row);
		cout << current->SoCau;
		gotoxy(75, row);
		cout << current->DIEM;
		for(int i = 0; i < dsMonHoc.index; i++){
			if(current->MAMH == dsMonHoc.ds[i]->MAMH){
				dsMonHoc.ds[i] = dsMonHoc.ds[dsMonHoc.index - 1];
				dsMonHoc.index--;
				break;
			}
		}
		row++;
		current = current->next;
	}
	for(int i = 0; i < dsMonHoc.index; i++){
		gotoxy(25, row + i);
		cout << dsMonHoc.ds[i]->MAMH;
//		gotoxy(50, row);
//		cout << current->SoCau;
		gotoxy(75, row + i);
		cout << "CHUA THI";
	}
	ptrDT beforeCurrent = NULL;
	current = sv->dsdiemthi;
	row = 5;
	// load danh sach sinh vien cua lop theo mang de len xuong cho de dang
	while(1){
		int input = getch();
		if(input == 72){	//	up
			if(beforeCurrent != NULL){
				TextColor(green);
				gotoxy(25, row);
				cout << current->MAMH;
				gotoxy(50, row);
				cout << current->SoCau;
				gotoxy(75, row);
				cout << current->DIEM;
				row--;
				current = beforeCurrent;
				beforeCurrent = layDTTruoc(*sv, current);
				TextColor(redWrapper);
				gotoxy(25, row);
				cout << current->MAMH;
				gotoxy(50, row);
				cout << current->SoCau;
				gotoxy(75, row);
				cout << current->DIEM;
				TextColor(green);
			}
			// else load the list should be index
		}
		else if(input == 80){	// down
			if(current != NULL){
				if(current->next != NULL){
				TextColor(green);
				gotoxy(25, row);
				cout << current->MAMH;
				gotoxy(50, row);
				cout << current->SoCau;
				gotoxy(75, row);
				cout << current->DIEM;
				row++;
				current = current->next;
				beforeCurrent = layDTTruoc(*sv, current);
				TextColor(redWrapper);
				gotoxy(25, row);
				cout << current->MAMH;
				gotoxy(50, row);
				cout << current->SoCau;
				gotoxy(75, row);
				cout << current->DIEM;
				TextColor(green);
			}
			}
		}
		else if( input == 13 && current != NULL){ //enter
			//ds diem cua sinh vien
			ChiTietDT(current, dsCauHoi);
			goto gotoTop;
		}
		else if( input == 27){
			return;
		}
	}
}

//chua xong
void ChiTietDT(ptrDT dt, ptrDSCauHoi dsCauHoi){
	ChitietDemLayout();
	gotoxy(10,10);
	for(int i=0;i<dt->SoCau;i++){
		cout << dt->DSCauHoi[i] << endl;
	}
	while(1){
		
	}
//	ptrDSCauHoi cauHoi = dsCauHoi;
//	int index = 0;
//	gotoTop:
//	ChitietDemLayout();
//	setcursor(0,0);
//	int row = 4;
//	int x = 55;
//	string dtLabel[7] = {"CAU HOI:", "A", "B", "C", "D", "DAP AN", "CAU TRA LOI"};
//	int col[7] = {8, 1, 1, 1, 1,  6, 11};
//	//create banner
//	TextColor(red);
//	gotoxy(50,3);
//	cout << "DANH SACH CAU TRA LOI MON THI: " << dt->MAMH;
//	TextColor(blue);
//	for( int i = 0; i < 7; i++){
//		gotoxy(25, row + i);
//		cout << dtLabel[i];
//	}
//	TextColor(green);
//	gotoxy(25 + col[0] + 1, 4);
//	cout << cauHoi->cauhoi.NoiDung;
//	gotoxy(25 + col[1] + 1, 5);
//	cout << cauHoi->cauhoi.A;
//	gotoxy(25 + col[2] + 1, 6);
//	cout << cauHoi->cauhoi.B;
//	gotoxy(25 + col[3] + 1, 7);
//	cout << cauHoi->cauhoi.C;
//	gotoxy(25 + col[4] + 1, 8);
//	cout << cauHoi->cauhoi.D;
//	gotoxy(25 + col[5] + 1, 9);
//	cout << cauHoi->cauhoi.DapAn;
//	gotoxy(25 + col[6] + 1, 10);
//	cout << dt->DapAn[index];
//	row = 5;
//	setcursor(0,0);
//	// load danh sach sinh vien cua lop theo mang de len xuong cho de dang
//	while(1){
//		int input = getch();
//		gotoxy(10,10);
//		cout << input;
//		if(input == 46 && index > 0){	//	left
//			index--;
//			cauHoi = timKiemCauHoiTheoId(dt->DSCauHoi[index], dsCauHoi);
//			goto gotoTop;
//		}
//		else if(input == 47 && index < dt->SoCau){	// right
//			index++;
//			cauHoi = timKiemCauHoiTheoId(dt->DSCauHoi[index], dsCauHoi);
//			goto gotoTop;
//		}
//		else if( input == 27){
//			return;
//		}
//	}
}
void TaoMonHoc(DSMonHoc &dsMonHoc){
	Layout();
	int row = 4;
	int x = 30;
	string mh[2] = {"MA MON HOC:", "TEN MON HOC:"};
	int col[2] ={11, 12};
	string inputMH[2] = {""}; // [0]: MA MON HOC; [1]: TEN MON HOC
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("THEM MON HOC");
	TextColor(blue);
	for( int i = 0; i < 2; i++){
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
			if(row<5){
				row++;
				gotoxy( x + col[row - 4 ] + inputMH[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			string flag = kiemtraMonHoc(inputMH, dsMonHoc);
			MonHoc monHoc = {inputMH[0], inputMH[1]};
			if(flag == pass && themMonHocTheoThuTuMaMonHoc(dsMonHoc, monHoc)){
				luuDanhSachMonHoc(dsMonHoc);
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,flag.c_str(),"THONG BAO",0);
			
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
			if(((input>=48&&input<=57)||(input>=97&&input<=122)) && inputMH[row - 4].length() < 50 && row == 4){
					gotoxy( x + col[row-4]+inputMH[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputMH[row-4].push_back(ch);
				}
			if(((input>=48&&input<=57)||(input>=97&&input<=122)||(input==32)) && inputMH[row - 4].length() < 50 && row == 5){
					gotoxy( x + col[row-4]+inputMH[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputMH[row-4].push_back(ch);
				}
		}
		else if( input == 27){	//ESC
			return;
		}
	}
}
void SuaMonHoc(MonHoc &monHoc){
	Layout();
	int row = 4;
	int x = 30;
	string mh[2] = {"MA MON HOC:", "TEN MON HOC:"};
	int col[2] ={11, 12};
	string inputMH[2] = {monHoc.MAMH, monHoc.TENMH}; // [0]: MA MON HOC; [1]: TEN MON HOC
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("THEM MON HOC");
	TextColor(blue);
	for( int i = 0; i < 2; i++){
		gotoxy(x, row + i);
		cout << mh[i];
	}
	TextColor(green);
	gotoxy(x+ col[0] + 1, row);
	cout << monHoc.MAMH;
	gotoxy(x+ col[1] + 1, row + 1);
	cout << monHoc.TENMH;
	setcursor(1,1);
	row = 5;
	gotoxy(x + col[row - 4] + inputMH[ row - 4].length() + 1, row);
	
	while(1){
		int input = getch();
		if( input == 13 ){ //enter
			string flag = kiemtraSuaMonHoc(inputMH);
			if(flag == pass){
				monHoc.TENMH = inputMH[1];
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,flag.c_str(),"THONG BAO",0);
			
		}
		else if( input == 8 ){ //backspace
			if( inputMH[row-4].length() > 0){
				gotoxy( x+ col[row - 4]+ inputMH[row - 4].length(),row);
				printf(" ");
				inputMH[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputMH[row - 4].length() + 1,row);
			}
		}
		else if( input == 27){	//ESC
			return;
		}
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
//			if(((input>=48&&input<=57)||(input>=97&&input<=122)) && inputMH[row - 4].length() < 50 && row == 4){
//					gotoxy( x + col[row-4]+inputMH[row - 4].length() + 1,row);
//					char ch = (char) input;
//					ch = toupper(ch);
//					printf("%c",ch);
//					inputMH[row-4].push_back(ch);
//				}
			if(((input>=48&&input<=57)||(input>=97&&input<=122)||(input==32)) && inputMH[row - 4].length() < 50 && row == 5){
					gotoxy( x + col[row-4]+inputMH[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputMH[row-4].push_back(ch);
				}
		}
	}
}
void DSMonHocUI(DSMonHoc &dsMonHoc, ptrDSCauHoi &dsCauHoi){
	gotoTop:
	InnerLayout();
	int row = 5;
	int x = 40;
	string mon[2] = {"MA MON HOC", "TEN MON HOC"};
	//create banner
	TextColor(red);
	gotoxy(60,3);
	printf("DANH SACH MON HOC");
	TextColor(blue);
	for( int i = 0; i < 2; i++){
		gotoxy((i+1)*40, 4);
		cout << mon[i];
	}
	// load danh sach mon hoc theo mang de len xuong cho de dang
	// bat dau to mau cho dau danh sach 
	for(int i = 0; i < dsMonHoc.index; i++){
		if( i == 0 ){
			TextColor(redWrapper);
			gotoxy(40, row + i);
			cout << dsMonHoc.ds[i]->MAMH;
			gotoxy(80, row + i);
			cout << dsMonHoc.ds[i]->TENMH;
			TextColor(green);
		}
		else{
			gotoxy(40, row + i);
			cout << dsMonHoc.ds[i]->MAMH;
			gotoxy(80, row + i);
			cout << dsMonHoc.ds[i]->TENMH;
		}
	}
	row = 5;
	while(1){
		int input = getch();
		if(input == 72 && row > 5){	//	up
			TextColor(green);
			gotoxy(40, row);
			cout << dsMonHoc.ds[row - 5]->MAMH;
			gotoxy(80, row);
			cout << dsMonHoc.ds[row - 5]->TENMH;
			row--;
			TextColor(redWrapper);
			gotoxy(40, row);
			cout << dsMonHoc.ds[row - 5]->MAMH;
			gotoxy(80, row);
			cout << dsMonHoc.ds[row - 5]->TENMH;
			TextColor(green);
		}
		else if(input == 80 && row < dsMonHoc.index + 4){	// down
			TextColor(green);
			gotoxy(40, row);
			cout << dsMonHoc.ds[row - 5]->MAMH;
			gotoxy(80, row);
			cout << dsMonHoc.ds[row - 5]->TENMH;
			row++;
			TextColor(redWrapper);
			gotoxy(40, row);
			cout << dsMonHoc.ds[row - 5]->MAMH;
			gotoxy(80, row);
			cout << dsMonHoc.ds[row - 5]->TENMH;
			TextColor(green);
		}
		else if( input == 13 ){ //enter
			//go to detail view
			DSCauHoiTheoMonHoc(*dsMonHoc.ds[row - 5], dsCauHoi);
			goto gotoTop;
		}
		else if( input == 102){ // sua
			//go to fix view
			SuaMonHoc(*dsMonHoc.ds[row - 5]);
			luuDanhSachMonHoc(dsMonHoc);
			goto gotoTop;
		}
		else if( input == 120){	// xoa
			MessageBox(0,"KHONG THE XOA MON HOC!!!","THONG BAO",0);
		}
		else if( input == 110){// them moi
			TaoMonHoc(dsMonHoc);
			goto gotoTop;
		}
		else if( input == 27){	//ESC
			return;
		}	
	}
}

// chon mon hoc roi moi tao cau hoi
void TaoCauHoi(MonHoc monHoc, ptrDSCauHoi &dsCauHoi){
	Layout();
	int row = 4;
	int x = 30;
	string cauhoi[6] = {"CAU HOI:", "A:", "B:", "C:", "D:", "DAP AN:"};
	int col[6] ={8, 2, 2, 2, 2, 7};
	string inputCauHoi[6] = {""}; // [0]: NOI DUNG; [1]: A; [2]: B; [3]: C; [4]: D; [5]: DAP AN
	//create banner
	TextColor(red);
	gotoxy(60,3);
	cout << "THEM CAU HOI CHO MON: " << monHoc.TENMH;
	TextColor(blue);
	for( int i = 0; i < 6; i++){
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
			if(row<9){
				row++;
				gotoxy( x + col[row - 4 ] + inputCauHoi[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			string flag = kiemtraCauHoi(inputCauHoi[0], inputCauHoi[1], inputCauHoi[2], inputCauHoi[3], inputCauHoi[4], inputCauHoi[5]);
			if(flag == "true"){
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,"XIN NHAP LAI!!!","THONG BAO",0);	
		}
		else if( input == 8 ){ //backspace
			if( inputCauHoi[row-4].length() > 0 && row != 9){
				gotoxy( x+ col[row - 4]+ inputCauHoi[row - 4].length(),row);
				printf(" ");
				inputCauHoi[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputCauHoi[row - 4].length() + 1,row);
			}
		}
		else if( input == 27){	//ESC
			return;
		}
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if((input >= 32 && input <= 126)  && inputCauHoi[row - 4].length() < 100 && row != 9){
					gotoxy( x + col[row-4]+inputCauHoi[row - 4].length() + 1,row);
					char ch = (char) input;
//					ch = toupper(ch);
					printf("%c",ch);
					inputCauHoi[row-4].push_back(ch);
			}
			if((input >= 65 && input <= 68)  && inputCauHoi[row - 4].length() < 1 && row == 9){
					gotoxy( x + col[row-4]+inputCauHoi[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputCauHoi[row-4][0] = ch;
			}
		}
	}
}
void SuaCauHoi(ptrDSCauHoi &ptrCauHoi){
	Layout();
	int row = 4;
	int x = 30;
	string cauhoi[6] = {"CAU HOI:", "A:", "B:", "C:", "D:", "DAP AN:"};
	int col[6] ={8, 2, 2, 2, 2, 7};
	string inputCauHoi[6] = {""}; // [0]: NOI DUNG; [1]: A; [2]: B; [3]: C; [4]: D; [5]: DAP AN
	inputCauHoi[0] = ptrCauHoi->cauhoi.NoiDung;
	inputCauHoi[1] = ptrCauHoi->cauhoi.A;
	inputCauHoi[2] = ptrCauHoi->cauhoi.B;
	inputCauHoi[3] = ptrCauHoi->cauhoi.C;
	inputCauHoi[4] = ptrCauHoi->cauhoi.D;
	inputCauHoi[5] = ptrCauHoi->cauhoi.DapAn;
	//create banner
	TextColor(red);
	gotoxy(60,3);
	cout << "SUA CAU HOI : " << ptrCauHoi->cauhoi.ID;
	TextColor(blue);
	for( int i = 0; i < 6; i++){
		gotoxy(x, row + i);
		cout << cauhoi[i];
	}
	TextColor(green);
	gotoxy(x + col[0] + 1, row );
	cout << ptrCauHoi->cauhoi.NoiDung;
	gotoxy(x + col[1] + 1, row + 1);
	cout << ptrCauHoi->cauhoi.A;
	gotoxy(x + col[2] + 1, row + 2);
	cout << ptrCauHoi->cauhoi.B;
	gotoxy(x + col[3] + 1, row + 3);
	cout << ptrCauHoi->cauhoi.C;
	gotoxy(x + col[4] + 1, row  + 4);
	cout << ptrCauHoi->cauhoi.D;
	gotoxy(x + col[5] + 1, row + 5);
	cout << ptrCauHoi->cauhoi.DapAn;
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
			if(row<9){
				row++;
				gotoxy( x + col[row - 4 ] + inputCauHoi[row - 4].length() + 1, row);
			}
		}
		else if( input == 13 ){ //enter
			string flag = kiemtraCauHoi(inputCauHoi[0], inputCauHoi[1], inputCauHoi[2], inputCauHoi[3], inputCauHoi[4], inputCauHoi[5]);
			if(flag == "true"){
				ptrCauHoi->cauhoi.NoiDung = inputCauHoi[0];
				ptrCauHoi->cauhoi.A = inputCauHoi[1];
				ptrCauHoi->cauhoi.B = inputCauHoi[2];
				ptrCauHoi->cauhoi.C = inputCauHoi[3];
				ptrCauHoi->cauhoi.D = inputCauHoi[4];
				ptrCauHoi->cauhoi.DapAn = inputCauHoi[5][0];
				return;
			}
			MessageBeep(MB_ICONWARNING);
			MessageBox(0,"XIN NHAP LAI!!!","THONG BAO",0);	
		}
		else if( input == 8 ){ //backspace
			if( inputCauHoi[row-4].length() > 0 && row != 9){
				gotoxy( x+ col[row - 4]+ inputCauHoi[row - 4].length(),row);
				printf(" ");
				inputCauHoi[row - 4].pop_back();
				gotoxy( x + col[row - 4]+ inputCauHoi[row - 4].length() + 1,row);
			}
		}
		else if( input == 27){	//ESC
			return;
		}
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if((input >= 32 && input <= 126)  && inputCauHoi[row - 4].length() < 100 && row != 9){
					gotoxy( x + col[row-4]+inputCauHoi[row - 4].length() + 1,row);
					char ch = (char) input;
//					ch = toupper(ch);
					printf("%c",ch);
					inputCauHoi[row-4].push_back(ch);
			}
			if((input >= 65 && input <= 68)  && inputCauHoi[row - 4].length() < 1 && row == 9){
					gotoxy( x + col[row-4]+inputCauHoi[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputCauHoi[row-4][0] = ch;
			}
		}
	}
}
void DSCauHoiTheoMonHoc(MonHoc monHoc, ptrDSCauHoi &dsCauHoi){
	gotoTop:
	InnerLayout();
	setcursor(0,0);
	int row = 4;
	int x = 55;
	int soCau = timKiemCauHoiTheoMaMonHocInt(monHoc.MAMH, dsCauHoi);
	CauHoi danhSachCauHoiTheoMaMonHoc[soCau];
	timKiemCauHoiTheoMaMonHoc(monHoc.MAMH, dsCauHoi, danhSachCauHoiTheoMaMonHoc);
	string sv = "CAU HOI";
	//create banner
	TextColor(red);
	gotoxy(50,3);
	cout << "DANH SACH CAU HOI CUA MON: " << monHoc.TENMH;
	TextColor(blue);
	//
	gotoxy(25, row);
	cout << sv;
	//
	row++;
	for(int i = 0; i < soCau; i++){
		if( i == 0){
			TextColor(redWrapper);
			gotoxy(25, row);
			cout << danhSachCauHoiTheoMaMonHoc[i].NoiDung;
			TextColor(green);
		}
		else{
			gotoxy(25, row + i);
			cout << danhSachCauHoiTheoMaMonHoc[i].NoiDung;
		}
	}
	row = 5;
	// load danh sach sinh vien cua lop theo mang de len xuong cho de dang
	while(1){
		int input = getch();
		if(input == 72){	//	up
			if(row > 5){
				TextColor(green);
				gotoxy(25, row);
				cout << danhSachCauHoiTheoMaMonHoc[row - 5].NoiDung;
				row--;
				TextColor(redWrapper);
				gotoxy(25, row);
				cout << danhSachCauHoiTheoMaMonHoc[row - 5].NoiDung;
				TextColor(green);
			}
			// else load the list should be index
		}
		else if(input == 80 && row < soCau + 5){	// down
			TextColor(green);
			gotoxy(25, row);
			cout << danhSachCauHoiTheoMaMonHoc[row - 5].NoiDung;
			row++;
			TextColor(redWrapper);
			gotoxy(25, row);
			cout << danhSachCauHoiTheoMaMonHoc[row - 5].NoiDung;
			TextColor(green);
		}
		else if( input == 102){ // sua
			ptrDSCauHoi temp = timKiemCauHoiTheoId(danhSachCauHoiTheoMaMonHoc[row - 5].ID,dsCauHoi);
			SuaCauHoi(temp);
			goto gotoTop;
		}
		else if( input == 120){	// xoa
			MessageBox(0,"KHONG THE XOA CAU HOI!!!","THONG BAO",0);
		}
		else if( input == 110){// them moi
			TaoCauHoi(monHoc, dsCauHoi);
			goto gotoTop;
		}
		else if( input == 27){
			return;
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
string kiemtraLop(string maLop, string tenLop, string nienkhoa, DSLop classlist){
	if (maLop == "" || tenLop == "" || nienkhoa == "" ){
		return "KHONG THE BO TRONG!!!";
	}
	if (laKiTuVaLaSoNguyen(maLop) == false){
		return "Nhap sai cu phap";
	}
	if(checkMaLop(classlist, maLop) >= 0){
		return "Ma lop da ton tai";
	}
	else if(kiemTraCuPhapNienKhoa(nienkhoa) == false){
		return "Nien khoa nhap vao khong hop le";
	}
	return pass;
}
string kiemtraSuaLop(string maLop, string maLopCu, string tenLop, string nienkhoa, DSLop classlist){
	if (maLop == "" || tenLop == "" || nienkhoa == "" ){
		return "KHONG THE BO TRONG!!!";
	}
	
	if (laKiTuVaLaSoNguyen(maLop) == false){
		return "Nhap sai cu phap";
	}
	if( checkMaLopKhongCoMaLopCu(classlist, maLop, maLopCu) >= 0){
		return "Ma lop da ton tai";
	}
	else if(kiemTraCuPhapNienKhoa(nienkhoa) == false){
		return "Nien khoa nhap vao khong hop le";
	}
	return pass;
}
string kiemtraSinhVien(string inputSV[5], DSLop dsLop){
	for(int i = 0; i < 5; i++){
		if( inputSV[i] == "") return "KHONG THE BO TRONG!!!";
	}
	if(kiemTraMaSinhVienTatCa(inputSV[0], dsLop) == false){
		return "DA TON TAI MA SINH VIEN!!!";
	}
	if(inputSV[3] == "NAM" || inputSV[3] == "NU"){
		return pass;
	}
	return "GIOI TINH KHONG HOP LE";
}
string kiemtraSuaSinhVien(string inputSV[5]){
	for(int i = 0; i < 5; i++){
		if( inputSV[i] == "") return "KHONG THE BO TRONG!!!";
	}
	if(inputSV[3] == "NAM" || inputSV[3] == "NU"){
		return pass;
	}
	return "GIOI TINH KHONG HOP LE";
}
string kiemtraMonHoc(string inputMH[2], DSMonHoc dsMonHoc){
	for(int i = 0; i < 2; i++){
		if( inputMH[i] == "") return "KHONG THE BO TRONG!!!"; 
	}
	if(kiemTraMaMonHoc(inputMH[0], dsMonHoc) != -1){
		return "MA MON HOC DA TON TAI!!!";
	}
	return pass;
}
string kiemtraSuaMonHoc(string inputMH[2]){
	for(int i = 0; i < 2; i++){
		if( inputMH[i] == "") return "KHONG THE BO TRONG!!!"; 
	}
	return pass;
}
string kiemtraCauHoi(string NoiDung, string A, string B, string C, string D, char DapAn){
	if( NoiDung == "" || A  == "" || B == "" || C == "" || D == "" || isblank(DapAn)){
		return "KHONG THE BO TRONG!!!"; 
	}
	return pass;
}
//-----

#endif
