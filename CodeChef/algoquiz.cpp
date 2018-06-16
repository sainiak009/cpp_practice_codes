// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

void f(int m,int n) {
     int ans = 0;
     while (m - n >= 0) {
       m = m - n;
       ++ans;
       cout << ans << endl;
     }
     cout << ans << endl;
     return;
   }

int main(){
	f(120,13);	
	return 0;
}
		