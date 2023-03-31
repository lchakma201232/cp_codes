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

vector<int> arr;
vector<int> tree;
int n;
void build(int node, int start, int end){
    if(start==end ){
        if(end<arr.size())
        tree[node]=1;
    }else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
void update(int node, int start, int end, int idx, int val){
    if(start==end){
        tree[node]=val;
    }
    else{
        int mid=(start+end)/2;
        if(start<=idx && idx<=mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node+1,mid+1,end,idx,val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int query(int node, int start, int end, int k){
    if(start>end){
        return -1;
    }
    if(start==end && k==1){
        return start;
    }
    int mid=(start+end)/2;
    if(tree[2*node]>=k){
        return query(2*node,start,mid,k);
    }else{
        return query(2*node+1,mid+1,end,k-tree[2*node]);
    }
}

void run(){
    int t;
    cin>>t;
    int tt=1;
    // cout<<acos(-1)<<endl;
    while(t--){
        cout<<"Case "<<tt++<<":\n";
        int q;
        cin>>n>>q;
        arr.resize(n);
        tree.resize(4*(n+q));
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        build(1,0,n+q-1);
        for(int i=0;i<q;i++){
            char x;
            int k;
            cin>>x>>k;
            if(x=='c'){
                int l=query(1,0,n+q-1,k);
                if(l>=arr.size()){
                    cout<<"none"<<endl;
                }else{
                    cout<<arr[l]<<endl;
                    update(1,0,n+q-1,l,0);
                }
            }else{
                arr.push_back(k);
                update(1,0,n+q-1,arr.size()-1,1);
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
