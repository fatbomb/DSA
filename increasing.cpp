#include "bst1.hpp"


node* newtree(node* root, node* t=NULL){
    if(root==NULL){
        return t;
    }
    node* temp= newtree(root->left,root);
    root->left=NULL;
    root->right= newtree(root->right,t);
    return temp;
}
int main(){
    BinaryTree t;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        t.addnode(x);

    }
    t.root=newtree(t.root);
    cout<<t.root->data<<endl;
    t.preOrder();
}