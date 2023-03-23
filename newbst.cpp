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

class node
{
public:
    Student *data;
    node *left;
    node *right;
    int lev;
    node(Student *val)
    {
        data = val;
        left = NULL;
        right = NULL;
        lev = 0;
    }
};
class BinaryTree
{

public:
    node *root;
    int node_count;
    BinaryTree()
    {
        root = NULL;
        node_count = 0;
    }
    void addnode(Student *val)
    {
        node *n = new node(val);
        if (root == NULL)
        {
            n->lev = 0;
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
                    n->lev = par->lev + 1;
                    par->left = n;
                    node_count++;
                    return;
                }
            }
            else
            {
                temp = temp->right;
                if (temp == NULL)
                {
                    n->lev = par->lev + 1;
                    par->right = n;
                    node_count++;
                    return;
                }
            }
        }
    }
    void Addnode(node *&t, Student *val)
    {
        if (t->data->roll <= val->roll)
        {
            if (t->right == NULL)
            {
                node *n = new node(val);
                n->lev = t->lev + 1;
                t->right = n;
                node_count++;
                return;
            }
            else
            {
                Addnode(t->right, val);
            }
        }
        else
        {
            if (t->left == NULL)
            {
                node *n = new node(val);
                n->lev = t->lev + 1;
                t->left = n;
                node_count++;
            }

            else
            {
                Addnode(t->left, val);
            }
        }
    }
    void ADDnode(Student *val)
    {
        if (root == NULL)
        {
            node *n = new node(val);
            root = n;
            return;
        }
        Addnode(root, val);
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
    void preOrder()
    {
        preOrderTravarsal(root);
        cout << endl;
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
    void inOrder()
    {
        inOrderTravarsal(root);
        cout << endl;
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
    void postOrder()
    {
        postOrderTravarsal(root);
        cout << endl;
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

    node *find_min(node *temp)
    {
        while (temp and temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    node *Delete(node *temp, int val)
    {
        if (temp == NULL)
        {
            return NULL;
        }
        if (val < temp->data->roll)
        {
            temp->left = Delete(temp->left, val);
        }
        else if (val > temp->data->roll)
        {
            temp->right = Delete(temp->right, val);
        }
        else
        {
            if (temp->left == NULL)
            {
                node *temp1 = temp->right;
                if (temp->right != NULL)
                    temp1->lev = temp->lev;
                // cout<<"deleted Data1\n"<<temp->data<<endl;
                free(temp);
                node_count--;

                return temp1;
            }
            else if (root->right == NULL)
            {
                node *temp1 = temp->left;
                if (temp->left != NULL)
                    temp1->lev = temp->lev;
                free(temp);
                node_count--;
                // cout<<"deleted Data2\n";
                return temp1;
            }
            else
            {
                node *temp1 = find_min(temp->right);
                temp->data = temp1->data;
                // temp1->data->DIsplay();
                temp->right = Delete(temp->right, temp1->data->roll);
                // cout<<"deleted Data3\n";
            }
        }
        return temp;
    }
    bool Isskew(node *root)
    {
        if (root->left == NULL and root->right == NULL)
        {
            return true;
        }
        if (root->left != NULL and root->right != NULL)
        {
            return false;
        }
        else if (root->left == NULL)
        {
            return Isskew(root->right);
        }
        else
        {
            return Isskew(root->left);
        }
    }
    bool isSkewed()
    {
        if (this->root == NULL)
        {
            return true;
        }
        return Isskew(root);
    }
    bool IS_left(node *root)
    {
        if (root->left == NULL and root->right == NULL)
        {
            return true;
        }
        if (root->right != NULL)
        {
            return false;
        }
        return IS_left(root->left);
    }
    bool Isskewed_left()
    {
        if (root == NULL)
        {
            return true;
        }
        return IS_left(root);
    }
    
    void delnode(int val)
    {
        this->root = Delete(root, val);
    }
    bool IS_right(node *root)
    {
        if (root->left == NULL and root->right == NULL)
        {
            return true;
        }
        if (root->left != NULL)
        {
            return false;
        }
        return IS_right(root->right);
    }
    bool Isskewed_right()
    {
        if (root == NULL)
        {
            return true;
        }
        return IS_right(root);
    }
    bool is_f(node *root)
    {
        if (root->left == NULL and root->right == NULL)
        {
            return true;
        }
        if (root->left == NULL or root->right == NULL)
        {
            return false;
        }
        return (is_f(root->left) & is_f(root->right));
    }
    bool is_full()
    {
        if (root == NULL)
        {
            return true;
        }
        return is_f(root);
    }
    int depth()
    {
        node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->lev;
    }
    bool is_per(node *n, int d)
    {
        if (n == NULL)
        {
            return true;
        }
        if (n->left == NULL and n->right == NULL)
        {
            return (d == n->lev);
        }
        if (n->left == NULL or n->right == NULL)
        {
            return false;
        }
        return (is_per(n->left, d) & is_per(n->right, d));
    }
    bool is_perfect()
    {
        int d = depth();
        return is_per(root, d);
    }
    bool is_comp(node *root, int ind)
    {
        if (root == NULL)
        {
            return true;
        }
        if (ind >= this->node_count)
        {
            return false;
        }
        return (is_comp(root->left, ind * 2 + 1) & is_comp(root->right, ind * 2 + 2));
    }
    bool is_complete()
    {
        if (this->root == NULL)
        {
            return true;
        }
        return is_comp(root, 0);
    }
    int height(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    bool is_ba(node *root)
    {
        int lh, rh;
        if (root == NULL)
        {
            return true;
        }
        lh = height(root->left);
        rh = height(root->right);
        return (abs(lh - rh) <= 1 and is_ba(root->right) and is_ba(root->left));
    }
    bool is_balanced()
    {
        if (root == NULL)
        {
            return true;
        }
        return is_ba(root);
    }
};

int main()
{
    BinaryTree t = BinaryTree();

    t.ADDnode(new Student("ARAF", 15, "23/06/2002", 3.84));
    t.preOrder();
    t.ADDnode(new Student("Faik", 1, "23/06/2002", 3.57));
    t.preOrder();
    t.ADDnode(new Student("Zisan", 23, "23/06/2002", 3.63));
    t.preOrder();
    t.ADDnode(new Student("Shawn", 22, "23/06/2002", 3.55));
    t.preOrder();
    t.preOrder();
    t.ADDnode(new Student("Aniket", 48, "17/08/2002", 3.60));
    t.preOrder();
    cout << t.search(47);
    t.delnode(47);
    cout << t.search(47) << endl;
    t.preOrder();
    cout << t.is_full() << endl;
}
