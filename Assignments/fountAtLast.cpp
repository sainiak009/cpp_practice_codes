#include <iostream>
using namespace std;

//Prints the index of m in array
void fountAtLast(int arr[], int be, int en, int m){
	if(be <= en){

		if(arr[en]==m){
			cout << en;
			return;
		}
		else fountAtLast(arr, be, en-1, m);
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
	
	fountAtLast(arr, 0, n-1, m);


	return 0;
}