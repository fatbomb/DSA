#include "bst1.hpp"
int sum=0;
node<int>* bstToGst(node<int>* root){
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
    BinaryTree<int> t= BinaryTree<int>();
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


