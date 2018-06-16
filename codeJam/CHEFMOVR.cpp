// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <cmath>
using namespace std;

bool simulate(int *arr, int ans, int d, int n, int median){
	int cnt = 0;
	for(int i=0; i<n/2; ++i){
		while(arr[i] != median){
			if(i+d > n) return false;
			int temp = arr[i] - d;
			cnt += abs(temp);
			arr[i+d] += temp;
		}
	}
}


int main(){
	int t;
	cin >> t;

	while(t--){
		int n,d;
		cin >> n >> d;
		int arr[n];
		int sum = 0;
		for(int i=0; i<n; ++i){
			cin >> arr[i];
			sum += arr[i];
		}

		if(sum%n != 0){
			cout << "-1" << endl;
			return 0;
		}

		int median = sum/n;
		int ans = 0;

		for(int i=0; i<n; ++i){
			int temp = arr[i] - median;
			ans += abs(temp);
		}

		ans = ans >> 1;

		while( !simulate(arr, ans, d, n, median) ){
			++ans;
		}

		cout << ans << endl;
	}

	return 0;
}
		