#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) { // constructor
        data = val;
        next = NULL;
    }
};

// insert at end or tail
void insertAtTail(node*& head, int val) {
    node* n = new node(val); // new node to be inserted

    if (head == NULL) {
        head = n;
        return;
    }

    node* temp = head; // for traversing we are using temp
    while (temp->next != NULL) { // finding the last node
        temp = temp->next;
    }
    temp->next = n; // inserting new node at the end
}

// insert at the beginning
void insertAtHead(node*& head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}

// insert at middle (at a specific position)
void insertAtMiddle(node*& head, int val, int pos) {
    // if position is 0 or inserting at head
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    int count = 0;

    // Traverse to the position before where we want to insert
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // If temp is NULL, position is out of bounds
    if (temp == NULL) {
        cout << "Position is out of bounds." << endl;
        return;
    }

    // Insert the new node
    n->next = temp->next;
    temp->next = n;
}

// display the list
void display(node* head) {
    node* temp = head; // temp pointer for traversing

    while (temp != NULL) {
        cout << temp->data << "->"; // print data of each node
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtHead(head, 50);
    insertAtHead(head, 60);
    insertAtTail(head, 400);

    display(head);

    insertAtMiddle(head, 25, 3); // Insert 25 at position 3 (0-based index)
    display(head);

    return 0;
}

