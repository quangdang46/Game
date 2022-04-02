#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool kt(char a[]){
    if((a[1] != '-' and a[1] == a[2] and a[2] == a[3])or(a[4] != '-' and a[5] == a[4] and a[4] == a[6])or(a[7] != '-' and a[7] == a[8] and a[8] == a[9])or(a[3] != '-' and a[3] == a[9] and a[9] == a[6])or(a[4] != '-' and a[1] == a[4] and a[4] == a[7])or(a[1] != '-' and a[5] == a[1] and a[5] == a[9])or(a[2] != '-' and a[5] == a[2] and a[5] == a[8])or(a[3] != '-' and a[5] == a[3] and a[5] == a[7])){
        return false;
    }else
    if(a[1]=='-' or a[1]=='-' or a[2]=='-' or a[3]=='-' or a[4]=='-' or a[5]=='-' or a[6]=='-' or a[7]=='-' or a[8]=='-' or a[9]=='-'){
        return true;
    }else{
        return false;
    }
}
ll t = 1, x = 1;
void tkct(char a[]){
	if((a[1] == 'o' and a[2] == 'o' and a[3] =='-')or(a[3] == 'o' and a[2] == 'o' and a[1] =='-')or(a[1] == 'o' and a[3] == 'o' and a[2] =='-')){
		a[1] = 'o';
		a[2] = 'o';
		a[3] = 'o';
		t = 0; 
		x = 0; 
	}else
	if((a[4] == 'o' and a[5] == 'o' and a[6] =='-')or(a[6] == 'o' and a[5] == 'o' and a[4] =='-')or(a[4] == 'o' and a[6] == 'o' and a[5] =='-')){
		a[4] = 'o';
		a[5] = 'o';
		a[6] = 'o';
		t = 0; 
		x = 0; 
	}else
	if((a[7] == 'o' and a[8] == 'o' and a[9] =='-')or(a[9] == 'o' and a[8] == 'o' and a[7] =='-')or(a[7] == 'o' and a[9] == 'o' and a[8] =='-')){
		a[7] = 'o';
		a[8] = 'o';
		a[9] = 'o';
		t = 0; 
		x = 0; 
	}else
	if((a[1] == 'o' and a[5] == 'o' and a[9] =='-')or(a[1] == 'o' and a[9] == 'o' and a[5] =='-')or(a[9] == 'o' and a[5] == 'o' and a[1] =='-')){
		a[1] = 'o';
		a[5] = 'o';
		a[9] = 'o';
		t = 0; 
		x = 0; 
	}else
	if((a[5] == 'o' and a[2] == 'o' and a[8] =='-')or(a[8] == 'o' and a[2] == 'o' and a[5] =='-')or(a[8] == 'o' and a[5] == 'o' and a[2] =='-')){
		a[5] = 'o';
		a[2] = 'o';
		a[8] = 'o';
		t = 0; 
		x = 0; 
	}else
	if((a[7] == 'o' and a[5] == 'o' and a[3] =='-')or(a[3] == 'o' and a[7] == 'o' and a[5] =='-')or(a[5] == 'o' and a[3] == 'o' and a[7] =='-')){
		a[5] = 'o';
		a[7] = 'o';
		a[3] = 'o';
		t = 0; 
		x = 0; 
	}else
	if((a[1] == 'o' and a[4] == 'o' and a[7] =='-')or(a[4] == 'o' and a[7] == 'o' and a[1] =='-')or(a[1] == 'o' and a[7] == 'o' and a[4] =='-')){
		a[1] = 'o';
		a[4] = 'o';
		a[7] = 'o';
		t = 0; 
		x = 0; 
	}else
	if((a[6] == 'o' and a[9] == 'o' and a[3] =='-')or(a[3] == 'o' and a[6] == 'o' and a[9] =='-')or(a[9] == 'o' and a[3] == 'o' and a[6] =='-')){
		a[6] = 'o';
		a[9] = 'o';
		a[3] = 'o';
		t = 0; 
		x = 0; 
	}
} 

