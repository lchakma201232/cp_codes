#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int is_prime=1;
    for(int i=2;i<n;i++){
        if(n%i==0){
            is_prime=0;
            break;
        }
    }
    if(is_prime){
        cout<<"Prime"<<endl;
    }
    else{
        cout<<"Not Prime"<<endl;
    }
}