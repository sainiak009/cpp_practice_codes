// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		int arr[n];
		int arr2[8] = {};
		for(int i=0; i<n; i++) cin >> arr[i];

		int i=0;
		int j=n-1;
		bool result = true;

		while(j>=i){
			if(arr[i] > 7 or arr[j] > 7){
				result = false;
				break;
			}

			if(arr[i] == arr[j]){
				arr2[arr[i]] += 1;
				++i;--j;
			}else{
				result = false;
				break;
			}
		}

		if(result == true){
			for(int i=1; i<8; ++i){
				if(arr2[i] == 0){
					result = false;
					break;
				}
			}
		}
		
		if(result == true) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}
		