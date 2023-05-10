#include <bits/stdc++.h>

using namespace std;

#define pow2(n) (1 << (n))

template <typename T>
class avl
{
public:
    T d;
    avl<T> *l;
    avl<T> *r;
    avl(T val)
    {
        this->d = val;
        this->l = NULL;
        this->r = NULL;
    }
    avl(T val, avl<T> *left, avl<T> *right)
    {
        this->d = val;
        this->l = left;
        this->r = right;
    }
};
template <typename T>
class avl_tree
{
    

public:
    avl<T> *r;
    int height(avl<T> *t)
    {
        int h = 0;
        if (t != NULL)
        {
            int l_height = height(t->l);
            int r_height = height(t->r);
            h = max(l_height, r_height) + 1;
        }
        return h;
    }
    int difference(avl<T> *t)
    {
        return (height(t->l) - height(t->r));
    }
    avl<T> *ll_rotate(avl<T> *par)
    {
        avl<T> *t = par->r;
        par->r = t->l;
        t->l = par;
        cout << "Left-Left Rotation" << endl;
        return t;
    }
    avl<T> *rr_rotate(avl<T> *par)
    {
        avl<T> *t = par->l;
        par->l = t->r;
        t->r = par;
        cout << "Right-Right Rotation" << endl;
        return t;
    }
    avl<T> *lr_rotate(avl<T> *par)
    {
        avl<T> *t = par->l;
        par->l = ll_rotate(t);
        cout << "Left-Right Rotate." << endl;
        return rr_rotate(par);
    }
    avl<T> *rl_rotate(avl<T> *par)
    {
        avl<T> *t = par->r;
        par->r = rr_rotate(t);
        cout << "Right-Left Rotate." << endl;
        return ll_rotate(par);
    }
    avl<T> *balance(avl<T> *t)
    {
        int bal_factor = difference(t);
        if (bal_factor > 1)
        {
            if (difference(t->l) > 0)
            {
                t = ll_rotate(t);
            }
            else
            {
                t = lr_rotate(t);
            }
        }
        else if (bal_factor < -1)
        {
            if (difference(t->r) > 0)
            {
                t = rl_rotate(t);
            }
            else
            {
                t = rr_rotate(t);
            }
        }
        return t;
    }
    avl<T>* insert( avl<T>*r,T v)
    {
        if (r == NULL)
        {
            r = new avl<T>(v);
        }
        else if (v < r->d)
        {
            r->l = insert(r->l, v);
            r = balance(r);
        }
        else if (v >= r->d)
        {
            r->r = insert(r->r, v);
            r = balance(r);
        }
        return r;
    }
    void show(avl<T> *p, int l)
    {
        int i;
        if (p != NULL)
        {
            show(p->r, l + 1);
            cout << " ";
        }
        if (p == r)
        {
            cout << "Root ->";
        }
        for (int i = 0; i < l and p != r; i++)
        {
            cout << " " << p->d;
            show(p->l, l + 1);
        }
    }
    void inorder(avl<T> *t)
    {
        if (t == NULL)
        {
            return;
        }
        inorder(t->l);
        cout << t->d << " ";
        inorder(t->r);
    }
    void preorder(avl<T> *t)
    {
        if (t == NULL)
        {
            return;
        }
        cout << t->d << " ";
        preorder(t->l);

        preorder(t->r);
    }
    void postorder(avl<T> *t)
    {
        if (t == NULL)
        {
            return;
        }

        postorder(t->l);

        postorder(t->r);
        cout << t->d << " ";
    }
    avl_tree()
    {
        r = NULL;
    }
};
int main()
{
    int c, i;
    avl_tree<int> avl=avl_tree<int>();
    while (1)
    {
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.show Balanced AVL Tree" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.PreOrder traversal" << endl;
        cout << "5.PostOrder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            avl.r=avl.insert( avl.r,i);
            break;
        case 2:
            if (avl.r == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(avl.r, 1);
            cout << endl;
            break;
        case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(avl.r);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(avl.r);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(avl.r);
            cout << endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}
