#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class BinaryTree
{
public:
    node *root;
    BinaryTree()
    {
        root = NULL;
    }
    void addnode(int val)
    {
        node *n = new node(val);
        if (root == NULL)
        {
            root = n;
            return;
        }
        node *temp = root;
        node *par;
        while (true)
        {
            par = temp;
            if (val < temp->data)
            {
                temp = temp->left;
                if (temp == NULL)
                {
                    par->left = n;
                    return;
                }
            }
            else
            {
                temp = temp->right;
                if (temp->right == NULL)
                {
                    par->right = n;
                    return;
                }
            }
        }
    }
    void preOrderTravarsal(node *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            preOrderTravarsal(temp->left);
            preOrderTravarsal(temp->right);
        }
    }
    void inOrderTravarsal(node *temp)
    {
        if (temp != NULL)
        {
            inOrderTravarsal(temp->left);
            cout << temp->data << " ";
            inOrderTravarsal(temp->right);
        }
    }
    void postOrderTravarsal(node *temp)
    {
        if (temp != NULL)
        {
            postOrderTravarsal(temp->left);
            postOrderTravarsal(temp->right);
            cout << temp->data << " ";
        }
    }
    node *_search(int val, node *temp)
    {
        if (temp == NULL)
        {
            return NULL;
        }
        if (val == temp->data)
        {
            return temp;
        }
        if (val < temp->data)
        {
            return _search(val, temp->left);
        }
        else
        {
            return _search(val, temp->right);
        }
    }
    bool search(int val)
    {
        if (_search(val, root) == NULL)
            return false;
        return true;
    }
    
    node* find_min(node* temp){
        while(temp and temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    node* Delete(node* temp, int val){
        if(val<temp->data){
            temp->left= Delete(temp->left,val);
        }
        else if(val<temp->data){
            temp->right= Delete(temp->right,val);
        }
        else{
            if(temp->left==NULL){
                node *temp1=temp->right;
                free(temp); 
                return temp1;
            }
            if(temp->right==NULL){
                node *temp1=temp->left;
                free(temp); 
                return temp1;
            }
            else{
                node* temp1=find_min(temp->right);
                temp->data=temp1->data;
                temp->right=Delete(temp->right,temp1->data);
            }


        }
        return temp;
    }
    void delnode(int val)
    {
        this->root=Delete(root,val);
    }
};
