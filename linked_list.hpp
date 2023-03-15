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
class node
{
public:
    ll data;
    node *next;
    node(ll val)
    {
        data = val;
        next = NULL;
    }
};
class doublyNode
{
public:
    ll data;
    doublyNode *prev;
    doublyNode *next;
    doublyNode(ll val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};


// Singly linked List.
class linked_list
{

public:
    node *head;
    node *tail;
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void insAthead(ll val)
    {
        
        node *n = new node(val);
        n->next = head;
        head = n;
        if(head->next==NULL){
            tail=head;
        }
    }

    void insAttail(ll val)
    {

        if (head == NULL)
        {
            insAthead(val); // seting the firsrt node.
            return;
        }
        node *n = new node(val);
        (this->tail->next)=n;
        this->tail=n;
    }
    void insAtpos(ll val, ll pos)
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

        
        node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                return;
            }
        }
        node *n = new node(val);

        n->next = temp->next;
        temp->next = n;
        if((n->next)=NULL){
            tail=(n);
        }
    }
    void delAthead()
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        this->head = (this->head->next);
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
        node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL or temp->next==NULL)
            {
                return;
            }
        }
        node *temp1 = temp->next;
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
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node *temp1 = temp->next;
        temp->next = NULL;
        tail=temp;
        free(temp1);
    }

    void display()
    {
        node *temp = head;
        while (temp != tail->next)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    bool search(ll key)
    {
        node *temp = head;
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
class Circular_linked_list
{
public:
    node *head;
    node* tail;
    Circular_linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void insAthead(int val)
    {
        node *n = new node(val);
        if (head == NULL)
        {
            head = n;
            n->next = head;
            tail=head;

            return;
        }
        
        n->next = head;
        head = n;
        tail->next = head;
    }
    void insAttail(int val)
    {
        if (head == NULL)
        {
            insAthead(val);
            return;
        }
        node *n = new node(val);
        tail->next = n;
        n->next = head;
        tail=n;
    }
    void insAtpos(ll val, ll pos)
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

        node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == head)
                return;
        }
        node *n = new node(val);
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
        node *temp = tail;
        node *temp1 = head;
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
        node *temp = head;
        while (temp->next->next != head)
        {
            // cout<<temp->data<<" ";
            temp = temp->next;
        }
        node *temp1 = temp->next;
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
        node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == head)
            {
                return;
            }
        }
        node *temp1 = (temp->next);
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
        node *temp = head;
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
    bool search(ll key)
    {
        node *temp = head;
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
class doubly_linked_list
{
public:
    doublyNode *head;
    doublyNode *tail;
    doubly_linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void insAthead(ll val)
    {
        doublyNode *n = new doublyNode(val);
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
    void insAttail(ll val)
    {
        if (head == NULL)
        {
            insAthead(val);
            return;
        }
        doublyNode *n = new doublyNode(val);
        doublyNode *temp = tail;
        temp->next = n;
        n->prev = temp;
        tail = n;
    }
    void insAtpos(ll val, ll pos)
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
        doublyNode *n = new doublyNode(val);
        doublyNode *temp = head;
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
        doublyNode *temp = head;
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
        doublyNode *temp = tail;
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
        doublyNode *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL or temp->next==NULL)
            {
                return;
            }
        }
        doublyNode *temp1 = temp->next;
        
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
        doublyNode *temp = tail;
        for (int i = 2; i < pos; i++)
        {
            temp = temp->prev;
            if (temp == NULL or temp->prev==NULL)
            {
                return;
            }
        }
        doublyNode *temp1 = temp->prev;
        
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
        doublyNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "End\n";
    }
    void displayfromback()
    {
        doublyNode *temp=tail;
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
        doublyNode *temp = head;
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
class doublyNodeS
{
public:
    string data;
    doublyNodeS *prev;
    doublyNodeS *next;
    doublyNodeS(string val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
class doubly_linked_list_S
{
public:
    doublyNodeS *head;
    doublyNodeS *tail;
    doubly_linked_list_S()
    {
        head = NULL;
        tail = NULL;
    }
    void insAthead(string val)
    {
        doublyNodeS *n = new doublyNodeS(val);
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
    void insAttail(string val)
    {
        if (head == NULL)
        {
            insAthead(val);
            return;
        }
        doublyNodeS *n = new doublyNodeS(val);
        doublyNodeS *temp = tail;
        temp->next = n;
        n->prev = temp;
        tail = n;
    }
    void insAtpos(string val, ll pos)
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
        doublyNodeS *n = new doublyNodeS(val);
        doublyNodeS *temp = head;
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
        doublyNodeS *temp = head;
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
        doublyNodeS *temp = tail;
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
        doublyNodeS *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL or temp->next==NULL)
            {
                return;
            }
        }
        doublyNodeS *temp1 = temp->next;
        
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
        doublyNodeS *temp = tail;
        for (int i = 2; i < pos; i++)
        {
            temp = temp->prev;
            if (temp == NULL or temp->prev==NULL)
            {
                return;
            }
        }
        doublyNodeS *temp1 = temp->prev;
        
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
        doublyNodeS *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "End\n";
    }
    void displayfromback()
    {
        doublyNodeS *temp=tail;
        cout << "Dilplay from back:\n";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << "Start\n";
    }
    bool search(string key)
    {
        doublyNodeS *temp = head;
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
class node_string
{
public:
    string data;
    node_string *next;
    node_string(string val)
    {
        data = val;
        next = NULL;
    }
};
class linked_list_string
{

public:
    node_string *head;
    node_string *tail;
    linked_list_string()
    {
        head = NULL;
        tail = NULL;
    }
    void insAthead(string val)
    {
        
        node_string *n = new node_string(val);
        n->next = head;
        head = n;
        if(head->next==NULL){
            tail=head;
        }
    }

    void insAttail(string val)
    {

        if (head == NULL)
        {
            insAthead(val); // seting the firsrt node.
            return;
        }
        node_string *n = new node_string(val);
        tail->next=n;
        tail=n;
    }
    void insAtpos(string val, ll pos)
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

        
        node_string *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                return;
            }
        }
        node_string *n = new node_string(val);

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
        node_string *temp = head;
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
        node_string *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL or temp->next==NULL)
            {
                return;
            }
        }
        node_string *temp1 = temp->next;
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
        node_string *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node_string *temp1 = temp->next;
        temp->next = NULL;
        tail=temp;
        free(temp1);
    }

    void display()
    {
        node_string *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    bool search(string key)
    {
        node_string *temp = head;
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
