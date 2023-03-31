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
ll st[20][100005], lca[20][100005];
int depth[100005];
void dfs(int v, int p, int d, vector<vector<pair<ll,ll>>> &adj){
    // cerr<<v<<" "<<p<<" "<<d<<endl;
    depth[v]=d;
    for(auto u:adj[v]){
        if(u.first!=p){
            lca[0][u.first]=v;
            st[0][u.first]=u.second;
            dfs(u.first,v,d+1,adj);
        }
    }
}


void run(){
    int n;
    while(cin>>n){
        if(n==0)break;
        memset(st,0,sizeof(st));
        memset(lca,0,sizeof(lca));
        memset(depth,0,sizeof(depth));
        vector<vector<pair<ll,ll>>> adj(n);
        forb(i,n-1){
            ll a,l;
            cin>>a>>l;
            adj[a].pb(mkp(i,l));
            // adj[a].pb(mkp(i,l));
        }
        dfs(0,-1,0,adj);
        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                st[i][j]=st[i-1][j]+st[i-1][lca[i-1][j]];
                lca[i][j]=lca[i-1][lca[i-1][j]];
            }
        }
        int q;
        cin>>q;
        while(q--){
            int l,r;
            cin>>l>>r;
            if(depth[l]<depth[r])swap(l,r);
            ll ans=0;
            for(int i=19;i>=0;i--){
                if(depth[lca[i][l]]>=depth[r]){
                    ans+=st[i][l];
                    l=lca[i][l];
                }
            }
            if(l==r){
                cout<<ans<<(q?" ":"");
                continue;
            }
            for(int i=19;i>=0;i--){
                if(lca[i][l]!=lca[i][r]){
                    ans+=st[i][l]+st[i][r];
                    l=lca[i][l];
                    r=lca[i][r];
                }
            }
            ans+=st[0][l]+st[0][r];
            cout<<ans<<(q?" ":"");
        }
        cout<<endl;
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
