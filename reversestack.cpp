#include "stack.hpp"
void insertAtbottom(StackV1_1 &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;

    }
    int tople=st.top();
    st.pop();
    insertAtbottom(st,ele);
    st.push(tople);
}

void reverse(StackV1_1 &st){
    if(st.empty()){
        return;
    }
    int ele =st.top();
    st.pop();
    reverse(st);
    insertAtbottom(st,ele);
}
int main(){
    StackV1_1 st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        st.push(i+1);
    }
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}