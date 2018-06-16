#include <iostream>
#include <string>
using namespace std;

//checks if strings are reverse from index be
bool is_reverse(string s1, int i, string s2, int j){
	if(i == s1.size() && j == -1 ) return true;

	if(s1[i] == s2[j]) is_reverse(s1, ++i, s2, --j);
	else return false;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	if(s1.size() != s2.size()){
		cout << "false";
		return 0;
	}
 	//checks if strings are reverse from index be 
	if(is_reverse(s1, 0, s2, s2.size()-1)) cout << "true";
	else cout << "false";

	return 0;
}