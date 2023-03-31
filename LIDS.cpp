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
int dp[32][10][2][2];
int dp2[32][32];
int count(int index, int current, bool tight_a, bool tight_b, string a, string b)
{
    if (index == b.size())
    {
        dp2[current][0]++;
        return 0;
    }
    if (dp[index][current][tight_a][tight_b] != -1)
    {
        return dp[index][current][tight_a][tight_b];
    }
    int ans = 0;
    for (int start = (tight_b ? b[index] - '0' : 9); start >= (tight_a ? a[index] - '0' : 0); start--)
    {
        ans = max(count(index + 1, start, tight_a & (start == a[index] - '0'), tight_b & (start == b[index] - '0'), a, b) + (start > current), ans);
        dp2[index][ans]+=dp2[index+1][ans-1];
    }

    return dp[index][current][tight_a][tight_b] = ans;
}
// int dp3[32][32];
ll countWays(int val, int index,int n){
    ll ans=0;
    if(index==n){
        return 1;
    }
    for(int i=index+1;i<n;i++){
        ans+=countWays(val-1,i,n);
    }
    return max(ans,(ll)1)*dp2[index][val];
}
void run()
{
    int t;
    cin >> t;
    int tt=1;
    while (t--)
    {
        cout<<"Case "<<tt++<<": ";
        memset(dp, -1, sizeof(dp));
        memset(dp2, 0, sizeof(dp2));
        // memset(dp3, -1, sizeof(dp3));
        string x, y;
        cin >> x >> y;
        x = string(y.size() - x.size(), '0') + x;
        dp2[y.size()][0]=1;
        int res = count(0, 0, 1, 1, x, y);
        // dp2[0][res]++;
        ll ans=countWays(res,0,y.size()+1);
        dbgA2(dp2,y.size()+1,res+1);
        cout<<res<<" "<<ans<<endl;


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