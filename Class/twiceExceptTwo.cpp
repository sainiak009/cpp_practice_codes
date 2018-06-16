// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <numeric>
using namespace std;


int comparator(int x, int y){
	return x ^ y;
}

void print(int arr[], int n){
	for(int i=0; i<n; ++i) cout << arr[i] << " ";
	cout << endl;
}

void twiceExcept2(int arr[], int size){

	int temp = accumulate(arr, arr+size, 0, comparator);
	int arr1[size] = {};
	int arr2[size] = {};

	int lsb = temp & (-temp); //check this
	int j = 0;
	int k = 0;
	for(int i = 0; i<size; ++i){
		if((arr[i]%2) == lsb){
			arr1[j] = arr[i];
			++j;
		}else{
			arr2[k] = arr[i];
			++k;
		}
	}

	print(arr1, j);
	print(arr2, k);
	int ans1 = accumulate(arr1, arr1+j, 0, comparator);
	int ans2 = accumulate(arr2, arr2+k, 0, comparator);

	cout << ans1 << " and " << ans2 ;
}

int main(){
	int nums[] = {1,2,1,2,3,5};
	int size = sizeof(nums) / sizeof(int);

	twiceExcept2(nums, size);
	return 0;
}
		