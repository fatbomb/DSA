#include "linked_list.hpp"

const int X = 1e5;
template <typename T>
class Queue
{
    linked_list<T> l1=linked_list<T>();
    int cnt = 0;

public:
    bool empty()
    {
        if (l1.head == NULL)
        {
            return true;
        }
        return false;
    }
    T front()
    {
        if (empty())
        {
            cout << "Empty Queue\n";
            return -1;
        }
        return l1.head->data;
    }
    void push(T n)
    {
        l1.insAttail(n);
        cnt++;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Nothing to pop\n";
            return;
        }
        l1.delAthead();
        cnt--;
    }
    ll size()
    {
        return cnt;
    }
    void clear()
    {
        while (l1.head != NULL)
        {
            l1.delAthead();

        }
        cnt=0;
    }
    void display()
    {
        l1.display();
    }
};
template <typename T>
class Queue_array
{
    T *ar;
    int f;
    int l;
    int n;
    int cnt;

public:
    Queue_array(int x = X)
    {
        n = x;
        ar = new T[x];
        f = 0;
        l = -1;
        cnt = 0;
    }
    bool empty()
    {
        if (l < f)
        {
            return true;
        }
        return false;
    }
    T front()
    {
        if (empty())
        {
            cout << "Empty Queue\n";
            return -1;
        }
        return ar[f];
    }
    void pop()
    {
        if (empty())
        {
            cout << "Nothing To Pop\n";
            return;
        }
        cnt--;
        f++;
    }
    void push(T x)
    {
        if (empty())
        {
            l = -1;
            f = 0;
        }
        l++;
        ar[l] = x;
        cnt++;
    }
    void clear()
    {
        l = -1;
        f = 0;
        cnt = 0;
    }
    void display()
    {
        if (!empty())
        {
            for (int i = f; i <= l; i++)
            {
                cout << ar[i] << " ";
            }
            cout << endl;
            return;
        }
        cout << "Empty Queue\n";
    }
    int size()
    {
        return cnt;
    }
    bool full()
    {
        if (l == n - 1)
            return true;
        return false;
    }
};
// #include<bits/stdc++.h>
// const int N = 1e5;
template <typename T>
class Circular_Queue
{
    T *ar;
    int f;
    int l;
    int n;
    int cnt;

public:
    Circular_Queue(int x = X)
    {
        ar = new T[x];
        n = x;
        f = 0;
        l = -1;
        cnt = 0;
    }
    bool empty()
    {
        if (cnt == 0)
        {
            return true;
        }
        return false;
    }
    bool full()
    {
        if (cnt == n)
        {
            return true;
        }
        return false;
    }
    void push(T x)
    {
        if (full())
        {
            cout << "Queue is Full\n";
            return;
        }
        l++;
        l %= n;
        ar[l] = x;
        cnt++;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Nothing to Pop\n";
            return;
        }
        cnt--;
        f++;
        f %= n;
    }
    int size()
    {
        return cnt;
    }
    void clear()
    {
        f = 0;
        l = -1;
        cnt = 0;
    }
    T front()
    {
        if (empty())
        {
            cout << "Emty Queue\n";
            return -1;
        }
        return ar[f];
    }
    void display()
    {
        if (empty())
        {
            return;
        }
        int i = f;
        while (i != l)
        {
            cout << ar[i] << " ";
            i++;
            i %= n;
        }
        cout << ar[l] << endl;
    }
};
class Queue_string
{
    linked_list_string l1;
    int cnt = 0;

public:
    bool empty()
    {
        if (l1.head == NULL)
        {
            return true;
        }
        return false;
    }
    string front()
    {
        if (empty())
        {
            cout << "Empty Queue\n";
            return "empty";
        }
        return l1.head->data;
    }
    void push(string n)
    {
        l1.insAttail(n);
        cnt++;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Nothing to pop\n";
            return;
        }
        l1.delAthead();
        cnt--;
    }
    ll size()
    {
        return cnt;
    }
    void clear()
    {
        while (l1.head != NULL)
        {
            l1.delAthead();

        }
        cnt=0;
    }
    void display()
    {
        l1.display();
    }
};
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int dat, Node *nxt)
    {
        this->data = dat;
        this->next = nxt;
    }

    Node(int dat)
    {
        this->data = dat;
        this->next = NULL;
    }
};

