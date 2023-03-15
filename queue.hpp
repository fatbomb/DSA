#include "linked_list.hpp"

const int X = 1e5;

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
        cnt=0;
    }
    void display()
    {
        l1.display();
    }
};
class Queue_array
{
    int *ar;
    int f;
    int l;
    int n;
    int cnt;

public:
    Queue_array(int x = X)
    {
        n = x;
        ar = new int[x];
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
    int front()
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
    void push(int x)
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
class Circular_Queue
{
    int *ar;
    int f;
    int l;
    int n;
    int cnt;

public:
    Circular_Queue(int x = X)
    {
        ar = new int[x];
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
    void push(int x)
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