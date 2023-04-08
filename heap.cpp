#include <bits/stdc++.h>

using namespace std;

void Swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap
{
    int *har;
    int n;
    int cnt;

public:
    MinHeap(int x)
    {
        this->n = x + 1;
        this->cnt = 0;
        har = new int[x + 1];
    }
    int parent(int i)
    {
        return (i / 2);
    }
    int left(int i)
    {
        return (i * 2);
    }
    int right(int i)
    {
        return (i * 2) + 1;
    }
    void insertKey(int k)
    {
        if (cnt == n - 1)
        {
            cout << "\nOverflow: Couldn't insert key.\n";
            return;
        }
        cnt++;
        har[cnt] = k;
        int i = cnt;
        while (i != 1 and har[parent(i)] > har[i])
        {
            Swap(har[i], har[parent(i)]);
            i = parent(i);
        }
    }
    void decreaseKey(int i, int val)
    {
        har[i] = val;
        while (i != 1 and har[parent(i)] > har[i])
        {
            Swap(har[i], har[parent(i)]);
            i = parent(i);
        }
    }
    void minHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l <= cnt and har[l] < har[i])
        {
            smallest = l;
        }
        if (r <= cnt and har[r] < har[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            Swap(har[i], har[smallest]);
            minHeapify(smallest);
        }
    }
    int extractMin()
    {
        if (this->cnt < 1)
        {
            return INT_MAX;
        }
        if (cnt == 1)
        {
            return har[cnt];
            cnt--;
        }
        int root = har[1];
        har[1] = har[cnt];
        cnt--;
        minHeapify(1);

        return root;
    }
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    int getMin()
    {
        return har[1];
    }
};
class MaxHeap
{
    int *har;
    int n;
    int cnt;

public:
    MaxHeap(int x)
    {
        this->n = x + 1;
        this->cnt = 0;
        har = new int[x + 1];
    }
    int parent(int i)
    {
        return (i / 2);
    }
    int left(int i)
    {
        return (i * 2);
    }
    int right(int i)
    {
        return (i * 2) + 1;
    }
    void insertKey(int k)
    {
        if (cnt == n - 1)
        {
            cout << "\nOverflow: Couldn't insert key.\n";
            return;
        }
        cnt++;
        har[cnt] = k;
        int i = cnt;
        while (i != 1 and har[parent(i)] < har[i])
        {
            Swap(har[i], har[parent(i)]);
            i = parent(i);
        }
    }
    void increaseKey(int i, int val)
    {
        har[i] = val;
        while (i != 1 and har[parent(i)] < har[i])
        {
            Swap(har[i], har[parent(i)]);
            i = parent(i);
        }
    }
    void maxHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l <= cnt and har[l] > har[i])
        {
            smallest = l;
        }
        if (r <= cnt and har[r] > har[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            Swap(har[i], har[smallest]);
            maxHeapify(smallest);
        }
    }
    int extractMax()
    {
        if (this->cnt < 1)
        {
            return INT_MIN;
        }
        if (cnt == 1)
        {
            return har[cnt];
            cnt--;
        }
        int root = har[1];
        har[1] = har[cnt];
        cnt--;
        maxHeapify(1);

        return root;
    }
    void deleteKey(int i)
    {
        increaseKey(i, INT_MAX);
        extractMax();
    }
    int getMax()
    {
        return har[1];
    }
};
void heapify(int ar[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n and ar[left] > ar[largest])
    {
        largest = left;
    }
    if (right < n and ar[right] > ar[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        Swap(ar[i], ar[largest]);
        heapify(ar, n, largest);
    }
}
void heapsort(int ar[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ar, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(ar[0], ar[i]);
        heapify(ar, i, 0);
    }
}
template <typename T>
class Node
{
public:
    T value;
    Node *parent;
    Node *child;
    Node *sibling;
    int degree;
    bool marked;
    Node()
    {
        this->degree = 0;
        this->parent = this->child = this->sibling = NULL;
    }
    Node(T value)
    {
        this->value = value;
        this->parent = NULL;
        this->child = NULL;
        this->sibling = NULL;
        this->degree = 0;
        this->marked = false;
    }
};
template <typename T>
class BinomialHeap
{
private:
    Node<T> *Root;
    Node<T> *min;
    void linkTrees(Node<T> *y, Node<T> *z)
    {
        y->parent = z;
        y->sibling = z->child;
        z->child = y;
        z->degree = z->degree + 1;
    }
    Node<T> *mergeRoots(BinomialHeap<T> *x, BinomialHeap<T> *y)
    {
        Node<T> *ret = new Node<T>();
        Node<T> *end = ret;

        Node<T> *L = x->Root;
        Node<T> *R = y->Root;
        if (L == NULL)
        {
            return R;
        }
        if (R == NULL)
        {
            return L;
        }
        while (L != NULL or R != NULL)
        {
            if (L == NULL)
            {
                end->sibling = R;
                end = end->sibling;
                R = R->sibling;
            }
            else if (R == NULL)
            {
                end->sibling = L;
                end = end->sibling;
                L = L->sibling;
            }
            else
            {
                if (L->degree < R->degree)
                {
                    end->sibling = L;
                    end = end->sibling;
                    L = L->sibling;
                }
                else
                {
                    end->sibling = R;
                    end = end->sibling;
                    R = R->sibling;
                }
            }
        }
        return ret->sibling;
    }
    // int count;
public:
    BinomialHeap()
    {
        this->Root = NULL;
    }
    BinomialHeap(Node<T> *x)
    {
        this->Root = x;
    }
    bool isEmpty()
    {
        return (this->Root == NULL);
    }
    void insert(Node<T> *x)
    {
        this->merge(new BinomialHeap(x));
    }
    void merge(BinomialHeap<T> *bh)
    {
        BinomialHeap<T> *H = new BinomialHeap<T>();
        H->Root = mergeRoots(this, bh);
        if (H->Root == NULL)
        {
            this->Root = NULL;
            this->min = NULL;
            return;
        }
        Node<T> *prevX = NULL;
        Node<T> *x = H->Root;
        Node<T> *nextX = x->sibling;
        while (nextX != NULL)
        {
            if (x->degree != nextX->degree or (nextX->sibling != NULL and nextX->sibling->degree == x->degree))
            {
                prevX = x;
                x = nextX;
            }
            else if (x->value <= nextX->value)
            {
                x->sibling = nextX->sibling;
                linkTrees(nextX, x);
            }
            else
            {
                if (prevX == NULL)
                    H->Root = nextX;
                else
                    prevX->sibling = nextX;
                linkTrees(x, nextX);
                x = nextX;
            }
            nextX = x->sibling;
        }
        this->Root = H->Root;
        this->min = H->Root;
        Node<T> *cur = this->Root;
        while (cur != NULL)
        {
            if (cur->value < this->min->value)
                this->min = cur;
            cur = cur->sibling;
        }
    }
    Node<T> *first(){
        return this->min;
    }
    Node<T> *extractMin(){
        Node<T> *ret= this->first();

        Node<T> *prevX=NULL;
        Node<T> *x=this->Root;
        while(x!=ret){
            prevX=x;
            x=x->sibling;
        }
        if(prevX==NULL) this->Root=x->sibling;
        else prevX->sibling = x->sibling;

        Node<T> *revchd=NULL;
        Node<T> *cur=ret->child;
        while(cur!=NULL){
            Node<T> *next =cur->sibling;
            cur->sibling= revchd;
            revchd=cur;
            cur=next;
        }
        BinomialHeap<T> *H= new BinomialHeap();
        H->Root=revchd;
        this->merge(H);

        return ret;

    }
    void decreaseKey(Node<T> *x, int newkey){
        x->value=newkey;
        Node<T> *y=x;
        Node<T> *z=y->parent;
        while(z!=NULL and y->value<z->value){
            swap(y->value, z->value);
            y=z;
            z=y->parent;
        }
        if(y->value< this->min->value) this->min=y;
    }
    void Delete(Node<T> *x){
        decreaseKey(x,INT_MIN);
        extractMin();
    }
};
int main()
{
    // MaxHeap h(11);
    // h.insertKey(3);
    // h.insertKey(2);
    // h.deleteKey(2);
    // h.insertKey(15);
    // h.insertKey(5);
    // h.insertKey(4);
    // h.insertKey(45);
    // cout << h.extractMax() << " ";
    // cout << h.getMax() << " ";
    // h.increaseKey(2, 16);
    // cout << h.getMax() << endl;
    // int n;
    // cin >> n;
    // int ar[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> ar[i];
    // }
    // heapsort(ar, n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ar[i] << " ";
    // }
    // cout << endl;
    BinomialHeap<string> *bh=new BinomialHeap<string>();
    string a[6]={"dip", "dipto","nill","siam","ayondip","arnob"};
    Node<string> *x= new Node(a[0]);
    Node<string> *y=new Node(a[1]);
    bh->insert(x);
    bh->insert(y);
    bh->insert(new Node<string>(a[2]));
    bh->insert(new Node<string>(a[3]));
    bh->insert(new Node<string>(a[4]));
    bh->insert(new Node<string>(a[5]));

    //bh->decreaseKey(x,2);
    while (!bh->isEmpty())
    {
        cout<<bh->extractMin()->value<<" ";
    }
    cout<<endl;

    

    return 0;
}