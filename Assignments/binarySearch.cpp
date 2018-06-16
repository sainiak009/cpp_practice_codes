#include <iostream>
using namespace std;

void myMerge(int arr[], int be, int en){
	int mid = (be + en) / 2;
	int nLeft = mid - be + 1;
	int nRight = en - mid;
	int *left = new int[nLeft];
	int *right = new int[nRight];

	for(int i = 0; i < nLeft; ++i){
		left[i] = arr[i + be]; 
	}

	for(int i = 0; i < nRight; ++i){
		right[i] = arr[mid + i + 1];
	}

	int k = be;	//main array idx
	int i = 0;	//left array idx
	int j = 0;	//right array idx

	while(i < nLeft && j < nRight){
		if (left[i] < right[j]){
			arr[k] = left[i];
			k++;
			++i;
		}
		else {
			arr[k++] = right[j++];
		}
	}

	while(i < nLeft) arr[k++] = left[i++];
	while(j < nRight) arr[k++] = right[j++];

	delete [] left;
	delete [] right;
}




void mergeSort(int arr[], int be, int en){
	if (be >= en){
		//either 1 or 0 elements
		return;
	}

	int mid = (be + en) / 2;
	mergeSort(arr, be, mid);
	mergeSort(arr, mid + 1, en);

	// myMerge(arr, be, mid, arr, mid + 1, en);
	myMerge(arr, be, en);
}

bool binarySearch(int inp[], int be, int en, int m){
	if(be>=en){
		if(inp[be]==m) return true;
		return false;
	}
	int num = en - be;
	int mid = num/2;
	if(inp[be+mid]== m) return true;
	if(inp[be+mid] > m) binarySearch(inp, be, be+mid-1, m);
	else binarySearch(inp, be+mid+1, en, m);
}

int main(){
	int n,m;
	bool ans;
	cin >> n;
	int inp[n];
	for(int i=0;i<n;++i){
		cin>>inp[i];
	}
	cin >> m;

	mergeSort(inp, 0, n-1);
	ans = binarySearch(inp,	0, n-1, m);
	if(ans) cout << "true";
	else cout << "false";
	return 0;

}