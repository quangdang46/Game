#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include "console.h"
#include <windows.h>

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
void PhaoHoa(int x, int y, int d, int max){
	if(y == max && d == 14){
			TextColor(d);
			gotoXY(x, y + 0); 	cout << "    * ";	gotoXY(50, 25);Sleep(10);
			gotoXY(x, y - 1); 	cout << "  *   *";	gotoXY(50, 25);
			gotoXY(x, y + 1); 	cout << "  *   *";	gotoXY(50, 25);
			gotoXY(x, y + 2); 	cout << "	        ";	gotoXY(50, 25);
			gotoXY(x, y - 2); 	cout << "	        ";	gotoXY(50, 25);Sleep(10);	
			gotoXY(x, y + 2); 	cout << "*       *";	gotoXY(50, 25);
			gotoXY(x, y - 2); 	cout << "*       *";	gotoXY(50, 25);
			gotoXY(x, y - 1); 	cout << "       ";	gotoXY(50, 25);
			gotoXY(x, y + 1); 	cout << "       ";	gotoXY(50, 25);Sleep(10);
	}else
	if( y == max && d == 11){
		
			TextColor(d);
			gotoXY(x + 4, y + 0); 	cout << "*";	gotoXY(50, 25);Sleep(10);
			gotoXY(x + 4, y - 2); 	cout << "*";	gotoXY(50, 25);
			gotoXY(x + 4, y + 2); 	cout << "*";	gotoXY(50, 25);
			gotoXY(x + 1, y); 	cout << "*  *  *";	gotoXY(50, 25);
			gotoXY(x + 4, y - 4); 	cout << " ";	gotoXY(50, 25);
			gotoXY(x + 4, y + 4); 	cout << " ";	gotoXY(50, 25);
			gotoXY(x, y) ;cout << " ";
			gotoXY(x + 10, y); cout << " "; Sleep(10);
				
			gotoXY(x + 4, y - 4); 	cout << "*";	gotoXY(50, 25);
			gotoXY(x + 4, y + 4); 	cout << "*";	gotoXY(50, 25);
			gotoXY(x + 10, y + 0); 	cout << "*";	gotoXY(50, 25);
			gotoXY(x -2, y + 0); 	cout << "*";	gotoXY(50, 25);
			gotoXY(x + 4, y - 2); 	cout << " ";	gotoXY(50, 25);
			gotoXY(x + 4, y + 2); 	cout << " ";	gotoXY(50, 25);
			gotoXY(x + 1, y + 0); 	cout << "       ";	gotoXY(50, 25);
	}
	if(y > max + 2){
		gotoXY(x + 4, y); 	cout << "*";
	}
	if(y > max -1){
		gotoXY(x + 4, y+3); cout <<"  ";
	}
	Sleep(10);
	gotoXY(50, 25);
}
void XoaPhao(int x, int y){
	gotoXY(x, y-4); cout << "                 ";
	gotoXY(x, y-2); cout << "                 ";
	gotoXY(x, y-3); cout << "                 ";
	gotoXY(x, y-1); cout << "                 ";
	gotoXY(x -2, y); cout << "                    ";
	gotoXY(x, y+1); cout << "                 ";
	gotoXY(x, y+2); cout << "                 ";
	gotoXY(x, y+3); cout << "                 ";
	gotoXY(x, y+4); cout << "                 ";
}
void Mung8_3(int x, int y, int color){
	TextColor(color);
	gotoXY(x + 0, y + 0); cout << "  888888888888               //       33333333333       ";	Sleep(100);
	gotoXY(x + 0, y + 1); cout << " 88          88             //                  33     ";Sleep(100);
	gotoXY(x + 0, y + 2); cout << " 88          88            //                   33      ";Sleep(100);
	gotoXY(x + 0, y + 3); cout << " 88          88           //                    33     ";Sleep(100);
	gotoXY(x + 0, y + 4); cout << " 88888888888888          //           333333333333     ";Sleep(100);
	gotoXY(x + 0, y + 5); cout << " 88          88         //                      33    ";Sleep(100);
	gotoXY(x + 0, y + 6); cout << " 88          88        //                       33    ";Sleep(100);
	gotoXY(x + 0, y + 7); cout << " 88          88       //                        33     ";Sleep(100);
	gotoXY(x + 0, y + 8); cout << "  888888888888       //               33333333333       ";
}
int main(){
	int a = 10, b = 7, color = 14;
	while(1){
		if(a < 70 && b == 7){
		gotoXY(10,b);	cout << "       Send to women sisters !!!";
		gotoXY(a, b);	cout <<"              ***       ***";
		a++; 
		gotoXY(10,b);
    		Sleep(100);
		if(a==69){
			TextColor(12);
  			gotoXY(a,b);	cout <<"              ***       ***";
   			TextColor(7);
   			b++;
   			a = 10;
		}	
		}else
		if(a <70 && b == 8){
			gotoXY(10,b);	cout <<"      Do you know ...";
     		gotoXY(a, b);	cout <<"            *******   ******* ";
 			a++; 
  			gotoXY(10,b);
     		Sleep(100);
     		if(a==69){
				TextColor(12);
  				gotoXY(a, b);	cout <<"            *******   ******* ";
   				TextColor(7);
   				b++;
   				a = 10;
			}
		}else
		if(a < 70 && b == 9){
			gotoXY(10,b);	cout <<"   Today is...";
     		gotoXY(a, b);	cout <<"           ********* ********* ";
 			a++; 
  			gotoXY(10,b);
     		Sleep(100);
     		if(a==69){
				TextColor(12);
  				gotoXY(a, b);	cout <<"           ********* ********* ";
   				TextColor(7);
   				b++;
   				a = 10;
			}
		}else
		if(a < 70 && b == 10){
			gotoXY(10,b);	cout <<"        8/3";
     		gotoXY(a, b);	cout <<"           ******************* ";
 			a++; 
  			gotoXY(10,b);
     		Sleep(100);
     		if(a==69){
				TextColor(12);
  				gotoXY(a, b);	cout <<"           ******************* ";
   				TextColor(7);
   				b++;
   				a = 10;
			}
		}else
		if(a < 70 && b == 11){
			gotoXY(10,b);	cout <<" It's your day!";
     		gotoXY(a, b);	cout <<"            ***************** ";
 			a++; 
  			gotoXY(10,b);
     		Sleep(100);
     		if(a==69){
				TextColor(12);
  				gotoXY(a, b);	cout <<"            ***************** ";
   				TextColor(7);
   				b++;
   				a = 10;
			}
		}else
		if(a < 70 && b == 12){
			gotoXY(10,b);	cout <<"  Feel special, unique and beautiful";
     		gotoXY(a, b);	cout <<"              **************                 ";
 			a++; 
  			gotoXY(10,b);
     		Sleep(100);
     		if(a==69){
				TextColor(12);
  				gotoXY(a, b);	cout <<"              **************                 ";
   				TextColor(7);
   				b++;
   				a = 10;
			}	
		}else
		if(a < 70 && b == 13){
			gotoXY(10,b);	cout <<"   And today, We want to tell you that:";
     		gotoXY(a, b);	cout <<"               ***********                               ";
 			a++; 
  			gotoXY(10,b);
     		Sleep(100);
     		if(a==69){
				TextColor(12);
  				gotoXY(a, b);	cout <<"               ***********                               ";
   				TextColor(7);
   				b++;
   				a = 10;
			}	
		}else
		if(a < 70 && b == 14){
			gotoXY(10,b);	cout <<"    'Happy Womens Day!'";
     		gotoXY(a, b);	cout <<"                 *******                              ";
 			a++; 
  			gotoXY(10,b);
     		Sleep(100);
     		if(a==69){
				TextColor(12);
  				gotoXY(a, b);	cout <<"                 *******                              ";
   				TextColor(7);
   				b++;
   				a = 10;
			}	
		}else
		if(a < 70 && b == 15){
			gotoXY(10,b);	cout <<"       Peace and Love. ";
     		gotoXY(a, b);	cout <<"                   ****                         ";
 			a++; 
  			gotoXY(10,b);
     		Sleep(100);
     		if(a==69){
				TextColor(12);
  				gotoXY(a, b);	cout <<"                   ****                         ";
   				b++;
   				a = 10;
			}	
		}else
		if(a == 10 && b == 16){
			TextColor(12);
			gotoXY(69,b); cout << "                     **                     ";	Sleep(100);
			gotoXY(69, b  + 1);	cout <<"                       *                     ";
			b++;
		}else
		if(a == 10 && b == 17){
			for(int i = 30; i>5; i--){
			PhaoHoa(55, i, 14, 6);
				PhaoHoa(55, i, 11, 6);
				PhaoHoa(61, i+6,14, 12);
				PhaoHoa(61, i+6,11, 12);
				PhaoHoa(15, i+16,14, 22);
				PhaoHoa(15, i+19,11, 22);
				PhaoHoa(35, i+19,14, 25);
				PhaoHoa(35, i+16,11, 25);
				PhaoHoa(117, i,14, 5);
				PhaoHoa(117, i,11, 5);
				PhaoHoa(127, i + 4,14, 9);
				PhaoHoa(127, i + 4,11, 9);
				PhaoHoa(137, i,14, 16);
				PhaoHoa(137, i,11, 16);
				PhaoHoa(148, i,14, 20);
				PhaoHoa(148, i,11, 20);
			}
			XoaPhao(54, 6);
			XoaPhao(61, 12);
			XoaPhao(15, 22);
			XoaPhao(35, 25);
			XoaPhao(117, 5);
			XoaPhao(127, 9);
			XoaPhao(137, 16);
			XoaPhao(148, 20);
			Mung8_3(70, 24, color);
			if(color == 14){
				color = 12;
			}else
			if(color == 12){
				color = 10;
			}else
			if(color == 10){
				color = 11;
			}else
				color = 14;
		}
		
	}
}
