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
vector<int> seg_tree;
void build_seg_tree(vector<int> &arr,int v, int l, int r){
    if(l==r){
        seg_tree[v]=1;
        return;
    }
    int mid=(l+r)/2;
    build_seg_tree(arr,2*v,l,mid);
    build_seg_tree(arr,2*v+1,mid+1,r);
    if(arr[mid]!=arr[mid+1]){
        seg_tree[v]=seg_tree[2*v]+seg_tree[2*v+1];
    }
    else{
        seg_tree[v]=seg_tree[2*v]+seg_tree[2*v+1]-1;
    }
}
int query(int v, int l, int r, int ql, int qr){
    if(ql<=l && qr>=r){
        return seg_tree[v];
    }
    int mid=(l+r)/2;
    if(qr<=mid){
        return query(2*v,l,mid,ql,qr);
    }
    else if(ql>mid){
        return query(2*v+1,mid+1,r,ql,qr);
    }
    else{
        return query(2*v,l,mid,ql,mid)+query(2*v+1,mid+1,r,mid+1,qr);
    }
}
void update(vector<int> &arr,int v, int l, int r, int pos, int val){
    if(l==r){
        arr[pos]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid){
        update(arr,2*v,l,mid,pos,val);
    }
    else{
        update(arr,2*v+1,mid+1,r,pos,val);
    }
    if(arr[mid]==arr[mid+1]){
        seg_tree[v]=seg_tree[2*v]+seg_tree[2*v+1];
    }
    else{
        seg_tree[v]=seg_tree[2*v]+seg_tree[2*v+1]-1;
    }
}
void run(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    fora(i,n){
        cin>>arr[i];
    }
    seg_tree.assign(4*n,0);
    build_seg_tree(arr,1,0,n-1);
    fora(i,m){
        int k,j;
        cin>>k>>j;
        update(arr,1,0,n-1,k-1,j);
        cout<<query(1,0,n-1,0,n-1)<<endl;

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
