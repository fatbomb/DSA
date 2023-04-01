#include "linked_list.hpp"

int N = 100;

class Stack
{
    int top;
    int n;
    int *ar;

public:
    
    Stack(int x = N)
    {
        n = x;
        top = -1;
        ar = new int[n];
    }
    bool empty()
    {
        return (top == -1);
    }
    bool full()
    {
        return (top == n - 1);
    }
    void push(int x)
    {
        if (full())
        {
            cout << "Stack Overflow.\n";
            return;
        }
        top++;
        ar[top] = x;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        top--;
    }
    int Top()
    {
        if (empty())
        {
            pop();
        }
        return ar[top];
    }
    int size(){
        return top+1;
    }
};
// stack using linked list
template <typename T>
class StackV1_1
{
    doubly_linked_list<T> l1 = doubly_linked_list<T>();
    int count ;
    int n;

public:
    StackV1_1(int x = INT_MAX)
    {
        n = x;
        count = 0;
    }
    bool empty()
    {
        return !l1.head;
    }
    bool full()
    {
        return (count == n);
    }
    void push(T x)
    {
        if (full())
        {
            cout << "Stack overflow.\n";
            return;
        }
        l1.insAttail(x);
        count++;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Empty Stack.\n";
            return;
        }
        l1.delAttail();
        count--;
    }
    T top()
    {
        if (empty())
        {
            cout << "No data to show.\n";
            return -1;
        }
        return l1.tail->data;
    }
    int size(){
        return count;
    }
};
template <typename T>
class StackV1_2
{
    linked_list<T> l1 = linked_list<T>();
    int n;
    int cnt;

public:
    StackV1_2(int x = INT_MAX)
    {
        n = x;
        cnt = 0;
    }
    bool empty()
    {
        return (!l1.head);
    }
    bool full()
    {
        return (cnt == n);
    }
    void push(T x)
    {
        if (full())
        {
            cout << "Stack Over flow.\n";
            return;
        }
        l1.insAthead(x);
        cnt++;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        l1.delAthead();
        cnt--;
    }
    T top()
    {
        if (empty())
        {
            pop();
            return -1;
        }
        return l1.head->data;
    }
    int size()
    {
        return cnt;
    }
    void display(StackV1_2 &st)
    {
        if (st.empty())
        {
            return;
        }
        T k = st.top();
        st.pop();
        display(st);
        cout << k << " ";
        st.push(k);
    }
};

class StackV1_1_S
{
    doubly_linked_list_S l1 = doubly_linked_list_S();
    int count = 0;
    int n;

public:
    StackV1_1_S(int x = INT_MAX)
    {
        n = x;
    }
    bool empty()
    {
        return !l1.head;
    }
    bool full()
    {
        return (count == n);
    }
    void push(string x)
    {
        if (full())
        {
            cout << "Stack overflow.\n";
            return;
        }
        l1.insAttail(x);
        count++;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Empty Stack.\n";
            return;
        }
        l1.delAttail();
        count--;
    }
    string top()
    {
        if (empty())
        {
            cout << "No data to show.\n";
            return "empty";
        }
        return l1.tail->data;
    }
    int size(){
        return count;
    }
};