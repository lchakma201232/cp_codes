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
void build(vector<int> &tree, string &arr, int node, int start, int end){
    if(start==end){
        // cout<<start<<" "<<end<<" "<<node<<endl;
        tree[node]=arr[start]-'0';
        return;
    }
    int mid=(start+end)/2;
    build(tree,arr,2*node,start,mid);
    build(tree,arr,2*node+1,mid+1,end);
}
//set node to 1 if range is in the query
void update(vector<int> &tree, int node, int start, int end, int l, int r){
    // cerr<<start<<" "<<end<<endl;
    if(start>r || end<l){
        return;
    }
    if(start==l && end==r){
        tree[node]^=1;
        return;
    }
    int mid=(start+end)/2;
    update(tree,2*node,start,mid,l,min(r,mid));
    update(tree,2*node+1,mid+1,end,max(l,mid+1),r);
}
int query(vector<int> &tree, int node, int start, int end, int idx){
    if(start==end){
        // cout<<start<<" "<<end<<" "<<node<<endl;
        return tree[node];
    }
    int mid=(start+end)/2;
    if(idx<=mid){
        return tree[node]^query(tree,2*node,start,mid,idx);
    }
    else{
        return tree[node]^query(tree,2*node+1,mid+1,end,idx);
    }
}
void run(){
    int t;
    cin>>t;
    int tt=1;
    while(t--){
        cout<<"Case "<<tt++<<":\n";
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<int> seg_tree(4*s.size(),0);
        build(seg_tree,s,1,0,s.size()-1);
        while(q--){
            char c;
            cin>>c;
            if(c=='I'){
                int l,r;
                cin>>l>>r;
                l--;
                r--;
                // dbgA(seg_tree,seg_tree.size());
                update(seg_tree,1,0,s.size()-1,l,r);
                // dbgA(seg_tree,seg_tree.size());
            }else{
                int idx;
                cin>>idx;
                idx--;
                cout<<query(seg_tree,1,0,s.size()-1,idx)<<endl;
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
