// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;

	Node(int num){
		data = num;
		next = NULL;
	}
};

void addToFront(Node* &head, Node* nodeToAdd){
	if(head == NULL){
		head = nodeToAdd;
		return;
	}

	nodeToAdd->next = head;
	head = nodeToAdd;
}

void printLL(Node* head){
	Node* temp = head;

	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
	return;
}

void takeInputLL(Node* &head, int arr[], int n){
	
	for(int i=n-1; i>=0; --i){
		Node* newNode = new Node(arr[i]);
		addToFront(head, newNode);
	}
}

void deleteLL(Node* &head, int index){
	if(head == NULL) return;

	if(index == 0){
		Node* temp = head;
		head = temp->next;
		delete temp;
		return;
	}

	Node* prev = head;
	for(int i = 0; i<index-1; ++i){
		if(prev && prev->next){
			prev = prev->next;
		}else return;
	}

	Node* next = prev->next->next;
	delete prev->next;
	prev->next = next;

	return;
}

int main(){
	int n,q;
	cin >> n >> q;
	int arr[n], que[q];
	for(int i=0;i<n;++i) cin >> arr[i];
	for(int i=0;i<q;++i) cin >> que[i];

	Node* head = NULL;
	takeInputLL(head, arr, n);

	for(int i = 0; i<q; ++i){
		deleteLL(head,que[i]);
		printLL(head);
	}
	return 0;
}
		