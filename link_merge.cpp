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
void merge(linked_list &l1, linked_list &l2)
{
    node *temp = l1.head;
    node *temp1 = l2.head;
    node *head = NULL;
    node *dump = NULL;

    while (temp1 != NULL and temp != NULL)
    {
        if (temp->data <= temp1->data)
        {
            if (dump == NULL)
            {
                dump = temp;
                head = dump;
            }
            else
            {
                dump->next = temp;
                dump = dump->next;
            }
            // dump=dump->next;
            temp = temp->next;
        }
        else
        {
            if (dump == NULL)
            {
                dump = temp1;
                head = dump;
            }
            else
            {
                dump->next = temp1;
                dump = dump->next;
            }
            temp1 = temp1->next;
        }
    }
    while (temp != NULL)
    {
        if (dump == NULL)
        {
            dump = temp;
            head = dump;
        }
        else
        {
            dump->next = temp;
            dump = dump->next;
        }
        temp = temp->next;
    }
    while (temp1 != NULL)
    {
        if (dump == NULL)
        {
            dump = temp1;
            head = dump;
        }
        else
        {
            dump->next = temp1;
            dump = dump->next;
        }
        temp1 = temp1->next;
    }
    l1.head = head;
    l2.head = NULL;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    linked_list l1, l2;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        if (i == 0)
        {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                l1.insAttail(x);
            }
        }
        else
        {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                l2.insAttail(x);
            }
            merge(l1, l2);
            
        }
    }
    
    l1.display();
}