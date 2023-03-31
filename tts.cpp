#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)  {cout<<"-->"<<#A<<"=\n";for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n)      {cout<<"-->"<<#A<<"=(";for(int i = 0; i < n; i++)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...)    {string sss(#args);sss+=',';cout<<"-->";debugger::call(sss.begin(), sss.end(), args);cout<<"\n";}
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I,n) for(int I=0; I<n;I++)
#define forb(I,n) for(int I=1; I<=n;I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mkp(a,b) make_pair(a,b)
using namespace std;

int dp[100][100];
bool can(int l,int r, map<int,int> &mp,map<int,int> &top,map<int,int> &bottom){
    if(r-l<1){
        return false;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    bool res=true;
    for(int i=l;i<r;i++){
        if(!mp[i] && !mp[i+1]){
            if((top[i] && bottom[i+1]) || (top[i+1] && bottom[i])) continue;
            res=min(max(can(l,i-1,mp,top,bottom),can(i+2,r,mp,top,bottom)),res);
        }
        if(res==false) break;
    }
    return dp[l][r]=!res;
}

void run(){
    int t;
    cin>>t;
    int cassee=1;
    while(t--){
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<cassee++<<": ";
        int n;
        cin>>n;
        map<int,int> top,bottom,mp;
        fora(i,3){
            fora(j,n){
                char x;
                cin>>x;
                if(i==0 && x=='X'){
                    top[j]=1;
                }else if(i==1 && x=='X'){
                    mp[j]=1;
                }else if(i==2 && x=='X'){
                    bottom[j]=1;
                }
                if(top[j] && bottom[j]) mp[j]=1;
            }
        }
        bool res=can(0,n-1,mp,top,bottom);
        if(res){
            cout<<"Jhinuk\n";
        }else{
            cout<<"Grandma\n";
        }
    }
}


int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
