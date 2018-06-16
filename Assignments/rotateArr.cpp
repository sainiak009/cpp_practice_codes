// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int main(){
	int n, x;
	cin >> n;
	int arr[n][n];

	for(int i = 0; i<n; ++i){
		for(int j = 0; j<n; ++j){
			cin >> x;
			arr[i][j] = x;
		}
	}

	for(int i=n-1; i>=0; --i){
		for(int j=0; j<n; ++j){
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
		