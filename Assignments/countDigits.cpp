#include <iostream>
using namespace std;

int count = 0;


void countDigits(string s, int be, int size, char m){
	if(be==size){
		cout << count;
		return;
	}

	if(s[be] == m) ++count;
	countDigits(s, be+1, size, m);
}

int main(){
	string s;
	cin >> s;
	char m;
	cin	>> m;


	//Prints number of occurrences in number
	countDigits(s, 0, s.size(), m);

	return 0;
}