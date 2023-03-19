#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Count=0;

class node
{
public:
    int val;
    node *left, *right;
    node()
    {
        val = 0;
        left = right = NULL;
    }
    node(int _val)
    {
        val = _val;
        left = right = NULL;
    }
};

class bst
{
public:
    node *root;
    bst()
    {
        root = NULL;
    }

    // void insert_rec(node *curr, int val)
    // {
    //     if (val < curr->val)
    //     {
    //         if (!curr->left)
    //         {
    //             curr->left = new node(val);
    //             return;
    //         }
    //         insert_rec(curr->left, val);
    //     }
    //     else
    //     {
    //         if (!curr->right)
    //         {
    //             curr->right = new node(val);
    //             return;
    //         }
    //         insert_rec(curr->right, val);
    //     }
    // }

    void insert_rec(node *&curr, int val)
    {
        if(!curr)
        {
            curr = new node(val);
            return ;
        }
        if (val < curr->val)
        {
            // if (!curr->left)
            // {
            //     curr->left = new node(val);
            //     return;
            // }
            insert_rec(curr->left, val);
            //cout<<"left "<<curr->val<<endl;
        }
        else
        {
            // if (!curr->right)
            // {
            //     curr->right = new node(val);
            //     return;
            // }
            insert_rec(curr->right, val);
            //cout<<"right "<<curr->val<<endl;
        }
        //cout<<curr->val<<endl;
    }

    void insert(int val)
    {
        node *curr = root;
        if (!root)
        {
            root = new node(val);
            return;
        }

        insert_rec(root, val);
    }

    void search(int val)
    {
        node *curr = root;
        if (!root)
        {
            cout << "Empty BST" << endl;
            return;
        }

        while (1)
        {
            if (val < curr->val)
            {
                if (!curr->left)
                {
                    cout << "Not found " << endl;
                    return;
                }
                curr = curr->left;
            }
            else if (val > curr->val)
            {
                if (!curr->right)
                {
                    cout << "Not found " << endl;
                    return;
                }
                curr = curr->right;
            }
            else
            {
                cout << "Found " << endl;
                return;
            }
        }
    }

};

int main()
{
    bst b;

    for (int i = 0; i < 9; i++)
    {
        b.insert(i);
    }

    b.search(5);

    return 0;
}