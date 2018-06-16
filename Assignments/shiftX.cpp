// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <cstring>
using namespace std;

void shift2End(char inp[], int be, int en){

	for(int i=be; i<en; ++i){
		char temp = inp[i];
		inp[i] = inp[i+1];
		inp[i+1]=temp;
	}
}


void moveX(char inp[], int be, int en){
	if(be > en) return;

	if(inp[be] == 'x'){
		shift2End(inp, be, en);
		moveX(inp, be+1, en-1);
	}else{
		moveX(inp, be+1, en);
	}

}


int main(){
	char inp[100];

	cin >> inp;
	//move all x between be and end to end
	moveX(inp, 0, strlen(inp)-1);

	cout << inp;
	return 0;
}
		