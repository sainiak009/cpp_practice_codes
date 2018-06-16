// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

void toh(int n, char source, char dest, char help){
	if(n==1){
		cout << "Move " << n << " from " << source << " to " << dest << endl;
		return;
	}

	toh(n-1, source, help, dest);
	cout << "Move " << n << " from " << source << " to " << dest << endl;
	toh(n-1, help, dest, source);
}

int main(){
	int n;
	cin >> n;

	toh(n, 'A', 'B', 'C');
	return 0;
}
		