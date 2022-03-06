#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <ctime>

// dong nay de chay ham GetConsoleWindow
extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow (); 

//=============================================================================================
inline void clrscr(void);
inline void fillscr(char c)
{
    CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
    HANDLE  hConsoleOut;
    COORD   Home = {0,0};
    DWORD   dummy;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    FillConsoleOutputCharacter(hConsoleOut,c,csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
    SetConsoleCursorPosition(hConsoleOut,Home);
}

void fillscr(char c);
void clrscr()
{	
    fillscr(' ');
}

void setcolor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void gotoxy(int x,int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void SetWindowSize(SHORT width, SHORT height) //change Console Window Size
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void SetScreenBufferSize(SHORT width, SHORT height) //change Console Window Buffer Size
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;
    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    
    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}
void ShowCur(bool CursorVisibility) // an hien con tro ( 0 = an , 1 = hien )
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;
    
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;
    
    SetConsoleCursorInfo(handle, &ConCurInf);
}
//=============================================================================================

void in_khung(int &so_van_choi, char vfirst, char vsecond, int diemX, int diemO)
{
	if (so_van_choi % 2 == 0)
	{
		vfirst = 'O';
		vsecond = 'X';
	}
	else if (so_van_choi  % 2 != 0)
	{
		vfirst = 'X';
		vsecond = 'O';
	}
	
	for (int h = 0; h < 29 ; h++)
	{
		for (int w = 0; w < 35; w++)
		{
			if (h == 0)
				putchar(175);					// ve khung ngang tren
			else if (w == 34)
				putchar(31);					// ve khung doc 
			else if (h == 28)
				putchar(174);					// ve khung nang duoi 
			else  std :: cout << " ";
		}
	}
	
	setcolor(9);
		gotoxy(10,2);
	std :: cout << "Game Co Caro" << std :: endl;
	
	setcolor(12);
		gotoxy(5,4);
	std::cout << "Van Thu : " << so_van_choi << ", " << vfirst << " Di Truoc!!";
	setcolor(13);
	gotoxy(1,7);
	std::cout << "Diem Cua X: "<< diemX << "  -  "<< "Diem Cua O: " << diemO;
	setcolor(15);
}

void in_o_caro(int cdai, int crong, int line)
{
	// in ra 1 2 3 tren dau
	gotoxy(8,9);
	for(int col = 0; col <= line; col++)  // col == column
	{
		setcolor(15); 
		if(col == 2) 
		std :: cout << "1 ";
		  else if (col == 4)
		  std :: cout << "2 ";
			else if (col == 6)
			std :: cout << "3 ";
			  else std :: cout << "  ";
	}

	for (cdai = 0; cdai < line; cdai ++ )
	{
		gotoxy(10,cdai + 12);
		for(crong = 0; crong <  line; crong ++)
		{ 
			if (cdai == 0 || cdai == line - 1 || crong == 0 || crong == line - 1 )	{
				setcolor(10);
				std :: cout << "* ";				// in ra hinh vuong rong
				setcolor(15); 			}
 	 		else if (cdai == 2 && cdai > 0 && cdai < line - 2 || crong == 2 && crong > 0 && crong < line - 2
		 	       ||cdai == 4 && cdai > 0 && cdai < line - 2 || crong == 4 && crong > 0 && crong < line - 2)	{
	 		 	setcolor(10); 						
				std :: cout << "+ ";				// in ra duong caro
				setcolor(15); }
			else std :: cout << "  ";
		}
		
		if (cdai == 1 )
			std::cout << "   " << cdai << std :: endl;  	  // in ra so 1 2 3 theo hang doc ben phan kem xuong dong
		else if (cdai == 3)
			std::cout << "   " << 2 << std :: endl;  	  // in ra so 1 2 3 theo hang doc ben phan kem xuong dong
		else if (cdai == 5)
			std::cout << "   " << 3 << std :: endl;  // in ra so 1 2 3 theo hang doc ben phan kem xuong dong
	}
	
	// in ra 1 2 3 o duoi cuoi
	std::cout << std :: endl << std :: endl;
	gotoxy(8,21);
	for(int col = 0; col <= line; col++)  // col == column
	{
		if(col == 2) 
			std :: cout << "1 ";
		else if (col == 4)
			std :: cout << "2 ";
		else if (col == 6)
			std :: cout << "3 ";
		else std :: cout << "  ";
	}
	
	// in ra 1 2 3 theo hang doc ben trai
	std::cout << std :: endl;
	gotoxy (5,13);		std :: cout << "1";
	gotoxy (5,15);		std :: cout << "2";
	gotoxy (5,17);		std :: cout << "3";
}

