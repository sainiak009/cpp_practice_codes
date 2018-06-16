// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;

int main(){
	int t,i;
	char temp;
	lli a[100];

	cin >> t;
	// cin.ignore();
	while(t--){
		i = 0;
		do{
        	scanf("%llu%c", &a[i], &temp); 
        	i++;
        }while(temp != '\n');

        sort(a, a+i);
		if(a[i-1] == i-1){
			cout << a[i-2] << endl;
		}
		else{
			cout << a[i-1] << endl;
		}
	}

	return 0;
}
		