void dk(char a[]){
	if((a[1] == 'x' and a[2] == 'x' and a[3] =='-')or(a[3] == 'x' and a[2] == 'x' and a[1] =='-')or(a[1] == 'x' and a[3] == 'x' and a[2] =='-')){
		if(a[1] != 'x'){
			a[1] = 'o'; 
			t = 0; 
		}else 
		if(a[2] != 'x'){
			a[2] = 'o'; 
			t = 0; 
		}else
		if(a[3] != 'x'){
			a[3] = 'o'; 
			t = 0; 
		}
	}else
	if((a[4] == 'x' and a[5] == 'x' and a[6] =='-')or(a[6] == 'x' and a[5] == 'x' and a[4] =='-')or(a[4] == 'x' and a[6] == 'x' and a[5] =='-')){
		if(a[4] != 'x'){
			a[4] = 'o'; 
			t = 0; 
		}else 
		if(a[5] != 'x'){
			a[5] = 'o'; 
			t = 0; 
		}else
		if(a[6] != 'x'){
			a[6] = 'o'; 
			t = 0; 
		}
	}else
	if((a[7] == 'x' and a[8] == 'x' and a[9] =='-')or(a[9] == 'x' and a[8] == 'x' and a[7] =='-')or(a[7] == 'x' and a[9] == 'x' and a[8] =='-')){
		if(a[7] != 'x'){
			a[7] = 'o'; 
			t = 0; 
		}else 
		if(a[8] != 'x'){
			a[8] = 'o'; 
			t = 0; 
		}else
		if(a[9] != 'x'){
			a[9] = 'o'; 
			t = 0; 
		}
	}else
	if((a[1] == 'x' and a[5] == 'x' and a[9] =='-')or(a[1] == 'x' and a[9] == 'x' and a[5] =='-')or(a[9] == 'x' and a[5] == 'x' and a[1] =='-')){
		if(a[1] != 'x'){
			a[1] = 'o'; 
			t = 0; 
		}else 
		if(a[5] != 'x'){
			a[5] = 'o'; 
			t = 0; 
		}else
		if(a[9] != 'x'){
			a[9] = 'o'; 
			t = 0; 
		}
	}else
	if((a[5] == 'x' and a[2] == 'x' and a[8] =='-')or(a[8] == 'x' and a[2] == 'x' and a[5] =='-')or(a[8] == 'x' and a[5] == 'x' and a[2] =='-')){
		if(a[2] != 'x'){
			a[2] = 'o'; 
			t = 0; 
		}else 
		if(a[5] != 'x'){
			a[5] = 'o'; 
			t = 0; 
		}else
		if(a[8] != 'x'){
			a[8] = 'o'; 
			t = 0; 
		}
	}else
	if((a[7] == 'x' and a[5] == 'x' and a[3] =='-')or(a[3] == 'x' and a[7] == 'x' and a[5] =='-')or(a[5] == 'x' and a[3] == 'x' and a[7] =='-')){
		if(a[3] != 'x'){
			a[3] = 'o'; 
			t = 0; 
		}else 
		if(a[5] != 'x'){
			a[5] = 'o'; 
			t = 0; 
		}else
		if(a[7] != 'x'){
			a[7] = 'o'; 
			t = 0; 
		}
	}else
	if((a[1] == 'x' and a[4] == 'x' and a[7] =='-')or(a[4] == 'x' and a[7] == 'x' and a[1] =='-')or(a[1] == 'x' and a[7] == 'x' and a[4] =='-')){
	if(a[1] != 'x'){
			a[1] = 'o'; 
			t = 0; 
		}else 
		if(a[4] != 'x'){
			a[4] = 'o'; 
			t = 0; 
		}else
		if(a[7] != 'x'){
			a[7] = 'o'; 
			t = 0; 
		}
	}else
	if((a[6] == 'x' and a[9] == 'x' and a[3] =='-')or(a[3] == 'x' and a[6] == 'x' and a[9] =='-')or(a[9] == 'x' and a[3] == 'x' and a[6] =='-')){
		if(a[6] != 'x'){
			a[6] = 'o'; 
			t = 0; 
		}else 
		if(a[3] != 'x'){
			a[3] = 'o'; 
			t = 0; 
		}else
		if(a[9] != 'x'){
			a[9] = 'o'; 
			t = 0; 
		}
	}
} 

void giang_hoa(char a[]){
	if(a[1] == a[9] and a[9] =='x'){ 
		if(a[3] == '-'){
			a[3] = 'o'; 
			t = 0; 
		}
		if(a[7] == '-'){
			a[7] = 'o'; 
			t = 0; 
		} 
	}else
	if(a[3] == a[7] and a[7] =='x'){
		if(a[1] == '-'){
			a[1] = 'o'; 
			t = 0; 
		}else
		if(a[9] == '-'){
			a[9] = 'o'; 
			t = 0; 
		} 
	} 
} 

