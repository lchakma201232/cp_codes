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
int lca[30005][20];
int e_time[30005];
int l_time[30005];
int depth[30005];
vector<int> weights;
vector<int> path;
void dfs(int v, int p, vector<vector<int>> &adj, int &time){
    e_time[v]=time++;
    path.pb(weights[v]);
    for(int u:adj[v]){
        if(u!=p){
            lca[u][0]=v;
            depth[u]=depth[v]+1;
            dfs(u,v,adj,time);
        }
    }
    l_time[v]=time++;
    path.push_back(-weights[v]);
}
vector<int> seg_tree;
void build(int node, int l, int r){
    if(l==r){
        seg_tree[node]=path[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);
    seg_tree[node]=seg_tree[2*node+1]+seg_tree[2*node+2];
}

int update(int node,int l,int r,int idx,int value){
    if(l==r){
        seg_tree[node]=value;
        return seg_tree[node];
    }
    int mid=(l+r)/2;
    if(idx<=mid){
        seg_tree[node]=update(2*node+1,l,mid,idx,value)+seg_tree[2*node+2];
    }else{
        seg_tree[node]=seg_tree[2*node+1]+update(2*node+2,mid+1,r,idx,value);
    }
    seg_tree[node]=seg_tree[2*node+1]+seg_tree[2*node+2];
    return seg_tree[node];
}

int query(int node,int l,int r,int ql,int qr){
    if(ql>r || qr<l){
        return 0;
    }
    if(ql<=l && qr>=r){
        return seg_tree[node];
    }
    int mid=(l+r)/2;
    return query(2*node+1,l,mid,ql,qr)+query(2*node+2,mid+1,r,ql,qr);
}
int getLCA(int u, int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    int diff=depth[u]-depth[v];
    for(int i=0;i<20;i++){
        if((diff>>i)&1){
            u=lca[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(int i=19;i>=0;i--){
        if(lca[u][i]!=lca[v][i]){
            u=lca[u][i];
            v=lca[v][i];
        }
    }
    return lca[u][0];
}
void run(){
    int t;
    cin>>t;
    int cases=1;
    while(t--){
        cout<<"Case "<<cases++<<":"<<endl;
        int n;
        cin>>n;
        memset(lca,-1,sizeof(lca));
        memset(e_time,0,sizeof(e_time));
        memset(l_time,0,sizeof(l_time));
        memset(depth,0,sizeof(depth));
        weights=vector<int>();
        path=vector<int>();
        fora(i,n){
            int x;
            cin>>x;
            weights.pb(x);
        }
        vector<vector<int>> adj(n);
        fora(i,n-1){
            int x,y;
            cin>>x>>y;
            // x--;y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        
        int time=0;
        dfs(0,-1,adj,time);
        for(int j=1;j<20;j++){
            for(int i=0;i<n;i++){
                if(lca[i][j-1]!=-1){
                    lca[i][j]=lca[lca[i][j-1]][j-1];
                }
            }
        }
        seg_tree=vector<int>(4*path.size());
        build(0,0,path.size()-1);
        int q;
        cin>>q;
        while(q--){
            int a,b,c;
            cin>>a>>b>>c;
            if(a==0){
                int l=getLCA(b,c);
                int ans=query(0,0,path.size()-1,e_time[l],e_time[b])+query(0,0,path.size()-1,e_time[l],e_time[c]);
                ans-=query(0,0,path.size()-1,e_time[l],e_time[l]);
                cout<<ans<<endl;
            }else{
                // b++;
                update(0,0,path.size()-1,e_time[b],c);
                update(0,0,path.size()-1,l_time[b],-c);
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
