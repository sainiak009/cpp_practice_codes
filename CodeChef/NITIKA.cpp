// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <ctype.h>
using namespace std;

char* formatedName(char name[]){
	int i = 0;
	int space_cnt = 0;
	char *ans = new char[50];
	ans[0] = toupper(name[0]);

	while(name[i] != '\0'){
		if(name[i] == ' '){
			++space_cnt;
		}
		++i;
	}


	if(!space_cnt){
		int j = 1;
		while(name[j] != '\0'){
			ans[j] = tolower(name[j]);
			++j;
		}
		ans[j] = '\0';
		return ans;
	}

	if(space_cnt == 1){
		int j = 1;
		ans[1] = '.';
		ans[2] = ' ';

		while(name[j] != ' ') ++j;
		++j;

		int k = 3;
		ans[k] = toupper(name[j]);
		++k;++j;

		while(name[j] != '\0'){
			ans[k] = tolower(name[j]);
			++j;++k;
		}
		ans[k] = '\0';
		return ans;
	}

	if(space_cnt == 2){
		int j = 1;
		ans[1] = '.';
		ans[2] = ' ';

		while(name[j] != ' ') ++j;
		++j;

		int k = 3;
		ans[k] = toupper(name[j]);
		ans[++k] = '.';
		ans[++k] = ' ';

		while(name[j] != ' ') ++j;
		++j;

		ans[++k] = toupper(name[j]);
		++k;++j;

		while(name[j] != '\0'){
			ans[k] = tolower(name[j]);
			++j;++k;
		}
		ans[k] = '\0';
		return ans;

	}
}

int main(){
	int t;
	cin >> t;
	cin.ignore();

	while(t--){
		char inp[50];
		cin.getline(inp,50);
		char *ans = formatedName(inp);
		cout << ans << endl;
		delete ans;
	}

	return 0;
}
		