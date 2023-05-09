#include <bits/stdc++.h>
#include "vector.hpp"

using namespace std;
const int N=1e5;
int d[N], pre[N];
bool vis[N];

void dfs(Vector<int> g[], int v){
    vis[v]=true;
    for(int child: g[v]){
        if(!vis[child]){
            pre[child]=v;
            d[child]=d[v]+1;
            dfs(g,child);
        }
    }

}
void print_path(int v){
    if(pre[v]==-1){
        cout<<v<<" ";
        return;
    }
    print_path(pre[v]);
    cout<<v<<" ";
}
int main(int argc, const char** argv) {
    int n,m;
    cin>>n>>m;
    Vector<int> g[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        pre[i]=-1;
        vis[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(g,i);
        }
    }
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        print_path(i+1);
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
