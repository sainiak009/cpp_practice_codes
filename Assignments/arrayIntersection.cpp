#include <iostream>
using namespace std;

void print(int arr[],int be,int en){
	for(int i=be; i < en; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}


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

int binarySearch(int inp[], int be, int en, int m){
	if(be>=en){
		if(inp[be]==m) return be;
		return -1;
	}
	int num = en - be;
	int mid = num/2;
	if(inp[be+mid]== m) return (be+mid);
	if(inp[be+mid] > m) binarySearch(inp, be, be+mid-1, m);
	else binarySearch(inp, be+mid+1, en, m);
}

int main(){
	int n;
	cin >> n;
	int inp1[n], inp2[n];
	for(int i=0;i<n;++i){
		cin>>inp1[i];
	}
	for(int i=0;i<n;++i){
		cin>>inp2[i];
	}
	

	mergeSort(inp1, 0, n-1);
	mergeSort(inp2, 0, n-1);

	char ans[2*n+10];
	ans[0] = '[';
	int k = 0;
	int cnt = 0;
	int x;
	for(int j=0; j<n; ++j){
		x = binarySearch(inp2, 0, n-1-cnt, inp1[j]);
		if(x>=0){
			ans[++k] = inp1[j] + '0';
			ans[++k] = ',';
			ans[++k] = ' ';
			// print(inp2, 0, n-1-cnt);
			++cnt;
			for(int y=x; y<(n-cnt) ; ++y) inp2[y] = inp2[y+1]; 
			// print(inp2, 0, n-1-cnt);
		}
	}
	ans[k-1] = ']';
	ans[k] = '\0';
	if(cnt > 0) cout << ans ;
	else cout << "[]";

	return 0;

}