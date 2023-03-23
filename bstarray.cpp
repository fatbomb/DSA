
#include <bits/stdc++.h>
using namespace std;
class Student
{
    // string Name;
    // int roll;
    // string DateOfBirth;
    // double cgpa;
public:
    string Name;
    int roll;
    string DateOfBirth;
    double cgpa;
    Student(string name, int roll, string DateOfBirth, double cgpa)
    {
        this->Name = name;
        this->roll = roll;
        this->DateOfBirth = DateOfBirth;
        this->cgpa = cgpa;
    }
    void DIsplay()
    {
        cout << "Name: " << Name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Date of Birth: " << DateOfBirth << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

class TreeArrat{
    public:
    Student *tree[100000];

    void addnode(int parent ,Student* s){
        if(tree[parent]==NULL){
            tree[parent]=s;
            return;
        }

        if(tree[parent]->roll>s->roll){
            if(tree[2*parent]==NULL){
                tree[2*parent]=s;
                return;
            }
            addnode(2*parent,s);

        }
        else{
            if(tree[(parent*2)+1]==NULL){
                tree[(2*parent)+1]=s;
                return;
            }
            addnode((2*parent)+1,s);
        }
    }
    void preOrderTravarsal(int parent)
    {
        if (tree[parent] != NULL)
        {
            cout<<tree[parent]->roll<<" ";
            preOrderTravarsal(parent*2);
            preOrderTravarsal((parent*2)+1);
        }
    }
    void inOrderTravarsal(int parent)
    {
        if (tree[parent] != NULL)
        {
            inOrderTravarsal(parent*2);
            cout<<tree[parent]->roll<<" ";
            inOrderTravarsal((parent*2)+1);
        }
    }
    void postOrderTravarsal(int parent)
    {
        if (tree[parent] != NULL)
        {
            
            postOrderTravarsal(parent*2);
            
            postOrderTravarsal((parent*2)+1);
            cout<<tree[parent]->roll<<" ";
        }
    }
    int find_min(int parent){
        while(tree[parent] and tree[parent*2]!=NULL){
            parent*=2;
        }
        return parent;
    }
    
    void delnode(int parent, int val){
        if(tree[parent]==NULL){
            return ;
        }
        if(val<tree[parent]->roll){
            delnode(parent*2,val);
        }
        else if(val>tree[parent]->roll){
            delnode((parent*2)+1,val);
        }
        else{
            if(tree[parent*2]==NULL){
                tree[parent]=tree[(parent*2)+1];
                tree[(parent*2)+1]=NULL;
                return;
            }
            else if(tree[(parent*2)+1]==NULL){
                tree[parent]=tree[parent*2];
                tree[(parent*2)]=NULL;
                return;
            }
            else{
                Student *s =tree[find_min(parent)];
                tree[parent]=s;
                delnode((parent*2)+1,val);

            }
        }
    }
    int search(int val,int par){
        if(tree[par]==NULL){
            return -1;
        }
        if(val== tree[par]->roll){
            return par;
        }
        if(val<tree[par]->roll){
            search(val,par*2);
        }
        else{
            search(val,(par*2)+1);
        }
    }
    bool isFull(int par){
        if(tree[par]==NULL){
            return true;
        }
        if(tree[par*2]==NULL and tree[par*2+1]==NULL){
            return true;
        }
        else if(tree[par*2]==NULL and tree[par*2+1]==NULL){
            return false;
        }
        else{
            return (isFull(par*2) & isFull(par*2+1));
        }

    }
void print_tree()
{
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        if (tree[i] != NULL)
            tree[i]->DIsplay();
        else
            cout << endl;
    }

    return;
}
};


// Driver Code
int main()
{
    TreeArrat t= TreeArrat();
     t.addnode(1, new Student("ARAF", 15, "23/06/2002", 3.84));
    t.preOrderTravarsal(1);
    cout<<endl;
    t.addnode(1, new Student("Faik", 1, "23/06/2002", 3.57));
    t.preOrderTravarsal(1);
    cout<<endl;
    t.addnode(1, new Student("Zisan", 23, "23/06/2002", 3.63));
    t.preOrderTravarsal(1);
    cout<<endl;
    t.addnode(1, new Student("Shawn", 47, "23/06/2002", 3.55));
    t.preOrderTravarsal(1);
    cout<<endl;
    t.addnode(1, new Student("Himel", 13, "10/10/2002", 3.85));
    t.preOrderTravarsal(1);
    cout<<endl;
    t.addnode(1, new Student("Aniket", 48, "17/08/2002", 3.60));
    t.preOrderTravarsal(1);
    t.delnode(1,47);
    cout<<endl;
    t.preOrderTravarsal(1);
    return 0;
}
