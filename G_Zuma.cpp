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
ll dp[501][501];
ll getCount(vector<int> &arr, int l,int r, vector<vector<int>> &pos){
    if(l>=r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int cur=lower_bound(pos[arr[l]].begin(),pos[arr[l]].end(),l)-pos[arr[l]].begin();
    auto &ans=dp[l][r]=1e9;
    for(int i=cur+1;i<pos[arr[l]].size();i++){
        if(pos[arr[l]][i]>r)break;
        int next=pos[arr[l]][i];
        ans=min(ans,getCount(arr,l+1,next-1,pos)+getCount(arr,next+1,r,pos)+(next+1<=r));
    }
    ans=min(ans,getCount(arr,l+1,r,pos)+1);
    return ans;
}
void run(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<int> arr(n);
    vector<vector<int>> pos(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pos[arr[i]].push_back(i);
    }
    cout<<getCount(arr,0,n-1,pos)+1<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
