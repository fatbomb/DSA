//implementation of radix sort algorithm

/* Radix sort is a fast sorting algorithm that is used to sort an array by sorting digit to digit.
It is used to sort an array where all elements are within a range when the range is much bigger for 
count sort to sort within linear time. It uses counting sort as a sub routine.

Time Complexity: O(n*d)
Space Complexity:O(n)

n=total number of elements of array
d=number of digits in the max number
*/

#include<bits/stdc++.h>
using namespace std;

void counting_sort(int n,int exp,int arr[])
{
    int out[n];
    int count[10];

    memset(count,0,sizeof(count));

    for(int i=0;i<n;i++)

    {
        int x=(arr[i]/exp)%10;
        cout<<x<<" ";
        count[(arr[i]/exp)%10]++;
    }
    cout<<endl;

    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    
    //for stable sort
    for(int i=n-1;i>=0;i--)
    {
       out[count[(arr[i]/exp)%10]-1]=arr[i];
       count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=out[i];
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void radix_sort(int n,int max,int arr[])
{
    for(int exp=1;max/exp>0;exp*=10)
    {
        counting_sort(n,exp,arr);
    }
}
int main(int argc, const char** argv) {
    int n;
    cin>>n;
    int ar[n];
    cin>>ar[0];
    int ma=ar[0];
    for(int i=1;i<n;i++){
        cin>>ar[i];
        ma=max(ar[i],ma);
    }
    radix_sort(n,ma,ar);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return 0;
}


