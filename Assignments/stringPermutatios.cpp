#include <iostream>
#include <vector>
using namespace std;


//Print all permutations starting from index be
void stringPermutations( char str[], int i, vector<char> decisonSoFar, int j, int s_last){
	if(str[i] == '\0'){
		for (vector<char>::const_iterator i = decisonSoFar.begin(); i != decisonSoFar.end(); ++i) cout << *i;
		cout << endl;
		return;
	}

	if(s_last >= j){
		decisonSoFar.insert(decisonSoFar.begin()+j, str[i]);
		stringPermutations(str, ++i, decisonSoFar, ++j, s_last);
		decisonSoFar.insert(decisonSoFar.begin()+s_last, str[i]);
		stringPermutations(str, ++i, decisonSoFar, j, --s_last);
	}else{
		for (vector<char>::const_iterator i = decisonSoFar.begin(); i != decisonSoFar.end(); ++i) cout << *i;
		cout << endl;
		return;
	}
}

int main(){
	char str[21];
	vector<char> decisonSoFar;
	int s_last = 0;
	cin >> str;
	while(str[s_last] != '\0') ++s_last;
	decisonSoFar.resize(s_last);
	//Print all permutations starting from index be
	stringPermutations(str, 0, decisonSoFar, 0, s_last-1);
}