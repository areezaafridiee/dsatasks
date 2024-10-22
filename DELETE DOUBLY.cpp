#include<iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int data;
    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
};

class CircularDoubly
{
public:
    Node *head;

    CircularDoubly()
    {
        head = NULL;
    }

    // Function to traverse the circular doubly linked list
    void traverse()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *kn = head;
        do {
            cout << kn->data << endl;
            kn = kn->next;
        } while (kn != head); // Stop when we return to the head
    }

    // Function to add a node at the start of the circular doubly linked list
    void addstart(int data)
    {
        Node *temp = new Node();
        temp->data = data;

        if (head == NULL)
        {
            head = temp;
            temp->next = head;
            temp->prev = head;
        }
        else
        {
            Node *last = head->prev;

            temp->next = head;
            temp->prev = last;
            head->prev = temp;
            last->next = temp;
            head = temp;
        }
    }

    // Function to add a node at the end of the circular doubly linked list
    void addend(int data)
    {
        Node *temp = new Node();
        temp->data = data;

        if (head == NULL)
        {
            head = temp;
            temp->next = head;
            temp->prev = head;
        }
        else
        {
            Node *last = head->prev;

            temp->next = head;
            temp->prev = last;
            last->next = temp;
            head->prev = temp;
        }
    }

    // Function to add a node at the middle (position) of the circular doubly linked list
    void addmiddle(int position, int data)
    {
        Node *n2 = new Node();
        n2->data = data;

        if (head == NULL)
        {
            head = n2;
            n2->next = head;
            n2->prev = head;
        }
        else
        {
            Node *n1 = head;
            int count = 1;
            do
            {
                if (count == position - 1)
                {
                    Node *nextNode = n1->next;
                    n1->next = n2;
                    n2->prev = n1;
                    n2->next = nextNode;
                    nextNode->prev = n2;
                    return;
                }
                n1 = n1->next;
                count++;
            } while (n1 != head);

            cout << "Position out of bounds!" << endl;
        }
    }
};

int main()
{
    CircularDoubly cd;
    cd.addstart(5);
    cd.addend(20);
    cd.addmiddle(2, 10); // Insert at position 2
    cd.traverse();
    return 0;
}

