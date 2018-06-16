// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <algorithm>
using namespace std;


void counting_sort(int arr[], int out[], int max, int n){
	int counts[max+1] = {};

	//Filling counts array
	for(int i=0; i<n; ++i){
		++counts[arr[i]];
	}

	for(int i=1; i<=max; ++i){
		counts[i] += counts[i-1];
	}

	for (int i = 0; i<n; ++i)
    {
        out[counts[arr[i]]-1] = arr[i];
        --counts[arr[i]];
    }

    return;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	int out[n];

	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}

	int max = *max_element(arr, arr + n);
	// cout << max;
	counting_sort(arr, out, max, n);

	for(int i= 0; i<n; ++i){
		cout << out[i] << " ";
	}
	return 0;
}
		