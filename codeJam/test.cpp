// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	bool arr[5] = {false};
	char c;

	for(int i=0; i<5; ++i){
		scanf("%c", &c);
		if(c == '1') arr[i] = true;
	}

	for(int i=0; i<5; ++i)
		cout << arr[i] << endl;
	
	return 0;
}
		