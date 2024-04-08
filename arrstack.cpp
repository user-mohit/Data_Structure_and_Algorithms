#include <iostream>
using namespace std;

#define n 100
class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack is full." << endl;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "There is no element to pop." << endl;
        }
        top--;
    }

    void Top()
    {
        if (top == -1)
        {
            cout << "The stack is empty." << endl;
        }

        cout << arr[top] << endl;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == n - 1;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.Top();
    st.pop();
    st.Top();
    st.pop();
    st.pop();
    st.Top();
    st.pop();
    st.pop();
    cout << st.isEmpty() << endl;
    cout << st.isFull() << endl;

    return 0;
}