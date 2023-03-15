#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define endl "\n"
#define lp(n) for (ll i = 0; i < n; i++)
#define lp1(n) for (ll i = 1; i <= n; i++)
#define rlp(n) for (ll i = n - 1; i >= 0; i--)
#define pb(x) push_back(x)
#define f first
#define S second
#define in insert
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

ll const N = 1e5 + 7;
// ll ar[N];
// bool ar[N][N];
// bool ar[N];
// ll dp[1000005];
// vector <ll> graph[N];//no weight
vector<ll> g[N];
ll subsum[N], evensub[N], Bap[N];
ll mx_dpt = -1;
ll mx_node;
// vector <vector<ll>> cc;
// vector <ll> cur_cc;
ll cnt = 0;

void aro_govire_jao(ll v, ll bap=-1)
{
    /* Take action on vertex after entering
    the vertex */
    Bap[v]=bap;

    for (ll child : g[v])
    {
        if (child == bap)
        {
            continue;
        }
        /* Take action on child before entering
        the child node */
    
        aro_govire_jao(child, v);

        /* Take action on child after exiting
        the child node */
    }

    /* Take action on vertex before exiting
    the vertex */
}
vector <ll> rasta(ll v){
    vector<ll> uttor;
    while(v!=-1){
        uttor.pb(v);
        v=Bap[v];
    }
    reverse(uttor.begin(),uttor.end());
    return uttor;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n;

    lp(n - 1)
    {
        ll a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    aro_govire_jao(1);
    ll x,y,ans=0;
    cin>>x>>y;
    vector <ll> rasta_x=rasta(x);
    vector <ll> rasta_y=rasta(y);
    ll coto_rasta=min(rasta_x.size(),rasta_y.size());
    //cout<<coto_rasta<<endl;
    lp(coto_rasta){
        if(rasta_x[i]!=rasta_y[i]){
            break;

        }
        else{
            ans=rasta_x[i];
        }
    }
    cout<<ans<<endl;


   
    

    return 0;
}
