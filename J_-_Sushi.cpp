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
const int nax=305;
double dp[nax][nax][nax];
double ev[nax][nax][nax];
// double expected;
void run(){
    int n;
    cin>>n;
    vector<int> cnt(4);
    fora(i,n){
        int x;
        cin>>x;
        cnt[x]++;
    }
    // expected=0;
    dp[cnt[1]][cnt[2]][cnt[3]]=1;
    for(int c=n;c>=0;c--){
        for(int b=n;b>=0;b--){
            for(int a=n;a>=0;a--){
                if(a==0 && b==0 && c==0)continue;
                if(a+b+c>n)continue;
                double p_waste=(double)(n-a-b-c)/(double)n;
                double ev_waste = p_waste/(1-p_waste)+1;
                ev[a][b][c]+=ev_waste*dp[a][b][c];
                if(a!=0){
                    double p_a=(double)a/(double)(a+b+c);
                    dp[a-1][b][c]+=dp[a][b][c]*p_a;
                    ev[a-1][b][c]+=ev[a][b][c]*p_a;
                }
                if(b!=0){
                    double p_a=(double)b/(double)(a+b+c);
                    dp[a+1][b-1][c]+=dp[a][b][c]*p_a;
                    ev[a+1][b-1][c]+=ev[a][b][c]*p_a;
                }

                if(c!=0){
                    double p_a=(double)c/(double)(a+b+c);
                    dp[a][b+1][c-1]+=dp[a][b][c]*p_a;
                    ev[a][b+1][c-1]+=ev[a][b][c]*p_a;
                }
            }
        }
    }
    cout<<fixed<<setprecision(15)<<ev[0][0][0]<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
