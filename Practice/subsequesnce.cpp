// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

//Prints all sub sequences from index be
void subsequences(char *c, int be, char *ans, int i){
	if(c[be] == '\0'){
		ans[i] = '\0';
		cout << ans << endl;
		return;
	}

	subsequences(c, be+1, ans, i); //Ek baar nahi lena

	ans[i] = c[be]; //Ek baar lena hai
	subsequences(c, be+1, ans, i+1);

}

int main(){
	char c[100];
	char ans[100];
	cin >> c;

	//Prints all sub sequences from index be
	subsequences(c,0,ans,0);
	return 0;
}
		