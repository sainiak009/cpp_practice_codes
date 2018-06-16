// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

void binary(int num)
{
    int rem;
 
    if (num <= 1)
    {
        cout << num;
        return;
    }
    rem = num % 2;
    binary(num / 2);
    cout << rem;
}

int main(){
	
	return 0;
}
		