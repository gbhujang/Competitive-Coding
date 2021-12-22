// Count triplets in a sorted DLL whose sum is equal to given value “X”.

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node* next;
};

void push(Node** head, int data){
	
	Node* newnode = new Node();

	newnode->data = data;

	newnode->next = *head;

	newnode->prev = NULL;

	if((*head) != NULL) (*head)->prev = newnode;

	*head = newnode;
}
int countPairs(Node* first, Node* second, int value){
	int count = 0;

	while(first != NULL && second != NULL && first != second && second->next != first){
		if(first->data + second->data == value){
		 count++;
		
		first = first->next;
		second = second->prev;
	}

	else if(first->data + second->data > value) second = second->prev;
	else first= first->next;
}
	return count;
}

int countTriplets(Node* head,int x){
	if(head == NULL) return 0;

	Node* current;
	Node* first = head;
	Node* last = head;
	int count = 0;

	while(last->next != NULL) last = last->next;

	for(current = head; current != NULL; current = current->next){
		first = current->next;

		count += countPairs(first,last,x-current->data);
	}

	return count;
}



// void print(Node* head){
// 	while(head != NULL){
// 		cout<<head->data<<" ";
// 		head = head->next;
// 	}
// }

int main(){

	Node* head = NULL;

	push(&head,9);
	push(&head,8);
	push(&head,7);
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);

	int x;

	cin>>x;

	cout<<countTriplets(head,x)<<endl;

}
