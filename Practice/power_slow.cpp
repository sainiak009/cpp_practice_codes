#include <iostream>
using namespace std;


//Returns "n to the power p" solution 
int powerFuntion(int n, int p){
	if(p==0) return 1;
	if(p==1) return n;

	int result;
	result = n*powerFuntion(n,p-1);
	return result;
}

int main(){
	int n,p,result;
	cin >> n >> p;

	result = powerFuntion(n,p);
	cout << result << endl;
}