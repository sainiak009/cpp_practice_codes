// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <cstdlib>
using namespace std;


void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

//Returns random number between be and en
int randomPivot(int be, int en){
	int n = en-be+1;
	return rand() % n + be;
}


int doPartitioning(int arr[], int be, int en, int pi){
	swap(arr[be],arr[pi]);

	int j = be;
	for(int i=be+1; i <= en; ++i){
		if(arr[i] < arr[be]){
			swap(arr[j+1], arr[i]);
			++j;
		}
	}

	swap(arr[be], arr[j]);

	return j;
}


//sort subarray between be and en
void quickSort(int arr[], int be, int en){
	if(be>=en) return;

	
	if(en>be){
		//Returns random number between be and en
		int pi = randomPivot(be, en);

		// Sends Pi element to it's rightful place "p"
		int p = doPartitioning(arr, be, en, pi);

		quickSort(arr, be, p-1);
		quickSort(arr, p+1, en);
	}


}


int main(){
	int n;
	cin >> n;
	int arr[n];

	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}

	quickSort(arr, 0, n-1);

	for(int i=0; i<n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
		