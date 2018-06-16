#include <iostream>
using namespace std;

//print all odd number less than n(Decreasing)
void printOdd(int n){
	if(n==1){
		cout << n << endl;
		return;
	}


	if(n%2 != 0) cout << n << endl;
	printOdd(n-1);
}

void printEven(int n,int be){
	if(be > n) return;

	cout << be << endl;
	printEven(n,be+2);

}

int main(){
	int n;
	cin >> n;

	//print all odd number less than n(Decreasing)
	printOdd(n);

	//print all even number less than n(Increasing)
	printEven(n,2);
}