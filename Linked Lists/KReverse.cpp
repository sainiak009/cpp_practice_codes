// Ankit Saini - sainiak009@gmail.com
		
#include <iostream>
#include "LL.h"
using namespace std;


void reverseLL(Node* &head, int k){
	if(head	== NULL || head->next == NULL) return;

	Node* curr = head;
	Node* prev = NULL;
	Node* ahead = NULL;
	while(curr){
		ahead = curr->next;
		curr->next = prev; //Link reversed
		prev = curr;
		curr = ahead;
	}

	head = prev;

}

int main(){
	Node* head = NULL; //Initiating linked list

	takeInputLL(head); //Populating linked list
	printLL(head);
	reverseLL(head, 3);
	printLL(head);

	return 0;
}
		