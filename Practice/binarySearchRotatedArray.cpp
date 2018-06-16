// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int searchRotated(int *arr, int be, int en, int key){
	// cout << be << " " << en << endl;	
	if(be>en){
		return -1;
	}

	int mid = (be+en)/2;
	if(arr[mid] == key) return mid;

	// cout << mid << " ";

	if(arr[be] <= arr[mid]){
		if(arr[be] <= key && key < arr[mid]){
			searchRotated(arr, be, mid-1, key);
		}else searchRotated(arr, mid+1, en, key);

	}else if(arr[mid] < key && key <= arr[en]) searchRotated(arr, mid+1, en, key);
	else searchRotated(arr, be, mid-1, key);
}

int main(){
	int arr[] = {7,8,9,1,2,3,4,5,6};

	int x;
	cin >> x;
	int index = searchRotated(arr,0,8, x);
	cout << index;
	return 0;
}
		