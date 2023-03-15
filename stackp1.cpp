#include "stack.hpp"
void reverseSentence(string s){
    StackV1_1_S st=StackV1_1_S();
    for(int i=0;i<s.size();i++){
        string w="";
        while(s[i]!=' '&& i<s.length()){
            w+=s[i];
            i++;
        }
        st.push(w);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
     
}

int main(){
    string s;
    getline(cin,s);
    reverseSentence(s);
}