// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int main(){
	int t;
	long long int n,a,ans;
	cin	>> t;
	while(t--){
		cin >> n;
		ans = 0;
		while(n--){
			cin	>> a;
			ans |= a;
		}
		cout << ans << endl;
	}
	return 0;
}
		