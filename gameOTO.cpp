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

void VeVatThe1(int i, int j){ // n = 7
	TextColor(9);
	gotoXY(i, j + -1);		
	cout <<"       " ;
	if(j+1 <= 25){
		gotoXY(i, j + 0);		
		cout <<"   +   " ;
	}
	if(j+2 <= 25){
		gotoXY(i, j + 1);		
		cout <<"  +++  " ;
	}
	if(j+3 <= 25){
		gotoXY(i, j + 2);		
		cout <<" +++++ " ;
	}
	if(j+4 <= 25){
		gotoXY(i, j + 3);		
		cout <<"  +++  " ;
	}
	if(j+5 <= 25){
		gotoXY(i, j + 4);		
		cout <<"   +   " ;
	}
}
void VeVatThe2(int i, int j){ // n = 10
	TextColor(14);
	gotoXY(i, j + -1);		
	cout <<"         " ;
	if(j+1 <= 25){
		gotoXY(i, j + 0);		
		cout <<" ******** " ;
	}
	if(j+2 <= 25){
		gotoXY(i, j + 1);		
		cout <<" ******** " ;
	}
	if(j+3 <= 25){
		gotoXY(i, j + 2);		
		cout <<" ******** " ;
	}
	if(j+4 <= 25){
		gotoXY(i, j + 3);		
		cout <<" ******** " ;
	}
	if(j+5 <= 25){
		gotoXY(i, j + 4);		
		cout <<" ******** " ;
	}
}
void VeVatThe3(int i, int j){ // n = 26;
	TextColor(11);
	gotoXY(i, j + -1);		
	cout << "                ";
	if(j+1 <= 25){
		gotoXY(i, j + 0);		
		cout << "    (\\_(\\ ";
	}
	if(j+2 <= 25){
		gotoXY(i, j + 1);		
		cout << "    (=’ :’) ";
	}
	if(j+3 <= 25){
		gotoXY(i, j + 2);		
		cout << "•.. (,(”)(”)";
	}
}
void VeVatThe4(int i, int j){ // n = 27
	TextColor(11);
	gotoXY(i, j + -1);		
		cout << "                         ";
	if(j+1 <= 25){
		gotoXY(i, j + 0);		
		cout << "       ..•:::::•..       ";
	}
	if(j+2 <= 25){
		gotoXY(i, j + 1);		
		cout << "¸,.•´¨`•.( -.- ).•´¨`•.,¸";
	}
	if(j+3 <= 25){
		gotoXY(i, j + 2);		
		cout << "  ¨`•–•-¨( “)(“ )¨-•–•´¨ ";
	}
}
void VeXe(int i, int j){
	TextColor(14);
	gotoXY(i, j + 0);	cout << "   *   ";
	gotoXY(i, j + 1);	cout << "  ***  ";
	gotoXY(i, j + 2);	cout << " ***** ";
}
void XoaXe(int i, int j){
	gotoXY(i, j + 0);	cout << "  ";
	gotoXY(i, j + 1);	cout << "  ";
	gotoXY(i, j + 2);	cout << " ";
}
void Sleep(int x){
	int i, j;
	for(i=0; i<1000*x ; i++)
		for(j=0; j<213; j++);
}
int KT(int x1, int y1, int x2, int y2, int n){
	/*
	
	00	10	20	x1,y1
	01	11	21				++
	02	12	22				++
		++	x2,y2
		++
	*/
	if(y2 + 3 == y1 + 5 && x1 <= x2 && x2  < x1+n)
		return 1;
	if(y2 - 2 == y1 && x2 <= x1 + n && x2 + 5 > x1)
		return 1;
	return 0;
}
void VeCanh(){
	int j;
	TextColor(14);
	for(j=0; j<25; j++){
		gotoXY(20, j);	cout << (char) 4 ;
		gotoXY(20 + 43, j); cout << (char) 4;
	}
}
void TaoO(int x, int y, int n){
	int iy, ix;
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
void ThemChu(int x, int y, char a[100], char b[100], char c[100], int d){
	int i = strlen(a)/2;
	int j = strlen(b)/2;
	int ij = strlen(c)/2;
//	if(d == 0){
		gotoXY(x + 10 - i, y); cout << a;
		gotoXY(x + 10 - j, y + 2); cout << b;
		gotoXY(x + 10 - j, y + 4); cout << c;
//	}else
//	if(d == 1){
//		gotoXY(x + 10 - j, y + 4); cout << c;
//		gotoXY(x + 10 - j, y + 2); cout << b;
//		TextColor(996);
//		gotoXY(x + 10 - i, y); cout << a;
//	}
//	if(d == 2){
//		gotoXY(x + 10 - i, y); cout << a;
//		gotoXY(x + 10 - j, y + 4); cout << c;
//		TextColor(996);
//		gotoXY(x + 10 - j, y + 2); cout << b;
//	}else{
//		gotoXY(x + 10 - i, y); cout << a;
//		gotoXY(x + 10 - j, y + 2); cout << b;
//		TextColor(996);
//		gotoXY(x + 10 - j, y + 4); cout << c;
//	}
}
int main(){
	int  max = 0, n, henXui = 1;
	int ij = 11, d, dodai, speed = 5;
	char cc;
	do{	
		clrscr();
		d = 0;
		TextColor(3);
		TaoO(46,12,3);
		char a1[100], a2[100], a3[100];
		strcpy(a1, "Bat dau");
		strcpy(a2, "Cai dat");
		strcpy(a3, "Thoat");
		ThemChu(47, 13, a1, a2, a3, d);
		gotoXY(38,10);	cout <<"    Diem cao nhat: " << max << " - muc do: " << speed;
//		gotoXY(46,12);	cout <<"    1. Bat dau.     ";
//		gotoXY(46,13);	cout <<"    0. Thoat.       "  ;
		gotoXY(46,19);	cout << "Chuc nang: "; cin >> n;
		if(n ==2 ){
			clrscr();
			gotoXY(46,15);	cout << "Muc do: "; cin >> speed;
			max = 0;
		}
		if(n == 1){
			clrscr();
			int i1 = 24, i2 =40, j1 = 3, j2 = 22; // 2 la xe
			int count =0;
			TextColor(14);
			VeCanh();
			gotoXY(15,25);	cout << "______________________________________________________";
			char c;	
			while(1){
			TextColor(736);
			gotoXY(35, 1);
			cout << "Diem cua ban: " << count ;
			TextColor(8);
			if(kbhit()){
				c = getch();
				switch (c) {
					case 'a':{
						XoaXe(i2-1,j2);
						i2--;
						break;
					}
					case 'w':{
						gotoXY(i2, j2 + 2);	cout << "       ";
						j2--;
						break;
					}	
					case 'd':{
						XoaXe(i2 +3, j2);
						i2++;
						break;
					}	
					case 'z':{
						gotoXY(i2, j2);	cout << "       ";
						j2++;
						break;
					}
				}
			}
		if(j2 >23)
			j2 = 23;
		if(henXui == 2 || henXui == 4){
			VeVatThe2(i1, j1);
			dodai = 10;
		}else
		if(henXui == 3){
			VeVatThe3(i1, j1);
			dodai = 12;
		}else
		if(henXui == 4){
			VeVatThe4(i1, j1);
			dodai = 27;
		}else{
			VeVatThe1(i1, j1);
			dodai = 7;
		}
		VeXe(i2, j2);
		j1++;
		if(KT(i1, j1, i2, j2, dodai) == 1){
			clrscr();
			gotoXY(50,17);
			TextColor(4);
			cout << " Ban duoc: " << count << " diem."<< "\n\n\n\n\n\n\n";
			if(count > max)
				max = count;
			break;
		}
		if(j1==26){
			srand(time(0));
			i1 = rand() %6;
			i1 += i2;
			if(i1 + dodai > 62) 
				i1 -= 8;
			j1 =3;
			count ++;
			henXui = rand() %3 + 1;
		}
		Sleep(800/speed);
	}
		}
	Sleep(3000);
	}while(n != 0);
	
}
