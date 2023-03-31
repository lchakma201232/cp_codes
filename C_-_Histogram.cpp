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
vector<int> tree;
void build(int node, int start, int end, vector<int> &arr)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid, arr);
    build(2 * node + 1, mid + 1, end, arr);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int start, int end, int l, int r)
{
    if (l > r)
    {
        return INT_MAX;
    }
    if (start == l && end == r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, min(mid, r));
    int p2 = query(2 * node + 1, mid + 1, end, max(l, mid + 1), r);
    return min(p1, p2);
}
int histogram(vector<int> &arr)
{
    int n = arr.size();
    tree.resize(4 * n);
    build(1, 0, n - 1, arr);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int mn = query(1, 0, n - 1, i, mid);
            if (mn >= arr[i])
            {
                ans = max(ans, arr[i] * (mid - i + 1));
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        int right=l;
        l = 0, r = i;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int mn = query(1, 0, n - 1, mid, i);
            if (mn >= arr[i])
            {
                ans = max(ans, arr[i] * (i - mid + 1));
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans=max(ans,arr[i]*(right-l));
    }
    return ans;
}

void run()
{
    int t;
    cin >> t;
    int tt = 1;
    while (t--)
    {
        cout << "Case " << tt++ << ": ";
        int n;
        cin >> n;
        vector<int> arr;
        fora(i, n)
        {
            int x;
            cin >> x;
            arr.pb(x);
        }
        cout << histogram(arr) << endl;
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
