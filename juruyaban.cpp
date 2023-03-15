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
class linked_list
{

public:
    node *head;
    linked_list()
    {
        head = NULL;
    }
    void insAthead(ll val)
    {
        node *n = new node(val);
        n->next = head;
        head = n;
    }

    void insAttail(ll val)
    {

        if (head == NULL)
        {
            insAthead(val); // seting the firsrt node.
            return;
        }
        node *n = new node(val);
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
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

        node *n = new node(val);
        node *temp = head;
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
    }
    void delAthead()
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        head = head->next;
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
            if (temp == NULL)
            {
                return;
            }
        }
        node *temp1 = temp->next;
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
            head = NULL;
            return;
        }
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node *temp1 = temp->next;
        temp->next = NULL;
        free(temp1);
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
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
    void juruyaban(){
        node* temp=head;
        while(temp!=NULL){
            node* t=temp->next;
            if(t==NULL){
                break;
            }
            while(t->data==temp->data){
                node* r=t;
                t=t->next;
                free(r);
                if(t==NULL){
                    break;
                }
            }
            temp->next=t;
            temp=temp->next;
        }
    }
    void juruyabanv2(){
        node* temp=head;
        node* temp1=NULL;
        head=NULL;
        while(temp!=NULL){
            node* t=temp->next;
            if(t==NULL){
                if(head==NULL){
                    temp1=temp;
                    head=temp;
                    
                }
                else{
                    temp1->next=temp;
                    temp1=temp1->next;
                }
                break;
            }
            bool fl=false;
            while(t->data==temp->data){
                node* r=t;
                t=t->next;
                fl=true;
                free(r);
                if(t==NULL){
                    break;
                }
            }
            
            if(!fl){
                if(head==NULL){
                    temp1=temp;
                    head=temp;
                    
                }
                else{
                    temp1->next=temp;
                    temp1=temp1->next;
                }
            }
            temp=t;

        }
        if(temp1->next!=NULL){
            temp1->next=NULL;
        }
    }
};
int main()
{
    linked_list l1, l2, l3;
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        l1.insAttail(x);
    }
    l1.juruyabanv2();
    l1.display();
    //cout<<l1.head<<endl;
    
}