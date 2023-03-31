

#include <bits/stdc++.h>

using namespace std;

#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define fo(i, j, n) for (i = j; i < n; i++)
#define cinn(x) \
    for (int i = 0; i < x.size(); i++) cin >> x[i];
#define printa(x) \
    for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
#define LL long long
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define sl2(x, y) scanf("%lld %lld", &x, &y)
#define sl3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define si2(x, y) scanf("%d %d", &x, &y);
#define si3(x, y, z) scanf("%d %d %d", &x, &y, &z);
#define ss(s) scanf("%s", s)
#define pis(x) printf("%d ", x)
#define pi(x) printf("%d", x)
#define pl(x) printf("%lld", x)
#define ps(s) printf("%s", s)
#define lb() printf("\n")
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define dbgA2(A, n, m)                    \
    {                                     \
        cout << "-->" << #A << "=\n";     \
        for (int i = 0; i < n; i++) {     \
            for (int j = 0; j < n; j++) { \
                cout << A[i][j] << " ";   \
            }                             \
            cout << "\n";                 \
        }                                 \
        cout << "\n";                     \
    }
#define dbgA(A, n)                                       \
    {                                                    \
        cout << "-->" << #A << "=(";                     \
        for (int i = 0; i < n; i++) cout << A[i] << " "; \
        cout << ")\n";                                   \
    }
#define dbg(args...)                                  \
    {                                                 \
        string sss(#args);                            \
        sss += ',';                                   \
        cout << "-->";                                \
        debugger::call(sss.begin(), sss.end(), args); \
        cout << "\n";                                 \
    }

struct debugger {
    typedef string::iterator si;

    static void call(si it, si ed) {}

    template <typename T, typename... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for (; *it != ','; ++it)
            if (*it != ' ') b += *it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};

const int N = 2e5 + 100;
const int MOD = 1e9 + 7;
int parent[100005][20];
int tin[100005], tout[100005], times;

int a[200005];
int val[100005];

vector<vector<long long>> mul(vector<vector<long long>> &a,
                              vector<vector<long long>> &b) {
    int sz = a.size();
    vector<vector<long long>> ans(sz, vector<long long>(sz, 0));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j] + MOD) % MOD;
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}

// vector<vector<long long>> power(vector<vector<long long>> &a, long long n) {
//     int sz = a.size();
//     vector<vector<long long>> ans(sz, vector<long long>(sz, 0));
//     if (n == 0) {
//         for (int i = 0; i < sz; i++) {
//             a[i][i] = 1;
//         }
//     }

//     if (n == 1) {
//         return a;
//     }
//     vector<vector<long long>> temp = power(a, n / 2);
//     temp = mul(temp, temp);
//     if (n & 1) {
//         temp = mul(temp, a);
//     }
//     return temp;
// }

map<long long, int> memo;

int fact(ll x, ll k) {
    if (memo[x])
        return memo[x];
    vector<vector<ll>> base = {{5}, {2}, {1}};
    vector<vector<ll>> res = {{k, 0, k - 2}, {1, 0, 0}, {0, 1, 0}};
    if (x <= 3)
        return base[3-x][0] % MOD;
    else {
        ll cx=x-3;
        while(cx){
            if(cx&1){
                base=mul(res,base);
            }
            res=mul(res,res);
            cx>>=1;
        }
        return memo[x] = (base[0][0] + MOD) % MOD;
    }
}

struct ST {
#define lc (n << 1)
#define rc ((n << 1) | 1)
    long long t[4 * N];

    ST() { memset(t, 0, sizeof t); }

    inline long long combine(long long a, long long b) {
        return (a + b + MOD) % MOD;
    }

    inline void pull(long long n) {
        t[n] = ((long long)t[lc] + (long long)t[rc] + MOD) % MOD;
    }

    void build(int n, int b, int e) {
        if (b == e) {
            t[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);
    }

    void upd(int n, int b, int e, int i, int j, int v) {
        if (j < b || e < i) return;
        if (i <= b && e <= j) {
            t[n] = v;
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }

    long long query(int n, int b, int e, int i, int j) {
        if (i > e || b > j) return 0;  // return null
        if (i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
};

void dfs(int n, int p, vector<vector<int>> &e) {
    tin[n] = times;
    times++;
    a[tin[n]] = val[n];

    parent[n][0] = p;

    for (int i = 1; i < 20; i++) {
        parent[n][i] = parent[parent[n][i - 1]][i - 1];
    }

    for (auto it : e[n]) {
        if (it != p) {
            dfs(it, n, e);
        }
    }
    tout[n] = times;
    times++;
    a[tout[n]] = -val[n];
}

bool isAncestor(int u, int v) { return tin[v] >= tin[u] && tout[v] <= tout[u]; }

int findLCA(int v, int u) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = 19; i >= 0; i--) {
        if (!isAncestor(parent[u][i], v)) {
            u = parent[u][i];
        }
    }
    u = parent[u][0];
    return u;
}

void solve() {
    long long n, q, k;
    cin >> n >> q >> k;

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        val[i] = ((long long)fact(x, k) + MOD) % MOD;
    }

    vector<vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 1, e);

    ST st;
    st.build(1, 0, 2 * n);
    //
    /*                printa(val);
                    cout << "\n";
                   printa(a);
                   cout << "\n";*/
    //
    //    st.upd(1, 1, a.size() - 1, 0, 0, -30);
    //
    //    //     cout << st.query(1, 0, a.size() - 1, 0, 3) << "\n";
    //
    while (q--) {
        long long i, u, v;
        cin >> i >> u >> v;

        if (i == 1) {
            int lca = findLCA(u, v);
            ll a1 = st.query(1, 0, 2 * n, tin[lca], tin[v]);
            ll a2 = st.query(1, 0, 2 * n, tin[lca], tin[u]);
            ll a3 = st.query(1, 0, 2 * n, tin[lca], tin[lca]);
            cout << ((a1 + a2 - (a3) + MOD) % MOD) << "\n";

        } else {
            v = ((long long)fact(v, k) + MOD) % MOD;
            st.upd(1, 0, 2 * n, tin[u], tin[u], v);
            st.upd(1, 0, 2 * n, tout[u], tout[u], -v);
            val[u] = v;
        }
    }
}

int main() {
    //  #ifndef ONLINE_JUDGE
    //      freopen("input.txt", "r", stdin);
    //      freopen("output.txt", "w", stdout);
    //  #endif
    int t = 1;

    Fast_io;

    //    cin >> t;
    int c = 1;
    while (t--) {
        solve();
    }
    return 0;
}