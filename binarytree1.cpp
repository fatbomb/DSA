#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};
class BinaryTree{
    public: 
    node* root;
    BinaryTree(){
        root=NULL;
    }
    void addnode(int val){
        node* n= new node(val);
        if(root==NULL){
            root=n;
            return;
        }
        node* temp=root;
        node* par ;
        while(true){
            par=temp;
            if(val<temp->data){
                temp=temp->left;
                if(temp==NULL){
                    par->left=n;
                    return;
                }

            }
            else{
                temp=temp->right;
                if(temp->right==NULL){
                    par->right=n;
                    return;
                }
            }

        }

    }
    void preOrderTravarsal(node *temp){
        if(temp!=NULL){
            cout<<temp->data<<" ";
            preOrderTravarsal(temp->left);
            preOrderTravarsal(temp->right);
        }
    }
    void inOrderTravarsal(node *temp){
        if(temp!=NULL){
            preOrderTravarsal(temp->left);
            cout<<temp->data<<" ";
            preOrderTravarsal(temp->right);
        }
    }
    void postOrderTravarsal(node *temp){
        if(temp!=NULL){
            preOrderTravarsal(temp->left);
            preOrderTravarsal(temp->right);
            cout<<temp->data<<" ";
        }
    }

};
