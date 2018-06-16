#include <iostream>
using namespace std;

//Shift string "step" steps ahead starting from "be" index
void shiftString(char chars[], int be, int step){
	int j = be;

	while(chars[j] != '\0') ++j;

	while(j >= be){
		chars[j+step] = chars[j];
		--j;
	}
}

void replace_pi(char chars[], int be){
	if(chars[be]=='\0') return;

	if(chars[be] == 'p' && chars[be+1] == 'i'){
		shiftString(chars, be+2, 2);
		chars[be] = '3';
		chars[be+1] = '.';
		chars[be+2] = '1';
		chars[be+3] = '4';
		replace_pi(chars, be+4); // Recursive Call
	}else{
		replace_pi(chars, be+1); // Recursive Call
	}
}

int main(){
	char chars[200];
	cin >> chars;

	//Replace all pi to 3.14 in char array starting from index be
	replace_pi(chars , 0);
	cout << chars;
	return 0;
}