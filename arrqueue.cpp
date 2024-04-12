#include <iostream>
using namespace std;
#define n 20

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int val)
    {
        if (back == n - 1)
        {
            cout << "Queue overflow." << endl;
            return;
        }
        back++;
        arr[back] = val;

        if (front == -1)
        {
            front++;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "No element to dequeue." << endl;
            return;
        }
        front++;
    }

    void peek()
    {

        if (front == -1 || front > back)
        {
            cout << "No element to peek." << endl;
            return;
        }

        cout << "The first element of queue: " << arr[front] << endl;
    }

    bool isEmpty()
    {

        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();

    cout << q.isEmpty() << endl;

    return 0;
}