#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> result;
set<string>::iterator sit;
//prints all combinations for given string starting from "index"
void printSubSequence(char str[], int be, char decisionSoFar[], int in){
	if(str[be]=='\0'){
		decisionSoFar[in] = '\0';
		string s = decisionSoFar;
		result.insert(s);
		return;
	}

	printSubSequence(str,be+1,decisionSoFar,in);
	decisionSoFar[in] = str[be];
	printSubSequence(str,be+1,decisionSoFar,in+1);
}

int main(){
	int n;
	cin >> n;
	char arr[n][21];

	for(int i=0;i<n;++i) cin >> arr[i];

	for(int j=0;j<n;++j){
		//prints all combinations for given string starting from "index"
		char decisionSoFar[21];
		printSubSequence(arr[j], 0, decisionSoFar, 0);
		for(sit = result.begin(); sit != result.end(); ++sit) cout << *sit << endl;
		result.clear();
	}
	return 0;
}