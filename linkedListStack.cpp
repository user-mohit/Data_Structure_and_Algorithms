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

class stack
{
public:
    node *top;

    stack()
    {
        top = nullptr;
    }

    void isEmpty()
    {
        if (top == nullptr)
        {
            cout << "The stack is Empty." << endl;
        }
        cout << "The stack is not empty." << endl;
    }

    void push(int val)
    {
        node *n = new node(val);
        n->next = top;
        top = n;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "The stack has no element to pop" << endl;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }

    int Top()
    {
        if (top == nullptr)
        {
            cout << "The stack has no value to peek." << endl;
        }

        return top->data;
    }
};

int main()
{
    stack st;
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;

    return 0;
}