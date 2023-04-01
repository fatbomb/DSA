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
        this->n = x+1;
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
    void minHeapify(int i){
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if(l<=cnt and har[l]<har[i]){
            smallest=l;
        }
        if(r<=cnt and har[r]<har[smallest]){
            smallest=r;
        }
        if(smallest!=i){
            Swap(har[i],har[smallest]);
            minHeapify(smallest);
        }
    }
    int extractMin(){
        if(this->cnt<1){
            return INT_MAX;
        }
        if(cnt==1){
            return har[cnt];
            cnt--;
        }
        int root=har[1];
        har[1]=har[cnt];
        cnt--;
        minHeapify(1);

        return root;


    }
    void deleteKey(int i){
        decreaseKey(i,INT_MIN);
        extractMin();
    }
    int getMin(){
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
        this->n = x+1;
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
    void maxHeapify(int i){
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if(l<=cnt and har[l]>har[i]){
            smallest=l;
        }
        if(r<=cnt and har[r]>har[smallest]){
            smallest=r;
        }
        if(smallest!=i){
            Swap(har[i],har[smallest]);
            maxHeapify(smallest);
        }
    }
    int extractMax(){
        if(this->cnt<1){
            return INT_MIN;
        }
        if(cnt==1){
            return har[cnt];
            cnt--;
        }
        int root=har[1];
        har[1]=har[cnt];
        cnt--;
        maxHeapify(1);

        return root;


    }
    void deleteKey(int i){
        increaseKey(i,INT_MAX);
        extractMax();
    }
    int getMax(){
        return har[1];
    }
};
void heapify(int ar[],int n, int i){
    int largest =i;
    int left = 2*i+1;
    int right = 2*i +2;
    if(left<n and ar[left]>ar[largest]){
        largest = left;
    
    }
    if(right <n and ar[right]>ar[largest]){
        largest=right;
    }
    if(largest!=i){
        Swap(ar[i],ar[largest]);
        heapify(ar,n,largest);
    }

}
void heapsort(int ar[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(ar,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(ar[0],ar[i]);
        heapify(ar,i,0);
    }
}
int main()
{
    MaxHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMax() << " ";
    cout << h.getMax() << " ";
    h.increaseKey(2, 16);
    cout << h.getMax()<<endl;
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    heapsort(ar,n);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return 0;
}