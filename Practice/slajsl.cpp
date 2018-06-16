// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n,q,a;
	cin >> n >> q;
	int b[n][n];

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j) cin >> b[i][j];

	for (int i = 0; i < n; ++i)
	{	
		if(n > 0){
			if(b[1][0])
		}
		cout << -1*b[0][i] << " ";
	}
	cout << endl;

	while(q--){
		int p;
		cin >> p;
		p = p-1;
		for (int i = 0; i < n; ++i)
		 {
		 	cin >> b[p][i];
		 	b[i][p] = b[p][i];
		 }

		 for (int i = 0; i < n; ++i)
		{
			cout << -1*b[0][i] << " ";
		}
		cout << endl; 
	}

	return 0;
}
		