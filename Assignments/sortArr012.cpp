// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int main(){
	int n,x;
	int c0 = 0;
	int c1 = 0;
	int c2 = 0;

	cin >> n;

	if(n==0){
		cout << endl;
		return;
	}
	
	for(int i=0; i<n; ++i){
		cin >> x;

		switch(x){
			case 0:
				++c0;
				break;
			case 1:
				++c1;
				break;
			case 2:
				++c2;
				break;
		}
	}

	for(int i=0; i<c0; ++i){
		cout << 0 << endl;
	}
	for(int i=0; i<c1; ++i){
		cout << 1 << endl;
	}
	for(int i=0; i<c2; ++i){
		cout << 2 << endl;
	}

	return 0;
}
		