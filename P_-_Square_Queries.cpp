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
    int cc=1;
    while(t--){
        cout<<"Case "<<cc++<<":\n";
        int n,q;
        cin>>n>>q;
        vector<vector<int>> arr(n,vector<int>(n));
        vector<vector<vector<int>>> mx(n+1,vector<vector<int>>(20,vector<int>(n+1)));
        fora(i,n){
            fora(j,n){
                cin>>arr[i][j];
                mx[i][0][j]=arr[i][j];
            }
        }
        fora(i,n){
            for(int p=1;p<20;p++){
                for(int j=0;j+(1<<p)<=n;j++){
                    mx[i][p][j]=max(mx[i][p-1][j],mx[i][p-1][j+(1<<(p-1))]);
                }
            }
        }
        while(q--){
            int a,b,s;
            cin>>a>>b>>s;
            a--,b--;
            int lg=log2(s);
            int ans=0;
            for(int i=a;i<a+s;i++){
                ans=max(ans,max(mx[i][lg][b],mx[i][lg][b+s-(1<<lg)]));
            }
            cout<<ans<<endl;
        }

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
