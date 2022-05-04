#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include "console.h"

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
void Sleep(int n){
	for(int i =0; i< 100*n; i++)
		for(int j=0; j<1000; j++);
}
void VeGiaoDienVaoGame(){
	int i, d = 0;
	getch();
	Sleep(300);
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	for(i=1; i<=40; i++){
		TextColor(d);
		gotoXY(10,8); cout << "    _____ _                                        _ _____             _  ";
		gotoXY(10,9); cout << "   /  ___| |          _ _____  _ _____ _     _    | | ___ \\ _  ____   | | ";
		gotoXY(10,10); cout << "  _| |__ | |     __ _| | ___ \\| | ___ \\ \\  / /    | |     /(_)/ ___| _| | "; 
		gotoXY(10,11); cout << " |_   __|| |    / _. | |___ _/| |___ _/\\ \\/ /     | |====<  _  /   / _. | ";
		gotoXY(10,12); cout << "   | |   | |___| (_| | |      | |       \\/ /      | | ___ \\| | |  | (_| | ";
		gotoXY(10,13); cout << "   |_|   |_____|\\__._|_|      |_|       /_/       |_|_____/|_|_|   \\__._| ";
		d++;
		gotoXY(100, 9); cout << "              __¦¦¦¦¦¦¦¦¦¦__";
		gotoXY(100, 10); cout << "                   ¦¦      ";
		gotoXY(100, 11); cout << "    _¦¦_    __¦¦¦¦¦¦¦¦¦¦¦¦__    _¦¦_";
		gotoXY(100, 12); cout << "   _¦¦¦   _¦¦¦¦          ¦¦¦¦_   ¦¦¦_";
		gotoXY(100, 13); cout << "  ¦¦¦¦_ _¦¦¦                ¦¦¦_ _¦¦¦¦";
		gotoXY(100, 14); cout << " ¦¦¦ ¦¦¦¦¦ _¦¦¦¦_      _¦¦¦¦_ ¦¦¦¦¦ ¦¦¦";
		gotoXY(100, 15); cout << " ¦¦   ¦¦¦  ¦¦¦¦¦¦      ¦¦¦¦¦¦  ¦¦¦   ¦¦";
		gotoXY(100, 16); cout << "     _¦¦    ¦¦¦¦   __   ¦¦¦¦    ¦¦_   ";
		gotoXY(100, 17); cout << "     ¦¦¦                        ¦¦¦";
		gotoXY(100, 18); cout << "     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦";
		gotoXY(100, 19); cout << " _¦   ¦¦  ¦¦¦   ¦¦    ¦¦   ¦¦¦  ¦¦¯  ¦_";
		gotoXY(100, 20); cout << " ¦¦¦  ¦¦¦ ¦¦¦   ¦¦    ¦¦   ¦¦¦_¦¦¦   ¦¦¦";
		gotoXY(100, 21); cout << "  ¦¦_¦¦¦¦¦¦¦¦   ¦¦    ¦¦   ¦¦¦¦¦¦¦¦_¦¦ ";
		gotoXY(100, 22); cout << "   ¦¦¦   ¦¦¦¦   ¦¦    ¦¦   ¦¦¦¦   ¦¦¦ ";
		gotoXY(100, 23); cout << "    ¦¦¦_   ¦¦¦¦¦¦¦    ¦¦¦¦¦¦¦   _¦¦¦";
		gotoXY(100, 24); cout << "     ¦¦¦       ¦¦¦¦¦¦¦¦¦¦       ¦¦¦ ";
		gotoXY(100, 25); cout << "             ___   ¦¦   ___";
		gotoXY(100, 26); cout << "------------ ¯¯¦¦¦¦¦¦¦¦¦¦¦¯¯ -----------";
		gotoXY(100, 27); cout << "----------------------------------------";


		if(d >13)
			d = 0;
		gotoXY(20, 20); cout << "Vu Trung Duc - K66 - UET.";
		TextColor(11);
		gotoXY(5 + i*4 + 1, 30);	cout << char (177);	
		gotoXY(5 + i*4 + 1, 31);	cout << char (177);	
		gotoXY(5 + i*4 + 2, 30);	cout << char (177); 
		gotoXY(5 + i*4 + 2, 31);	cout << char (177);	
		gotoXY(5 + i*4 + 3, 30);	cout << char (177);	
		gotoXY(5 + i*4 + 3, 31);	cout << char (177);	
		gotoXY(5 + i*4 + 4, 30);	cout << char (177);	
		gotoXY(5 + i*4 + 4, 31);	cout << char (177);	
		gotoXY(80, 32);	cout << float (i*2.5) << " % ";
		gotoXY(0,0);
		Sleep(400);
	}
	getch();
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
}
void ThemChu(int x, int y, char a[100], char b[100], char c[100], char a1[100], int d){
	int i = strlen(a)/2;
	int j = strlen(b)/2;
	int ij = strlen(c)/2;
	TextColor(14);
	gotoXY(x + 10 - i, y); cout << a;
	gotoXY(x + 10 - j, y + 2); cout << b;
	gotoXY(x + 10 - ij, y + 4); cout << c;
	gotoXY(x + 10 - strlen(a1)/2, y + 6); cout << a1;
	TextColor(7);
}

