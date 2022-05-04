#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char a[100];
	cout << "Nhap so a: "; cin >> a;
	if(strlen(a) > 1)
		switch (a[strlen(a) - 2] - 48){
			case 1:{
				cout << " muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 3:{
				cout << " ba muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 4:{
				cout << " bon muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 5:{
				cout << " nam muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			
			case 6:{
				cout << " sau muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 7:{
				cout << " bay muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 8:{
				cout << " tam muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 9:{
				cout << " chin muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
		}
	switch (a[strlen(a) - 1] - 48){
		case 0 :{
			cout << " khong.";
			break;
		}
		case 1 :{
			cout << " mot.";
			break;
		}
		case 2 :{
			cout << " hai.";
			break;
		}
		case 3 :{
			cout << " ba.";
			break;
		}
		case 4 :{
			cout << " bon.";
			break;
		}
		case 5 :{
			cout << " lam.";
			break;
		}case 6 :{
			cout << " sau.";
			break;
		}
		case 7 :{
			cout << " bay.";
			break;
		}
		case 8 :{
			cout << " tam.";
			break;
		}
		case 9 :{
			cout << " chin.";
			break;
		}
	}
}
