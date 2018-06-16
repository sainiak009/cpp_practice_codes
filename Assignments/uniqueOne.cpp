// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <numeric>
using namespace std;

int functionToApply(int x, int y){
	return x ^ y;
}

int main(){
	long long int n;
	cin >> n;
	int arr[n];

	for(long long int i=0; i<n; ++i) cin >> arr[i];

	int unique;
	if(n>0) unique = arr[0];
	else{
		cout << " ";
		return 0;
	}

	for(long long int i=1; i<n; ++i) unique ^= arr[i];

	cout << unique << endl;

	return 0;
}
		