#include "linked_list.hpp"

const int N = 1e5;

template <typename T>
class Queue
{
    linked_list l1;
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
    ll front()
    {
        if (empty())
        {
            cout << "Empty Queue\n";
            return -1;
        }
        return l1.head->data;
    }
    void push(ll n)
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
        cnt = 0;
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
    Queue_array(int x = N)
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
    Circular_Queue(int x = N)
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
    int front()
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

template <typename T>
class PriorityQueue
{
    T *arr;
    int n;
    int cnt;

public:
    PriorityQueue(int x)
    {
        n = x;
        cnt = 0;
        arr = new T[x];
    }
    void push(T item)
    {
        arr[cnt] = item;
        int ci = cnt++;
        while (ci > 0)
        {
            int pi = (ci - 1) / 2;
            if (arr[ci] <= arr[pi])
            {
                break;
            }
            T tem = arr[ci];
            arr[ci] = arr[pi];
            arr[pi] = tem;
            ci = pi;
        }
    }
    void pop()
    {
        // T fi = arr[0];
        arr[0] = arr[cnt];
        int li = --cnt;
        int pi = 0;
        while (true)
        {
            int ci = pi * 2;
            if (ci > li)
            {
                break;
            }
            int rc = ci + 1;
            if (rc <= li && arr[rc] < arr[ci])
                ci = rc;
            if (arr[pi] >= arr[ci])
                break;
            T tmp = arr[pi];
            arr[pi] = arr[ci];
            arr[ci] = tmp;
            pi = ci;
        }
        return;
    }
    T top()
    {
        return arr[0];
    }
    int size()
    {
        return cnt;
    }
};
template <typename T>

class Priority_Queue_low
{
    T *har;
    int n;
    int cnt;

public:
    Priority_Queue_low(int x)
    {
        this->n = x ;
        this->cnt = 0;
        har = new T[x + 1];
    }
    bool empty(){
        return(!cnt);
    }
    bool full(){
        return(cnt==n);
    }
    void Swap(T &x, T &y)
    {
        T temp = x;
        x = y;
        y = temp;
    }
    int parent(int i)
    {
        return (i / 2);
    }
    int left(int i)
    {
        return (i * 2);
    }
    int right(int i)
    {
        return (i * 2) + 1;
    }
    void push(T k)
    {
        if (cnt == n )
        {
            cout << "\nOverflow: Couldn't insert key.\n";
            return;
        }
        cnt++;
        har[cnt] = k;
        int i = cnt;
        while (i != 1 and har[parent(i)] > har[i])
        {
            Swap(har[i], har[parent(i)]);
            i = parent(i);
        }
    }
    void decreaseKey(int i, T val)
    {
        har[i] = val;
        while (i != 1 and har[parent(i)] > har[i])
        {
            Swap(har[i], har[parent(i)]);
            i = parent(i);
        }
    }
    void minHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l <= cnt and har[l] < har[i])
        {
            smallest = l;
        }
        if (r <= cnt and har[r] < har[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            Swap(har[i], har[smallest]);
            minHeapify(smallest);
        }
    }
    T extractMin()
    {
        if (this->cnt < 1)
        {
            return INT_MAX;
        }
        if (cnt == 1)
        {
            cnt--;
            return har[cnt];
            
        }

        int root = har[1];
        har[1] = har[cnt];
        cnt--;
        minHeapify(1);

        return root;
    }
    void pop(){
        if(cnt==0){
            return;
        }
        extractMin();
    }
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    T top()
    {
        if(cnt==0){
            return -1;
        }
        return har[1];
    }
    int size(){
        return cnt;
    }
};
template <typename T>

class Priority_Queue_high
{
    T *har;
    int n;
    int cnt;

public:
    Priority_Queue_high(int x)
    {
        this->n = x ;
        this->cnt = 0;
        har = new T[x + 1];
    }
    bool empty(){
        return(!cnt);
    }
    bool full(){
        return(cnt==n);
    }
    void Swap(T &x, T &y)
    {
        T temp = x;
        x = y;
        y = temp;
    }
    int parent(int i)
    {
        return (i / 2);
    }
    int left(int i)
    {
        return (i * 2);
    }
    int right(int i)
    {
        return (i * 2) + 1;
    }
    void push(T k)
    {
        if (cnt == n )
        {
            cout << "\nOverflow: Couldn't insert key.\n";
            return;
        }
        cnt++;
        har[cnt] = k;
        int i = cnt;
        while (i != 1 and har[parent(i)] < har[i])
        {
            Swap(har[i], har[parent(i)]);
            i = parent(i);
        }
    }
    void decreaseKey(int i, T val)
    {
        har[i] = val;
        while (i != 1 and har[parent(i)] < har[i])
        {
            Swap(har[i], har[parent(i)]);
            i = parent(i);
        }
    }
    void minHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l <= cnt and har[l] > har[i])
        {
            smallest = l;
        }
        if (r <= cnt and har[r] > har[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            Swap(har[i], har[smallest]);
            minHeapify(smallest);
        }
    }
    T extractMin()
    {
        if (this->cnt < 1)
        {
            return INT_MAX;
        }
        if (cnt == 1)
        {
            cnt--;
            return har[cnt];
            
        }

        int root = har[1];
        har[1] = har[cnt];
        cnt--;
        minHeapify(1);

        return root;
    }
    void pop(){
        if(cnt==0){
            return;
        }
        extractMin();
    }
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    T top()
    {
        if(cnt==0){
            return -1;
        }
        return har[1];
    }
    int size(){
        return cnt;
    }
};


int main()
{
    ll n;
    cin >> n;

    Priority_Queue_high<int> q = Priority_Queue_high<int>(n);
    for (int i = 1; i <= n; i++)
    {   
        ll x;
        cin>>x;
        q.push(x);
        cout<<q.top()<<" ";
    }
    cout<<endl;
    for (int i = 1; i <= n; i++)
    {   
        cout<<q.top()<<" "<<q.size()<<"\n";
        q.pop();
        cout<<q.size()<<endl;
    }

    cout<<endl;

    cout << q.size() << endl;
    cout << q.top() << endl;
    q.push(12);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout<<q.top()<<endl;

    
}