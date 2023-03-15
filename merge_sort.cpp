#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void append(int arr[],int l, int r,int m){
    int i=l;
    int j=m+1;
    int temp[r-l+1];
    int k=0;
    while(i<=m and j<=r){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=m){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(i=l;i<=r;i++){
        arr[i]=temp[i-l];
    }

}

void merge_sort(int arr[],int l, int r){
    if(l<r){
        int m=(l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);

        append(arr,l,r,m);
    }
}

int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    merge_sort(ar,0,n-1);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;

}