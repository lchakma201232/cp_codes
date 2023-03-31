#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)  {cout<<"-->"<<#A<<"=\n";for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n)      {cout<<"-->"<<#A<<"=(";for(int i = 0; i < n; i++)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...)    {string sss(#args);sss+=',';cout<<"-->";debugger::call(sss.begin(), sss.end(), args);cout<<"\n";}
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I,n) for(int I=0; I<n;I++)
#define forb(I,n) for(int I=1; I<=n;I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mkp(a,b) make_pair(a,b)
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
ll nr[1000][1000];
ll mod = 1e9+7;
ll nCr(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    if (nr[n][r] != 0)
        return nr[n][r];
    return nr[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % mod;
}
void run(){
    int t;
    cin>>t;
    int cc=1;
    while(t--){
        cout<<"Case "<<cc++<<": ";
        int n,m,k;
        cin>>n>>m>>k;
        vector<ll> res(n+1);
        res[0]=1;
        res[1]=0;
        res[2]=1;
        for(int j=3;j<=n;j++){
            res[j]=((j-1)*res[j-1])%mod+((j-1)*res[j-2])%mod;
            res[j]%=mod;
        }
        ll f=0;
        ll left=n-m;
        for(ll i=0;i<=left;i++){
            f+=(nCr(left,i)*res[n-i-k])%mod;
            f%=mod;
        }
        // cout<<nCr(m,k)<<' '<<f<<endl;
        cout<<(f*nCr(m,k))%mod<<endl;
        // cout<<pp<<endl;
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}