// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;


bool wildCard(char text[], int t, char pattern[], int p){
	if(text[t] == '\0') return true;
	if(pattern[p] == '\0') return false;

	if(pattern[p] == '*') while(pattern[p] != '*' && pattern[p] != '\0') ++p;
	else if((pattern[p] == '?') || pattern[p] == text[t]){
		++p;++t;
		return wildCard(text, t, pattern, p);
	}else{
		return false;
	}

	if(pattern[p] == '\0') return true;
	else{
		while(text[t] != pattern[p] && text[t] != '\0') ++t;
		if(text[t] == '\0') return false;
		else  return wildCard(text, t, pattern, p);
	}
}


int main(){
	char text[1000];
	char pattern[1000];
	cin >> text >> pattern;

	int t = 0;
	int p = 0;

	//Returns true if pattern and text matched ahead of indices t and p respectively
	if(wildCard(text, t, pattern, p)) cout << "MATCHED";
	else cout << "NOT MATCHED";

	return 0;
}
		