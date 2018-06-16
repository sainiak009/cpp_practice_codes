// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int main(){
	int x,y,c;
	cin >> x >> y;

	int xored = x^y;
	c = 0;
	
	while(xored){
		++c;
		xored >>= 1;
	}

	int ans = 1;
	ans = ans << c;
	cout << (ans-1);

	return 0;
}
		