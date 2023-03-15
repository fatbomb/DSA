#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int partition(int arr[],int l, int r){
    int p=arr[l];
    int i=l-1;
    int j=r+1;
    //cout<<i<<" "<<j<<endl;
    while(1){
        i++;
        while(arr[i]<p){
            i++;
        }
        j--;
        while(arr[j]>p){
            j--;
            //cout<<j<<" ";
        }
        for(int k=l;k<=r;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        if(i>=j){
            return j;
        }
        swap(arr[i],arr[j]);
    }
    return -1;
}
int part(int arr[],int l, int r){
    int pi=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        
        if(arr[j]<pi){
            i++;
            swap(arr[i],arr[j]);
        }
        for(int k=l;k<=r;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quick_sort(int arr[],int l,int r){
    if(l<r){
    int pi=partition(arr,l,r);
    //cout<<pi<<endl;
    quick_sort(arr,l,pi);
    quick_sort(arr,pi+1,r);
    }

}
void quickSort(int arr[],int l, int r){
    if(l<r){
        int pi=part(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main(){
    int n;
    cin>>n;
    int ar[n],br[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
        br[i]=ar[i];
    }
    quick_sort(ar,0,n-1);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl<<endl;;
    quickSort(br,0,n-1);
    for(int i=0;i<n;i++){
        cout<<br[i]<<" ";
    }
    cout<<endl;


}