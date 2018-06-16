// Ankit Saini - sainiak009@gmail.com
		
#include <bits/stdc++.h>
using namespace std;

unsigned long long int solution(int *c, int *l, int n){

	unsigned long long int total_cost = 0;

	for(int i=0; i<n; ++i){
		int j = i;
		int petrol = 0;
		while(j < n && c[i] <= c[j]){
			petrol += l[j];
			++j;
		}
		total_cost += petrol*c[i];
		i = j-1;
	}
	return total_cost;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		int c[n], l[n];
		for(int i=0; i<n; ++i) cin >> c[i];
		for(int i=0; i<n; ++i) cin >> l[i];

		unsigned long long int ans = solution(c, l, n);
		cout << ans << endl;
	}
	return 0;
}
		