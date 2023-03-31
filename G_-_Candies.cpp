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


void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<double> a;
        // res=vector<vector<double>>(1e3+5,vector<double>(1e3+5,0));
        fora(i,n){
            int x;
            cin>>x;
            a.pb(x);
        }
        vector<double> res(1e3+5,0);
        vector<vector<double>> dp(1e3+5,vector<double>(1e3+5,0));
        fora(i,n){
            res[i]=a[i];
            if(i) res[i]+=res[i-1];
        }
        fora(i,n){
            dp[i][i]=a[i];
        }
        for(int len = 2; len <= n; len++)
        {
            fora(i,n)
            {
                int j = i + len - 1;
                if(j >= n) continue;
                double left = a[i] + (res[j] - res[i] - dp[i + 1][j]);
                double right = a[j] + (res[j - 1] - (i ? res[i - 1] : 0) - dp[i][j - 1]);
                dp[i][j] = (left + right) / 2;
            }
        }
        cout<<fixed<<setprecision(15)<<dp[0][n-1]<<endl;

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
