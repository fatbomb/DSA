#include "bst.hpp"

int rangeSumBST(node* root,int low, int high ){
    if(root==NULL){
        return 0;
    }
    if(root->val==low ){
        //cout<<root->data<<endl;;
        return root->val+rangeSumBST(root->right,low,high);
    }
    if(root->val==high){
        return root->val+rangeSumBST(root->left,low,high);
    }
    if(root->data<low){
        return rangeSumBST(root->right,low,high);
    }
    if(root->data>high){
        return rangeSumBST(root->left,low,high);
    }

    //cout<<rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high)+root->data<<endl;
    return rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high)+root->data;
}
int main(){
    BinaryTree t=BinaryTree();
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        t.addnode(x);
    }
    int l,h;
    cin>>l>>h;
    cout<<rangeSumBST(t.root,l,h)<<endl;
}