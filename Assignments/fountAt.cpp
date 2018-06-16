#include <iostream>
using namespace std;

//Prints the index of m in array
void fountAt(int arr[], int be, int en, int m){
	if(be <= en){

		if(arr[be]==m){
			cout << be;
			return;
		}
		else fountAt(arr, be+1, en, m);
	}else cout << -1;

	return;
}


int main() {
	int n,m;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; ++i){
		cin	>> arr[i];
	}
	cin >> m;
	
	fountAt(arr, 0, n-1, m);


	return 0;
}