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
int cc=0;
struct stackB{
    ll n,w,cost;
    bool operator < (const stackB &a) const{
        return cost<a.cost;
    }
    stackB operator + (const stackB &a) const{
        return {n+a.n,w+a.w,max(0LL,n*w+a.n*a.w-cc)+cost+a.cost};
    }
};
stackB dp[101][101];
stackB getTime(vector<ll> &w, int l, int r){
    // cerr<<l<<" "<<r<<endl;
    if(l==r){
        return {1,w[l],0};
    }
    if(l>r){
        return {0,0,0};
    }
    if(dp[l][r].n){
        return dp[l][r];
    }
    stackB res=getTime(w,l,l)+getTime(w,l+1,r);
    for(int i=l+1;i<r;i++){
        res=min(res,getTime(w,l,i)+getTime(w,i+1,r));
    }
    return dp[l][r]=res;
}

void run(){
    int n,t;
    cin>>n>>t;
    vector<ll> weights(n);
    fora(i,n){
        cin>>weights[i];
    }
    cc=1;
    // stackB res=getTime(weights,0,n-1);
    // for(int i=165;i<=261;i++){
    //     cc=i;
    //     memset(dp,0,sizeof(dp));
    //     res=getTime(weights,0,n-1);
    //     cout<<i<<" "<<res.cost<<endl;
    //     // cout<<res.cost<<endl;
    // }
    int l=0,r=1e9;
    while(l<r){
        memset(dp,0,sizeof(dp));
        int mid=(l+r)/2;
        cc=mid;
        stackB left=getTime(weights,0,n-1);
        if(left.cost<=t){
            r=mid;
        }else{
            l=mid+1;
        }

    }
    cout<<l<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
