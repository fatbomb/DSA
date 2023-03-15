#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
int const N=5000;
void swup(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void count_sort(int ar[],int ind){
    int count[10];
    int output[N];
    memset(count,0,sizeof count);
    for(int i=0;i<N;i++){
        count[(ar[i]/ind)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=N-1;i>=0;i--){
        output[--count[(ar[i]/ind)%10]]=ar[i];
    }
    for(int i=0;i<N;i++){
        ar[i]=output[i];
    }
}
void selection_sort(int ar[],int ind){
    for(int i=0;i<N-1;i++){
        int mi=((ar[i]/ind)%10);
        int k=i;
        for(int j=i+1;j<N;j++){
            if(((ar[j]/ind)%10)<mi){
                mi=((ar[j]/ind)%10);
                k=j;
            }
        }
        if(k!=i){
            swup(ar[i],ar[k]);
        }
    }
}
int partition(int ar[],int l, int r,int ind){
    int pivot=(ar[l]/ind)%10;
    int i=l-1;
    int j=r+1;
    while(true){
        i++;
        while((ar[i]/ind)%10<pivot){
            i++;
        }
        j--;
        while((ar[j]/ind)%10>pivot){
            j--;
        }
        if(i>=j){
            return j;
        }
        swup(ar[i],ar[j]);
    }
}
void quick_sort(int ar[],int l,int r,int ind){
    if(l<r){
        int pi=partition(ar,l,r,ind);
        quick_sort(ar,l,pi,ind);
        quick_sort(ar,pi+1,r,ind);
    }
}
void append(int ar[],int l, int r, int m, int ind){
    int temp[r-l+1];
    int i=l;
    int j=m+1;
    int k=0;
    while(i<=m and j<=r){
        if((ar[j]/ind)%10<(ar[i]/ind)%10){
            temp[k]=ar[j];
            j++;
        }
        else{
            temp[k]=ar[i];
            i++;
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
void radix_sort(int ar[],int ma){
    auto st=high_resolution_clock::now();
    for(int ind=1;ma/ind>0;ind*=10){
        count_sort(ar,ind);
    }
    auto end=high_resolution_clock::now();
    auto t=(duration_cast<microseconds>(end-st)).count()/1000.00;
    cout<<"Counting sort Taken Time: "<<t<<"ms"<<endl;
    for(int i=0;i<N;i++){
        cout<<ar[i]<<" ";
        if(i%10==9){
            cout<<endl;
        }
    }
    cout<<endl;
    st=high_resolution_clock::now();
    for(int ind=1;ma/ind>0;ind*=10){
        selection_sort(ar,ind);
    }
    end=high_resolution_clock::now();
    t=(duration_cast<milliseconds>(end-st)).count();
    cout<<"Selection sort Taken Time: "<<t<<"ms"<<endl;
    for(int i=0;i<N;i++){
        cout<<ar[i]<<" ";
        if(i%10==9){
            cout<<endl;
        }
    }
    cout<<endl;
    st=high_resolution_clock::now();
    for(int ind=1;ma/ind>0;ind*=10){
        quick_sort(ar,0,N-1,ind);
    }
    end=high_resolution_clock::now();
    t=(duration_cast<milliseconds>(end-st)).count();
    cout<<"Quick sort Taken Time: "<<t<<"ms"<<endl;
    for(int i=0;i<N;i++){
        cout<<ar[i]<<" ";
        if(i%10==9){
            cout<<endl;
        }
    }
    cout<<endl;
    st=high_resolution_clock::now();
    for(int ind=1;ma/ind>0;ind*=10){
        merge_sort(ar,0,N-1,ind);
    }
    end=high_resolution_clock::now();
    t=(duration_cast<milliseconds>(end-st)).count();
    cout<<"Merge sort Taken Time: "<<t<<"ms"<<endl;
    for(int i=0;i<N;i++){
        cout<<ar[i]<<" ";
        if(i%10==9){
            cout<<endl;
        }
    }
    cout<<endl;
    

}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ar[N];
    cin>>ar[0];
    int ma=ar[0];
    for(int i=1;i<5000;i++){
        cin>>ar[i];
        ma=max(ma,ar[i]);
    }
    radix_sort(ar,ma);


    return 0;
}