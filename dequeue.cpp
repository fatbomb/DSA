#include<bits/stdc++.h>

using namespace std;
int const N=1e5;

class MycircularDequeue{
    int *arr;
    int cnt;
    int f;
    int l;
    int n;
    public:
    MycircularDequeue(int x=N){
        n=x;
        arr = new int[n];
        cnt=0;
        f=0;
        l=-1;
    }
    bool isEmpty(){
        return(!cnt);
    }
    bool isFull(){
        return(cnt==n);
    }
    void addFront(int x){
        if(cnt==n){
            cout<<"Q is full.\n";
            return;
        }
        if(f==0){
            f=n-1;
            arr[f]=x;
            cnt++;
            return;
        }
        f--;
        cnt++;
        arr[f]=x;

    }
    void addRear(int x){
        if(cnt==n){
            cout<<"Queue is full.\n";
            return;
        }
        l++;
        l%=n;
        arr[l]=x;
        cnt++;
    }
    void removeFront(){
        if(isEmpty()){
            cout<<"Empty Queue.\n";
            return;
        }
        cnt--;
        f++;
        f%=n;
    }
    void removeRear(){
        if(isEmpty()){
            cout<<"Empty Queue.\n";
            return;
        }
        cnt--;
        if(l==0){
            l=n-1;
        }
        else{
            l--;
        }
    }
    void display(){
        if (isEmpty())
        {
            return;
        }
        int i = f;
        while (i != l)
        {
            cout << arr[i] << " ";
            i++;
            i %= n;
        }
        cout << arr[l] << endl;
    }




};
int main(){
    MycircularDequeue deq= MycircularDequeue(5);
    deq.addFront(3);
    deq.addRear(4);
    deq.addRear(5);
    deq.display();
    deq.removeRear();
    deq.display();
    deq.addFront(2);
    deq.display();
    deq.removeFront();
    deq.display();
    cout<<deq.isEmpty()<<endl;
    return 0;
}