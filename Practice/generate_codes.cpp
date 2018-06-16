#include <iostream>
using namespace std;

char result[20];
//Print all codes for digits starting from be
void print_codes(char inp[], int be, int ridx){
	if(inp[be]=='\0'){
		result[ridx] = '\0';
		cout << result  << endl;
		return;
	}

	int digit = inp[be]-'0';
	char alphabet = 'A'+digit-1;
	result[ridx] = alphabet;

	print_codes(inp, be+1, ridx+1);
	if (inp[be + 1] == '\0') return;

	int digit2 = inp[be+1]-'0';
	int num = digit*10 + digit2;
	if(num > 26) return;

	char alphabet2 = 'A'+num-1;
	result[ridx] = alphabet2;
	print_codes(inp, be+2, ridx+1);


}

int main(){
	char inp[20];
	cin >> inp;

	//Print all codes for digits starting from be
	print_codes(inp, 0, 0);
}