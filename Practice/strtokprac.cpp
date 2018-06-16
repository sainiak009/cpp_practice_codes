// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char s[] = "Ankit is a good programmer";

	char *token = strtok(s," ");

	while(token != NULL){
		cout << token << endl;
		// cout << s << endl;
		token = strtok(NULL," ");
	}

	return 0;
}
		