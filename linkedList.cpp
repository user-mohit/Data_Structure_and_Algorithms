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
        next = NULL;
    }
};

// INSERTION IN THE LINKED LIST ----

//  CASE 1: INSERTION AT THE END OF THE LINKED LIST ----
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// CASE 2: INSERTION AT THE STARTING OF THE LINKED LIST ----
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

// DISPLAYING THE LINKED LIST ----
void dispaly(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// DELETION IN LINKED LIST ----

// DELETION AT HEAD OF THE LINKED LIST ----

void deletionAtHead(node *&head)
{
    node *toDelete = head;
    head = head->next;

    delete toDelete;
}

// DELETION OF THE Nth NODE ----

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deletionAtHead(head);
    }
    node *temp = head;
    while (temp->next->data != val && temp->next != NULL)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// DELETION AT THE END OF THE LINKED LIST ----

void deletionAtEnd(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deletionAtHead(head);
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;
}

// REVERSE A LINKED LIST USING ITERATIVE METHOD ----

node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
// REVERSE A LINKED LIST USING RECURSIVE METHOD ----
node *reverseRecursive(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    // insertAtHead(head, 4);
    insertAtTail(head, 4);
    // dispaly(head);
    // deletion(head,3);
    // deletionAtHead(head);
    // deletionAtEnd(head);
    
    cout<<"\nLINKED LIST BEFORE REVERSING ----"<<endl;
    dispaly(head);
    node *newHead = reverseRecursive(head);
    cout<<"\nLINKED LIST AFTER REVERSING ----"<<endl;
    dispaly(newHead);

    return 0;
}