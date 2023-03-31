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
ll st[20][100000], lca[20][100000];
ll depth[100000];
void dfs(int v, int p, int d, vector<vector<pair<ll, ll>>> &adj)
{
    for (auto u : adj[v])
    {
        if (u.first != p)
        {
            depth[u.first] = depth[v] + 1;
            lca[0][u.first] = v;
            st[0][u.first] = u.second;
            dfs(u.first, v, d + 1, adj);
        }
    }
}
int getLCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    for (int i = 19; i >= 0; i--)
    {
        if (depth[lca[i][a]] >= depth[b])
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

ll getDist(int a, int b)
{
    int l = getLCA(a, b);
    ll ans = 0;
    for (int i = 19; i >= 0; i--)
    {
        if (depth[lca[i][a]] >= depth[l])
        {
            ans += st[i][a];
            a = lca[i][a];
        }
    }
    for (int i = 19; i >= 0; i--)
    {
        if (depth[lca[i][b]] >= depth[l])
        {
            ans += st[i][b];
            b = lca[i][b];
        }
    }
    return ans;
}

void run()
{
    int t;
    int tt=scanf("%d", &t);
    while (t--)
    {
        memset(st, 0, sizeof(st));
        memset(lca, 0, sizeof(lca));
        memset(depth, 0, sizeof(depth));

        int n;
        int tt=scanf("%d", &n);
        vector<vector<pair<ll, ll>>> adj(n);
        fora(i, n - 1)
        {
            ll a, b, c;
            int tt=scanf("%lld%lld%lld", &a, &b, &c);
            a--, b--;
            adj[a].pb(mkp(b, c));
            adj[b].pb(mkp(a, c));
        }
        dfs(0, 0, 0, adj);
        for (int i = 1; i < 20; i++)
        {
            for (int j = 0; j < n; j++)
            {
                lca[i][j] = lca[i - 1][lca[i - 1][j]];
                st[i][j] = st[i - 1][j] + st[i - 1][lca[i - 1][j]];
            }
        }
        string s;
        while (cin>>s)
        {
            if(s=="DONE")
                break;
            if(s=="DIST"){
                int a,b;
                int tt=scanf("%d%d",&a,&b);
                a--,b--;
                printf("%lld\n",getDist(a,b));
            }else if(s=="KTH"){
                int a,b,k;
                int tt=scanf("%d%d%d",&a,&b,&k);
                a--,b--;
                int l=getLCA(a,b);
                int dist=depth[a]+depth[b]-2*depth[l];
                int d=depth[a]-depth[l];
                k--;
                if(k>d){
                    swap(a,b);
                    k=dist-k;
                }
                // cout<<a<<" "<<b<<" "<<k<<" "<<d<<" "<<l<<endl;
                for(int i=19;i>=0;i--){
                    if(depth[lca[i][a]]>=depth[l] && k>=(1<<i)){
                        k-=(1<<i);
                        a=lca[i][a];
                    }
                }
                printf("%d\n",a+1);
            }
        }
        printf("\n");
    }
}

int main()
{
// #ifdef HOME
//     freopen("input.txt", "r", stdin);
// #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    run();
}
