#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
struct Queue
{
    Node *front;
    Node *rear;
    int size;
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }
    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if (front == NULL)
        {
             front = rear = temp;
        }
        rear->next=temp;
        rear=temp;
        size++;
    }
    void dequeue(){
        if(front==NULL)return;
        Node* temp=front;
        front=front->next;
        // while deleting last element change rear also
        if(front==NULL){
            rear=NULL;
        }
        delete temp;
        size--;
    }
    int getFront(){
        if(front==NULL)return INT_MIN;
        return front->data;
    }
    int getRear(){
        if(rear==NULL)return INT_MIN;
        return rear->data;
    }
    int getSize(){
        return size;
    }
};
int32_t main()
{
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
   cout<< q.getSize();
   q.dequeue();
   cout<<endl;
   cout<<q.getFront();
   cout<<q.getRear();
}