void nhap_X_O(int &ngang, int &doc, int &buoc, int &x, int &y)
{		
	do{
		gotoxy(0,23);		 
		std :: cout << "                                  " << std :: endl;
		std :: cout << "                                  " << std :: endl;
		std :: cout << "                                  " << std :: endl;
		std :: cout << "                                  " << std :: endl;
		gotoxy(0,23);
		std :: cout << "  Nhap O Ngang : ";
		std :: cin	>> ngang ;
		std :: cout << "  Nhap Hang Doc : ";
		std :: cin	>> doc ;	
	}
	while (ngang <= 0 || ngang > 3 || doc <= 0 || doc > 3);
	
	if (ngang == 1 && doc == 1)	{
		x = 12;		y = 13;	
		buoc = 11;		}
	else if (ngang == 1 && doc == 2)	{
		x = 12; 	y = 15;	
		buoc = 12;		}
	else if (ngang == 1 && doc == 3)	{
		x = 12; 	y = 17;	
		buoc = 13;		}	
	else if (ngang == 2 && doc == 1)	{
		x = 16;		y = 13;	
		buoc = 21;		}
	else if (ngang == 2 && doc == 2)	{
		x = 16;		y = 15;	
		buoc = 22;		}	 
	else if (ngang == 2 && doc == 3)	{
		x = 16;		y = 17;	
		buoc = 23;		}
	else if (ngang == 3 && doc == 1)	{
		x = 20;		y = 13;	
		buoc = 31;		}
	else if (ngang == 3 && doc == 2)	{
		x = 20;		y = 15;	
		buoc = 32;		}
	else if (ngang == 3 && doc == 3)	{
		x = 20; 	y = 17;
		buoc = 33;		}
}

void in_X_O( int &sluot, int &x, int &y, int &so_van_choi, char vfirst, char vsecond)
{
	gotoxy(x,y);
	
	if (sluot % 2 == 0)
		{
			setcolor(11);
			std :: cout << vfirst;
			setcolor(15);
		}
		else if (sluot % 2 != 0)
		{
			setcolor(14);
			std :: cout << vsecond;
			setcolor(15);
		}
}

void xoabuoc(int mang[] ,int buoc, int &check)
{
	int turn = 9; // so luot di cua a 2 ben tong = 9
	int vtxoa = -1; //gan gia tri de kiem soat
	for (int i = 0; i < turn; i++)
	{
		if (mang[i] == buoc){
			vtxoa = i;	}
	}
	
	if (vtxoa == -1)
	{
		std  :: cout <<"  Ban Khong The Di Vi Tri Nay!!!";
		check = -1;
		Sleep(1000);
	}
		else 
		{
			check = 0;
			for (int j = vtxoa; j < turn; j++){
				mang[j] = mang[j + 1];	}
			turn--;
		}
}

