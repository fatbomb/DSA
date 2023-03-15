#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void countngsort(ll ar[], ll n)
{
    ll k = ar[0];

    for (ll i = 1; i < n; i++)
    {
        k = max(k, ar[i]);
    }
    ll count[k + 1];
    memset(count, 0, sizeof count);
    for (ll i = 0; i < n; i++)
    {
        count[ar[i]]++;
    }
    for (ll i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }
    ll output[n];
    for (ll i = n - 1; i >= 0; i--)
    {
        output[--count[ar[i]]] = ar[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ar[i] = output[i];
    }
}
void countingSortmi(ll ar[], ll n)
{
    ll k = ar[0];
    ll p = k;

    for (ll i = 1; i < n; i++)
    {
        k = max(k, ar[i]);
        p = min(p, ar[i]);
    }
    ll z=k-p+1;
    ll count[z];
    memset(count, 0, sizeof count);
    for (ll i = 0; i < n; i++)
    {
        count[ar[i]-p]++;
    }
    //cout<<count[0]<<" ";
    for (ll i = 1; i < z; i++)
    {
        count[i] += count[i - 1];
        //cout<<count[i]<<" ";
    }
    //cout<<endl;

    ll output[n];
    for (ll i = n - 1; i >= 0; i--)
    {
        output[--count[ar[i]-p]] = ar[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ar[i] = output[i];
    } 
}
int main()
{
    ll n, b = 0;
    cin >> n;
    ll ar[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
        if (ar[i] < 0)
        {
            b = 1;
        }
    }
    if (b)
    {
        countingSortmi(ar, n);
    }
    else
        countngsort(ar, n);

    for (ll i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}