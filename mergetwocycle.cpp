#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

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
 class Circular_linked_list
{
    node *head;
    node *tail;
    public:
    Circular_linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void sethead(node *temp){
        temp=head;
    }
    node* gethead(){
        return head;
    }
    void settail(node *temp){
        temp=tail;
    }
    node* gettail(){
        return tail;
    }
    void insAthead(int val)
    {
        node *n = new node(val);
        if (head == NULL)
        {
            head = n;
            n->next = head;
            tail = head;

            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        n->next = head;
        head = n;
        temp->next = head;
    }
    void insAttail(int val)
    {
        if (head == NULL)
        {
            insAthead(val);
            return;
        }
        node *n = new node(val);
        node *temp = tail;
        temp->next = n;
        n->next = head;
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

        node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == head)
                return;
        }
        node *n = new node(val);
        n->next = temp->next;
        if (temp->next == head)
        {
            tail = n;
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
        if (head == NULL)
        {
            tail = NULL;
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
        tail == temp;
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
        if (temp1->next == head)
        {
            tail = temp;
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
void merge(Circular_linked_list l1, Circular_linked_list l2)
{
    node *head1 = l1.gethead();
    node *head2 = l2.gethead();
    node *temp1 = head1;
    node *temp2 = l2.gettail();
    ll d1 = head1->data;
    ll d2 = head2->data;
    head1 = head1->next;
    while (head1 != l1.gethead())
    {
        if (head1->data > d1)
        {
            d1 = head1->data;
            temp1 = head1;
        }
        head1 = head1->next;
    }
    while(head2->next!=l2.gethead()){
        if (head2->next->data < d2)
        {
            d2 = head2->next->data;
            temp2 = head2;
        }
        head2 = head2->next; 
    }
    node* te=temp1->next;
    temp1->next=temp2->next;
    temp2->next=te;
}
int main(){
    Circular_linked_list l1, l2;
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        l1.insAttail(x);
    }
    ll m;
    cin>>m;
    while(m--){
        ll x;
        cin>>x;
        l2.insAttail(x);
    }
    l1.display();
    l2.display();
    merge(l1,l2);
    l1.display();
}