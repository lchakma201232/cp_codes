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
vector<int> tree;
void build(int node,int l,int r,vector<int>&arr){
    if(l==r){
        tree[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid,arr);
    build(2*node+1,mid+1,r,arr);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query(int node,int l,int r,int val){
    if(l==r){
        return l;
    }
    int mid=(l+r)/2;
    if(tree[2*node+1]>=tree[2*node] && tree[2*node]<=val){
        return query(2*node+1,mid+1,r,val);
    }
    return query(2*node,l,mid,val);
}
void run(){
    int t;
    cin>>t;
    int tt=1;
    while(t--){
        cout<<"Case "<<tt++<<":\n";
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        fora(i,n)cin>>arr[i];
        sort(arr.begin(),arr.end());
        arr.pb(1e9);
        tree = vector<int>(4*n);
        build(1,0,n,arr);
        fora(i,m){
            int x,y;
            cin>>x>>y;
            int idx = query(1,0,n,y);
            int idx2 = query(1,0,n,x-1);
            // cout<<idx<<" "<<idx2<<endl;
            cout<<idx-idx2<<endl;
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
