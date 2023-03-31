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
vector<int> parents;

set<int> dfs(int v, vector<set<int>> &adj, vector<int> &visited,bool ok=false)
{
    visited[v] = 1;
    set<int> ans;
    for (auto &u : adj[v])
    {
        if (visited[u]==0 || (visited[u]==2 && (ok || parents[u]!=v)))
        {
            bool temp=ok;
            if(visited[u]==2){
                ok=true;
            }
            set<int> k = dfs(u, adj, visited,temp);
            if (k.count(-1))
            {
                for (auto &x : k)
                {
                    if (x == -1)
                        continue;
                    visited[x] = 0;
                }
                continue;
            }
            parents[u] = v;
            ans.insert(k.begin(), k.end());
            if (ans == adj[v])
            {
                visited[v] = 2;
                ans.insert(v);
                return ans;
            }
        }
        else if (visited[u] == 1)
        {
            ans.insert(-1);
            return ans;
        }
    }
    if (ans != adj[v])
    {
        ans.insert(-1);
        return ans;
    }
    visited[v] = 2;
    ans.insert(v);
    return ans;
}
map<int, int> mp;
void run()
{
    int n;
    cin >> n;
    assert(n<=1000);
    vector<set<int>> adj(n);
    parents = vector<int>(n, -1);
    int root = -1;
    set<pair<int,int>> sorter;
    ll sum=0;
    fora(i, n)
    {
        int c;
        cin >> c;
        fora(j, c)
        {
            int x;
            cin >> x;
            adj[i].insert(x - 1);
            mp[i]++;
        }
        sum+=c;
        if (c == (n - 1)){
            root = i;
        }
    }
    ll anss=n*(n-1)/2;
    if(sum<(n-1) || sum>anss){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n;i++) {
        sorter.insert({mp[i],i});
        if(mp[i]==(n-1) && root!=i){
            cout<<"NO"<<endl;
            return;
        }
    }
    map<int,int> newinds;
    map<int,int> oldinds;
    int ind=0;
    for(auto &x:sorter){
        oldinds[ind]=x.second;
        newinds[x.second]=ind++;
    }
    vector<set<int>> newadj(n);
    for(int i=0;i<n;i++){
        for(auto &x:adj[i]){
            newadj[newinds[i]].insert(newinds[x]);
        }
    }
    adj=newadj;
    vector<int> visited(n, 0);
    int ans = 0;
    if(root==-1){
        cout<<"NO"<<endl;
        return;
    }
    root=newinds[root];
    set<int> k = dfs(root, adj, visited);
    visited = vector<int>(n, 0);
    if (!k.count(-1))
    {
        if (k.size() == adj.size())
        {
            ans++;
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            if (parents[i] != -1)
            {
                cout << oldinds[parents[i]] + 1 << " " << oldinds[i] + 1 << endl;
            }
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
