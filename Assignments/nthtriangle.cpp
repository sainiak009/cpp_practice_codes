#include <iostream>
using namespace std;


int nthtriangle(int n){
	if(n==1) return 1;
	int temp;
	temp = n + nthtriangle(n-1);
	return temp;
}

int main(){
	int n;
	cin >> n;
	int result;

	//Returns nth triangle
	result = nthtriangle(n);
	cout << result << endl;
}