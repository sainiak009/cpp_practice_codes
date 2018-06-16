#include <iostream>
using namespace std;

int cnt;

void coinChange(int arr[], int be, int en, int n){
	if(be<=en){
		if(n >= arr[be]){
			for(int bal = n; bal >= 0; bal -= arr[be]){
				coinChange(arr, be+1, en, bal);
			}
		}else{
			coinChange(arr, be+1, en, n);
		}
			
	}else{
		if(n==0) ++cnt;
		return;
	}

}

int main(){
	int n,m;
	cin >> n >> m;
	int arr[m];

	for(int i=0; i<m; ++i){
		cin >> arr[i];
	}

	//prints no of options available with coins from index be to en
	coinChange(arr, 0, m-1, n);
	cout << cnt;
}