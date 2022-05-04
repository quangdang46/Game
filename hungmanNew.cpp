#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include "console.h"
#include <fstream>

using namespace std;

void TextColor (int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void clrscr(){
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
void gotoXY (int column, int line){
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void TaoO(int x, int y, int n){
	int iy, ix;
	TextColor(14);
	for(iy = 0; iy < 2*n + 1; iy++){
		if(iy % 2 == 1){
			gotoXY(x + 0 , iy + y); cout << (char) 179; 
			gotoXY(x + 21, iy + y); cout << (char) 179;
		}
		if(iy % 2 == 0){
			if(iy == 0){
				gotoXY(x + 0 , iy + y); cout << (char) 218; 
				gotoXY(x + 21, iy + y); cout << (char) 191;
			}else
			if(iy == 2*n){
				gotoXY(x + 0 , iy + y); cout << (char) 192; 
				gotoXY(x + 21, iy + y); cout << (char) 217;
			}else{
				gotoXY(x + 0 , iy + y); cout << (char) 195; 
				gotoXY(x + 21, iy + y); cout << (char) 180;
			}
			for(ix = x+1; ix <= x+20; ix++){
				gotoXY(ix, iy + y);
				cout << (char) 196;
			}
		}
	}
	TextColor(7);
}
void NhapTTO(int x, int y, char a[100], char b[100], char c[100]){
	TextColor(6);
	gotoXY(x + 10 - strlen(a)/2, y + 0); cout << a;
	gotoXY(x + 10 - strlen(b)/2, y + 2); cout << b;
	gotoXY(x + 10 - strlen(c)/2, y + 4); cout << c;
}
typedef struct TuKhoa{
	char Key[100];
	char Suggest[1000];
}TK;

void XoaXuongDong(char *a){
	if(a[strlen(a) - 1] == '\n')
		a[strlen(a) - 1] = '\0';
}
void Doc(int &n, TK *a){
	ifstream fileIn;
	fileIn.open("D:\\C++\\hungman file.txt");
	fileIn >> n;
	for(int i=0; i<n; i++){
		fileIn >> a[i].Key;	XoaXuongDong(a[i].Key);
		fileIn.ignore();
		fileIn.getline(a[i].Suggest, 999);	XoaXuongDong(a[i].Suggest);
	}
	fileIn.close();
}
void In(int n, TK *a){
	ofstream fileOut("D:\\C++\\hungman file.txt");
	fileOut << n << endl;
	for(int i =0; i<n; i++){
		fileOut << a[i].Key << endl;
		fileOut << a[i].Suggest << endl;
	}
	fileOut.close();
}
int KiemTra(int n, TK *a, TK b){
	int i;
	for(i=0; i <n; i++)
		if(strcmp(a[i].Key, b.Key) == 0 && strcmp(a[i].Suggest, b.Suggest) == 0)
			return 1;
	return 0;
}
void VeGia(){
	TextColor(14);
	gotoXY(30, 4 ); cout << "____________________"; // 20
	gotoXY(30, 5 ); cout << "   |           |    ";
	gotoXY(30, 6 ); cout << "   |           |    ";
	gotoXY(30, 7 ); cout << "   |           |    ";
	gotoXY(30, 8 ); cout << "   |                ";    
	gotoXY(30, 9 ); cout << "   |                ";
	gotoXY(30, 10); cout << "   |                ";
	gotoXY(30, 11); cout << "   |                ";
	gotoXY(30, 12); cout << "   |                ";
	gotoXY(30, 13); cout << "   |                ";
	gotoXY(30, 14); cout << "   |                ";
	gotoXY(30, 15); cout << " =====              ";
	TextColor(7);
}
void VeNguoi(int diem){
	if(diem == 1){
		gotoXY(30+15, 8);
		cout << "O";
	}else
	if(diem == 2){
		gotoXY(30+15, 9);
		cout << "|";
		gotoXY(30+15, 10);
		cout << "|";
	}else
	if(diem == 3){
		gotoXY(30+14, 9);
		cout << "/";
	}else
	if(diem == 4){
		gotoXY(30+16, 9);
		cout << "\\";
	}else
	if(diem == 5){
		gotoXY(30+14, 11);
		cout << "/";
	}else
	if(diem == 6){
		gotoXY(30+16, 11);
		cout << "\\";
	}
}
void Sleep(int n){
	for(int i = 0; i<10*n; i++)
		for(int j=0; j<500; j++);
}
int KiemTraSo(int *b, int n, int x){
	for(int i=0; i<n; i++)
		if(b[i] == x)	return 1;
	return 0;
}
void TuGoiY(char *a,char *c){
	int i, j=0, x, n = strlen(a), b[n+1];
	srand(time(0));
	for(i=0; i<strlen(a)*2; i++){
		c[i] = rand() %25 + 97;
	}
	for(i=0; i<strlen(a); i++){
		do{
			x = rand() %strlen(c);
		}while(KiemTraSo(b, j, x) != 0);
		b[j] = x;
		j++;
		c[x] = a[i];
	}
}

void TuCanDien(char *a, char *b, int &win){ // a dap an, b la doan
	int i, d = 0;
	TextColor(6);
	for(i=0; i<strlen(a); i++){
		if(strchr(b, a[i]) != 0 || i%3 == 0){
			gotoXY(28 + 2*i, 19);	cout << a[i];
			d++;
		}else{
			gotoXY(28 + 2*i, 19);	cout <<"-";
		}
	}
	if(d == strlen(a))
		win = 1;
	else 
		win = 0;	
}
void LuaChon(char *a, char *c){
	int i;
	for(i=0; i<strlen(a); i++)
		while(strchr(c, a[i]) !=0){
			char *d =	strchr(c, a[i]);
			strcpy(d, d+1);
		}
}
void Xuat(char *c){
	for(int i=0; i< strlen(c); i++){
		gotoXY(30 + 2*i, 22);
		cout << c[i];
	}
}
int main(){
	
	int n, k, diem, win =0; // So luong tu trong tu dien, bien thoat
	TK a[100], b;
	Doc(n, a);
	char c[5][20], kiTu[2], Doan[100], goiY[100] ;
	strcpy(c[0], "1. Bat dau" );
	strcpy(c[1], "0. Thoat"   );
	strcpy(c[2], "Chuc nang: ");
	strcpy(c[3], "1. Tu moi");
	strcpy(c[4], "2. Tu co san");
	do{
		clrscr();
		TaoO(50, 10, 3);
		NhapTTO(50, 11, c[0], c[1], c[2]);
		gotoXY(65, 11 + 4); cin >> k;
		switch (k){
			case 1 :{
				int k1; // Bien thoat
				do{
					clrscr();
					strcpy(Doan, " ");
					diem = 0;
					TaoO(50, 10, 3);
					NhapTTO(50, 11, c[3], c[4], c[2]);
					gotoXY(65, 11 + 4); cin >> k1;
					switch (k1){
						case 1:{
							clrscr();
							gotoXY(50, 6);	cout << "Nhap tu khoa: "; cin >> b.Key;
							gotoXY(50, 7);	cout << "Nhap goi y: "; cin.ignore(); cin.getline(b.Suggest, 999);
							if(KiemTra(n, a, b) == 0){
								n++;
								a[n-1] = b;
								In(n, a);
 							}
							break;
						}
						case 2:{
							srand(time(0));
							int HenXui = rand() %n;
							b = a[HenXui];
							break;
						}
					}clrscr();
					VeGia();
					TuGoiY(b.Key, goiY);
					do{
						TuCanDien(b.Key, Doan, win);
						TextColor(12);
						Xuat(goiY);
						if(win == 1){
							clrscr();
							TextColor(11);
							gotoXY(50, 12);	cout << "YOU WIN!";
							getch();
							break;
						}
						TextColor(14);
						gotoXY(34, 17);	cout << "Diem cua ban(6 diem ban se chet): " << diem;
						gotoXY(25, 18);	cout << "Tu can diem: ";
						gotoXY(25, 20);	cout << "Goi y: " << b.Suggest;
						gotoXY(25, 21);	cout << "Chu cai goi y: ";
						gotoXY(25, 23);	cout << "Nhap ki tu cua ban:    "; gotoXY(45,23);	cin >> kiTu;
						strcat(Doan, kiTu);		
						if(strstr(b.Key, kiTu) == 0)
							diem++;
						TextColor(4);
						VeNguoi(diem);
						LuaChon(Doan, goiY);
					}while(diem != 6);
					
					if(diem == 6){
						clrscr();
							TextColor(4);
							gotoXY(50, 12);	cout << "YOU DIE!";
							getch();
					}
					/*
					Ve gia treo
					tao tu goi y
					
					*/
				}while (k1 != 0);
				break;
			}
			case 0 :{
				clrscr();
				gotoXY(50, 12);
				cout << "Good bye!";
				gotoXY(47, 20);	cout <<" ";
				break;
			}
		}
	}while(k != 0);
//	strcpy(b.Key, "student");
//	strcpy(b.Suggest, "hoc sinh");
	
//	In(n, a);

	/*
	* Tao menu:
		1. Bat dau
			+ Doc het cac tu va goi y vao mang TK
			+ Chon tu va goi y co san
				+ ham rand ngau nhien
			+ Tao tu va goi y moi
				+ Nhap tu
				+ Kiem tra roi update vao file
		0. Thoat
		Chuc nang: 
	* Choi:
		+ Sinh cac tu goi y
		+ Kiem tra va in ra nhung tu da chon
		+ Ve them
	*/
	return 0;
}

