#include "queue.hpp"

void reversequeue(Queue_string &q){
    if(q.empty()){
        return;
    }
    string s=q.front();
    q.pop();
    reversequeue(q);
    q.push(s);
}
/* Circular_Queue smallx(Circular_Queue &q,int k){
    Circular_Queue r,p;
    int sum=0,z=q.size(),c=0;
    while(q.size()>0){
        if((sum+q.front())<=k){
            //cout<<q.front()<<"q ";
            sum+=q.front();
            p.push(q.front());
            q.pop();
            
        }
        else{
            if(p.size()<z and sum==k){
                // Queue temp;
                // while(!p.empty()){
                //     r.push(p.front());
                //     temp.push(p.front());
                //     p.pop();
                // }
                // p=temp;
                r=p;
            }
            //cout<<p.front()<<"p ";
            sum-=p.front();
            p.pop();
            
        }
        
        
    }
    //cout<<endl;
    //cout<<r.size()<<endl;
    //p.display();
    r.display();
    return r;



} */
Queue smallx(Queue &q,int k){
    Queue r,p;
    int sum=0,z=q.size(),c=0;
    while(q.size()>0){
        if((sum+q.front())<=k){
            //cout<<q.front()<<"q ";
            sum+=q.front();
            p.push(q.front());
            q.pop();
            
        }
        else{
            if(p.size()<z and sum==k){
                // Queue temp;
                // while(!p.empty()){
                //     r.push(p.front());
                //     temp.push(p.front());
                //     p.pop();
                // }
                // p=temp;
                r=p;
            }
            //cout<<p.front()<<"p ";
            sum-=p.front();
            p.pop();
            
        }
        
        
    }
    //cout<<endl;
    //cout<<r.size()<<endl;
    //p.display();
    r.display();
    return r;



}

int main(){
    Queue q;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        q.push(x);
    }
    cin>>k;
    //q.display();
    Queue p = smallx(q,k);
    //p.display();
    cout<<p.size();
    // while(!p.empty()){
    //     cout<<p.front()<<" ";
    //     p.pop();
    // }
    cout<<endl;

    

}