#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
};
void traverseList(Node *head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node *current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}
Node* deleteAtStart(Node *head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return NULL;
    }
    
    Node *temp = head;
    if (head->next == head) { 
        delete temp;
        return NULL;
    }
    
  
    Node *last = head;
    while (last->next != head) {
        last = last->next;
    }

    
    last->next = head->next;
    head = head->next;
    delete temp;
    
    return head;
}


Node* deleteAtEnd(Node *head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return NULL;
    }

    Node *temp = head;
    if (head->next == head) {  
        delete temp;
        return NULL;
    }


    Node *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head; 
    delete temp;
    
    return head;
}


Node* deleteAtMid(Node *head, int value) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return NULL;
    }

    if (head->data == value) {  
        return deleteAtStart(head);
    }

    Node *temp = head, *prev = NULL;
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != value);

    if (temp == head) {
        cout << "Value not found in the list." << endl;
        return head;
    }

    prev->next = temp->next;
    delete temp;
    
    return head;
}

int main() {
    Node *n1 = new Node;
    Node *n2 = new Node;
    Node *n3 = new Node;
    Node *n4 = new Node;
    Node *n5 = new Node;

    n1->data = 5;
    n2->data = 10;
    n3->data = 15;
    n4->data = 20;
    n5->data = 25;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
	n5->next = n1;  

    Node *head = n1; 

    cout << "Initial List: ";
    traverseList(head);


    cout << "Deleting at start: " << endl;
    head = deleteAtStart(head);
    traverseList(head);

   
    cout << "Deleting at end: " << endl;
    head = deleteAtEnd(head);
    traverseList(head);

    
    cout << "Enter value to delete from the middle: ";
    int value;
    cin >> value;
    head = deleteAtMid(head, value);
    traverseList(head);

    return 0;
}

