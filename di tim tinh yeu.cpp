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
	gotoXY(x + 10 - i, y); cout << a;
	gotoXY(x + 10 - j, y + 2); cout << b;
	gotoXY(x + 10 - ij, y + 4); cout << c;
	gotoXY(x + 10 - strlen(a1)/2, y + 6); cout << a1;
}
void VeNguoiBay(int x, int y, int d){
	TextColor(11);
	if(d == 1){
		gotoXY(x, y - 1);	cout << "          ";
		gotoXY(x, y + 0);	cout << "  \\   \\   ";
		gotoXY(x, y + 1);	cout << "   -----O ";
		gotoXY(x, y + 2);	cout << "    \\   \\" << (char) 3 << "  ";
		gotoXY(x, y + 3);	cout << "          ";
	}else{
		gotoXY(x, y - 1);	cout << "          ";
		gotoXY(x, y + 0);	cout << "   /    /   ";
		gotoXY(x, y + 1);	cout << "  ------O ";
		gotoXY(x, y + 2);	cout << "  /    /" << (char) 3 << " ";
		gotoXY(x, y + 3);	cout << "          ";
	}
	gotoXY(50,27);

}
void VeNguoi(int x, int y, int d){ // d = 2 nhay, 3 xuong, 0 di sang phai , 1 sang trai
	TextColor(12);
	if(d == 2){
		gotoXY(x, y - 1);	cout << "       ";
		gotoXY(x, y + 0); cout << "     " << (char) 3 << "  ";
		gotoXY(x, y + 1);	cout << "   O/ ";
		gotoXY(x, y + 2);	cout << "  /|  ";
		gotoXY(x, y + 3);	cout << "   |/ ";
		gotoXY(x, y + 4);	cout << "  /   ";
	}else
	if(d == 0){
		gotoXY(x, y - 1);	cout << "       ";
		gotoXY(x, y + 0); cout << " " << (char) 3 << "      ";
		gotoXY(x, y + 1);	cout << "  \\O  ";
		gotoXY(x, y + 2);	cout << "   |\\ ";
		gotoXY(x, y + 3);	cout << "   |  ";
		gotoXY(x, y + 4);	cout << "  / \\ ";
	}else
	if(d == 3){
		gotoXY(x, y - 1);	cout << "       ";
		gotoXY(x, y + 0); cout << " " << (char) 3 << "    ";
		gotoXY(x, y + 1);	cout << "  \\O/ ";
		gotoXY(x, y + 2);	cout << "   |  ";
		gotoXY(x, y + 3);	cout << "  \\|/ ";
	}else{
		gotoXY(x, y - 1);	cout << "       ";
		gotoXY(x, y + 0); cout << "     " << (char) 3 << "    ";
		gotoXY(x, y + 1);	cout << "   O/  ";
		gotoXY(x, y + 2);	cout << "  /|  ";
		gotoXY(x, y + 3);	cout << "   |   ";
		gotoXY(x, y + 4);	cout << "  / \\  ";
	}
	if(y < 20){
		gotoXY(x, y + 5);	cout << "      ";
	}
	gotoXY(50,27);
}
void ClearNguoi(int x, int y){
		gotoXY(x, y - 2);	cout << "                       ";
		gotoXY(x, y - 1);	cout << "                       ";
		gotoXY(x, y + 0); 	cout << "                       ";
		gotoXY(x, y + 1);	cout << "                       ";
		gotoXY(x, y + 2);	cout << "                       ";
		gotoXY(x, y + 3);	cout << "                       ";
		gotoXY(x, y + 4);	cout << "                       ";
}
void VeVatCan(int x, int y, int d){
	if(d == 50){
		TextColor(12);
		gotoXY(x, y + 1);	cout << "  =O  ";
		gotoXY(x, y + 2);	cout << "  /|  ";
		gotoXY(x, y + 2);	cout << (char) 3;
		gotoXY(x, y + 3);	cout << "   |   ";
		gotoXY(x, y + 4);	cout << "  / \\  ";
	}else
//	if(d == 4 || d == 6){
//		TextColor(7);
//		gotoXY(x, y + 0);	cout << "==========||              ";
//		gotoXY(x, y + 1);	cout << "  _____-------______      ";
//		gotoXY(x, y + 2);	cout << " /      FA, F0      \\    ";
//		gotoXY(x, y + 3);	cout << "/===OOO========OOO===\\   ";
//		gotoXY(x, y + 4);	cout << "    OOO        OOO        ";
//		for(int i =x; i >= x/3; i--){
//			gotoXY(i, y);
//			cout << "-";
//		}
//	}else
	if(d == 3 || d == 5){ // n =4,  h = 4
		TextColor(10);
		gotoXY(x, y - 2);	cout << " _ ";
		gotoXY(x, y - 1);	cout << "/_\\  ";
		gotoXY(x, y + 0);	cout << " O   ";
		gotoXY(x, y + 1);	cout << "/|\\   ";
		gotoXY(x, y + 2);	cout << " |   ";
		gotoXY(x, y + 3);	cout << "/ \\  ";
	}else
	if(d == 2){ // n = 2 , h= 3
		TextColor(3);
		gotoXY(x, y - 2);	cout << "F0 ";
		gotoXY(x, y - 1);	cout << "F0 ";
		gotoXY(x, y + 0);	cout << "F0 ";
		gotoXY(x, y + 1);	cout << "F0 ";
		gotoXY(x, y + 2);	cout << "F0 ";
	}else{ // n = 2, h = 3
		TextColor(1);
		gotoXY(x, y - 2);	cout << "FA ";
		gotoXY(x, y - 1);	cout << "FA ";
		gotoXY(x, y + 0);	cout << "FA ";
		gotoXY(x, y + 1);	cout << "FA ";
		gotoXY(x, y + 2);	cout << "FA ";
	}
	gotoXY(50,27);	
}
int KT(int xn, int yn, int xv, int yv, int tt, int d){
	if(tt == 1){
		if(d == 50)
			if(((xn + 1 <= xv && xn + 9 >= xv) || xn + 3 == xv) && ( yn >= yv - 4 && yn <= yv + 3) ) 
				return 1;
		if(d == 1 || d == 2 || d == 0)
			if(( (xn + 1 <= xv && xn + 9 >= xv) || xn + 3 == xv) && ( yn >= yv - 4 && yn <= yv + 2) )
				return 1;
		if(d == 3 || d == 5)
			if(((xn + 1 <= xv && xn + 9 >= xv) || xn + 3 == xv) && ( yn >= yv - 4 && yn <= yv + 3) ) 
				return 1;
		if(d == 4 || d == 6)
			if((((xn + 1 <= xv && xn + 9 >= xv) || (xn <= xv + 24)) && (yn + 2 >= yv && yn <= yv + 4)) || (yn <= yv && yn + 3 >= yv && xv - 40 < xn && xn < xv + 24 ) )
				return 1;
	}else{
		if(d == 50)
			if(((xn + 1 <= xv && xn + 9 >= xv) || xn + 3 == xv) && ( yn >= yv - 4 && yn <= yv + 3))
				return 1;
		if(d == 1 || d == 2 || d == 0)
			if(( (xn + 1 <= xv && xn + 9 >= xv) || xn + 3 == xv) && ( yn >= yv - 4 && yn <= yv + 2) )
				return 1;
		if(d == 3 || d == 5)
			if(((xn + 1 <= xv && xn + 9 >= xv) || xn + 3 == xv) && ( yn >= yv - 4 && yn <= yv + 3))
				return 1;
		if(d == 4 || d == 6)
			if((((xn + 1 <= xv && xn + 9 >= xv) || (xn <= xv + 24)) && (yn + 2 >= yv && yn <= yv + 4)) || (yn <= yv && yn + 2 >= yv && xv - xv/3 < xn && xn < xv + 24 ) )
				return 1;
	}
}
int main(){
	int k, k1, caidat = 2, win;
	char dk;
	char a1[100], a2[100], a3[100], a4[100];
	strcpy(a1, "Bat dau");
	strcpy(a2, "Cai dat");
	strcpy(a3, "Thoat");
	strcpy(a4, "Chuc nang:");
	do{	
		clrscr();
		int xn = 5, yn = 20, hd = 0, tt = 1, batdau = 0, bay = 1, henXui = 1, xv = 80, yv = 13, honKem = 1, diem = 0, kk=0;
		srand(time(0));
		win = rand() %5 + 20;
		TaoO(46,12,4);
		ThemChu(47, 13, a1, a2, a3, a4, 0);
		cin >> k;
		switch (k){
			case 1 :{
				clrscr();
				TextColor(14);
				gotoXY(5, 25);	cout <<"==================================================================================================================";
				TextColor(12); gotoXY(30, 26); cout << "DI TIM TINH YEU " << (char) 11 << " ^^ ";
				VeNguoi(5, 20, hd);
				gotoXY(5, 30); cout<< " ";
				while(1){
					if(kbhit()){
						dk = getch();
						switch(dk){ // 2 nhay, 3 xuong, 0 phai, 1 trai
							case 'w':{
								yn --;
								hd = 2;
								break;
							}
							case 'a':{
								xn --;
								hd = 1;
								break;
							}
							case 'd':{
								xn ++;
								hd = 0;
								break;
							}
							case 'x':{
								yn++;
								hd = 3;
								break;
							}
							case 's':{
								tt *= -1;
								batdau = 1;
								break;
							}
						}
					}
					if(yn >20)
						yn = 20;
					if(xn < 5)
						xn = 5;
					if(tt == 1){
						if(batdau == 1){
							ClearNguoi(xn, yn);
							yn = 20;
							batdau = 0;
						}
						VeNguoi(xn, yn, hd);	
					}else{
					if(batdau == 1){
						ClearNguoi(xn, yn);
						yn = 3;
						batdau = 0;
						}
					bay *= -1;
					VeNguoiBay(xn, yn, bay);
					}
					kk++;
					if(kk == 30/caidat + 1){
						xv--;
						kk=0;
						if(xn == xv)
						diem ++;
					}
					if(xv == 2){
						ClearNguoi(xv, yv);
						xv = 80;
						srand(time(0));
						henXui = rand() %7;
						honKem *= -1;
						yv = yn + honKem*henXui;
					}
					if(yv > 20 || yv < 4)
						yv = 18;
					if(diem + 1  % win  == 0)
						henXui = 50;
					VeVatCan(xv, yv, henXui);
					Sleep(20);
					if(KT(xn, yn, xv, yv, tt, henXui) == 1 && henXui == 50){
						clrscr();
						gotoXY(40,10);		cout << " Ban da tim duoc tinh yeu cua minh";
						getch();
						break;
						}	
					if(KT(xn, yn, xv, yv, tt, henXui) == 1){
						clrscr();
						gotoXY(50,10);		cout << "Diem cua ban: " << diem << " - muc: " << caidat;
						getch();
						break;
						}
					TextColor(14);
						gotoXY(50,27);		cout << "Diem cua ban: " << diem << " - muc: " << caidat;
						gotoXY(50,27);	
				}
				break;
			}
			case 2 :{
				clrscr();
				TaoO(46,12,1);
				gotoXY(48, 13); cout << "Muc do: " ;
				gotoXY(48 + 8, 13); cin >> caidat;
				break;
			}
			case 0 :{
				clrscr();
				gotoXY(50, 12);	cout << "GOOD BYE!";
				getch();
				break;
			}
		}
	}while(k != 0);
	/*
	Ve:
		Vat: di bo, tren khong, chuong ngai vat
	Chuyen dong: 	Vat di chuyen a w d z , thay doi s
				chuong ngai di chuyen
	*/
}





















