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
#define ull unsigned ll
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
    int n;
    cin>>n;
    vector<ll> arr(n);
    vector<vector<ll>> sq(sqrt(n)+1);
    ll len=sqrt(n)+1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sq[i/len].push_back(arr[i]);
    }
    for(auto &x:sq){
        sort(x.begin(),x.end());
    }
    int q;
    cin>>q;
    int last=0;
    while(q--){
        ll i,j,k;
        cin>>i>>j>>k;
        i^=last;
        j^=last;
        k^=last;
        if(i<1)i=1;
        if(j>n)j=n;
        if(i>j){
            last=0;
            cout<<0<<endl;
            continue;
        }
        i--;
        j--;
        ll ans=0;
        ll l=i/len;
        ll r=j/len;
        if(l==r){
            for(ll x=i;x<=j;x++){
                if(arr[x]>k)ans++;
            }
            last=ans;
            cout<<ans<<endl;
            continue;
        }
        for(ll x=i;x<(l+1)*len;x++){
            if(arr[x]>k)ans++;
        }
        for(ll x=r*len;x<=j;x++){
            if(arr[x]>k)ans++;
        }
        for(ll x=l+1;x<r;x++){
            ans+=sq[x].end()-upper_bound(sq[x].begin(),sq[x].end(),k);
        }
        last=ans;
        cout<<ans<<endl;
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
