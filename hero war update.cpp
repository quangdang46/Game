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
	TextColor(14);
	gotoXY(x + 10 - i, y); cout << a;
	gotoXY(x + 10 - j, y + 2); cout << b;
	gotoXY(x + 10 - ij, y + 4); cout << c;
	gotoXY(x + 10 - strlen(a1)/2, y + 6); cout << a1;
	TextColor(7);
}
void VeThapAnhHung(int x, int y){
	TextColor(14);
	gotoXY(x, y - 4); cout <<"   _____________ ";
	gotoXY(x, y - 3); cout <<"  /||         ||\\  ";
	gotoXY(x, y - 2); cout <<"   ||         ||  ";
	gotoXY(x, y - 1); cout <<"   ||         ||  ";
	gotoXY(x, y - 0); cout <<" ================= ";
	TextColor(7);
}
void VeAnhHung(int x, int y, int diem, int attack){
	if(diem < 20){
	TextColor(15);
	gotoXY(x + 1, y - 4); cout << " " << diem << " ";
	gotoXY(x, y - 5); cout <<"      ";
	gotoXY(x, y - 3); cout <<"  O   ";
	gotoXY(x, y - 2); cout <<" /|\\ ";
	gotoXY(x, y - 1); cout <<"  |  ";
	gotoXY(x, y - 0); cout <<" / \\ ";
	if(attack == 1){
		gotoXY(x, y - 1); cout <<"  |/ ";
		gotoXY(x, y - 0); cout <<" /  "; Sleep(300);
		gotoXY(x, y - 1); cout <<"  |  ";
		gotoXY(x, y - 0); cout <<" / \\ ";
	}
	}else
	if(diem < 50){
		TextColor(14);
			gotoXY(x + 1, y - 4); cout << " " << diem << " ";
		gotoXY(x, y - 5); cout <<"     ";
		gotoXY(x, y - 3); cout <<"  O    ";
		gotoXY(x, y - 2); cout <<" /|\\=}";
		gotoXY(x, y - 1); cout <<"  |   ";
		gotoXY(x, y - 0); cout <<" / \\ ";
		if(attack == 1){
			int i;
			for(i=0; i<3; i++){
				gotoXY(6+x+i, y-2);	cout << ">"; Sleep(150);
				gotoXY(6+x+i, y-2);	cout << " ";
			}
		}
	}else{
		TextColor(11);
			gotoXY(x + 1, y - 4); cout << " " << diem << "       ";
		gotoXY(x, y - 5); cout <<"            ";
		gotoXY(x, y - 3); cout <<"  _ O _  /} ";
		gotoXY(x, y - 2); cout <<" //| |\\\\/   ";
		gotoXY(x, y - 1); cout <<"  _| |_/    ";
		gotoXY(x, y - 0); cout <<"  // \\\\   ";
		if(attack == 1){
			gotoXY(x, y - 3); cout <<"  _ O _       ";Sleep(150);
			gotoXY(x, y - 2); cout <<" //| |\\\\_____ ";
			gotoXY(x, y - 1); cout <<"  _| |_       }";Sleep(150);
			gotoXY(x, y - 0); cout <<"  // \\\\ ";
			gotoXY(x, y - 3); cout <<"  _ O _  /} ";
			gotoXY(x, y - 2); cout <<" //| |\\\\/   ";
			gotoXY(x, y - 1); cout <<"  _| |_/       ";
		}
	}
	TextColor(7);
	gotoXY(0,0);
}
void DiChuyen(int &x, int &y, char c, int &attack, int xtah, int ytah){
	switch (c){
		case 'w':{
			y--;
			break;
		}
		case 'a':{
			x--;
			break;
		}
		case 'd':{
			x++;
			break;
		}
		case 'x':{
			y++;
			break;
		}
		case 's':{
			attack = 1;
			break;
		}
	}
	if(x == 0)
		x = 1;
	if(y > ytah - 5 && x + 4 >= xtah && x <= 14 + xtah)
		y = 40;
	if(y == 46)
		y = 45;
}
void Quai(int x, int y, int diem){
	if(diem == 1){
			TextColor(7);
		gotoXY(x, y - 2); cout <<" \\  /";
		gotoXY(x, y - 1); cout <<">Oooo ";
		gotoXY(x, y - 0); cout <<" /  \\";
	}else
	if(diem == 5){
		TextColor(6);
		gotoXY(x, y - 4); cout <<"\\ /";
		gotoXY(x, y - 3); cout <<"ooo";
		gotoXY(x, y - 2); cout <<"/|\\";
		gotoXY(x, y - 1); cout <<"/|\\";
		gotoXY(x, y - 0); cout <<"/ \\";
	}else
	if(diem == 10){
		TextColor(10);
		gotoXY(x, y - 4); cout <<"   \\|/";
		gotoXY(x, y - 3); cout <<"\\  ooo ";
		gotoXY(x, y - 2); cout <<" \\ /|\\";
		gotoXY(x, y - 1); cout <<"  \\/|\\";
		gotoXY(x, y - 0); cout <<"   /|\\";
	}else
	if(diem == 20){
		TextColor(13);
		gotoXY(x, y - 5); cout <<"  \\\\ //";
		gotoXY(x, y - 4); cout <<"   OOO";
		gotoXY(x, y - 3); cout <<"    | ";
		gotoXY(x, y - 2); cout <<"(\\ /|\\";
		gotoXY(x, y - 1); cout <<"  \\/|\\";
		gotoXY(x, y - 0); cout <<"   /|\\";
	}else
	if(diem == 50){
		TextColor(4);
		gotoXY(x, y - 5); cout <<"  \\\\|//";
		gotoXY(x, y - 4); cout <<"   OOO";
		gotoXY(x, y - 3); cout <<"\\  *|* ";
		gotoXY(x, y - 2); cout <<" \\ /|\\";
		gotoXY(x, y - 1); cout <<"  \\/|\\";
		gotoXY(x, y - 0); cout <<"   /|\\";
	}
	TextColor(7);
	gotoXY(0,0);
}
void XoaQuai(int x, int y, int diem){
	if(diem == 1){
		gotoXY(x, y - 1); cout <<"      "; Sleep(150);
		gotoXY(x, y - 2); cout <<"      ";
		gotoXY(x, y - 0); cout <<"      ";
	}else
	if(diem == 5){
		gotoXY(x, y - 4); cout <<"   ";	Sleep(150);
		gotoXY(x, y - 3); cout <<"   ";Sleep(150);
		gotoXY(x, y - 2); cout <<"   ";Sleep(150);
		gotoXY(x, y - 1); cout <<"   ";Sleep(150);
		gotoXY(x, y - 0); cout <<"   ";Sleep(150);
	}else
	if(diem == 10){
		gotoXY(x, y - 4); cout <<"       ";Sleep(150);
		gotoXY(x, y - 3); cout <<"       ";Sleep(150);
		gotoXY(x, y - 2); cout <<"       ";Sleep(150);
		gotoXY(x, y - 1); cout <<"       ";Sleep(150);
		gotoXY(x, y - 0); cout <<"       ";Sleep(150);
	}else{
		gotoXY(x, y - 5); cout <<"        ";Sleep(150);
		gotoXY(x, y - 4); cout <<"        ";Sleep(150);
		gotoXY(x, y - 3); cout <<"        ";Sleep(150);
		gotoXY(x, y - 2); cout <<"        ";Sleep(150);
		gotoXY(x, y - 1); cout <<"        ";Sleep(150);
		gotoXY(x, y - 0); cout <<"        ";Sleep(150);
	}
	gotoXY(0,0);
}

