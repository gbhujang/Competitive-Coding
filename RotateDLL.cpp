//Rotate DoublyLinked list by N nodes.

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	Node* prev;
	Node* next;
};

void push(Node** head, int data){

	Node* newnode = new Node();

	newnode->data = data;

	newnode->next = (*head);

	newnode->prev = NULL;

	if((*head) != NULL) (*head)->prev = newnode;

	(*head) = newnode;

}

Node* rotateDLL(Node* head, int n){

	if(head == NULL) return NULL;

	Node* tail = head;
	Node* temp1 = head;

	int count = 0;
	while(tail->next != NULL) {
		tail = tail->next;
		count++;
	}

	if(n == count || n > count){ 
		cout<<"n is could not be equal or greater to the size of the linkedlist"<<endl;
		return NULL;
	}
	while(n) {
		head = head->next;
		--n;
	}

	Node* temp = head->next;

	head->next = NULL;

	temp->prev = NULL;

	head = temp1;

	tail->next = head;

	head->prev = tail;

	return temp;


}

void printList(Node* head){

	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}


int main(){

	Node* head = NULL;

	push(&head,'e');
	push(&head,'d');
	push(&head,'c');
	push(&head,'b');
	push(&head,'a');

	cout<<"Before Rotation"<<endl;
	printList(head);

	int n;

	cin>>n;

	Node* temp = head;
	head = rotateDLL(head,n-1);

	if(head != NULL){
	cout<<"After Rotation"<<endl;
	 printList(head);
	}
	else printList(temp);


}