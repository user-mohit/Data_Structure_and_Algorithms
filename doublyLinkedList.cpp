#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void insertionAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != nullptr)
    {
        head->prev = n;
    }
    head = n;
}
void insertionAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == nullptr)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void deletionAtTail(node* &head)
{
    node* temp = head;
    while(temp->next->next!=nullptr)
    {
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = nullptr;
    delete todelete;
}

void deletionAtHead(node* &head)
{
    node* temp = head;
    head->next->prev = nullptr;
    head = head->next;
}

void deletionAtPostion(node* &head, int pos)
{
    node* temp = head;
    int count = 0;
    while(count!=pos-1 && temp!=nullptr){
        temp = temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev = temp;

    delete todelete;
    
}

void display(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    node *head = nullptr;
    cout<<"Insertion at Tail:"<<endl;
    insertionAtTail(head, 1);
    insertionAtTail(head, 2);
    insertionAtTail(head, 3);
    insertionAtTail(head, 4);
    insertionAtTail(head, 5);
    insertionAtTail(head, 6);
    insertionAtTail(head, 7);
    display(head);

    cout<<"Insertion at Head: "<<endl;
    insertionAtHead(head, 8);
    display(head);

    cout<<"Deletion at Tail: "<<endl;
    deletionAtTail(head);
    display(head);

    cout<<"Deletion at Head: "<<endl;
    // deletionAtHead(head);
    // display(head);

    cout<<"Deletion at given Position: "<<endl;
    deletionAtPostion(head,4);
    display(head);

    return 0;
}