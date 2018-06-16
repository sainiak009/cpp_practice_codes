// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include <numeric>
using namespace std;


//Runs simulation for atmost books ans
bool canPossible(int books[], int en, int students, int atmostPages){
	int nStudents = 1;
	int maxPages = 0;

	for (int i = 0; i < en; ++i)
	{
		if(books[i] > atmostPages){
			return false;
		}

		if(books[i] + maxPages <= atmostPages){
			maxPages += books[i];
		}else{
			maxPages = books[i];
			++nStudents;

			if(nStudents > students) return false;
		}
	}

	return true;
}

int MinPages(int books[], int en, int students){
	int low = 0;
	int high = accumulate(books, books+en, 0); // Atmost books read by an student 
	int maxPages = high;

	
	while(low <=high){
		int mid = (low + high)/2;

		if(canPossible(books, en, students, mid)){
			maxPages = min(mid, maxPages);
			high = mid-1;
		}else {
			low = mid+1;
		}
	}

	return maxPages;
}



int main(){
	int pages[] = {1,2,3,4,5,6};
	int n = sizeof(pages) / sizeof(int);
	cout << "Enter number of students: ";
	int students;
	cin	>> students;
	int ans = MinPages(pages, n, students);
	cout << ans;
	return 0;
}
		