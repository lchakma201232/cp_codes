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
int lca[20][100001];
int depth[100001];
int parent[100001];
void dfs(int v, int p, int d, vector<vector<int>> &adj)
{
    depth[v] = d;
    for (int u : adj[v])
    {
        if (u != p)
        {
            parent[u] = v;
            lca[0][u] = v;
            dfs(u, v, d + 1, adj);
        }
    }
}
int getLCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = 0; i < 20; i++)
    {
        if ((diff >> i) & 1)
        {
            a = lca[i][a];
        }
    }
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
    {
        if (lca[i][a] != lca[i][b])
        {
            a = lca[i][a];
            b = lca[i][b];
        }
    }
    return lca[0][a];
}
void run()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<vector<int>> adj(n + 1);
        memset(lca, 0, sizeof(lca));
        memset(depth, 0, sizeof(depth));
        memset(parent, 0, sizeof(parent));
        fora(i, n - 1)
        {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(1, 0, 0, adj);
        for (int i = 1; i < 20; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                lca[i][j] = lca[i - 1][lca[i - 1][j]];
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            int _lca = getLCA(a, b);
            int distance = depth[a] + depth[b] - 2*depth[_lca];
            // cout<<_lca<<" "<<distance<<endl;
            if (depth[a] > depth[b])
                swap(a, b);
            int dep = (distance / 2);
            // cout<<dep<<endl;
            int p = b;
            for (int i = 19; i >= 0; i--)
            {
                if ((dep >> i) & 1)
                {
                    p = lca[i][p];
                }
            }
            if (distance % 2 == 0)
            {
                cout << "The fleas meet at " << p << "." << endl;
            }
            else
            {
                int p2 = lca[0][p];
                if (p > p2)
                    swap(p, p2);
                cout << "The fleas jump forever between " << p << " and " << p2 << "." << endl;
            }
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
