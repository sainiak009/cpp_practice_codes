// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <numeric>
using namespace std;

void unique2(int arr[], int n){
	if(n==0) return;

	//Calculating first set bit 
	int xored = arr[0];
	for(int i=1; i<n; ++i){
		xored ^= arr[i];
	}
	int first_set_bit = xored & ~(xored-1); // Bitwise AND with 2s complement

	int x,y; //Seprated numbers
	x = 0; y = 0;

	for(int i=0; i<n; ++i){
		if(arr[i] & first_set_bit){
			x ^= arr[i];
		}else{
			y ^= arr[i];
		}
	}

	if(x < y) cout << x << " " << y << endl;
	else cout << y << " " << x << endl;

	return;
}


int main(){
	int n;
	cin >> n;
	int arr[n];

	for(int i=0; i<n; ++i) cin >> arr[i];

	unique2(arr,n);
	return 0;
}
		