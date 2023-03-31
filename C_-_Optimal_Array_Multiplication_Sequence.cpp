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
struct matrix{
    int r,c;
    string s;
};
struct tcost{
    matrix t;
    ll cost;
    bool operator < (const tcost &a) const{
        return cost<a.cost;
    }
};
vector<matrix> v;
bool vis[100][100];
tcost dp[100][100];
tcost getMinMat(int l, int r){
    if(l==r){
        return {v[l],0};
    }
    if(vis[l][r]){
        return dp[l][r];
    }
    vis[l][r]=1;
    tcost ans;
    ans.cost=1e18;
    for(int i=l;i<r;i++){
        tcost lcost=getMinMat(l,i);
        tcost rcost=getMinMat(i+1,r);
        tcost tans;
        tans.t.r=lcost.t.r;
        tans.t.c=rcost.t.c;
        tans.t.s="("+lcost.t.s+" x "+rcost.t.s+")";
        tans.cost=lcost.cost+rcost.cost+lcost.t.r*lcost.t.c*rcost.t.c;
        if(tans<ans){
            ans=tans;
        }

    }
    return dp[l][r]=ans;
}
void run(){
    int n;
    int casee=1;
    while(cin>>n){
        if(n==0)break;
        v.clear();
        v.resize(n);
        memset(vis,0,sizeof(vis));
        cout<<"Case "<<casee++<<": ";
        fora(i,n){
            cin>>v[i].r>>v[i].c;
            v[i].s="A"+to_string(i+1);
        }
        tcost ans=getMinMat(0,n-1);
        cout<<ans.t.s<<endl;
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
