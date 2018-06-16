#include <iostream>
using namespace std;

//Shift string "step" steps ahead starting from "be" index
void shiftString(char chars[], int be){
	int j = be;

	while(chars[j+2] != '\0'){
		chars[j] = chars[j+2];
		++j;
	}
	chars[j] = '\0';
}

void replace_pi(char chars[], int be){
	if(chars[be]=='\0' || chars[be+1]=='\0' || chars[be+2]=='\0' || chars[be+3]=='\0') return;

	if(chars[be] == '3' && chars[be+1] == '.'&& chars[be+2] == '1'&& chars[be+3] == '4'){
		shiftString(chars, be+2);
		chars[be] = 'p';
		chars[be+1] = 'i';
		replace_pi(chars, be+2); // Recursive Call
	}else{
		replace_pi(chars, be+1); // Recursive Call
	}
}

int main(){
	int n;
	cin >> n;
	cin.ignore();
	char chars[n][1010];
	for(int i=0; i<n; ++i){
		cin.getline(chars[i],1000);
	}
	//Replace all pi to 3.14 in char array starting from index be
	for(int i=0; i<n; ++i){
		replace_pi(chars[i] , 0);
	}
	for(int i=0; i<n; ++i){
		cout << chars[i] << endl;
	}
	return 0;
}