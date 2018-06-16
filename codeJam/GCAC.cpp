// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t--){
		long n, m, nJobs, nComp;
		char c;
		cin >> n >> m;
		long offeredSalary[m],maxJobOffers[m], minSalary[n], stuComp[n];
		bool qual[n][m] = {false};
		long compStu[m] = {};
		for(long i=0; i<n; ++i) stuComp[i] = -1;

		unsigned long long int totalSal;
		totalSal = 0;
		nJobs = 0;
		nComp = 0;

		//Taking Inputs
		for(long i=0; i<n; ++i){
			cin >> minSalary[i];
		}

		for(long i=0; i<m; ++i){
			cin >> offeredSalary[i] >> maxJobOffers[i];
		}


		for(long i=0; i<n; ++i){
			cin.ignore();
			for(long j=0; j<m; ++j){
				cin >> c;
				if(c == '1') qual[i][j] = true;
			}
		}

		//Solution starts
		for(long i=0; i<n; ++i){

			for(long j=0; j<m; ++j){	

				if(qual[i][j] && (maxJobOffers[j] > 0) && (offeredSalary[j] >= minSalary[i]) ){	

					if(stuComp[i]>-1){
						compStu[stuComp[i]] -= 1;
						maxJobOffers[stuComp[i]] += 1;
					}
					stuComp[i] = j;
					compStu[j] += 1;
					maxJobOffers[j] -= 1;
					minSalary[i] = offeredSalary[j];
				}
			}
		}

		for(long i=0; i<n; ++i){
			if(stuComp[i] > -1){
				nJobs += 1;
				totalSal += offeredSalary[stuComp[i]];
			}
		}

		for(long i=0; i<m; ++i){
			if(compStu[i] == 0) nComp += 1;
		}

		cout << nJobs << ' ' << totalSal << ' ' << nComp << endl;
		
	}

	return 0;
}
		