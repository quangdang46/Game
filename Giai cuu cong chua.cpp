// Dua em ve nha
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include "console.h"
#include <math.h>

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
}
void ThemChu(int x, int y, char a[100], char b[100], char c[100], char a1[100], int d){
	int i = strlen(a)/2;
	int j = strlen(b)/2;
	int ij = strlen(c)/2;
	TextColor(11);
	gotoXY(x + 10 - i, y); cout << a << char (3);
	gotoXY(x + 10 - j, y + 2); cout << b << char (15);
	gotoXY(x + 10 - ij, y + 4); cout << c << char (120) ;
	gotoXY(x + 10 - strlen(a1)/2, y + 6); cout << a1;
	TextColor(2);
}
// Ve map, nhan vat, quai vat, cong chua.
//void VeThap(){
//	TextColor(14);
//	gotoXY(x - , y - ); cout << "                    ";
//	gotoXY(x - , y - ); cout << "                    ";
//	gotoXY(x - , y - ); cout << "                    ";
//	gotoXY(x - , y - ); cout << "                    ";
//	gotoXY(x - , y - ); cout << "                    ";
//	gotoXY(x - , y - ); cout << "                    ";
//}
void VeOVuong(int x, int y, int r, int d, int k){
	int i, j;
	if (k != 1){ // Ve duong tren
		gotoXY(x, y); cout << char (201);
		gotoXY(x + d, y); cout << char (187);
	}
	if( k != 2){ // Ve duong duoi
			gotoXY(x, y + r); cout << char (200);
			gotoXY(x + d, y + r); cout << char (188);
	}
	for(i=x + 1; i<x+d; i++){
		if(k != 1)	{
			gotoXY(i, y); cout << char (205);
		}
		if( k != 2){
			gotoXY(i, y + r); cout << char (205);
		}
	}
	for(j=y+1; j<y+r; j++){
			gotoXY(x, j); cout << char (186);
			gotoXY(x+d, j); cout << char (186);
			}
}
void VeMap(int d){
	if(d == 1){// x1 = 40, 80, 150, 55, 120, 165; y1 = 8, 25
		VeOVuong(40, 8, 37, 15, 2);
		VeOVuong(80, 0, 25, 40, 1);
		VeOVuong(150, 8, 37, 15, 2);
		VeOVuong(0, 0, 45, 210, 0);
	}else	
	if(d == 2){
		VeOVuong(45, 14, 2, 55, 0);
		VeOVuong(145, 28, 2, 75, 0);
		VeOVuong(160, 35, 2, 45, 0);
		VeOVuong(30, 6, 33, 15, 0);
		VeOVuong(100, 0, 25, 10, 1);
		VeOVuong(60, 0, 7, 20, 1);
		VeOVuong(65, 25, 20, 20, 2);
		VeOVuong(130, 6, 33, 15, 0);
		VeOVuong(0, 0, 45, 210, 0);
	}
}
void VeThap(int x, int y){
	TextColor(13);
	gotoXY(x - 0, y - 5); cout << "  _____^___"; 
	gotoXY(x - 0, y - 4); cout << " /_________\\";
	gotoXY(x - 0, y - 3); cout << "/___________\\";
	gotoXY(x - 0, y - 2); cout << "  |   __   |";
	gotoXY(x - 0, y - 1); cout << "  |   __   |";
	gotoXY(x - 0, y - 0); cout << "  |__|  |__|";
	TextColor(7);
}
void VeHoangTu(int x, int y, int hd, int chieu){ // 1: sang trai, 2 sang phai
	TextColor(11);
	if(hd == 1){
		gotoXY(x - 0, y - 3); cout << "   V  ";	
		gotoXY(x - 0, y - 2); cout << " /||\\";	
		gotoXY(x - 0, y - 1); cout << "  ||  ";
		gotoXY(x - 0, y - 0); cout << " |  |"; 
		if(chieu == 1){
			gotoXY(x - 0, y - 2); cout << " /||\\ <=";
			for(int i = 0; i<5; i++){
				TextColor(4);
				gotoXY(x+8+i, y-2); cout << "=";Sleep(100); gotoXY(x + 6 + i, y -2); cout << "   ";
				TextColor(10);
			}
		}
	}else
	if(hd == 2){
		gotoXY(x - 0, y - 3); cout << "  V  ";
		gotoXY(x - 0, y - 2); cout << " /||\\ ";
		gotoXY(x - 0, y - 1); cout << "  ||   ";
		gotoXY(x - 0, y - 0); cout << " |  | ";
		if(chieu == 1){
			gotoXY(x - 3, y - 2); cout << " => /||\\ "; 
			for(int i = 0; i<5; i++){
				TextColor(4);
				gotoXY(x - 2 - i, y-2); cout << "="; Sleep(100); gotoXY(x - 3 - i, y -2); cout << "   ";
			}
		}
	}
	TextColor(7);
	gotoXY(0,0);
}
void VeYeuQuai(int x, int y, int time, int d){
	TextColor(1);
	gotoXY(x - 0, y - 4); cout << " Time remaining: " << time;
	if(time == 10){
		gotoXY(x - 0, y - 4); cout << " Time remaining:     ";
	}		
	if(d == 1){
		gotoXY(x - 0, y - 3); cout << " OOO  ";
		gotoXY(x - 0, y - 2); cout << "__|__";
		gotoXY(x - 0, y - 1); cout << "  |  ";
		gotoXY(x - 0, y - 0); cout << " /|\\";
	}
	if(time == 0){
		gotoXY(x - 0, y - 2); cout << "__|__";
		for(int i = 0; i<5; i++){
				TextColor(1);
				gotoXY(x+8+i, y-2); cout << char (175);Sleep(50);
			}
	}
	TextColor(0);
	gotoXY(0,0);
}
void VeCongChua(int x, int y){
	gotoXY(x - 0, y - 3); cout << "  ~O~  ";
	gotoXY(x - 0, y - 2); cout << "  /|\\ ";
	gotoXY(x - 0, y - 1); cout << "   ^   ";
	gotoXY(x - 0, y - 0); cout << "  / \\ ";
	TextColor(7);
	gotoXY(0,0);
}
void XoaNV(int x, int y, int dk){
	 if(dk == 0){
	 	gotoXY(x - 0, y - 4); cout << "                    ";
	 }
	gotoXY(x - 0, y - 3); cout << "          "; if (dk == 0) Sleep(100);
	gotoXY(x - 0, y - 2); cout << "          ";if (dk == 0) Sleep(100);
	gotoXY(x - 0, y - 1); cout << "          ";if (dk == 0) Sleep(100);
	gotoXY(x - 0, y - 0); cout << "          ";
}
int Help(int xn, int yn, int xq, int yq, int hd){
	if(xn + 12 > xq && hd == 1 && yn - 2 >= yq -3 && yn - 2 <= yq)
		return 1;
	if( xn > xq && xn -6 <= xq + 5 && hd == 2 && yn - 2 >= yq -3 && yn - 2 <= yq)
		return 1;
	return 0;
}
void XuyenTuong(int x, int y, int r, int d, int &xn, int &yn, int k){
			if(xn  == x - 6 && yn >= y  && yn <= y + r) // Ben trai
				xn--;
		if(k != 1)
			if(xn  >= x-6 && xn <= x + d && yn == y)	// Ben tren
				yn--;
			if(xn == x + d && yn >= y && yn <= y + r)	// Ben phai
				xn++;
		if(k != 2)
			if(xn >= x-6 && xn <= x + d && yn == y + r + 3)	// Ben duoi
				yn++;
}
void Tuong(int &xn, int &yn, int map){
	if(xn ==0) xn = 1;
	if(yn == 3) yn = 4;
	if(yn == 45) yn = 44;
	if(xn == 204) xn = 203;
	if(map == 1){
		if(xn < 60){
			XuyenTuong(40, 8, 37, 15, xn, yn, 2);
		}else
		if(xn <=140)
			XuyenTuong(80, 0, 25, 40, xn, yn, 1);
		else
		if(xn <= 170)
			XuyenTuong(150, 8, 37, 15, xn, yn, 2);
	}else{
		XuyenTuong(45, 14, 2, 55, xn, yn, 0);
		XuyenTuong(145, 28, 2, 75, xn, yn, 0);
		XuyenTuong(160, 35, 2, 45, xn, yn, 0);
		XuyenTuong(30, 6, 33, 15, xn, yn, 0);
		XuyenTuong(100, 0, 25, 10, xn, yn, 0);
		XuyenTuong(60, 0, 7, 20, xn, yn, 0);
		XuyenTuong(65, 25, 20, 20, xn, yn, 0);
		XuyenTuong(130, 6, 33, 15, xn, yn, 0);
	}
}
int main(){
	int k, k1,xn, yn, hd, chieu, xq, yq, time, itime, endd, xcc, ycc, help = 0, map = 1;
	char dk;
	char a1[100], a2[100], a3[100], a4[100];
	strcpy(a1, "1. Bat dau ");
	strcpy(a2, "2. Cai dat ");
	strcpy(a3, "0. Thoat ");
	strcpy(a4, "Chuc nang:");
	do{	
		clrscr();
		TaoO(90,24,4);
		gotoXY(99, 23); cout << "Map - " << map;
		ThemChu(91, 25, a1, a2, a3, a4, 0);
		cin >> k;
		switch(k){
			case 1 :{
				clrscr();
				VeMap(map);
				if(map == 1){
					xn = 20, yn= 45, xq = 180, yq = 40;
					VeThap(5,44);
					time = 15;
				}else{
					VeThap(5, 25);
					xn = 19, yn= 25, xq = 190, yq =20;
					time = 20;
				}
				itime = 0, endd, xcc = xq +6, ycc = yq, help = 0,hd = 1, chieu = 0;
				TextColor(12);
				VeCongChua(xcc, ycc);
				VeYeuQuai(xq, yq, time, 1);
					while(1){
						if(kbhit()){
							dk = getch();
							switch(dk){ 
								case 'w':{
									yn --;
									gotoXY(xn, yn+1); cout << "     ";
									if(help == 2){
										ycc --;
										gotoXY(xcc, ycc+1); cout << "        ";
									}
									hd = 1;
									break;
								}
								case 'a':{
									xn --;
									if(help == 2){
										xcc --;
									}
									hd = 2;
									break;
								}
								case 'd':{
									xn ++;
									if(help == 2){
										xcc ++;
									}
									hd = 1;
									break;
									}
								case 'x':{
									yn++;
									gotoXY(xn, yn-4); cout << "     ";
									hd = 1;
									if(help == 2){
										ycc ++;
										gotoXY(xcc, ycc - 4); cout << "        ";
									}
								break;
								}
								case 's':{
									chieu = 1;
									if(help != 2)
									help = Help(xn, yn, xq, yq, hd);
									break;
								}
							}
						}
						Tuong(xn, yn, map);
						if(help == 2){
							Tuong(xcc, ycc, map);
							TextColor(12);
							VeCongChua(xcc, ycc);
						}
						gotoXY(0,0);
						VeHoangTu(xn, yn, hd, chieu);
						if(map == 1){
							if(xn == 18 && yn <= 44 && yn >= 39){
								if(help == 2){
									TextColor(14);
									gotoXY(80, 15); cout << "You win!"; map++;
									break;
								}else{
									TextColor(12);
									gotoXY(80, 30); cout << "Cong chua van chua duoc cuu! Hay quay tro lai cuu cong chua.";
									getch();
									gotoXY(80, 30); cout << "                                                            ";
									xn++;
								}
							}
						}else{
							if(xn == 18 && yn <= 25 && yn >= 20){
								if(help == 2){
									TextColor(14);
									gotoXY(90, 30); cout << "You win!";
									clrscr();
									break;
								}else{
									TextColor(12);
									gotoXY(90, 30); cout << "Cong chua van chua duoc cuu!";
									gotoXY(90, 31); cout << "Hay quay tro lai cuu cong chua.";
									getch();
									gotoXY(90, 30); cout << "                            ";
									gotoXY(90, 31); cout << "                               ";
									xn++;
								}
							}
						}
						if(help == 0)
							VeYeuQuai(xq, yq, time, 0);
						if(time == 0){
							TextColor(1);
							VeCongChua(xcc, ycc);
						}
						if(help == 1){
							XoaNV(xq, yq, 0);	XoaNV(xcc, ycc, 1);
							xq = 0;
							yq = 0;
							xcc = xn+5;
							ycc = yn;
							help = 2;
							TextColor(12);
							gotoXY(xn + 6, yn -2); cout << char (3);
						}
						if(help == 0){
							itime++;
							if(time == 0){
								TextColor(4);
								gotoXY(80, 15); cout << "The princess was murdered!";
								getch();
								break;
							}
							if(itime == 30){
								time --;
								itime = 0;
							}
						}
						if(chieu == 1)
							chieu = 0;
						Sleep(50);
					}
					
					break;
				}
			case 2:{
				clrscr();
				gotoXY(92, 23); cout << "Chon map(1 or 2): ";
				cin >> map;
				break;
			}
			case 0:{
				clrscr();
				TextColor(12);
				gotoXY(100, 25);
				cout << "Bye";
				break;
			}
		}
	}while(k != 0);
}

/*
Idea
sinh vi tri cua 1 cong chua bi quai vat tan cong thoi gian giai cuu cang ngan ban se co co hoi cuoi cong chua
nv cua ban la den va tieu diet roi dan con chua ve lau dai
*/