void check_win_lose(int buoc, int sluot, int so_van_choi,
					int &x1, int &x2, int &x3, int &x4, int &x5, int &x6, int &x7,int &x8, int &x9, 
					int &o1, int &o2, int &o3, int &o4, int &o5, int &o6, int &o7, int &o8, int &o9)
{
	if (so_van_choi % 2 != 0)
	{
		if (buoc  == 11 && sluot % 2 == 0)
			x1 = 1;
		else if (buoc  == 12 && sluot % 2 == 0)
			x2 = 1;
		else if (buoc  == 13 && sluot % 2 == 0)
			x3 = 1;
		else if (buoc  == 21 && sluot % 2 == 0)
			x4 = 1;
		else if (buoc  == 22 && sluot % 2 == 0)
			x5 = 1;
		else if (buoc  == 23 && sluot % 2 == 0)
			x6 = 1;
		else if (buoc  == 31 && sluot % 2 == 0)
			x7 = 1;
		else if (buoc  == 32 && sluot % 2 == 0)
			x8 = 1;
		else if (buoc  == 33 && sluot % 2 == 0)
			x9 = 1;

		if (buoc  == 11 && sluot % 2  != 0)
			o1 = 1;
		else if (buoc  == 12 && sluot % 2 != 0)
			o2 = 1;
		else if (buoc  == 13 && sluot % 2 != 0)
			o3 = 1;
		else if (buoc  == 21 && sluot % 2 != 0)
			o4 = 1;
		else if (buoc  == 22 && sluot % 2 != 0)
			o5 = 1;
		else if (buoc  == 23 && sluot % 2 != 0)
			o6 = 1;
		else if (buoc  == 31 && sluot % 2 != 0)
			o7 = 1;
		else if (buoc  == 32 && sluot % 2 != 0)
			o8 = 1;
		else if (buoc  == 33 && sluot % 2 != 0)
			o9 = 1;
	}
	
	if (so_van_choi % 2 == 0)
	{
		if (buoc  == 11 && sluot % 2 != 0)
			x1 = 1;
		else if (buoc  == 12 && sluot % 2 != 0)
			x2 = 1;
		else if (buoc  == 13 && sluot % 2 != 0)
			x3 = 1;
		else if (buoc  == 21 && sluot % 2 != 0)
			x4 = 1;
		else if (buoc  == 22 && sluot % 2 != 0)
			x5 = 1;
		else if (buoc  == 23 && sluot % 2 != 0)
			x6 = 1;
		else if (buoc  == 31 && sluot % 2 != 0)
			x7 = 1;
		else if (buoc  == 32 && sluot % 2 != 0)
			x8 = 1;
		else if (buoc  == 33 && sluot % 2 != 0)
			x9 = 1;
			
			if (buoc  == 11 && sluot % 2  == 0)
			o1 = 1;
		else if (buoc  == 12 && sluot % 2 == 0)
			o2 = 1;
		else if (buoc  == 13 && sluot % 2 == 0)
			o3 = 1;
		else if (buoc  == 21 && sluot % 2 == 0)
			o4 = 1;
		else if (buoc  == 22 && sluot % 2 == 0)
			o5 = 1;
		else if (buoc  == 23 && sluot % 2 == 0)
			o6 = 1;
		else if (buoc  == 31 && sluot % 2 == 0)
			o7 = 1;
		else if (buoc  == 32 && sluot % 2 == 0)
			o8 = 1;
		else if (buoc  == 33 && sluot % 2 == 0)
			o9 = 1;

	}
}

void try_again(bool &again)
{
	int num;
	do {
	gotoxy(0,23);	 	
	std :: cout << "                                  " << std :: endl;
	std :: cout << "                                  " << std :: endl;
	std :: cout << "                                  " << std :: endl;
	std :: cout << "                                  " << std :: endl;
	std :: cout << "                                  " << std :: endl;
	gotoxy(0,23);
	std :: cout << "  Ban Co Muon Choi Lai Khong ?" << std :: endl;
	std :: cout << "  Bam Phim 1 Neu Thu Lai!!" << std :: endl;
	std :: cout << "  Bam Phim 2 Neu Ban Muoc Thoat!!" << std :: endl;
	std :: cout << "  Moi Nhap Lua Chon : ";
	std :: cin >> num;
	} 
	while (num < 0 || num > 2);
	
	if (num == 2)
	{
		again = false;
	}
	else if (num == 1)
	{
		again = true;
	}
}

