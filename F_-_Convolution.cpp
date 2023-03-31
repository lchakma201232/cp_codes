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
const long long mod = 998244353;
ll get_mod(ll a){
    while(a<0){
        a+=mod;
    }
    return a%mod;
}
void build(vector<ll> &tree, int node,vector<ll> &arr, int start,int end){
    if(start==end){
        tree[node]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build(tree,2*node,arr,start,mid);
    build(tree,2*node+1,arr,mid+1,end);
    tree[node]=(tree[2*node]+tree[2*node+1]);
    tree[node]=get_mod(tree[node]);
}

void update(vector<ll> &tree, int node, int start, int end, int l, int r, long long val){
    if(start>end || start>r || end<l){
        return;
    }
    if(start==l && end==r){
        tree[node]+=get_mod(val*((ll)end-start+1));
        tree[node]=get_mod(tree[node]);
        return;
    }
    int mid=(start+end)/2;
    update(tree,2*node,start,mid,l,min(mid,r),val);
    update(tree,2*node+1,mid+1,end,max(l,mid+1),r,val);
    tree[node]=tree[2*node]+tree[2*node+1];
    tree[node]=get_mod(tree[node]);
}
void run(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<ll> a,b;
        ll sum=0;
        fora(i,n){
            int x;
            cin>>x;
            a.pb(x);
            sum+=x;
        }
        ll sum2=0;
        fora(i,m){
            int x;
            cin>>x;
            b.pb(x);
            sum2+=x;
        }
        // vector<ll> tree1(4*n),tree2(4*m);
        // build(tree1,1,a,0,n-1);
        // build(tree2,1,b,0,m-1);
        int q;
        cin>>q;
        fora(i,q){
            int type;
            cin>>type;
            if(type==1){
                ll l,r,x;
                cin>>l>>r>>x;
                // update(tree1,1,0,n-1,l-1,r-1,x);
                sum+=(r-l+1)*x;
                sum=get_mod(sum);
            }else if(type==2){
                ll l,r,x;
                cin>>l>>r>>x;
                // update(tree2,1,0,m-1,l-1,r-1,x);
                sum2+=(r-l+1)*x;
                sum2=get_mod(sum2);
            }else{
                // ll res=tree1[1]*tree2[1];
                ll res=sum*sum2;
                res=get_mod(res);

                cout<<res<<"\n";
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
