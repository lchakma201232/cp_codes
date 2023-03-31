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
const int mod = 998244353;

void run()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    forb(i, n)
    {
        forb(j, m)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + m + 1, 0));
    if (arr[1][1])
    {
        dp[1][1] = 1;
    }
    if (arr[1][1]==0)
    {
        dp[1][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }

            if (arr[i][j] == 1)
            {
                for (int k = i+j-1; k>=1; k--)
                {
                    dp[j][k] = (dp[j][k - 1] + dp[j - 1][k-1]) % mod;
                }
                dp[j][0] = 0;
            }
            else
            {
                for (int k = i+j-1; k>=0; k--)
                {
                    dp[j][k] = (dp[j][k] + dp[j - 1][k]) % mod;
                }
            }
        }
    }
    // dbgA2(dp, m + 1, n + m + 1);
    int ans = 0;

    for (int i = q; i <= n + m-1-p; i++)
    {

        ans += dp[m][i];
        ans %= mod;
        
    }
    cout << ans << endl;
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
