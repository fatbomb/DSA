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
};
void add(linked_list &l1, linked_list &l2)
{
    int c = 0;
    node *n1 = l1.head;
    node *n2 = l2.head;
    if (n1 == NULL)
    {
        l1.head = n2;
        return;
    }
    if (n2 == NULL)
    {
        return;
    }
    while (n1->next != NULL and n2->next != NULL)
    {
        int temp = n1->data + n2->data + c;
        n1->data = temp % 10;
        c = temp / 10;
        //cout<<temp<<" "<<n1->data<<" "<<c<<"in"<<endl;
        n1 = n1->next;
        n2 = n2->next;
    }

    if (n1->next != NULL)
    {
        int temp = n1->data + n2->data + c;
        n1->data = temp % 10;
        c = temp / 10;
        n1 = n1->next;
        while (n1 != NULL)
        {
            temp = n1->data + c;
            n1->data = temp % 10;
            c = temp / 10;
            //cout<<temp<<" "<<n1->data<<" "<<c<<endl;
            if (n1->next == NULL and c > 0)
            {
                node *n = new node(c);
                n1->next = n;
                c = 0;
            }
            n1 = n1->next;
        }
    }
    else if (n2->next != NULL)
    {
        int temp = n1->data + n2->data + c;
        n1->data = temp % 10;
        c = temp / 10;
        n1->next = n2->next;
        n1=n1->next;
        while (n1 != NULL)
        {
            temp = n1->data + c;
            n1->data = temp % 10;
            c = temp / 10;
            //cout<<temp<<" "<<n1->data<<" "<<c<<endl;
            if (n1->next == NULL and c > 0)
            {
                node *n = new node(c);
                n1->next = n;
                c = 0;
            }
            n1 = n1->next;
        }
    }
    else
    {
        int temp = n1->data + n2->data + c;
        n1->data = temp % 10;
        c = temp / 10;
        //cout<<temp<<" "<<n1->data<<" "<<c<<endl;
        if (n1->next == NULL and c > 0)
        {
            node *n = new node(c);
            n1->next = n;
            c = 0;
        }
    }
}

int main()
{
    linked_list l1, l2;
    int k;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l1.insAttail(x);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        l2.insAttail(x);
    }
    add(l1,l2);

    l1.display();
    //l2.display();
}