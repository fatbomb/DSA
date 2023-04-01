#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

/* struct node{
     ll data;
     node* next;

     node(ll val){
         data=val;
         next=NULL;
     }
}; */
template <typename T>
class node
{
public:
    T data;
    node<T> *next;
    node(T val)
    {
        data = val;
        next = NULL;
    }
};
template <typename T>
class doublyNode
{
public:
    T data;
    doublyNode<T> *prev;
    doublyNode<T> *next;
    doublyNode(T val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Singly linked List.
template <typename T>
class linked_list
{

public:
    node<T> *head;
    node<T> *tail;
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void insAthead(T val)
    {
        
        node<T> *n = new node<T>(val);
        n->next = head;
        head = n;
        if(head->next==NULL){
            tail=head;
        }
    }

    void insAttail(T val)
    {

        if (head == NULL)
        {
            insAthead(val); // seting the firsrt node.
            return;
        }
        node<T> *n = new node<T>(val);
        node<T> *temp = tail;
        tail->next=n;
        tail=n;
    }
    void insAtpos(T val, ll pos)
    {
        if (pos == 0)
        {
            insAthead(val);
            return;
        }
        if (head == NULL)
        {
            return;
        }

        node<T> *n = new node<T>(val);
        node<T> *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                return;
            }
        }

        n->next = temp->next;
        temp->next = n;
        if(n->next=NULL){
            tail=n;
        }
    }
    void delAthead()
    {
        if (head == NULL)
        {
            return;
        }
        node<T> *temp = head;
        head = head->next;
        if(head==NULL){
            tail=NULL;
        }
        free(temp);
    }
    void delAtpos(int pos)
    {
        if (head == NULL)
        {
            return;
        }
        if (pos == 0)
        {
            head = head->next;
            return;
        }
        node<T> *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL or temp->next==NULL)
            {
                return;
            }
        }
        node<T> *temp1 = temp->next;
        if(temp1->next==NULL){
            tail=temp;
        }
        temp->next = temp->next->next;
        free(temp1);
    }
    void delAttail()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            delAthead();
            return;
        }
        node<T> *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node<T> *temp1 = temp->next;
        temp->next = NULL;
        tail=temp;
        free(temp1);
    }

    void display()
    {
        node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    bool search(T key)
    {
        node<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

// Circular linked List
template <typename T>
class Circular_linked_list
{
public:
    node<T> *head;
    node<T> *tail;
    Circular_linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void insAthead(T val)
    {
        node<T> *n = new node<T>(val);
        if (head == NULL)
        {
            head = n;
            n->next = head;
            tail=head;

            return;
        }
        node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        n->next = head;
        head = n;
        temp->next = head;
    }
    void insAttail(T val)
    {
        if (head == NULL)
        {
            insAthead(val);
            return;
        }
        node<T> *n = new node<T>(val);
        node<T> *temp = tail;
        temp->next = n;
        n->next = head;
        tail=n;
    }
    void insAtpos(T val, ll pos)
    {
        if (pos == 0)
        {
            insAthead(val);
            return;
        }
        if (head == NULL)
        {
            return;
        }

        node<T> *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == head)
                return;
        }
        node<T> *n = new node<T>(val);
        n->next = temp->next;
        if(temp->next==head){
            tail=n;
        }
        temp->next = n;
        
    }
    void delAthead()
    {
        if (head == NULL)
        {
            return;
        }
        node<T> *temp = tail;
        node<T> *temp1 = head;
        head = head->next;
        if(head==NULL){
            tail=NULL;
            return;
        }
        temp->next = head;
        free(temp1);
    }
    void delAttail()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == head)
        {
            head = NULL;
            return;
        }
        node<T> *temp = head;
        while (temp->next->next != head)
        {
            // cout<<temp->data<<" ";
            temp = temp->next;
        }
        node<T> *temp1 = temp->next;
        temp->next = head;
        tail==temp;
        free(temp1);
    }
    void delAtpos(int pos)
    {
        if (head == NULL)
        {
            return;
        }
        if (pos == 0)
        {
            delAthead();
            return;
        }
        node<T> *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == head)
            {
                return;
            }
        }
        node<T> *temp1 = (temp->next);
        if(temp1->next==head){
            tail=temp;
        }
        temp->next = temp->next->next;
        free(temp1);
    }
    void display()

    {
        if (head == NULL)
        {
            cout << "NULL\n";
            return;
        }
        node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
            if (temp == head)
            {
                break;
            }
        }
        // cout<<temp->data<<" ";
        cout << "Head\n";
    }
    bool search(T key)
    {
        node<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
            if (temp == head)
            {
                return false;
            }
        }
        return false;
    }
};
template <typename T>
class doubly_linked_list
{
public:
    doublyNode<T> *head;
    doublyNode<T> *tail;
    doubly_linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void insAthead(ll val)
    {
        doublyNode<T> *n = new doublyNode<T>(val);
        if (head != NULL)
        {
            head->prev = n;
        }
        else
        {
            tail = n;
        }
        n->next = head;
        head = n;
    }
    void insAttail(T val)
    {
        if (head == NULL)
        {
            insAthead(val);
            return;
        }
        doublyNode<T> *n = new doublyNode<T>(val);
        doublyNode<T> *temp = tail;
        temp->next = n;
        n->prev = temp;
        tail = n;
    }
    void insAtpos(T val, ll pos)
    {
        if (pos == 0)
        {
            insAthead(val);
            return;
        }
        if (head == NULL)
        {
            return;
        }
        doublyNode<T> *n = new doublyNode<T>(val);
        doublyNode<T> *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                return;
            }
        }
        if (temp->next == NULL)
        {
            temp->next = n;
            n->prev = temp;
            tail = n;
            return;
        }
        temp->next->prev = n;
        n->next = temp->next;
        n->prev = temp;
        temp->next = n;
    }
    void delAthead()
    {
        if (head == NULL)
        {
            return;
        }
        doublyNode<T> *temp = head;
        head = head->next;
        if(head==NULL){
            tail=NULL;
            return;
        }
        head->prev = NULL;
        free(temp);
    }
    void delAttail()
    {
        if (tail == NULL)
        {
            return;
        }
        if (tail->prev == NULL)
        {
            delAthead();
            return;
        }
        doublyNode<T> *temp = tail;
        tail=tail->prev;
        tail->next = NULL;
        free(temp);
    }
    void delAtposfront(ll pos)
    {
        if (pos == 0)
        {
            delAthead();
            return;
        }
        if (head == NULL)
        {
            return;
        }
        doublyNode<T> *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL or temp->next==NULL)
            {
                return;
            }
        }
        doublyNode<T> *temp1 = temp->next;
        
        if (temp->next->next != NULL)
        {
            //cout<<1<<endl;
            temp->next->next->prev = temp;
        }
        else{
            tail=temp;
        }
        temp->next = temp->next->next;
        // else{
        //     tail=temp;
        // }
        free(temp1);
    }
    void delAtposback(ll pos)
    {
        if (pos == 1)
        {
            delAttail();
            return;
        }
        if (tail == NULL)
        {
            return;
        }
        doublyNode<T> *temp = tail;
        for (int i = 2; i < pos; i++)
        {
            temp = temp->prev;
            if (temp == NULL or temp->prev==NULL)
            {
                return;
            }
        }
        doublyNode<T> *temp1 = temp->prev;
        
        if (temp->prev->prev != NULL)
        {
            //cout<<1<<endl;
            temp->prev->prev->next = temp;
        }
        else{
            head=temp;
        }
        temp->prev = temp->prev->prev;
        // else{
        //     tail=temp;
        // }
        free(temp1);
    }

    void displayfromfront()
    {
        cout << "Display from front:\n";
        doublyNode<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "End\n";
    }
    void displayfromback()
    {
        doublyNode<T> *temp=tail;
        cout << "Dilplay from back:\n";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << "Start\n";
    }
    bool search(ll key)
    {
        doublyNode<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
int main()
{
    doubly_linked_list<int> l1;
    linked_list<int> l2;
    //l1.display();
    for (ll i = 1; i <= 6; i++)
    {
        l2.insAttail(i);
    }
    l2.insAttail(1);
    l2.display();
    l2.delAtpos(6);
    l2.display();
    // l1.display();
    // l1.insAthead(32);
    // l1.display();
    // l1.insAtpos(33, 1);
    // l1.display();
    // l1.delAthead();
    // l1.display();
    // l1.delAttail();
    // l1.display();
    // cout << l1.search(3) << endl;
    // l1.delAtpos(3);
    // l1.display();
    // cout << l1.search(3) << endl;
    return 0;
}