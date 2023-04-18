#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void swup(ll &a, ll &b)
{
    ll t = a;
    a = b;
    b = t;
}

void boubleSort(ll ar[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n - i; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(ar[j], ar[j + 1]);
            }
        }
    }
}
void selectionSort(ll ar[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        ll mi = i;
        for (ll j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[mi])
            {
                mi = j;
            }
        }
        if (mi != i)
        {
            swup(ar[mi], ar[i]);
        }
    }
}
void insertionSort(ll ar[], ll n)
{
    for (ll i = 1; i < n; i++)
    {
        ll j = i;
        while (j > 0 and ar[j] < ar[j - 1])
        {
            swup(ar[j], ar[j - 1]);
            j--;
        }
    }
}
void merge(ll ar[], ll l, ll r, ll m)
{
    ll i = l, j = m + 1, k = 0, tep[r - l + 1];
    while (i <= m and j <= r)
    {
        if (ar[i] < ar[j])
        {
            tep[k] = ar[i];
            i++;
        }
        else
        {
            tep[k] = ar[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
        tep[k] = ar[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        tep[k] = ar[j];
        j++;
        k++;
    }
    for (ll i = l; i <= r; i++)
    {
        ar[i] = tep[i - l];
    }
}
void mergesort(ll ar[], ll l, ll r)
{
    if (l < r)
    {
        ll m = (l + r) / 2;
        mergesort(ar, l, m);
        mergesort(ar, m + 1, r);
        merge(ar, l, r, m);
    }
}
ll partition(ll ar[], ll l, ll r)
{
    ll p = ar[r];
    ll i = l - 1;
    for (ll j = l; j < r; j++)
    {
        if (ar[j] < p)
        {
            i++;
            swup(ar[i], ar[j]);
        }
    }
    swup(ar[i + 1], ar[r]);
    return i + 1;
}
ll part(ll ar[], ll l, ll r)
{
    ll p = ar[l];
    ll i = l - 1;
    ll j = r + 1;
    while (1)
    {
        i++;
        while (ar[i] < p)
        {
            i++;
        }
        j--;
        while (ar[j] > p)
        {
            j--;
        }
        if (i >= j)
        {
            return j;
        }
        swup(ar[i], ar[j]);
    }
    return -1;
}
void quickSort(ll ar[], ll l, ll r)
{
    if (l < r)
    {
        ll p = partition(ar, l, r);
        quickSort(ar, l, p - 1);
        quickSort(ar, p + 1, r);
    }
}
void quicksort(ll ar[], ll l, ll r)
{
    if (l < r)
    {
        ll p = part(ar, l, r);
        quickSort(ar, l, p);
        quickSort(ar, p + 1, r);
    }
}
int main()
{
    ll n;
    cin >> n;
    ll ar[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    // boubleSort(ar,n);
    // selectionSort(ar,n);
    // insertionSort(ar,n);
    // mergesort(ar,0,n-1);
    // quickSort(ar,0,n-1);
    quicksort(ar, 0, n - 1);
    for (ll i = 0; i < n; i++)
    {
        cout << ar[i] << "  ";
    }
    cout << endl;
}