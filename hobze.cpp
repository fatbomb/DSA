#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,k;
    cin>>n>>k;
    if(n%2 and k%2) cout<<"Omda\n";
    else if(n%2 and k%2==0) cout<<"Omda\n";
    else if(n%2==0 and k%2) cout<<"Teemo\n";
    else{
        cout<<"Omda\n";
    }
}

int32_t main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    freopen("dotak.in", "r", stdin);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}