template <typename T>
class QueueLL
{
private:
    Node<T> *start;
    Node<T> *end;
    int count;
    int limit;

public:
    QueueLL();
    QueueLL(int sz);
    void enqueue(T num);
    void dequeue();
    T front();
    bool isEmpty();
    bool isFull();
    void display();
    int size()
    {
        return this->count;
    }
};
template <typename T>
QueueLL<T>::QueueLL()
{
    this->start = NULL;
    this->end = NULL;
    this->count = 0;
    this->limit = INT_MAX;
}
template <typename T>
QueueLL<T>::QueueLL(int sz)
{
    this->start = NULL;
    this->end = NULL;
    this->count = 0;
    this->limit = sz;
}
template <typename T>
void QueueLL<T>::enqueue(T num)
{
    if (this->count + 1 > this->limit)
    {
        cout << "Queue size overloaded\n";
        return;
    }

    Node<T> *newNode = new Node<T>(num);
    if (this->count == 0)
    {
        this->start = newNode;
        this->end = newNode;
        this->count = this->count + 1;
        return;
    }

    this->end->next = newNode;

    this->end = newNode;

    this->count = this->count + 1;
}
template <typename T>
void QueueLL<T>::dequeue()
{
    if (this->count <= 0)
    {
        cout << "Nothing to dequeue!!\n";
        return;
    }

    if (this->count == 1)
    {
        this->start = NULL;
        this->end = NULL;

        this->count = this->count - 1;

        return;
    }

    this->start = this->start->next;
    this->count = this->count - 1;
}
template <typename T>
T QueueLL<T>::front()
{
    return this->start->data;
}
template <typename T>
bool QueueLL<T>::isEmpty()
{
    return (this->count == 0);
}
template <typename T>
bool QueueLL<T>::isFull()
{
    return (this->count == this->limit);
}
template <typename T>
void QueueLL<T>::display()
{
    Node<T> *curr = this->start;

    // cout << "Display... ";

    if (curr == NULL)
    {
        cout << endl;
        return;
    }

    if (this->count == 1)
    {
        cout << this->start->data << endl;
        return;
    }

    while (curr != this->end->next)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
template <typename T>
class MycircularDequeue{
    T *arr;
    int cnt;
    int f;
    int l;
    int n;
    public:
    MycircularDequeue(int x=1e6){
        n=x;
        arr = new T[n];
        cnt=0;
        f=0;
        l=-1;
    }
    bool isEmpty(){
        return(!cnt);
    }
    bool isFull(){
        return(cnt==n);
    }
    void addFront(T x){
        if(cnt==n){
            cout<<"Q is full.\n";
            return;
        }
        if(f==0){
            f=n-1;
            arr[f]=x;
            cnt++;
            return;
        }
        f--;
        cnt++;
        arr[f]=x;

    }
    void addRear(T x){
        if(cnt==n){
            cout<<"Queue is full.\n";
            return;
        }
        l++;
        l%=n;
        arr[l]=x;
        cnt++;
    }
    void removeFront(){
        if(isEmpty()){
            cout<<"Empty Queue.\n";
            return;
        }
        cnt--;
        f++;
        f%=n;
    }
    T front(){
        if(isEmpty()){
            return -1;
        }
        return arr[f];

    }
    T back(){
        if(isEmpty()){
            return -1;
        }
        return arr[l];
    }
    void removeRear(){
        if(isEmpty()){
            cout<<"Empty Queue.\n";
            return;
        }
        cnt--;
        if(l==0){
            l=n-1;
        }
        else{
            l--;
        }
    }
    void display(){
        if (isEmpty())
        {
            return;
        }
        int i = f;
        while (i != l)
        {
            cout << arr[i] << " ";
            i++;
            i %= n;
        }
        cout << arr[l] << endl;
    }




};
