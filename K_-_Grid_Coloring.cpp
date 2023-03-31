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
const ll mod = 1e9;
ll modPow(ll a, ll b)
{
    if (b == 0 || a==0)
        return 1;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll modMul(ll a, ll b)
{
    return (a * b) % mod;
}
ll getSections(vector<ll> &a)
{
    sort(a.begin(), a.end());
    //remove duplicates
    a.erase(unique(a.begin(), a.end()), a.end());
    ll ans = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] != a[i - 1] + 1)
        {
            ans++;
        }
    }
    if (a[0] == 1)
        ans--;
    return ans;
}
void run()
{
    int t;
    cin >> t;
    int casee = 1;
    while (t--)
    {
        cout << "Case " << casee++ << ": ";
        ll n, m, k, b;
        cin >> m >> n >> k >> b;
        assert(k>0);
        map<ll, vector<ll>> mp;
        map<ll, bool> vis;
        map<ll, bool> vis2;
        ll counter = 0;
        fora(i, b)
        {
            ll x, y;
            cin >> x >> y;
            if (x == 1)
                vis[y] = 1;
            if (x == m)
                vis2[y] = 1;
            mp[y].pb(x);
            counter += x == 1;
        }
        ll total=n;
        ll rr=m*n-n;
        for (auto &it : mp)
        {
            ll res = getSections(it.second) - vis2[it.first] + vis[it.first];
            int sz = it.second.size() - vis[it.first] + res;
            rr-=sz;
            total+=res;
        }
        total-=counter;
        if(rr>0 && k==1){
            cout<<0<<endl;
            continue;
        }
        ll ans = modMul(modPow(k, total),modPow(k-1,rr));
        cout << ans << endl;
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
