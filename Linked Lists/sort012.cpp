// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include "LL.h"
using namespace std;

void sort012(Node* &head){
	if(head == NULL || head->next == NULL) return;

	Node* temp = head;

	int c_0 = 0;
	int c_1 = 0;
	int c_2 = 0;

	while(temp){
		switch(temp->data){
			case 0:
				++c_0;
				break;
			case 1:
				++c_1;
				break;
			case 2:
				++c_2;
				break;
		}
		temp = temp->next;
	}

	temp = head;
	for(int i=0; i<c_0; ++i){
		temp->data = 0;
		temp = temp->next;
	}
	for(int i=0; i<c_1; ++i){
		temp->data = 1;
		temp = temp->next;
	}
	for(int i=0; i<c_2; ++i){
		temp->data = 2;
		temp = temp->next;
	}

	return;
}

int main(){
	Node* head = NULL;

	takeInputLL(head);
	printLL(head);
	sort012(head);
	printLL(head);
	return 0;
}
		