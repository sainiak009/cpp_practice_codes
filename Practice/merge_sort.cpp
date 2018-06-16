#include <iostream>
using namespace std;

void print_array(int arr[], int n){
	for(int i=0;i<n;++i){
		cout << arr[i] << " ";
	}
}


//Merge two sorted parts of an array
int* myMerge(int arr[], int be, int en){
	int mid = (be+en)/2;
	int nLeft = mid-be+1;
	int nRight = en-mid;

	int* left = new int[nLeft];
	int* right = new int[nRight];

	for(int i=0; i<nLeft; ++i) left[i] = arr[be+i];
	for(int j=0; j<nRight; ++j) right[j] = arr[mid+1+j];

	int k=be;
	int i = 0;
	int j = 0;

	while(i<nLeft && j<nRight){
		if(left[i]<right[j]){
			arr[k]=left[i];
			++k;++i;
		}else{
			arr[k]=right[j];
			++k;++j;
		}
	}

	while(i<nLeft){
		arr[k]=left[i];
		++k;++i;
	}
	while(j<nRight){
		arr[k]=right[j];
		++k;++j;	
	}

	delete [] left;
	delete [] right; 

}

void mergeSort(int arr[], int be, int en){
	int mid = (be + en)/2;

	if(be >= en){
		return ;
	}

	mergeSort(arr, be, mid);
	mergeSort(arr, mid+1, en);

	myMerge(arr,be,en);
}

int main(){
	int arr[100];
	int n; cin >> n;
	for(int i = 0; i<n ; i++) cin >> arr[i];
	mergeSort(arr,0,n-1);
	print_array(arr,n);
}