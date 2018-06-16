// Ankit Saini - sainiak009@gmail.com
// Backtracking is used here

#include <iostream>
using namespace std;

//Prints all permutations from index be
void perString(char str[], int be){
	if(str[be] == '\0'){
		cout << str << endl; 
		return;
	}

	for(int i = be; str[i] != '\0'; ++i){
		swap(str[i], str[be]);
		perString(str, be+1);
		swap(str[be], str[i]); //Here it is backtracking
	}
}

int main(){
	char str[100];
	cin >> str;

	//Prints all permutations from index be 
	perString(str, 0);
	return 0;
}
		