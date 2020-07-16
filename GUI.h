#ifndef _GUI
#define _GUI
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
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
void DSLop();
void SuaLop();
// create update delete SV
void ThongTinSV();
void ThemSV();
void SuaSV();
// create mon hoc
void MonHocForm();
// create cau hoi
void QuestionForm();
// Thi trac nghiem
void TestForm();

// ham giao dien
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void setcursor(bool visible, DWORD size);
void TextColor(int x);
void gotoxy(int x, int y);
void InitWindow();

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
	printf("DUNG PHIM LEN XUONG DE DIEU HUONG  ||  ENTER DE CHON || ESC DE QUAY LAI || F1 DE THEM || F2 DE XOA || F3 DE SUA ");
	gotoxy(50,1);
	printf("-------------------------------------");
	gotoxy(40,2);
	printf("POSTS AND TELECOMMUNICATIONS INSTITUTE OF TECHNOLOGY");
	
}
void Login(){
	Layout();
	setcursor(1,1);
	string UserAndPass[2] = {""};// [1] : username; [2]: password
	int row = 4;
	int col[2] = {45,45};
	int size[2] = {0};
	TextColor(12);
	gotoxy(60,3);
	printf("DANG NHAP");
	TextColor(2);
	gotoxy(35,4);
	printf("USERNAME:");
	gotoxy(35,5);
	printf("PASSWORD:");
	gotoxy(col[row - 4] + size[row -4], row);
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
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if((input>=48&&input<=57)||(input>=97&&input<=122) && UserAndPass[row - 4].length() < 50){
					gotoxy(col[row-4]+size[row-4],row);
					char ch = (char) input;
					if(row == 5){ // password
						printf("*");
					}
					else{ // username
						ch = toupper(ch);
						printf("%c",ch);
					}
					UserAndPass[row-4].push_back(ch);
					size[row-4]++;
				}
		}
	}
}
void MainMenuGV(){
	InnerLayout();
	string func[3] = {"LOP", "MON HOC", "LICH THI"};
	int row = 4;
	int x = 55;
	//create banner
	TextColor(12);
	gotoxy(60,3);
	printf("DANG NHAP");
	gotoxy(x,row);
	TextColor(192);
	cout << func[0] << "\n";
	TextColor(2);
	for(int i=1;i<3;i++){
		gotoxy(x,row + i);
		cout  << func[i] << "\n";
	}	
	while(1){
		int input;
		input  = getch();
		switch(input){
			case 72:
				if(row>4){
					gotoxy(x,row);
					TextColor(2);
					cout  << func[row -4] << "\n";
//					printf("%s\n",func[row-2]);
					row--;
					gotoxy(x,row);
					TextColor(192);
					cout  << func[row -4] << "\n";
//					printf("%s\n",func[row-2]);
					TextColor(2);
				}
				break;
			case 80:
			if(row<6){
					gotoxy(x,row);
					TextColor(2);
					cout  << func[row -4] << "\n";
//					printf("%s\n",func[row-2]);
					row++;
					gotoxy(x,row);
					TextColor(192);
					cout  << func[row -4] << "\n";
//					printf("%s\n",func[row-2]);
					TextColor(2);
				}
				break;	
			case 13:
				switch(row){
					case 2:	//cap nhap danh sach may bay
//						goto gototop;
						break;
					case 3:	//cap nhap chuyen bay
//						goto gototop;
						break;
					case 4:	//dat ve
//						goto gototop;
						break;
					case 5:	//huy ve
//						goto gototop;
						break;
					case 6: //danh sach khach hang trong chuyen bay
//						goto gototop;
						break;
					case 7:	//danh sach cac chuyen bay con trong cho
						setcursor(1,1);
//						goto gototop;
						break;
					case 8:	//thong ke
//						goto gototop;
						break;
					case 9:	//exit
						return;
						break;
						
				}			
		}
	}	
}
void DSLop(){
	InnerLayout();
	int row = 4;
	int x = 55;
	string lop[3] = {"MA LOP", "TEN LOP", "NIEN KHOA"};
	//create banner
	TextColor(12);
	gotoxy(60,3);
	printf("DANH SACH LOP");
	TextColor(2);
	gotoxy(40, row);
	cout << "NIEN KHOA:";
	for( int i = 0; i < 3; i++){
		gotoxy((i+1)*30, 5);
		cout << lop[i];
	}
	setcursor(1,1);
	// load danh sach lop theo mang de len xuong cho de dang
	// tao 1 cai filter de search	
	while(1){
		int input;
		input  = getch();
		switch(input){
				
		}		
	}
}
void ThemLop(){
	Layout();
	int row = 4;
	int x = 30;
	string lop[3] = {"MA LOP:", "TEN LOP:", "NIEN KHOA:"};
	int col[3] ={7, 8, 10 };
	string inputLop[3] = {""}; // [1]: ma lop; [2]: ten lop; [3]: nien khoa
	//create banner
	TextColor(12);
	gotoxy(60,3);
	printf("THEM LOP");
	TextColor(2);
	for( int i = 0; i < 3; i++){
		gotoxy(x, row + i);
		cout << lop[i];
	}
	setcursor(1,1);
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
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if((input>=48&&input<=57)||(input>=97&&input<=122) && inputLop[row - 4].length() < 50){
					gotoxy( x + col[row-4]+inputLop[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputLop[row-4].push_back(ch);
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
	string inputLop[3] = {""}; // [1]: ma lop; [2]: ten lop; [3]: nien khoa
	//create banner
	TextColor(12);
	gotoxy(60,3);
	printf("THEM LOP");
	TextColor(2);
	for( int i = 0; i < 3; i++){
		gotoxy(x, row + i);
		cout << lop[i];
	}
	setcursor(1,1);
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
		else if( input != 224 && input !=72 && input != 80 && input != 8 ){ // input char 
			if((input>=48&&input<=57)||(input>=97&&input<=122) && inputLop[row - 4].length() < 50){
					gotoxy( x + col[row-4]+inputLop[row - 4].length() + 1,row);
					char ch = (char) input;
					ch = toupper(ch);
					printf("%c",ch);
					inputLop[row-4].push_back(ch);
				}
		}
	}
}
void DSSVCuaLop(){
	
}
//-----

#endif
