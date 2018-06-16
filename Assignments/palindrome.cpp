// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;


bool isPalindrome(string str, int l, int h){
	if(l>h) return true;

	if(str[l] != str[h]) return false;
	isPalindrome(str, ++l, --h);
}

int main(){
	string str;
	cin >> str;
	high = str.size()-1;

	if(isPalindrome(str, 0, high)) cout << "true";
	else return "false";
	return 0;
}
		