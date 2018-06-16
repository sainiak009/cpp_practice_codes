// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <string>
using namespace std;

string keypad[] = {"-","-","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypadComb(char *in, int be, char *ans, int i){
	if(in[be] == '\0'){
		ans[i] == '\0';
		cout << ans << endl;
		return;
	}

	int d = in[be] - '0';
	string s = keypad[d];

	for(int j=0; j < s.size(); ++j){
		ans[i] = s[j];
		keypadComb(in,be+1,ans,i+1);
	}
}

int main(){
	char in[100], ans[100];
	cin >> in;

	//Print all possible combinnations for digits from index be
	keypadComb(in,0,ans,0);
	return 0;
}
		