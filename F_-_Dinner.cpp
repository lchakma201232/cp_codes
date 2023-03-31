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
ll dp[101][101][101];
ll getCount(string s, int l, int r,int count,vector<vector<int>> &pos,int k){
    if(l>r){
        return count>=k;
    }
    if(dp[l][r][count]!=-1){
        return dp[l][r][count];
    }
    int curr=lower_bound(pos[s[l]-'G'].begin(),pos[s[l]-'G'].end(),l)-pos[s[l]-'G'].begin();
    auto &res = dp[l][r][count]=1e9;
    for(int i=curr+1;i<pos[s[l]-'G'].size();i++){
        if(pos[s[l]-'G'][i]>r){
            break;
        }
        int next=pos[s[l]-'G'][i];
        res=min(res,getCount(s,l+1,next-1,0,pos,k)+getCount(s,next,r,count+1,pos,k));
    }
    if(count+1>=k|| count==0) res=min(res,1+getCount(s,l+1,r,0,pos,k));
    return res;

}
void run(){
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<int>> pos(2);
    for(int i=0;i<n;i++){
        pos[s[i]-'G'].push_back(i);
    }
    ll res=getCount(s,0,n-1,0,pos,k);
    cout<<(res>=1e9?-1:res)<<endl;

}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
