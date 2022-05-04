/* co ban:

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

int main(){
	int a, b, d = 0, min, max;
	cout << "\t\tNhap khoang gia tri: " ;
	cin >> min  >> max;
	srand(time(NULL));
	a = rand() %max + min;
	srand(1);
	do{
		cout << "\t\tNhap so b: ";
		cin >> b;
		if(a > b) 
			cout << "\t\ta > b" << endl;
		if(a < b)
			cout << "\t\ta < b" << endl;
		d++;
		if(d == (int) log(max + 1 - min)/log(2) + 1) break;
	}while(a != b);
	if(d <= (int) log(max + 1 - min)/log(2) + 1)
		cout << "\t\t\aban da doan dung! a = " << a << endl;
	else
		cout << "\t\tBan da thua! a = " << a << endl;
}

/*
Nang cao : 1 chuong trinh ng choi, 1 chuong trinh may choi
May choi:

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

void startGame(int min1, int max1, int yourNumber){
	int bootNumber, count = 0;
	int min2 = min1, max2 = max1;
	do{
		bootNumber = (min2 + max2)/2;
		if(bootNumber < yourNumber)
			min2 = bootNumber;
		if(bootNumber > yourNumber)
			max2 = bootNumber;
		count ++;
	}while( bootNumber != yourNumber);
	cout << " Your number is: " << bootNumber << endl;
	cout << " Number of implementations: " << count << endl;
	
}

int main(){
	int min1, max1, yourNumber;
	cout << "Enter the value range: "; cin >> min1 >> max1;
	cout << " Enter your number: ";	cin >> yourNumber;
	startGame(min1, max1, yourNumber);
}

nguoi choi:
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void startGame(int min, int max){
	int bootNumber, yourNumber;;
	srand(time(0));
	bootNumber = rand() %max + min;
	int count = 0;
	do{
		cout << "\t\t\tEnter the your number: ";
		cin >> yourNumber;
		count ++;
		if(yourNumber > bootNumber)
			cout << "\t\t\tYour number is greater than the boot number!" << endl;
		if(yourNumber < bootNumber)
			cout << "\t\t\tYour number is smaller than the boot number!" << endl;
		cout << endl << endl;
	}while( yourNumber != bootNumber);
	cout << "\t\t\tYour point is: " << 1000 - 100*count << "\n\t\t\tThe answer is: " << bootNumber;
}

int main(){
	int min, max;
	int k;
	do{
		cout << "\t\t\t\t1. START.\n\t\t\t\t0. END.\n\t\t\t\tThe number: "; cin >> k;
		if(k==0) break;
		cout << "\t\t\tEnter value range: ";	cin >> min >> max;
		startGame(min, max);
		cout << "\n\n\n\n\n\n\n";
	} while(k != 0);
}
