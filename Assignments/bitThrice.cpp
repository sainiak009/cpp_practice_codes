// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;
int INT_SIZE = 32;

int uniqueInThrice(int arr[], int n){
	int ans = 0;
	for(int i=0; i< INT_SIZE; ++i){

		int sum = 0;
		int x = ( 1 << i); //It will return a set bit at position i

		for(int j=0; j<n; ++j){
			if(x & arr[j]) //It will check if bit is set at ith position
				++sum;
		}

		if(sum%3) //It will check if it contains bit from unique element at ith position
			ans |= x; //Add that bit to ith position of answer

	}

	return ans;
}

int main(){
	int n;
	cin >> n;
	int arr[n];

	for(int i=0; i<n; ++i) cin >> arr[i];

	cout << uniqueInThrice(arr,n);
	return 0;
}
		