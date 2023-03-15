#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

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
int main()
{
    doubly_linked_list l1;
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        l1.insAttail(x);
    }
    ll m;
    cin>>m;
    l1.delAtposback(m);
    l1.displayfromfront();


    
    return 0;
}