// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int maxSubArr(int arr[], int n){
	if(n==0) return 0;

	int currMax = 0;
	int MaxEnd = 0;

	for(int i=0; i<n; ++i){
		MaxEnd += arr[i];
		if(MaxEnd < 0) MaxEnd = 0;
		if(currMax < MaxEnd) currMax = MaxEnd;
	}

	return currMax;
}

int main(){
	int n;
	cin >> n;
	int arr[n];

	for(int i=0; i<n; ++i){
		cin	>> arr[i];
	}

	int ans = maxSubArr(arr, n);

	cout << ans << endl;
	return 0;
}
		