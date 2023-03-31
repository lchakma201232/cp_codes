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
const ll mod = 1000000007;
vector<char> colors;
set<int> nodes;
unordered_map<ll,bool> visited;
// vector<int> node(1100);
ll dfs(int u,vector<vector<ll>> &adj,vector<ll> &apaths,bool ok){
    if(visited[u]){
        return 0;
    }
    visited[u]=1;
    __int128_t alternating_sum=0,not_alternating_sum=0;
    ll counter=0;
    for(auto &x:adj[u]){
        if(colors[x]!=colors[u] && !visited[x]){
            // counter++;
            alternating_sum+=(dfs(x,adj,apaths,1)+1);
        }else{
            not_alternating_sum+=(dfs(x,adj,apaths,0));
        }
    }
    apaths[u]=alternating_sum*(alternating_sum+1)/(__int128_t)2%mod;
    if(!ok) nodes.insert(u);
    return alternating_sum;
}

void run(){
    int n;
    cin>>n;
    // visited.assign(n,0);
    vector<vector<ll>> graph(n);
    // unordered_map<ll,ll> leafs(n);
    // int start=0;
    fora(i,n-1){
        int u,v;
        cin>>u>>v;
        u--,v--;
        graph[u].pb(v);
        graph[v].pb(u);

    }
    
    fora(i,n){
        char x;
        cin>>x;
        colors.pb(x);
    }
    vector<ll> apaths(n);
    fora(i,n){
        if(graph[i].size()==1){
            // cout<<i<<endl;
            dfs(i,graph,apaths,0);
            break;
        }
    }
    // dbgA(apaths,n);
    // dbgA(node,n);
    ll ans=0;
    for(auto &x:nodes){
        ans=(ans+apaths[x])%mod;
    }
    cout<<(ans+n)%mod<<endl;

}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
