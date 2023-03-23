#include <bits/stdc++.h>

using namespace std;
class Student{
    // string Name;
    // int roll;
    // string DateOfBirth;
    // double cgpa;
    public:
    string Name;
    int roll;
    string DateOfBirth;
    double cgpa;
    Student(string name,int roll, string DateOfBirth,double cgpa){
        this->Name=name;
        this->roll=roll;
        this->DateOfBirth=DateOfBirth;
        this->cgpa=cgpa;
    }
    void DIsplay(){
        cout<<"Name: "<<Name<<endl;
        cout<<"Roll: "<<roll<<endl;
        cout<<"Date of Birth: "<<DateOfBirth<<endl;
        cout<<"CGPA: "<<cgpa<<endl;
    }
};

class node
{
public:
    Student *data;
    node *left;
    node *right;
    node(Student* val)
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
    void addnode(Student* val)
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
            if ((val->roll) < (temp->data->roll))
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
                if (temp == NULL)
                {
                    par->right = n;
                    return;
                }
            }
        }
    }
    void Addnode(node* &t, Student* val){
        if(t->data->roll<=val->roll){
            if(t->right==NULL){
                node* n=new node(val);
                t->right=n;
                return;
            }
            else{
                Addnode(t->right,val);
            }
        }
        else{
            if(t->left==NULL){
                node* n=new node(val);
                t->left=n;
            }

            else{
                Addnode(t->left,val);
            }
        }
    }
    void ADDnode(Student* val){
        if(root==NULL){
            node *n =new node(val);
            root=n;
            return;
        }
        Addnode(root,val);
    }
    
    
    void preOrderTravarsal(node *temp)
    {
        if (temp != NULL)
        {
            temp->data->DIsplay();
            preOrderTravarsal(temp->left);
            preOrderTravarsal(temp->right);
        }
    }
    void preOrder(){
        preOrderTravarsal(root);
        cout<<endl;
    }

    void inOrderTravarsal(node *temp)
    {
        if (temp != NULL)
        {
            inOrderTravarsal(temp->left);
            temp->data->DIsplay();
            inOrderTravarsal(temp->right);
        }
    }
    void inOrder(){
        inOrderTravarsal(root);
        cout<<endl;
    }
    void postOrderTravarsal(node *temp)
    {
        if (temp != NULL)
        {
            postOrderTravarsal(temp->left);
            postOrderTravarsal(temp->right);
            temp->data->DIsplay();
        }
    }
    void postOrder(){
        postOrderTravarsal(root);
        cout<<endl;
    }
    node *_search(int val, node *temp)
    {
        if (temp == NULL)
        {
            return NULL;
        }
        if (val == temp->data->roll)
        {
            return temp;
        }
        if (val < temp->data->roll)
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
        if(temp==NULL){
            return NULL;
        }
        if(val<temp->data->roll){
            temp->left= Delete(temp->left,val);
        }
        else if(val>temp->data->roll){
            temp->right= Delete(temp->right,val);
        }
        else{
            if(temp->left==NULL){
                node *temp1=temp->right;
                //cout<<"deleted Data1\n"<<temp->data<<endl;
                free(temp); 
                
                return temp1;
                
            }
            else if(root->right==NULL){
                node *temp1=temp->left;
                free(temp); 
                //cout<<"deleted Data2\n";
                return temp1;
            }
            else{
                node* temp1=find_min(temp->right);
                temp->data=temp1->data;
                //temp1->data->DIsplay();
                temp->right=Delete(temp->right,temp1->data->roll);
                //cout<<"deleted Data3\n";
            }


        }
        return temp;
    }
    bool isleft_sweked(){
        node* temp=root;
        if(root==NULL){
            return true;
        }
        while(temp->left!=NULL){
            if(temp->right!=NULL){
                return false;
            }
            temp=temp->left;
        }
        return true;
    }
    bool isright_sweked(){
        node* temp=root;
        if(root==NULL){
            return true;
        }
        while(temp->right!=NULL){
            if(temp->left!=NULL){
                return false;
            }
            temp=temp->right;
        }
        return true;
    }
    bool isFull(node* root){
        if(root==NULL){
            return true;
        }
        if(root->left==NULL and root->right==NULL){
            return true;
        }
        else if(root->left==NULL or root->right==NULL){
            return false;
        }
        else{
            return (isFull(root->left) & isFull(root->right));
        }

    }
    void delnode(int val)
    {
        this->root=Delete(root,val);
    }
};

int main(){
    BinaryTree t= BinaryTree();
    
    t.ADDnode(new Student("ARAF", 15, "23/06/2002", 3.84));
    t.preOrder();
    t.ADDnode(new Student("Faik", 1, "23/06/2002", 3.57));
    t.preOrder();
    t.ADDnode(new Student("Zisan", 23, "23/06/2002", 3.63));
    t.preOrder();
    t.ADDnode(new Student("Shawn", 22, "23/06/2002", 3.55));t.preOrder();
    t.preOrder();
    t.ADDnode(new Student("Aniket", 48, "17/08/2002", 3.60));
    t.preOrder();
    cout<<t.search(47);
    t.delnode(47);
    cout<<t.search(47)<<endl;
    t.preOrder();
    cout<<t.isFull(t.root)<<endl;



}
