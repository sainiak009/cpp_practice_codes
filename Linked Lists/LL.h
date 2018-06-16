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
		cout << "--->" << temp->data;
		temp = temp->next;
	}

	cout << endl;
	return;
}

void takeInputLL(Node* &head){
	cout << "Enter numbers for LL(-1 to terminate input) :";
	int n;

	while(cin>>n && n!=-1){
		Node* newNode = new Node(n);
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

void insertLL(Node* &head, int index, int num){
	if(head == NULL && index == 0){
		Node* newNode = new Node(num);
		head = newNode;
		return;
	}	

	//For index zero, Just add to front
	if(index == 0){
		Node* newNode = new Node(num);
		newNode->next = head;
		head = newNode;
		return;
	}

	//For other indices, Get previous pointer
	Node* prev = head;
	for(int i = 0; i<index-1; ++i){
		if(prev && prev->next){
			prev = prev->next;
		}else return;
	}

	//Manipulate Links
	Node* newNode = new Node(num);
	Node* temp = prev->next;
	prev->next = newNode;
	newNode->next = temp;
	return;
}

//Returns pointer to middle element
Node* findMiddle(Node* head){
	Node* s_ptr = head;
	Node* f_ptr = head;

	while(s_ptr && f_ptr && f_ptr->next){
		s_ptr = s_ptr->next;
		f_ptr = f_ptr->next->next;
	}

	return s_ptr;
}	

// Returns length of Link List
int lenghtLL(Node* head){
	if(head == NULL) return 0;

	int i=0;
	Node* temp = head;
	while(temp){
		temp = temp->next;
		++i;
	}
	return i;
}	

//Recursion to find an element
Node* findLL(Node* node, int num){
	if(node == NULL) return NULL;

	if(node->data == num){
		return node;
	}

	findLL(node->next, num);
}

//Bubble Sort for Linked Lists
void bubbleSortLL(Node* &head){
	if(head == NULL || head->next == NULL) return;

	int swapped = 1;

	while(swapped){
		swapped = 0;
		Node* temp = head;
		while(temp && temp->next){
			if(temp->data > temp->next->data){
				int t = temp->data;
				temp->data = temp->next->data;
				temp->next->data = t;
				swapped = 1;
			}
			temp = temp->next;
		}

	}

	return;
}