#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int main(){
    freopen("input.txt","w",stdout);
    srand((unsigned) time(NULL));
    for(int i=0;i<5000;i++){
        int random = 10000+(rand()%90000);
        cout<<random<<" ";
        if(i%10==9 ){
            cout<<endl;
        }
    }

    return 0;
}