// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		double A,B;
		long k;
		cin >> k >> A >> B;
		double rad = (double)k/(double)2;

		if(abs(A-B) == rad){
			cout << 0 << endl;
		}else{
			if( A <= rad) A += rad;
			else A -= rad; 
			if( B <= rad) B += rad;
			else B -= rad;

			long a,b;
			if(A > B){
				a = ceil(A);
				b = floor(B);
			}
			else{
				b = ceil(B);
				a = floor(A);
			}

			long ans = abs(a-b) - 1 ;
			cout << ans << endl;
		}
	}
	return 0;
}
		