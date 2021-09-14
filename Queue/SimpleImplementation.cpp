#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Queue
{
private:
    int cap, size;
    int *arr;

public:
    Queue(int c)
    {
        cap = c;
        arr = new int[cap];
        size = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == cap;
    }
    void enqueue(int el)
    {
        if (isFull())
            return;
        arr[size] = el;
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }
    int getFront(){
        if(isEmpty())return INT_MIN;
        return arr[0];
    }
    int getRear(){
        if(isEmpty())return INT_MIN;
        return arr[size-1];
    }
};
int32_t main()
{
     Queue q=5;
     q.enqueue(3);
     q.enqueue(4);
     q.enqueue(5);
     q.enqueue(6);
    //  q.dequeue();
     cout<<q.getFront()<<endl;
     cout<<q.getRear()<<endl;
}