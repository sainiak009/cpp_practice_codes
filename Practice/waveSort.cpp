// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

void waveSort(int arr[], int en){
	if(en == 0) return;

	for(int i=0; i<=en; i+=2){

		//checking left element
		if(i>0 && arr[i-1] < arr[i]) swap(arr[i],arr[i-1]);
		//Checking right element
		if(i<en && arr[i+1] < arr[i]) swap(arr[i],arr[i+1]);
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];

	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}

	waveSort(arr,n-1);

	for(int i=0; i<n; ++i){
		cout << arr[i] << " ";
	}
	return 0;
}
		