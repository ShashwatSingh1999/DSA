#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int data;
    Node *next;
    Node(int v)
    {
        data = v;
        next = NULL;
    }
};
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void printMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << slow->data << "\n";
}
// reverse a ll
Node *reverse(Node *frnt)
{
    if (frnt == NULL || frnt->next == NULL)
        return frnt;
    Node *head = reverse(frnt->next);
    frnt->next->next = frnt;
    frnt->next = NULL;
    return head;
}
Node* reverseIterative(Node *head)
{
    Node*prev=NULL,*curr=head;
    while(curr!=NULL){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int32_t main()
{
    Node *head = new Node(4);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(6);
    printLL(head);
    cout << endl;
    head = reverseIterative(head);
    printLL(head);
    cout << endl;
    // printMiddle(head);
}