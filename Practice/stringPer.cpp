// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>	
using namespace std;

void swap(char &a, char &b){
	char temp = a;
	a = b;
	b = temp;
}

void stringPer(char *s, int be){
	if(s[be] == '\0'){
		cout << s << endl;
		return;
	}

	for(int i=be; s[i] != '\0'; ++i){
		swap(s[be], s[i]); 
		stringPer(s, be+1);
		swap(s[be], s[i]);
	}

}


int main(){
	char s[100];
	cin >> s;
	//Handles swaping of element at index be and prints permutaions
	stringPer(s,0);
	return 0;
}
		