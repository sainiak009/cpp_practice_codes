// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

template <typename T>
class Stack{
	T* data;
	int index;
	int capacity;
public:
	Stack(){
		data = new T[10];
		index = -1;
		capacity = 10;
	}
	void push(T num){
		if((capacity-1) == index){
			capacity += 10;
			T* temp = new T[capacity];
			for(int i=0; i<= index; ++i) temp[i] = data[i];
			delete[] data;
			data = temp;
		}
		index += 1;
		data[index] = num; 
	}
	int pop(){
		if(index == -1){
		cout << "Stack Underflow" <<endl;
		return -1;
	}
		index -= 1;
		return data[index+1];
	}
	bool is_empty(){
		if(index == -1) return true;
		else return false;
	}
	int top(){
		return data[index];
	}
	void print(){
		for(int i=index; i>=0; --i) cout << data[i] << " ";
	}
	void takeInput(){
		int x;
		while(cin >> x && x != -1){
			push(x);
		}
	}
	friend ostream& operator<<(ostream& obj, Stack s){
		//ostream& for cout << A << B where A, B are students
		s.print();
		cout << endl;
		return obj;
	}

	friend istream& operator>>(istream& obj, Stack &s){
		//ostream& for cout << A << B where A, B are students
		s.takeInput();
		cout << endl;
		return obj;
	}

};



int main(){
	Stack<int> s;
	cout << "Give input, -1 to terminate: ";
	cin >> s;
	cout << s;
	return 0;
}
		