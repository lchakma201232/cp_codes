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
    int n;
    cin>>n;
    vector<int> arr;
    fora(i,n) {
        int x;
        cin>>x;
        arr.pb(x);
    }
    vector<vector<double>> mn(20,vector<double>(n,0)), mx(20,vector<double>(n,0));
    for(int i=0;i<n;i++){
        mn[0][i]=mx[0][i]=arr[i];
    }
    for(int i=1;i<20;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
            mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int k=log2(r-l+1);
        int lg1=log2(l);
        int lg2=log2(n-r-1);
        double mn1=min(mn[k][l],mn[k][r-(1<<k)+1]);
        double mx1=(max(mx[k][l],mx[k][r-(1<<k)+1])-mn1)/2.0;
        double mn2=umXI,mx2=0;
        if(lg1>=0){
            mn2=min(mn[lg1][0],mn[lg1][l-(1<<lg1)]);
            mx2=max(mx[lg1][0],mx[lg1][l-(1<<lg1)]);
        }
        if(lg2>=0){
            mn2=min(mn2,min(mn[lg2][r+1],mn[lg2][n-(1<<lg2)]));
            mx2=max(mx2,max(mx[lg2][r+1],mx[lg2][n-(1<<lg2)]));
        }
        double ans=max(mx1,mx2)+mn1;
        cout<<fixed<<setprecision(1)<<ans<<endl;
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
