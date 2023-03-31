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
int lca[100005][20];
int mn[100005][20];
int mx[100005][20];
ll depth[100005];
int parent[100005];
vector<pair<int,int>> adj[100005];
void dfs(int u, int p){
    parent[u]=p;
    for(auto v:adj[u]){
        if(v.first!=p){
            depth[v.first]=depth[u]+1;
            lca[v.first][0]=u;
            mn[v.first][0]=v.second;
            mx[v.first][0]=v.second;
            dfs(v.first,u);
        }
    }
}
// vector<pair<int,int>> adj[100005];
void run(){
    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        cout<<"Case "<<cnt++<<":\n";
        int n;
        cin>>n;
        for(int i=0;i<=n;i++){
            adj[i].clear();
        }
        for(int i=0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        memset(lca,-1,sizeof(lca));
        memset(mn,1e9,sizeof(mn));
        memset(mx,0,sizeof(mx));
        memset(depth,0,sizeof(depth));
        memset(parent,-1,sizeof(parent));
        dfs(1,0);
        for(int j=1;j<20;j++){
            for(int i=1;i<=n;i++){
                if(lca[i][j-1]!=-1){
                    lca[i][j]=lca[lca[i][j-1]][j-1];
                    mn[i][j]=min(mn[i][j-1],mn[lca[i][j-1]][j-1]);
                    mx[i][j]=max(mx[i][j-1],mx[lca[i][j-1]][j-1]);
                }
            }
        }
        int q;
        cin>>q;
        while(q--){
            int u,v;
            cin>>u>>v;
            if(depth[u]<depth[v]){
                swap(u,v);
            }
            int diff=depth[u]-depth[v];
            int ans1=0;
            int ans2=1e9;
            for(int i=0;i<20;i++){
                if(diff&(1<<i)){
                    ans1=max(ans1,mx[u][i]);
                    ans2=min(ans2,mn[u][i]);
                    u=lca[u][i];
                }
            }
            if(u==v){
                cout<<ans2<<" "<<ans1<<endl;
                continue;
            }
            for(int i=19;i>=0;i--){
                if(lca[u][i]!=lca[v][i]){
                    ans1=max(ans1,mx[u][i]);
                    ans2=min(ans2,mn[u][i]);
                    ans1=max(ans1,mx[v][i]);
                    ans2=min(ans2,mn[v][i]);
                    u=lca[u][i];
                    v=lca[v][i];
                }
            }
            ans1=max(ans1,mx[u][0]);
            ans2=min(ans2,mn[u][0]);
            ans1=max(ans1,mx[v][0]);
            ans2=min(ans2,mn[v][0]);
            cout<<ans2<<" "<<ans1<<endl;

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
