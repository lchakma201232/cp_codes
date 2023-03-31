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
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<ll> dist1(n+1,1e10),dist2(n+1,1e10);
    vector<vector<ll>> adj(n+1);
    vector<vector<ll>> matrix(n+1,vector<ll>(n+1,0));
    fora(i,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        matrix[a][b]=1;
        matrix[b][a]=1;
    }
    dist1[s]=0;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<=n;j++){
            for(auto k:adj[j]){
                if(dist1[j]+matrix[j][k]<dist1[k]){
                    dist1[k]=dist1[j]+matrix[j][k];
                }
            }
        }
    }
    dist2[t]=0;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<=n;j++){
            for(auto k:adj[j]){
                if(dist2[j]+matrix[j][k]<dist2[k]){
                    dist2[k]=dist2[j]+matrix[j][k];
                }
            }
        }
    }
    ll counter=0;
    forb(i,n-1){
        for(int k=i+1;k<=n;k++){
            if((dist1[i]+dist2[k]+1)>=dist1[t] && matrix[i][k]==0 && (dist1[k]+dist2[i]+1)>=dist1[t]){
                counter++;
            }
        }
    }
    cout<<counter<<endl;

}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
