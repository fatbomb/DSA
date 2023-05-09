#include "queue.hpp"
#include "vector.hpp"
const int N=1e5;
int d[N],color[N],pre[N];

void BFS(Vector <int> g[],int n,int s){
    
    for(int i=0;i<=n;i++){
        color[i]=-1; //considered as white
        pre[i]=-1;
        d[i]=INT_MAX;
    }
    color[s]=0;//considered as gray
    d[s]=0;
    QueueLL<int> Q=QueueLL<int>();
    Q.enqueue(s);
    while(!Q.isEmpty()){
        int u= Q.front();
         //cout<<u<<" | ";
        Q.dequeue();
        for(int v:g[u]){
             //cout<<v<<" | ";
            if(color[v]==-1){
                color[v]=0;
                d[v]=d[u]+1;
                pre[v]=u;
                Q.enqueue(v);
                //cout<<v<<" "<<u<< " ";
            }
        }
        cout<<endl;
        color[u]=1;//considered as black.
    }


}
void print_path(int n){
    if(pre[n]==-1){
        cout<<n<<" ";
        return;
    }
    else{
        print_path(pre[n]);
        cout<<n<<" ";
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    //cout<<m<<endl;
    Vector<int> g[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        //cout<<m<<" "<<i<<endl;
        g[x].push_back(y);
        g[y].push_back(x);
        //cout<<x<<y<<endl;
        
    }
    BFS(g,n,1);
    print_path(7);
    cout<<endl;
    for (size_t i = 1; i <n+1; i++)
    {
        print_path(i);
        cout<<endl;
    }
    
    return 0;
}