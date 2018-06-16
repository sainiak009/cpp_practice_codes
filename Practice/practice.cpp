// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comparator(const string s1, const string s2){
	return s1.size() < s2.size();
}

int main(){
	vector<string> v;
	vector<string>::iterator it;
	string in;

	while(cin >> in && in != "stop"){
		v.push_back(in);
	}

	sort(v.begin(), v.end(), comparator);

	for(it = v.begin(); it != v.end(); ++it) cout << *it << " ";

	return 0;
}
		