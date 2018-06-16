#include <iostream>
using namespace std;

//Checks is the array is sorted between indexes
bool isSorted(int arr[], int be, int en){
	if(be==en) return true;

	if(arr[be] <= arr[be+1]) isSorted(arr, be+1, en);
	else return false;
}


int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; ++i){
		cin	>> arr[i];
	}

	if(isSorted(arr, 0, n-1)) cout << "true";
	else cout << "false";


	return 0;
}