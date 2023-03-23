#include "bst1.hpp"

int prv=-1;

int minDiffInBST(node *root)
{
    int x=1e9;
    if(root==NULL){
        return 1e9;
    }
    x=minDiffInBST(root->left);
    if(prv>=0){
        x=min(x,root->data-prv);
    }
    prv=root->data;
    x=min(x,minDiffInBST(root->right));
    
    return x;


}
int main(){
    int n;
    BinaryTree t= BinaryTree();
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        t.addnode(x);

    }
    cout<<minDiffInBST(t.root);

    
    
}