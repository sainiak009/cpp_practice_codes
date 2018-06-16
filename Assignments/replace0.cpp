#include <iostream>
using namespace std;


//Replaces 0 with 5 from index "be" and prints
void replace5(char inp[], int be){
	if(inp[be]=='\0'){
		cout<<inp<<endl;
		return;
	}

	if(inp[be]=='0') inp[be] = '5';
	replace5(inp,be+1);
}

int main(){
	char inp[15];
	cin >> inp;

	//Replaces 0 with 5 from index "be" and prints
	replace5(inp,0);
}