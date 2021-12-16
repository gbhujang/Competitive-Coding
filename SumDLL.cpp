Find pairs with a given sum in a DLL.


#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node*next;
};

void push(Node** head, int data){

	Node* newnode = new Node();
	newnode->data = data;

	newnode->prev = NULL;

	newnode->next = *head;

	if ((*head) != NULL) (*head)->prev = newnode;

	(*head) = newnode;
}

void pairSum(Node* head, int x){
	Node* front = head;
	Node* back = head;

	bool found = false;
	while(back->next != NULL) back=back->next;

	while(front != back && back->next != front){
		if((front->data + back->data) == x){
			found = true; 
			cout<<front->data<<" "<<back->data<<endl;
			front = front->next;
			back = back->prev;
		}
		else{
		if((front->data + back->data)<x) front = front->next;
		else back = back->prev;
		} 
	}

	if(!found) cout<<"Np pair found"<<endl;
}


void print(Node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
int main(){

Node* head = NULL;

push(&head, 9);
    push(&head, 8);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);
    int x;
    cin>>x;
print(head);

pairSum(head,x);

}