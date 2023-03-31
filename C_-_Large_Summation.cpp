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
const ll mod = 1e9+7;
void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<ll,ll>> arr(n);
        vector<ll> p(n),c(n);
        fora(i,n){
            cin>>arr[i].first;
            arr[i].second=i;
            p[i]=arr[i].first;
        }
        // vector<int> x={1,2,4,4};
        // cout<<(upper_bound(x.begin(),x.end(),3)-x.begin())<<endl;
        sort(arr.begin(),arr.end());
        sort(p.begin(),p.end());
        map<ll,ll> mp;
        fora(i,n) mp[arr[i].second]=i;
        fora(i,n){
            ll ans=p[i]+p[n-1];
            if(i==n-1)ans=(p[i])+p[i-1];
            if(ans>=mod){
                int k=upper_bound(p.begin(),p.end(),mod-p[i]-1)-p.begin();
                k--;
                ans%=mod;
                if(k>=0 && k!=i)
                ans=max((p[i]+p[k]),ans);
                if(k==i){
                    k--;
                    if(k>=0)
                    ans=max((p[i]+p[k]),ans);
                }
            }
            c[arr[i].second]=ans;
        }
        fora(i,n) cout<<c[i]<<" ";
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
