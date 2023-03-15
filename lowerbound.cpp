#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int lower_bound(int ar[], int n, int x)
{
    int l, h, m;
    l = 0, h = n;
    while (l < h)
    {
        m = l + (h - l) / 2;
        if (x <= ar[m])
            h = m;
        else{
            l=m+1;
        }

    }
    if(l<n and ar[l]<x){
        l++;
    }
    return l;
}
int uper_bound(int ar[], int n, int x)
{
    int l, h, m;
    l = 0, h = n;
    while (l < h)
    {
        m = l + (h - l) / 2;
        if (x < ar[m])
            h = m;
        else{
            l=m+1;
        }

    }
    if(l<n and ar[l]<=x){
        l++;
    }
    return l;
}
int main(){
    int ar[7]={1,2,3,5,8,9,9};
    cout<<uper_bound(ar,7,5)<<endl;


}