//Add 1 to a number represented as linked list

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};


Node *newNode(int data) 
{ 
    Node *new_node = new Node; 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
} 



Node* reverse(Node* head){
	
	Node* prev = NULL;
	Node* current = head;
	Node* next;

	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;

}


Node* addOneUtil(Node* head){

	Node* res = head;

	Node* temp, *prev = NULL;

	int carry = 1, sum;

	while(head != NULL){
		sum = carry + head->data;

		carry = (sum >= 10) ? 1 : 0;

		sum = sum % 10;

		head->data = sum;

		temp = head;

		head = head->next;
	}

	if(carry > 0) temp->next = newNode(carry);

	return res;
}

Node* add_one(Node* head){

	head = reverse(head);

	head = addOneUtil(head);

	return reverse(head);
}

void display(Node* head){

	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}

	cout<<"\n";	
}

int main(){



Node *head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(9); 

// display(head);

head = add_one(head);
display(head);

}