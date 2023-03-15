#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
int  N=5000;
void append(int ar[],int l, int r, int m,int ind){
    int temp[r-l+1];
    int i=l;
    int j=m+1;
    int k=0;
    while(i<=m and j<=r){
        if((ar[i]/ind)%10<=(ar[j]/ind)%10){
            temp[k]=ar[i];
            i++;
        }
        else{
            temp[k]=ar[j];
            j++;
        }
        k++;
    }
    while(i<=m){
        temp[k]=ar[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=ar[j];
        j++;
        k++;
    }
    for(int i=l;i<=r;i++){
        ar[i]=temp[i-l];
    }

}
void merge_sort(int ar[],int l, int r,int ind){
    if(l<r){
        int m=(l+r)/2;
        merge_sort(ar,l,m,ind);
        merge_sort(ar,m+1,r,ind);
        append(ar,l,r,m,ind);
    }
}
void bucketSort(int ar[],int ind){
    int v[3][N];
    int a=0,b=0,c=0;
    for(int i=0;i<N;i++){
        int z=(ar[i]/ind)%10;
        if(z<=3){
            v[0][a]=ar[i];
            a++;
        }
        else if(z<=6){
            v[1][b]=ar[i];
            b++;
        }
        else{
            v[2][c]=ar[i];
            c++;
        }

    }
    int k=0;
    if(a!=0){
        merge_sort(v[0],0,a-1,ind);
        for(int i=0;i<a;i++){
            ar[k]=v[0][i];
            k++;
        }
    }
    if(b!=0){
        merge_sort(v[1],0,b-1,ind);
        for(int i=0;i<b;i++){
            ar[k]=v[1][i];
            k++;
        }
    }
    if(c!=0){
        merge_sort(v[2],0,c-1,ind);
        for(int i=0;i<c;i++){
            ar[k]=v[2][i];
            k++;
        }
    }
    

}
void radix_sort(int ar[],int ma){
    auto st=high_resolution_clock::now();
    for(int ind=1;ma/ind>0;ind*=10){
        bucketSort(ar,ind);
    }
    auto end=high_resolution_clock::now();
    auto t=(duration_cast<microseconds>(end-st)).count()/1000.00;
    cout<<"Bucket sort Taken Time: "<<t<<"ms"<<endl;
    for(int i=0;i<N;i++){
        cout<<ar[i]<<" ";
        if(i%10==9){
            cout<<endl;
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ar[N];
    cin>>ar[0];
    int ma=ar[0];
    for(int i=1;i<N;i++){
        cin>>ar[i];
        ma=max(ma,ar[i]);
    }
    radix_sort(ar,ma);


    return 0;
}