// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

void merge(int a[], int b[], int n, int result[]){
	if(n == 0) return;

	int i=0;
	int j=0;
	int k=0;

	while(i<n && j<n){
		if(a[i] < b[j]){
			result[k] = a[i];
			++k;
			++i;
		}else{
			result[k] = b[j];
			++k;
			++j;
		}
	}

	while(i < n){
		result[k] = a[i];
		++k;
		++i;
	}

	while(j < n){
		result[k] = b[j];
		++k;
		++j;
	}
}


int main(){
	int n;
	cin >> n;
	int a[n],b[n];
	int c[n+n];
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	for(int i=0; i<n; ++i){
		cin >> b[i];
	}

	merge(a, b, n, c);

	cout << c[n -1];

	return 0;
}
		