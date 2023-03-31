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
int find(vector<int> &parents,int p){
    if(parents[p]==p){
        return p;
    }
    return parents[p]=find(parents,parents[p]);
}
void join(vector<int> &parents,int u,int v,vector<int> &ranks){
    int pu=find(parents,u);
    int pv=find(parents,v);
    parents[pv]=pu;
    ranks[pu]+=ranks[pv];
    ranks[pv]=0;
}
void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> weights;
        vector<int> parents(n+1);
        vector<int> ranks(n+1,1);
        for(int i=1;i<=n;i++){
            int w;
            cin>>w;
            weights.pb(w);
            parents[i]=i;
        }
        int q;
        cin>>q;
        fora(i,q){
            int type;
            cin>>type;
            if(type==1){
                int u,v;
                cin>>u>>v;
                int pu=find(parents,u);
                int pv=find(parents,v);
                if(pu!=u || pv!=v || weights[pu-1]==weights[pv-1]){
                    continue;
                }
                if(weights[pu-1]<weights[pv-1]) swap(pu,pv);
                join(parents,pu,pv,ranks);
                weights[pu-1]+=weights[pv-1];
            }else if(type==2){
                int u;
                cin>>u;
                cout<<ranks[u]<<endl;
            }else{
                int u;
                cin>>u;
                int pu=find(parents,u);
                cout<<pu<<endl;
            }
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
