#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == nullptr)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == nullptr)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deletionAtTail(node* &head){
    node* temp = head;
    while (temp->next->next != head){
        temp = temp->next;
    }
    node* toDelete = temp->next;
    delete(toDelete);
    temp->next = head;
    
    
}

void deletionAtHead(node* &head){
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    node* todelete = temp->next;
    head = temp->next->next;
    temp->next = head;
    delete(todelete);
}

void deletionAtPosition(node* &head, int pos){
    node* temp = head;
    if(pos==0){
        deletionAtHead(head);
    }
    int count = 0;
    while(count!=pos-1){
        temp = temp->next;
        count++;
    }

    node * todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;


}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    node *head = nullptr;
    // Insertion at tail 
    cout<<"Insertion at head: "<<endl;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    // Insertion at head
    cout<<"Insertion at head: "<<endl;
    insertAtHead(head, 5);
    display(head);
    // Deletion at tail
    // cout<<"Deletion at tail: "<<endl;
    // deletionAtTail(head);
    // display(head);
    // cout<<"Deletion at head: "<<endl;
    // deletionAtHead(head);
    // display(head);

    // Deletion at given position 
    cout<<"Deletion at given postion: "<<endl;
    deletionAtPosition(head,3);
    display(head);

    return 0;
}