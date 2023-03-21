#include "bst.hpp"
int sum=0;
node* bstToGst(node* root){
    if(root==NULL){
        return NULL;
    }
        root->right=bstToGst(root->right);
        sum+=root->data;
        root->data=sum;
        root->left=bstToGst(root->left);
    return root;

}
int main(){
    BinaryTree t= BinaryTree();
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        t.addnode(x);
    }
    t.preOrder();
    t.root=bstToGst(t.root);
    t.preOrder();
}