void giang_hoa2(char a[]){
	if(a[1] == '-' and a[9] =='x'){ 
		a[1] = 'o';
		t = 0; 
	}else
	if(a[8] == '-' and a[9] =='x'){ 
		a[8] = 'o';
		t = 0; 
	}else
	if(a[6] == '-' and a[9] =='x'){ 
		a[6] = 'o';
		t = 0; 
	}else
	if(a[3] == '-' and a[7] =='x'){
		a[3] = 'o';
		t = 0; 
	}else
	if(a[8] == '-' and a[7] =='x'){
		a[8] = 'o';
		t = 0; 
	}else
	if(a[4] == '-' and a[7] =='x'){
		a[4] = 'o';
		t = 0; 
	}else
	if(a[9] == '-' and a[1] =='x'){ 
		a[9] = 'o';
		t = 0;
	}else
	if(a[2] == '-' and a[1] =='x'){ 
		a[2] = 'o';
		t = 0; 
	}else
	if(a[4] == '-' and a[1] =='x'){ 
		a[4] = 'o';
		t = 0; 
	}else
	if(a[7] == '-' and a[3] =='x'){ 
		a[7] = 'o';
		t = 0; 
	}else
	if(a[2] == '-' and a[3] =='x'){ 
		a[2] = 'o';
		t = 0; 
	}else
	if(a[6] == '-' and a[3] =='x'){ 
		a[6] = 'o';
		t = 0; 
	}
} 

bool ktt(char a[]){
	if((a[1] == 'x' and a[1] == a[2] and a[2] == a[3])or(a[4] == 'x' and a[5] == a[4] and a[4] == a[6])or(a[7] == 'x' and a[7] == a[8] and a[8] == a[9])or(a[3] == 'x' and a[3] == a[9] and a[9] == a[6])or(a[4] == 'x' and a[1] == a[4] and a[4] == a[7])or(a[1] == 'x' and a[5] == a[1] and a[5] == a[9])or(a[2] == 'x' and a[5] == a[2] and a[5] == a[8])or(a[3] == 'x' and a[5] == a[3] and a[5] == a[7])){
        return true;
    }else{
    	return false;
	}
} 

int main()
{
    char a[100];
    for(ll i = 1; i <= 9; i++){
        a[i] = '-';
    }
	while(kt(a)){
		for(ll i = 1; i <= 9; i++){
	    	if(i % 3 != 0){
	    		cout << a[i] <<" | "; 
			}else{
				cout << a[i] <<endl; 
			} 
		} 
		cout << "                              you : x\n"; 
		cout << "                              me : o\n"; 
		ll z, y; 
		cout << "hay danh dau!\n";
		cout << "ban chon danh o hang :";
		cin >> z;
		cout << "\nban chon danh o cot :";
		cin >> y;
		cout <<"\n";
		a[3*z - (3-y)] = 'x';
		t = 1; 
		system("cls");
		if(z == 2 and y == 2){
			for(ll i = 1; i <= 9; i++){
				if(a[i] == '-'){
					a[i] = 'o';
					t = 0;
					break; 
				} 
			}
		} 
    	if(t == 1 and kt(a)){
    		dk(a);
		}
		if(t == 1 and kt(a)){
			giang_hoa2(a); 
		}
		x = 1; 
		if(t == 1 and kt(a)){
			tkct(a);
		}
		if(x == 0 and !kt(a)){
			system("cls");
			for(ll i = 1; i <= 9; i++){
		    	if(i % 3 != 0){
		    		cout << a[i] <<" | "; 
				}else{
					cout << a[i] <<endl; 
				} 
			} 
		  cout <<"Thua ruiii!! :>"; 
		  return 0; 
		}
		if(t == 1 and kt(a)){
			giang_hoa(a); 
		}
		if(t == 1 and kt(a)){
			for(ll i = 1; i <= 9; i++){
				if(a[i] =='-'){
					a[i] = 'o';
					break; 
				} 
			} 
		} 
		if(ktt(a) and t == 1){
			system("cls");
			cout <<"ok ok t thua :33\n";
			for(ll i = 1; i <= 9; i++){
		    	if(i % 3 != 0){
		    		cout << a[i] <<" | "; 
				}else{
					cout << a[i] <<endl; 
				}
			}
			return 0; 
		}
		if(!kt(a)){
		   	for(ll i = 1; i <= 9; i++){
			   	if(i % 3 != 0){
			   		cout << a[i] <<" | "; 
				}else{
					cout << a[i] <<endl; 
				}
			}
			cout <<"Sao ma win dc e :>"; 
			return 0; 
		}
	}
}
