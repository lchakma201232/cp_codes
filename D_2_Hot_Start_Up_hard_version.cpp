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
/*struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it)
            if(*it!=' ')
                b+=*it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
ll siev_arr[mXI];
void siev(ll n)
{
    siev_arr[0] = siev_arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!siev_arr[i])
        {
            cout<<i<<endl;
            for (int j = i + i; j <= n; j += i)
            {
                siev_arr[j] = 1;
            }
        }
    }
}

int dfs(int v, int *arr, int *visited){
    if(visited[arr[v]]){
        return arr[v]=arr[arr[v]];
    }
    visited[v]=1;
    return arr[v]=dfs(arr[v],arr,visited);
}*/

void run(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<ll> arr;
        fora(i,n){
            int x;
            cin>>x;
            arr.pb(x);
        }
        vector<ll> hot, cold;
        hot.push_back(0);
        cold.push_back(0);
        fora(i,k){
            int x;
            cin>>x;
            cold.pb(x);
        }
        fora(i,k){
            int x;
            cin>>x;
            hot.pb(x);
        }
        vector<ll> dp(k+1,1e18);
        dp[0]=0;
        int last=0;
        for(auto &x:arr){
            vector<ll> temp(k+1,1e18);
            if(last==x){
                for(int i=0;i<=k;i++){
                    temp[i]=min(temp[i],dp[i]+hot[x]);
                    temp[x]=min(temp[x],dp[i]+cold[x]);
                    
                }
                temp[x]=min(temp[x],dp[x]+hot[x]);
            }else{
                for(int i=0;i<=k;i++){
                    temp[i]=min(temp[i],dp[i]+cold[x]);
                    temp[last]=min(temp[last],dp[i]+cold[x]);
                }
                temp[last]=min(temp[last],dp[x]+hot[x]);
            }
            last=x;
            dp=temp;
        }
        ll ans=1e18;
        for(auto &x:dp){
            ans=min(ans,x);
        }
        cout<<ans<<endl;
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
