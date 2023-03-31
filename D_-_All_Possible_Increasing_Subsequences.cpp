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
const int mod =1000000007;
vector<int> arr,sorted_arr;
vector<int> mn;
map<int,int> mp;
void update(int node, int l, int r, int idx, int val){
    if(idx>r || idx<l){
        return;
    }
    if(idx<=l && r<=idx){
        // cout<<"yes"<<endl;
        // cout<<l <<" "<<r<<endl;
        mn[node]=((mn[node]+val)%mod+mod)%mod;
        return;
    }
    int mid=(l+r)/2;
    update(2*node,l,mid,idx,val);
    update(2*node+1,mid+1,r,idx,val);
    mn[node]=((mn[2*node]+mn[2*node+1])%mod+mod)%mod;
}
int query(int node, int l, int r, int start,int end){
    if(r<start || l>end){
        return 0;
    }
    if( l >=start && r<=end){
        cout<<l<<" "<<r<<endl;
        return mn[node];
    }
    int mid=(l+r)/2;
    int lmn=query(2*node,l,mid,start,end);
    int rmn=query(2*node+1,mid+1,r,start,end);
    return ((lmn+rmn)%mod+mod)%mod;
}
void run(){
    int t;
    cin>>t;
    int tt=1;
    while(t--){
        cout<<"Case "<<tt++<<": ";
        int n;
        cin>>n;
        arr=vector<int>(n);
        sorted_arr=vector<int>(n);
        mn=vector<int>(4*n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sorted_arr[i]=arr[i];
        }
        sort(sorted_arr.begin(),sorted_arr.end());
        sorted_arr.erase(unique(sorted_arr.begin(),sorted_arr.end()),sorted_arr.end());
        for(int i=0;i<sorted_arr.size();i++){
            mp[sorted_arr[i]]=i+1;
        }
        fora(i,n){
            int q=query(1,1,sorted_arr.size(),1,mp[arr[i]]-1)+1;
            // cout<<q<<" "<<arr[i]<<endl;
            update(1,1,sorted_arr.size(),mp[arr[i]],q);
        }
        cout<<mn[1]<<endl;

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
