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
int n;
vector<vector<int>> adj;
vector<bool> levels;
vector<int> w;
void dfs(int u,int p, int last){
    levels[u]=(last+1)%2;
    for(auto v:adj[u]){
        if(v!=p){
            dfs(v,u,last+1);
        }
    }
}

pair<int,int> calc(int bit){
    ll ans=0,poscount=0,ncount=0;
    for(int i=0;i<n;i++){
        if(levels[i]==bit){
            poscount++;
            ans+=w[i];
        }else{
            ncount++;
            ans-=w[i];
        }
    }
    int best=0;
    int result=0;
    for(int i=0;i<n;i++){
        if(levels[i]!=bit){
            int temp=w[i]*ncount - w[i]*poscount + ans;
            if(temp>best){
                best=temp;
                result=i;
            }
        }else{
            int temp=-w[i]*ncount + w[i]*poscount - ans;
            if(temp>best){
                best=temp;
                result=i;
            }
        }
    }
    return mkp(result,best);
}


void run(){
    int t;
    cin>>t;
    int tt=1;
    // cin>>t;
    while(t--){
        cout<<"Case "<<tt++<<": ";
        cin>>n;
        adj=vector<vector<int>>(n);
        levels=vector<bool>(n);
        w=vector<int>(n);
        for(int i=0;i<n;i++){
            cin>>w[i];
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(0,0,-1);
        pair<int,int> ans=calc(0);
        cout<<ans.first+1<<endl;
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
