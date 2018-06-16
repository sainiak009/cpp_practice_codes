// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

void possibleComb(char *c, int i, char *ans, int j){
	if(c[i] == '\0'){
		ans[j] = '\0';
		cout << ans << endl;
		return;
	}

	int d1 = c[i] - '0';
	char c1 = d1 + 'A' - 1;
	ans[j] = c1; possibleComb(c, i+1, ans, j+1);

	if(c[i+1]!= '\0'){
		int d2 = c[i+1] - '0';
		d2 = d1*10 + d2;
		if(d2 <= 26){
			char c2 = d2 + 'A' - 1;
			ans[j] = c2; possibleComb(c, i+2, ans, j+1);
		}
	}

	return;
}

int main(){
	char c[100];
	char ans[100];
	cin >> c;


	// Prints all poosible combination for digits starting from 0 
	possibleComb(c, 0, ans, 0);
	// int temp = '5' - '0';
	// char c1 = temp + 'A' - 1;
	// cout << temp << " " << c1;

	return 0;
}
		