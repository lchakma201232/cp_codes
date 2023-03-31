#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)                  \
    {                                   \
        cout << "-->" << #A << "=\n";   \
        for (int i = 0; i < n; i++)     \
        {                               \
            for (int j = 0; j < m; j++) \
            {                           \
                cout << A[i][j] << " "; \
            }                           \
            cout << "\n";               \
        }                               \
        cout << "\n";                   \
    }
#define dbgA(A, n)                   \
    {                                \
        cout << "-->" << #A << "=("; \
        for (int i = 0; i < n; i++)  \
            cout << A[i] << " ";     \
        cout << ")\n";               \
    }
#define dbg(args...)                                  \
    {                                                 \
        string sss(#args);                            \
        sss += ',';                                   \
        cout << "-->";                                \
        debugger::call(sss.begin(), sss.end(), args); \
        cout << "\n";                                 \
    }
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I, n) for (int I = 0; I < n; I++)
#define forb(I, n) for (int I = 1; I <= n; I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mkp(a, b) make_pair(a, b)
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
int lca[20][50001];
int mx[20][50001];
int depth[50001];
vector<pair<int,int>> prims(vector<vector<pair<int,int>>> &adj, int start){
    vector<pair<int,int>> ans(adj.size()+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
    pq.push(mkp(0,start));
    vector<bool> visited(adj.size(),false);
    vector<int> parent(adj.size(),-1);
    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        int u=top.second;
        if(visited[u])continue;
        visited[u]=true;
        if(parent[u]!=-1){
            ans[u]=mkp(parent[u],top.first);
        }
        for(auto &v:adj[u]){
            if(!visited[v.first]){
                pq.push(mkp(v.second,v.first));
                parent[v.first]=u;
            }
        }
    }
    return ans;
}
void dfs()
void run()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n + 1);
        memset(lca, 0, sizeof lca);
        memset(mx, 0, sizeof mx);
        memset(depth, 0, sizeof depth);
        fora(i, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb(mkp(v, w));
            adj[v].pb(mkp(v, w));
        }
        vector<pair<int,int>> mst=prims(adj,1);
        vector<
        int q;
        cin >> q;
        while (q--)
        {

            int a, b;
            cin >> a >> b;
            if (depth[a] < depth[b])
                swap(a, b);
            cout << depth[a] << " " << depth[b] << endl;
            // dbgA(depth,n+1);
            int ans = 0;
            for (int i = 19; i >= 0; i--)
            {
                if (depth[lca[i][a]] >= depth[b])
                {
                    // cout<<"here"<<endl;
                    ans = max(mx[i][a], ans);
                    a = lca[i][a];
                }
            }
            cout << a << " " << b << endl;
            for (int i = 19; i >= 0; i--)
            {
                if (lca[i][a] != lca[i][b])
                {
                    ans = max({ans, mx[i][a], mx[i][b]});
                    a = lca[i][a];
                    b = lca[i][b];
                }
            }
            cout << a << " " << b << endl;
            ans = max({ans, mx[0][lca[0][a]], mx[0][lca[0][b]]});
            cout << ans << endl;
        }
    }
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
