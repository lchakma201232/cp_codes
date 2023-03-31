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

int dfs(int v, int *arr, int *visited){
    if(visited[arr[v]]){
        return arr[v]=arr[arr[v]];
    }
    visited[v]=1;
    return arr[v]=dfs(arr[v],arr,visited);
}*/
vector<int> primes;
ll siev_arr[mXI];
void siev(ll n)
{
    siev_arr[0] = siev_arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!siev_arr[i])
        {
            primes.push_back(i);
            for (int j = i + i; j <= n; j += i)
            {
                siev_arr[j] = 1;
            }
        }
    }
}
ll dp2[1120 + 1][20][200];
ll calc(ll sum, ll k, ll ind)
{
    if (sum == 0 && k == 0)
        return 1;
    if (sum < 0 || k < 0)
        return 0;
    if (ind >= primes.size())
        return 0;
    if (dp2[sum][k][ind] != -1)
        return dp2[sum][k][ind];
    ll ans = 0;
    ans += calc(sum - primes[ind], k - 1, ind + 1);
    ans += calc(sum, k, ind + 1);
    return dp2[sum][k][ind] = ans;
}

void run()
{
    siev(1120);
    int n, k;
    // memset(dp2,-1,sizeof(dp2));
    vector<vector<int>> dp(1121, vector<int>(20, 0));
    dp[0][0] = 1;
    for (auto &x : primes)
    {
        for (int i = 1120; i >= x; i--)
        {
            for (int j = 1; j <= 16; j++)
            {
                dp[i][j] += dp[i - x][j - 1];
            }
        }
    }
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0)
            break;

        cout << dp[n][k] << "\n";

        // cout<<calc(n,k,0)<<"\n";
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
