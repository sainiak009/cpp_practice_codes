// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

void printIndices(int arr[], int be, int en, int m){
	if( be > en ) return;

	if(arr[be] == m) cout << be << " ";
	printIndices(arr, be+1, en, m);
}

int main(){
	int n,m;
	cin >> n;
	int arr[n];

	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}

	cin >> m;

	printIndices(arr, 0, n-1, m);

	return 0;
}
		