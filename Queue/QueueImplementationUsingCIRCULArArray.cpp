#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Queue
{

    int size, cap, front, *arr;

    Queue(int c)
    {
        cap = c;
        arr = new int[cap];
        size = 0;
        front = 0;
    }
    bool isFull()
    {
        return size == cap;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getFront()
    {
        if (isEmpty())
            return INT_MIN;
        return front;
    }
    int getRear()
    {
        if (isEmpty())
            return INT_MIN;
        return (front + size - 1) % cap;
    }
    void enqueue(int x)
    {
        if (isFull())
            return;
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
            return;
        front = (front + 1) % cap;
        size--;
    }
};

int32_t main()
{
    Queue q=5;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout<<q.getFront()<<endl;
    cout<<q.getRear();
    
}