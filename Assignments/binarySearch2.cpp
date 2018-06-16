#include <iostream>
using namespace std;

void binarySearch(int inp[], int be, int en, int m){
	if(be>=en){
		if(inp[be]==m){
			cout << be << endl;
			return;
		}
		cout << -1 << endl;
		return;
	}
	int num = en - be;
	int mid = num/2;
	if(inp[be+mid]== m){
		cout << be+mid<< endl;
		return;
	}
	if(inp[be+mid] > m) binarySearch(inp, be, be+mid-1, m);
	else binarySearch(inp, be+mid+1, en, m);
}

int main(){
	int n,m;
	cin >> n;
	int inp[n];
	for(int i=0;i<n;++i){
		cin>>inp[i];
	}
	cin >> m;
	
	binarySearch(inp,	0, n-1, m);
	return 0;

}