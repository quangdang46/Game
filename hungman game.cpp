#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>


using namespace std;

int KTXuatHien(int *a, int n, int x){
	int i;
	for(i=0; i<n; i++)
		if(a[i] == x)
			return 1;
	return 0;
}
void GoiY(char *a1, char *c){
	int i ; 
	for(i=0; i<= 2*strlen(a1) + 5; i++)
		c[i] = rand() % (122 - 97 + 1) + 97;
	int x[100], n =0;
	for(i=0; i<strlen(a1); i++){
		int j;
		do{
			j = rand() % (2*strlen(a1) + 5) + 1;
		} while( KTXuatHien(x, n, j) != 0);
		x[n] = j;
		n++;
		c[j] = a1[i];
	}
}
void TuCanDien(char *a, char *b, int *diem){ // a dap an, b la doan
	int i, d = 0;
	cout << "\t\t\t\t";
	for(i=0; i<strlen(a); i++){
		if(strchr(b, a[i]) != 0){
			cout << " \a" << a[i] << " ";
			d++;
		}else
			cout <<" - ";
	}
	cout << endl;
	if(d == strlen(a))
		*diem = 1;
	else 
		*diem = 0;	
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
	for(int i=0; i< strlen(c); i++)
		cout << c[i] << "  ";
		cout << endl;
}
int main(){
	int die = 0, diem =0;   // diem chet;
	char a1[100]; // Tu can tim
	char a2[100]; // lua chon cua bn
	cout << "Nhap tu khoa: ";	cin >> a1;
	char b[10000]; // Phan goi y.
	cout << "Nhap goi y: ";	cin.ignore();  cin.getline(b, 9999);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	// Tao cac tu goi y.
	char c[100]; // chua cac tu goi y.
	GoiY(a1, c);
	do{
			cout << endl;
			switch (die) { // Ve
			case 0:{
				cout << "\t+----------------------------+" << endl;
				cout << "\t|          HUNG MAN          |" << endl;
				cout << "\t+----------------------------+" << endl;
				cout << "\t|  .............             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t| | |                        |" << endl;
				cout << "\t|----------------------------|" << endl;
				break;
			}
			case 1:{
				cout << "\t+----------------------------+" << endl;
				cout << "\t|          HUNG MAN          |" << endl;
				cout << "\t+----------------------------+" << endl;
				cout << "\t|  .............             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           O             |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t| | |                        |" << endl;
				cout << "\t|----------------------------|" << endl;
				break;
			}
			case 2:{
				cout << "\t+----------------------------+" << endl;
				cout << "\t|          HUNG MAN          |" << endl;
				cout << "\t+----------------------------+" << endl;
				cout << "\t|  .............             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           O             |" << endl;
				cout << "\t|  |          | |            |" << endl;
				cout << "\t|  |          | |            |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t| | |                        |" << endl;
				cout << "\t|----------------------------|" << endl;
				break;
			}
			case 3:{
				cout << "\t+----------------------------+" << endl;
				cout << "\t|          HUNG MAN          |" << endl;
				cout << "\t+----------------------------+" << endl;
				cout << "\t|  .............             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           O             |" << endl;
				cout << "\t|  |        +=| |            |" << endl;
				cout << "\t|  |          | |            |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t| | |                        |" << endl;
				cout << "\t|----------------------------|" << endl;
				break;
			}
			case 4:{
				cout << "\t+----------------------------+" << endl;
				cout << "\t|          HUNG MAN          |" << endl;
				cout << "\t+----------------------------+" << endl;
				cout << "\t|  .............             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           O             |" << endl;
				cout << "\t|  |        +=| |=+          |" << endl;
				cout << "\t|  |          | |            |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t| | |                        |" << endl;
				cout << "\t|----------------------------|" << endl;
				break;
			}
		}
		cout << "Goi y: " << b << endl;
		cout << "\tDiem( = 5 ban se chet): " << die << endl;
		cout << "\tTu ban can dien la:\n";
		TuCanDien(a1, a2, &diem);
		if(diem == 1)
			break;
		cout << "\tCac tu goi y: ";	Xuat(c);
		char x[2];
		cout << "\tNhap chu cai tiep theo: ";	cin >> x;
		LuaChon(x, c);
		if(strstr(a1, x) != 0){
			if(strlen(a2) ==0)
				strcpy(a2, x);
			else
				strcat(a2, x);
		}else
			die++;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    }while (die != 5);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";	
	if(diem ==1)
		cout << "\n\t\t           YOU WIN!              ";
	else{
				cout << "\n		     YOU DIE!              " << endl;
				cout << "\t+----------------------------+" << endl;
				cout << "\t|          HUNG MAN          |" << endl;
				cout << "\t+----------------------------+" << endl;
				cout << "\t|  .............             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           |             |" << endl;
				cout << "\t|  |           O             |" << endl;
				cout << "\t|  |        +=| |=+          |" << endl;
				cout << "\t|  |          | |            |" << endl;
				cout << "\t|  |         || ||           |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t|  |                         |" << endl;
				cout << "\t| | |                        |" << endl;
				cout << "\t|----------------------------|" << endl;
	}
}
