#include <iostream>
using namespace std;

void myMerge(int t[], int s[], int be, int en, int id[]){
	int mid = (be + en) / 2;
	int nLeft = mid - be + 1;
	int nRight = en - mid;
	int *left_t = new int[nLeft];
	int *right_t = new int[nRight];
	int *left_s = new int[nLeft];
	int *right_s = new int[nRight];

	int *left_id = new int[nLeft];
	int *right_id = new int[nRight];

	for(int i = 0; i < nLeft; ++i){
		left_t[i] = t[i + be];
		left_s[i] = s[i + be]; 
		left_id[i] = id[i + be];
	}

	for(int i = 0; i < nRight; ++i){
		right_t[i] = t[mid + i + 1];
		right_s[i] = s[mid + i + 1];
		right_id[i] = id[mid + i + 1];
	}

	int k = be;	//main array idx
	int i = 0;	//left array idx
	int j = 0;	//right array idx

	while(i < nLeft && j < nRight){
		if ((left_s[i]*right_t[j]) >= (right_s[j]*left_t[i])){
			t[k] = left_t[i];
			s[k] = left_s[i];
			id[k] = left_id[i];
			k++;
			++i;
		}
		else {
			t[k] = right_t[j];
			s[k] = right_s[j];
			id[k] = right_id[j];
			++j;++k;
		}
	}

	while(i < nLeft) {
		t[k] = left_t[i];
		s[k] = left_s[i];
		id[k] = left_id[i];
		++i;++k;
	}
	while(j < nRight){
		t[k] = right_t[j];
		s[k] = right_s[j];
		id[k] = right_id[j];
		++k;++j;
	}

	delete [] left_t;
	delete [] left_s;
	delete [] left_id;
	delete [] right_t;
	delete [] right_s;
	delete [] right_id;
}




void mergeSort(int t[], int s[], int be, int en, int id[]){
	if (be >= en){
		//either 1 or 0 elements
		return;
	}

	int mid = (be + en) / 2;
	mergeSort(t, s, be, mid, id);
	mergeSort(t, s, mid + 1, en, id);

	myMerge(t, s, be, en, id);
}


int main(){
	int n; 
	cin >> n;
	int t[n], s[n], id[n];
	for(int i = 0; i < n; ++i){
		cin >> t[i] >> s[i];
		id[i] = i+1;
	}
	// for(int i = 0; i < n; ++i) cout << t[i] << " " << s[i] << endl;

	mergeSort(t, s, 0, n - 1, id);
	
	for(int i = 0; i < n; ++i) cout << id[i] << endl;

}