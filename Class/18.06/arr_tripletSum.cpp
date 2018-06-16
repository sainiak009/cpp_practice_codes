// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int inp[], int be, int en, int m){
	if(be>=en){
		if(inp[be]==m) return be;
		return -1;
	}
	int num = en - be;
	int mid = num/2;
	if(inp[be+mid]== m) return (be+mid);
	if(inp[be+mid] > m) binarySearch(inp, be, be+mid-1, m);
	else binarySearch(inp, be+mid+1, en, m);
}

void tripletSum(int arr[], int target, int en){
	if(en <= 1){
		cout << "" << endl;
		return;
	}

	for(int i=0; i<en-1; ++i){
		for(int j=i+1; j<en; ++j){
			int bal = target - arr[i] - arr[j];
			int x = binarySearch(arr, j+1, en, bal);
			if(x>j){
				cout << arr[i] << ", " << arr[j] << " and " << arr[x] << endl;
			}
		}
	}
}

int main(){
	int n,target;
	cin >> n;
	int arr[n];

	for(int i=0; i<n; ++i) cin >> arr[i];
	cin >> target;
	
	sort(arr, arr+n);
	//Prints triplets whose sum is target
	tripletSum(arr, target, n-1);
	

	return 0;
}
		