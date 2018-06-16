#include <iostream>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

//Prints codes for numbers from index be
void smartKeypad1(char arr[], int be, char decisionSoFar[], int i){
	if(arr[be]=='\0'){
		decisionSoFar[i] = '\0';
		cout << decisionSoFar << endl;
		return;
	}

	int in = arr[be] - '0';
	string s = table[in];
	for(int j=0; j<s.size(); ++j){
		decisionSoFar[i] = s[j];
		smartKeypad1(arr, be+1, decisionSoFar, i+1);
	}

}


int main(){
	char input[11];
	char output[11];
	cin >> input;

	//Prints codes for numbers from index be
	smartKeypad1(input, 0, output, 0);
	return 0;
}