void VeNhaDich(int x, int y, int diem, int attack, int soluong){ // 0: khong mai, khong mong, 1 co mai khong mong, 2 co mong, mai
		int i;
		TextColor(12);
		gotoXY(5, 46);	cout << "================================================================================================================";
				
		int k = 3;
		if(soluong > 3)
			k = 6;
		else
		if(soluong > 6)
			k = 9;
		gotoXY(x, y - 8); cout <<" /||";
				gotoXY(x, y - 7); cout <<"  ||";
				gotoXY(x, y - 6); cout <<"  ||";
				gotoXY(x, y - 5); cout <<"  ||";
				gotoXY(x, y - 4); cout <<"  ||";
				gotoXY(x, y - 3); cout <<" /||";
				gotoXY(x, y - 2); cout <<"  ||";
				gotoXY(x, y - 1); cout <<"  ||";
		for(i=0; i<k*10+5; i++){
			if(i < 8*k + 5){
				gotoXY(x +i, y - 9); cout  <<"=";
				gotoXY(x +i, y - 0); cout  <<"=";
			}
			if((i > 4 && i<8*k+2 ) || i > 10*k + 5){
				gotoXY(x + i, y - 8); cout <<" ";
				gotoXY(x + i, y - 7); cout <<" ";
				gotoXY(x + i, y - 6); cout <<" ";
				gotoXY(x + i, y - 5); cout <<" ";
				gotoXY(x + i, y - 4); cout <<" ";
				gotoXY(x + i, y - 3); cout <<" ";
				gotoXY(x + i, y - 2); cout <<" ";
				gotoXY(x + i, y - 1); cout <<" ";
			}
		}
		if(attack == 1){ 
		gotoXY(x, y - 1); cout <<"    "; Sleep(150);
		gotoXY(x, y - 2); cout <<"    "; Sleep(150);
		gotoXY(x, y - 3); cout <<"    "; Sleep(150);
		gotoXY(x, y - 4); cout <<"    "; Sleep(150);
		gotoXY(x, y - 5); cout <<"    "; Sleep(150);
		gotoXY(x, y - 6); cout <<"    "; Sleep(150);
		}
		gotoXY(x+k*4, y-8); cout << "diem: " << diem;
}
void Tang(int x, int y, int diem, int attack, int &soluong){
	int a[] ={50, 20, 10, 5, 1},i = 0, d = 1;
	soluong =0;
	int Diem = diem;
	do{
		if(diem < a[i])
			i++;
		else{
			diem -= a[i];
			soluong++;
		}
	}while(diem != 0);
	diem = Diem;
	i = 0;
	VeNhaDich(x, y, Diem, attack, soluong);
	do{
		if(diem < a[i])
			i++;
		else{
			Quai(x + 7*d - 2, y - 1, a[i]);
			d++;
			diem -= a[i];
		}
	}while(diem != 0);
 //Tang 5
}
void XoaQuai(int x, int y, int diem, int attack, int soluong){
	VeNhaDich(x, y, diem, attack, soluong); //Tang 5
	int a[] ={50, 20, 10, 5, 1},i = 0, d = 1;
	do{
		if(diem < a[i])
			i++;
		else{
			XoaQuai(x + 7*d - 2, y - 1, a[i]);
			d++;
			diem -= a[i];
		}
	}while(diem != 0);
}
void ThapQuai(int x, int y, int *diem, int tang, int soluong, int luot){
	int i, r;
	srand(time(0));
	r = rand() %3;
	int k =1;
	if(luot > 5)
		k = 2;
	for(i=tang; i<4; i++)
		diem[i] = diem[i+1];
	diem[4] = k*diem[3] + diem[r];
	for(i=0; i<5; i++)
		Tang(x, y - 9*i, diem[i], 0, soluong);
}
int main(){
	int k, k1, caidat = 2, x, y, attack, diem[5], xah, yah, xtah, ytah, diemah;
	char dk;
	char a1[100], a2[100], a3[100], a4[100];
	strcpy(a1, "Bat dau");
	strcpy(a2, "Cai dat");
	strcpy(a3, "Thoat");
	strcpy(a4, "Chuc nang:");
	do{	
		clrscr();
		TaoO(46,12,4);
		int c[] = {0, 0, 0, 0, 0}, soluong;
		ThemChu(47, 13, a1, a2, a3, a4, 0);
		cin >> k;
		x = 60, y = 45, attack = 0, xah = 12, yah = 40, xtah = 10, ytah = 45, diemah = 4;
		int tang = 100;
		switch(k){
			case 1:{
				clrscr();
				int YeuCau[] = {3, 5, 10, 15, 21};
				int luot = 0;
				VeThapAnhHung(xtah, ytah);
				VeAnhHung(xah, yah, diemah, attack);
				ThapQuai(x, y, YeuCau, 2, soluong, luot);
			while(1){
					if(kbhit()){
						dk = getch();
						DiChuyen(xah, yah, dk, attack, xtah, ytah);
						char yn;
						VeAnhHung(xah, yah, diemah, attack);
						if(dk == 'w'){
							gotoXY(xah, yah + 1); cout <<"         ";
						}
						if(yah == y -9*4 -1){
							tang = 4;
						}else
						if(yah == y - 9*3 - 1){
							tang = 3;
						}else
						if(yah == y - 9*2 - 1){
							tang = 2;
						}else
						if(yah == y - 9*1 - 1){
							tang = 1;
						}else
						if(yah == y - 1)
							tang = 0;
						if(xah >= x -10 && tang != 100 && c[tang] == 0){
							gotoXY(5, 10); cout << "Ban co muon tan cong(y/n)?";
							gotoXY(6, 11); cin >> yn;
							c[tang] = 1;
							if(yn == 'y')
								Tang(x, y - 9*tang, YeuCau[tang], 1, soluong);
							else
								xah--;
							gotoXY(5, 10); cout << "                           ";
							gotoXY(6, 11); cout << "         ";
							
						}
						if(c[tang] == 1 && attack == 1 && xah >= x - 8){
							if(diemah > YeuCau[tang]){
								diemah += YeuCau[tang] + 5;
								luot ++;
								XoaQuai(x, y -9*tang, YeuCau[tang], 1, soluong);
								Sleep(300);
								c[tang] = 0;
								gotoXY(xah-5, yah - 5); cout <<"                                                              ";
								gotoXY(xah-5, yah - 4); cout <<"                                                              ";
								gotoXY(xah-5, yah - 3); cout <<"                                                              ";
								gotoXY(xah-5, yah - 2); cout <<"                                                              ";
								gotoXY(xah-5, yah - 1); cout <<"                                                              ";
								gotoXY(xah-5, yah - 0); cout <<"                                                              ";
								xah = 12, yah = 40;
								VeAnhHung(xah, yah, diemah, attack);
								ThapQuai(x, y, YeuCau, tang, soluong, luot);
							}else{
								clrscr();
								gotoXY(50, 12);	cout << "LOSE";
								getch();
								break;
							}
						}
						if(attack == 1)
							attack = 0;
					
					}
				}
				getch();
				break;
			}
			case 2:{
				clrscr();
				TaoO(46, 12, 1);
				char c[100] = {"Muc do: "};
				gotoXY(48,13);	cout << c;
				gotoXY(55,13); cin >> caidat;
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
	
	
	
	
	
	
	
	
