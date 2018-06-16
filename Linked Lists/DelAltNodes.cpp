// Ankit Saini - sainiak009@gmail.com
// Delete Alternate nodes

#include <iostream>
#include "LL.h"
using namespace std;

void delAlt(Node* &head){
	if(head == NULL || head->next == NULL) return;

	Node* temp = head;
	Node* temp2 = NULL;
	while(temp && temp->next){
		temp2 = temp->next;
		temp->next = temp->next->next;
		delete temp2;

		temp = temp->next;
	}
}

int main(){
	Node* head = NULL;

	takeInputLL(head);
	printLL(head);
	delAlt(head);
	printLL(head);
	return 0;
}
		