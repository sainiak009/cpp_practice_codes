// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int printLInd(int arr[], int en, int m){
	if(en<0) return -1;

	if(arr[en] == m) return en;
	else return printLInd(arr, en-1, m);

}


int main(){
	int n,m;
	cin	>> n;
	int arr[n];

	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}

	cin >> m;

	int ans = printLInd(arr, n-1, m);
	cout << ans;
	return 0;
}
		