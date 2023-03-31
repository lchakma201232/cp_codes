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

struct fenwicktree{
    vector<ll> arr;
    fenwicktree(int n){
        arr.resize(n+1);
    }
    void update(int i, ll val){
        while(i<arr.size()){
            arr[i]+=val;
            i+=(i&-i);
        }
    }
    ll query(int i){
        ll sum=0;
        while(i>0){
            sum+=arr[i];
            i-=(i&-i);
        }
        return sum;
    }
    ll search(int val){
        int l=0,r=arr.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(query(mid)>=val){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    ll searchFrom(int idx, int val){
        return search(query(idx)+val);
    }
    void updateRange(int l, int r, ll val){
        update(l,val);
        update(r+1,-val);
    }
};

void matMul(vector<vector<ll>> &a, vector<vector<ll>> &b, vector<vector<ll>> &c){
    int n=a.size();
    int m=b[0].size();
    int k=b.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=0;l<k;l++){
                c[i][j]+=a[i][l]*b[l][j];
            }
        }
    }
}

void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(auto &i:arr){
            cin>>i;
        }
        vector<ll> arr2(n);
        for(auto &i:arr2){
            cin>>i;
        }
        vector<ll> csum(n+1);
        for(int i=0;i<n;i++){
            csum[i+1]=csum[i]+arr2[i];
        }
        vector<pair<ll,ll>> res;
        fenwicktree ft(n);
        for(int i=0;i<n;i++){
            int idx=lower_bound(csum.begin()+i,csum.end(),arr[i]+csum[i])-csum.begin();
            idx=min(idx,n);
            if(idx>i){
                ft.updateRange(i+1,idx-1,1);
                ll left=min(arr[i]-csum[idx-1]+csum[i],arr2[idx-1]);
                res.pb(mkp(idx,left));
            }
        }
        vector<ll> ans(n);
        for(int i=0;i<n;i++){
            ll res=ft.query(i+1);
            ans[i]=res*arr2[i];
        }
        for(auto &i:res){
            if(i.first-1<n)
            ans[i.first-1]+=i.second;
        }
        for(auto &i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
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