int main()
{ 
	/*		   
				0
			   +--------------------> x
			   |	  1   2   3
			   |	- - - - - - -  
		       |	| 1 | 2 | 3 |  1
			   |    | = = = = = |
			   |	| 4 | 5 | 6 |  2
			   |	| = = = = = | 
			   |	| 7 | 8 | 9 |  3
			   |    - - - - - - -
			Y \ /
	*/
	SetConsoleTitle(TEXT("Co Caro v1.0"));
	SetWindowSize(34,29);
	SetScreenBufferSize(35,30);
	DisableCtrButton(1,1,1);
	ShowCur(0);
	
	int so_van_choi = 1;		 // so luot choi tu luc bat game 
	int diemX = 0, diemO = 0;  // diem so cua 2 ben sau moi van
	bool again = true; 		 // dat bien choi laí
	char vfirst ,vsecond; // gia tri di dau tien va th2
	
	// do while vong lap vo tan bang bien again 
	do {
		
		// so van 
		if (so_van_choi % 2 == 0)
		{
			vfirst = 'O';
			vsecond = 'X';
		}
		else if (so_van_choi  % 2 != 0)
		{
			vfirst = 'X';
			vsecond = 'O';
		}
	
	// mang gom nhung vi tri buoc di trong 1 van
	int mang[9] = {11,12,13,21,22,23,31,32,33};  
	// bien x1-9 va o1-9 dung de tinh toan dk thang hoac thua, check bang tren 
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0, x9 = 0;
	int o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0, o7 = 0, o8 = 0, o9 = 0;
	int cdai, crong, line =7; // chieu dai, chieu rong de ve hinh, l vuong, ine la do dai canh hinh vuong
	int sluot, ngang, doc; // so luot di, vi tri ngang , vi tri doc
	int x, y, buoc = 0; // x = ngang, y = doc, // dat bien check buoc co the di va xoa mang
	int check = -1;  // dat bien check de kiem tra so buoc co the di duoc 
	
	in_khung(so_van_choi,vfirst,vsecond,diemX,diemO);      // in ra khung vien man hinh 
	
	in_o_caro(cdai,crong,line);								// in ra khung hinh chu nhat va o caro
	
		for (sluot = 0; sluot < 9; sluot ++)
		{
			do{
			nhap_X_O(ngang,doc,buoc,x,y);  
			xoabuoc(mang,buoc,check);
			}	while (check == -1);						// dieu kien de di 
			
			in_X_O(sluot,x,y,so_van_choi,vfirst,vsecond);	// sau khi thoa dieu kien roi se in ra man hinh
			
			// dieu kien thang - thua - hoa 
			check_win_lose(buoc,sluot,so_van_choi,x1,x2,x3,x4,x5,x6,x7,x8,x9,o1,o2,o3,o4,o5,o6,o7,o8,o9);
		
		// dieu kien thang cua x (ngang + doc + cheo )
		if (x1 == 1 && x2 ==1 && x3 == 1 || x4 == 1 && x5 ==1 && x6 == 1 || x7 == 1 && x8 ==1 && x9 == 1
		 || x1 == 1 && x4 ==1 && x7 == 1 || x2 == 1 && x5 ==1 && x8 == 1 || x3 == 1 && x6 ==1 && x9 == 1 
		 || x1 == 1 && x5 ==1 && x9 == 1 || x3 == 1 && x5 ==1 && x7 == 1 )
			{
			gotoxy(0,23);		 
				std :: cout << "                                  " << std :: endl;
				std :: cout << "                                  " << std :: endl;
				std :: cout << "                                  " << std :: endl;
				std :: cout << "                                  " << std :: endl;
			gotoxy(0,23);
				std :: cout << "  X thang!!!  O Thua!!!" << std :: endl;
			Sleep(2000);
			try_again(again);
			Sleep(1000);
			diemX++;
			break;
			}
		
		// dieu kien thang cua 0 (ngang + doc + cheo )
		if (o1 == 1 && o2 ==1 && o3 == 1 || o4 == 1 && o5 ==1 && o6 == 1 || o7 == 1 && o8 ==1 && o9 == 1
		 || o1 == 1 && o4 ==1 && o7 == 1 || o2 == 1 && o5 ==1 && o8 == 1 || o3 == 1 && o6 ==1 && o9 == 1 
		 || o1 == 1 && o5 ==1 && o9 == 1 || o3 == 1 && o5 ==1 && o7 == 1 )
			{
				gotoxy(0,23);
					std :: cout << "                                  " << std :: endl;
					std :: cout << "                                  " << std :: endl;
					std :: cout << "                                  " << std :: endl;
					std :: cout << "                                  " << std :: endl;
				gotoxy(0,23);
					std :: cout << "  O thang!!!  X Thua!!!" << std :: endl;
				Sleep(2000);
				try_again(again);
				Sleep(1000);
				diemO++;
				break;
			}
			
			if (sluot == 8)		
			{
				gotoxy(0,23);		 	
					std :: cout << "                                  " << std :: endl;
					std :: cout << "                                  " << std :: endl;
					std :: cout << "                                  " << std :: endl;
					std :: cout << "                                  " << std :: endl;
					std :: cout << "                                  " << std :: endl;
				gotoxy(0,23);
					std :: cout << "  Ban Da Het Luot Choi!!!\n";
					std :: cout << "  Ket Qua: Hoa NHau!!!\n";	
				Sleep(2000);
				try_again(again);
				Sleep(1000);
				break;			
			}
		}	
	so_van_choi++;
	clrscr();	
	}	
	while (again == true);		
}