void VeChim(int x, int y){
	TextColor(11);
	gotoXY(x + 4, y - 6);	cout << " "; 
	gotoXY(x, y - 5);	cout << "    _      "; 
	gotoXY(x, y - 4);	cout << " __\\_\\_____ "; 
	gotoXY(x, y - 3);	cout << " >|      O_\\"; 
	gotoXY(x, y - 2);	cout << " >|__ _ __\\ "; 
	gotoXY(x, y - 1);	cout << "    /_/     "; 
	gotoXY(x, y - 0);	cout << "          "; 
	gotoXY(0,0);
	TextColor(7);
}
void VeChuongNgai(int x, int y, int h, int d, int yy){
	int i, j;
	TextColor(10);
	for(j=1; j<d -1; j++){
		if(x + j > d + 2){
			gotoXY(x + j, yy);	cout <<char (196);
			gotoXY(x + j, yy + h);	cout <<char (196);
		}
	}
	for(i=3; i<yy; i++){
		for(j=0; j<=d; j++)
			if(x + j > 2 + d)
			if(j==0 || j == d - 1){
				gotoXY(x +j, i);	cout <<char (179);
			}else
			if(j == d){
				gotoXY(x +j, i);	cout <<" ";
			}else{
				gotoXY(x +j, i);	cout << (char) 176;
			}
	}
	if(x > 2 + d){
		gotoXY(x, yy); cout << char (192);
		gotoXY(x, yy + h); cout << char (218);
	}
	if(x  -1 > 2){
		gotoXY(x + d - 1 , yy); cout << char (217) << " ";
		gotoXY(x + d - 1, yy + h); cout << char (191) << " ";
	}
		gotoXY(x + d , yy); cout << " ";
		gotoXY(x + d , yy + h); cout << " ";
	for(i= yy + h + 1; i<y; i++){
		for(j=0; j<=d; j++)
			if(x + j > 2 + d)
			if(j==0 || j == d - 1){
				gotoXY(x +j, i);	cout <<char (179);
			}else
			if(j == d){
				gotoXY(x +j, i);	cout <<" ";
			}else{
				gotoXY(x +j, i);	cout << (char) 176;
			}
	}
	TextColor(7);
}
int Kt(int x, int y, int h, int d, int yy, int xc, int yc){
	if(( xc == x - 12 && (yc - 5 <= yy || yc > yy + h) ) || (xc + 12 >= x && xc <= x + d && ( yc - 5 <= yy || yc > yy + h) ) || (yc >= 40) )
		return 1;
	return 0;
}
void DiChuyen(int &x, int &y, char c){
	switch (c){
		case 'w':{
			y--;
			break;
		}
		default :{
			y++;
			break;
		}
	}	
}
void Random(int &vitri, int &h, int &d){
	vitri = rand() %23 + 3;
	h = rand() %10 + 6;
	d = rand() %10 + 6;
}
void Tang(int &xv, int &vitri, int &h, int &d, int &diem, int k){
	if(k==0){
		xv = 40;
	}else{
		diem++;
		xv = 190;
	}
	Random(vitri, h, d);
}

int main(){
	int k, k1, max = 0, x, y, yy, KT, diem, tocdo;
	int xv[5], yv[5], h[5], d[5], vitri[5];
	char dk;
	char a1[100], a2[100], a3[100], a4[100];
	strcpy(a1, "Bat dau");
	strcpy(a2, "Diem cao nhat");
	strcpy(a3, "Thoat");
	strcpy(a4, "Chuc nang:");
	do{	VeGiaoDienVaoGame();
		clrscr();
		gotoXY(0, 0); cout << "Vu Trung Duc - K66 - UET.";
		TaoO(80,20,4);
		ThemChu(81, 21, a1, a2, a3, a4, 0);
		cin >> k;
		switch(k){
			case 1:{
				x = 20, y = 20, yy = 0, KT = 0, diem = 0;
				for(int i=0; i<6; i++){
					yv[i] = 40;
					Tang(xv[i],vitri[i], h[i], d[i], diem, 0);
					xv[i] += 32*i;
				}
				clrscr();
				TextColor(11);
				for(int i=0; i<40; i++){
					gotoXY(7, i);
					cout << char(179) << "}";
				}
				for(int i=0; i<200; i++){
					gotoXY(i, 40); cout << "=";
				}
				while(1){
					gotoXY(50, 45); cout << "Vu Trung Duc - K66 - UET.";
					if(kbhit()){
						dk = getch();
						DiChuyen(x, y, dk);
					}	
					yy++;
					if(yy == 8 - tocdo){
						for(int i = 0; i<6; i++){
							xv[i] --;
							VeChuongNgai(xv[i], yv[i], h[i], d[i], vitri[i]);
							if(xv[i] == 1)	Tang(xv[i],vitri[i], h[i], d[i], diem, 1);
							TextColor(14);
							gotoXY(50, 0);	cout << "Diem cua ban: " << diem; 
						}	
						yy=0;
					}
					if(yy == 5)
						y++;	
					VeChim(x, y);
					for(int i=0; i<6; i++){
						KT = Kt(xv[i], yv[i], h[i], d[i], vitri[i], x, y);
						if(KT == 1){
							if(diem > max )
								max = diem;
							TextColor(4);
							gotoXY(80, 25); cout << "GAME OVER!";
							getch();
							clrscr();
							break;
							getch();
						}
					}
					if(KT == 1)
						break;
					if(8 - tocdo > 0)
					if(diem + 1 % 5 == 0)
						tocdo++;
					Sleep(100);
				}
				break;
			}
			case 2:{
				clrscr();
				TaoO(46, 12, 1);
				gotoXY(47,13);	cout << "Diem cao nhat: "<< max;
				gotoXY(47,16);	cout << "Huong dan choi: ";
				gotoXY(47,17);	cout << "\t+ Dung phim w de bay len.";
				gotoXY(47,18);	cout << "\t+ Dung phim bat ki de bay xuong";
				getch();
				clrscr();
				break;
			}
			case 0:{
				clrscr();
				gotoXY(50, 12);	cout << "GOOD BYE!";
				getch();
				break;
			}
		}
	}while(k != 0);
}
	
	
	
	
	
	
	
	
