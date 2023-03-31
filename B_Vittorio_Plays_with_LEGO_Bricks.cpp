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
// ll dp[301][2];
// ll getCount(vector<int> &arr, int i, int h, bool ok=false){
//     if(i==arr.size()){
//         return ok?0:1e9;
//     }
//     if(dp[i][ok]!=-1){
//         return dp[i][ok];
//     }
//     ll ans=1e9;
//     ll t1=-1,t2=-1,t3=-1,t4=-1;
//     if(ok){
//         t1=getCount(arr,i+1,h,1)+h;
//         t2=getCount(arr,i+1,h,0);
//         // cout<<i<<" "<<t1<<" "<<t2<<endl;
//         ans=min(ans,getCount(arr,i+1,h,1)+h);
//         ans=min(ans,getCount(arr,i+1,h,0));
//     }
//     if(i>0){
//         int diff=arr[i]-arr[i-1]-1;
//         int blocks=(diff/2) + (diff/2)+1;
//         int height=diff/2+1;
//         if(height<=h){
//             t3=getCount(arr,i+1,h,ok)+blocks;
//             t4=getCount(arr,i+1,h,1)+blocks+h-height;
//             // cout<<i<<" "<<t3<<" "<<t4<<endl;
//             ans=min(ans,getCount(arr,i+1,h,ok)+blocks);
//             // cout<<h-height<<endl;
//             ans=min(ans,getCount(arr,i+1,h,1)+blocks+h-height);
//         }
//         if(height>h && !ok){
//             return 1e9;
//         }
//     }
//     // cout<<i<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
//     return dp[i][ok]=ans;
//     // return ans;
// }

void run(){
    int n,h;
    cin>>n>>h;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n,1e18));
    for(int i=0;i<n;i++){
        dp[i][i]=h;
    }
    for(int l=n-1;l>=0;l--){
        for(int r=l+1;r<n;r++){
            for(int m=l;m<r;m++){
                dp[l][r]=min(dp[l][r],dp[l][m]+dp[m+1][r]-max(0LL,h+1-(arr[r]-arr[l]+1)/2));
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
