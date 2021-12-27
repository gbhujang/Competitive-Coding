//Sort a LL of 0's, 1's and 2's

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

void printList(Node* head){
	
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}

void push(Node** head, int data){

	Node* newnode = new Node();

	newnode->data = data;

	newnode->next = (*head);

	(*head) = newnode;
}


void  sort012(Node* head){
	
	int n = 0, n1 = 0, n2 = 0 ;

	Node* temp = head;
	int count[3] = {0,0,0};

	while(head != NULL){
		count[head->data] += 1;
		head = head->next;
	}

	int i = 0;

	while(temp != NULL){
		if(count[i] == 0){
			++i;
		}
		else{
			temp->data = i;
			--count[i];
			temp = temp->next;
		}
	}
}

int main(){

	Node* head = NULL;

	push(&head,2);
	push(&head,2);
	push(&head,0);
	push(&head,1);
	push(&head,0);
	push(&head,0);
	push(&head,1);
	push(&head,1);
	push(&head,1);
	push(&head,0);

	printList(head);

    sort012(head);

    printList(head);


}