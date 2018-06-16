// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;


class myVector{
	int * arr;
	int size = 0;
public:
	myVector(int size){
		arr = new int[size];
	}

	int size(){
		return sizeof(arr)/sizeof(int);
	}

	void resize(int * arr, new_size){
		int old_size = sizeof(arr)/sizeof(int);
		if(old_size > new_size) return;

		int* newArray = new int[new_size];
		int* temp;
		for(int i = 0; i<old_size; ++i) newArray[i] = arr[i];
		temp = arr;
		arr = newArray;
		delete[] arr;
		return;
	}

	void push_back(int num){
		int old_size = sizeof(arr)/sizeof(int);
		resize(arr, old_size+1);
		arr[old_size] = num;
		return;
	}

	void print(){

	}

}

int main(){
	myVector v;

	return 0;
}
		