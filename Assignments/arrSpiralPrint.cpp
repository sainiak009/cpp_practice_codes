// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int main(){
	int m,n,x;
	cin >> m >> n;
	int arr[m][n];

	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cin >> x;
			arr[i][j] = x;
		}
	}

	int top = 0;
	int bottom = m-1;
	int left = 0;
	int right = n-1;

	while(top <= bottom && left <= right){

		//print current top row
		if(top <= bottom){
			for(int i=left; i<=right; ++i){
				cout << arr[top][i] << " ";
			}
			++top;
		}

		//Print current right column
		if(left <= right){
			for(int i=top; i<= bottom; ++i){
				cout << arr[i][right] << " ";
			}
			--right;
		}

		//Print current bottom row
		if(top <= bottom){
			for(int i=right; i>=left; --i){
				cout << arr[bottom][i] << " ";
			}
			--bottom;
		}

		// Print cuurent left column
		if(left <= right){
			for(int i=bottom; i>=top; --i){
				cout << arr[i][left] << " ";
			}
			++left;
		}

	}


	return 0;
}
		