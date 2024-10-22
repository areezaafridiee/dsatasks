#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
int main()
{
	Node *n1 = new Node;
    Node *n2 = new Node;
    Node *n3 = new Node;
    Node *n4 = new Node;
    
    n1->data = 5;
    n2->data = 10;
    n3->data = 15;
    n4->data = 20;
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    
    Node *head = n1;  // Maintain the original head pointer

    // Traversing the list
    cout << "Traversing: " << endl;
    Node *current = head;  // Use current to traverse, keeping head intact
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }
 	int value;
	cout<<"Enter the value that you want to delete : "<<endl;
	cin>>value;
	Node *pree;
	pree=NULL;
	Node *c;
	c=head;
	while(c->data!=value)
	{
		pree=c;
		c=c->next;
	}
	pree->next=c->next;
	delete(c);
	cout<<"After transversing: "<<endl;
	Node *d=head;
	while(d!=NULL)
	{
		cout<<d->data<<endl;
		d=d->next;
	}
}
