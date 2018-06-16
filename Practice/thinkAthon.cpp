// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int MOD = 1000000007;

int fx(int c, int d){
	if(x<y) return (x*y)%MOD;
	else{
		return ncr(c,d)
	}
}


int printSol(int a, int b, int c, int d){

	long ans = 0;
	for(int i=a; i<=b; i++){
		ans += fx(i,d);
	}
}


int main(){
	int q;
	cin >> q;

	while(q--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;

		cout << printSol(a,b,c,d) << endl;
	}
	return 0;
}
		