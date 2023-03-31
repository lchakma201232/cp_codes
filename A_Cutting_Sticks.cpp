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
// ll dp[1001][1001];
// ll getCount(vector<int> &arr, int l, int r){
//     // cerr<<l<<" "<<r<<endl;
//     if(l==r){
//         return 0;
//     }
//     if(l>r){
//         return LLONG_MAX;
//     }
//     if(dp[l][r]!=-1){
//         return dp[l][r];
//     }
//     ll minCost=LLONG_MAX;
//     bool flag=false;
//     for(auto &i:arr){
//         if(i>l && i<r){
//             minCost=min(minCost,getCount(arr,l,i)+getCount(arr,i,r)+r-l);
//             flag=true;
//         }
//     }
//     if(!flag){
//         minCost=0;
//     }
//     return dp[l][r]=minCost;
//     // return minCost;
// }
void run(){
    int l;
    while(cin>>l){
        if(l==0){
            break;
        }
        int n;
        cin>>n;
        vector<ll> arr(n);
        fora(i,n){
            cin>>arr[i];
        }
        arr.pb(0);
        arr.pb(l);
        vector<vector<ll>> dp(n+2,vector<ll>(n+2,1e9));
        fora(i,n+2){
            dp[i][i]=0;
            if(i<n+1) dp[i][i+1]=0;
        }
        sort(arr.begin(),arr.end());
        for(int i=n+1;i>=0;i--){
            for(int j=i+1;j<=n+1;j++){
                for(int k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+arr[j]-arr[i]);
                }
            }
        }
        cout<<"The minimum cutting is "<<dp[0][n+1]<<".\n";
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
