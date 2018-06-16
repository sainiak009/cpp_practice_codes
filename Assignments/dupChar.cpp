// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <cstring>
using namespace std;


void dupChar(char str[], int be, int en){
	if(str[be+1] == '\0') return;

	if(str[be] == str[be+1]){
		for(int i=en; i>=be+1; --i){
			str[i+1] = str[i];
		}
		str[be+1] = '*';
		++en;
		str[en+1] = '\0';
	}else{
		dupChar(str, ++be, en);
	}

}

int main(){
	char str[10000];
	cin.getline(str,10000);
	int high = strlen(str)-1;

	dupChar(str, 0, high);
	cout << str;
	return 0;
}
