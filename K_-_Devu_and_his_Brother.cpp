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
ll f(int x,vector<int> &a,vector<int> &b){
    ll ans = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] > x)break;
        ans += x-a[i];
    }
    for(int i = b.size()-1; i >=0; i--){
        if(b[i] < x)break;
        ans += b[i]-x;
    }
    return ans;
}

void run(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    fora(i,n)cin>>a[i];
    fora(i,m)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int left = min(a[0], b[0]);
    int right = max(a[n-1], b[m-1]);
    ll ans = 0;
    while(left<=right){
        ll mid = (right - left) / 3;
        ll mid1 = left + mid;
        ll mid2 = right - mid;
        ll f1 = f(mid1,a,b);
        ll f2 = f(mid2,a,b);
        if(f1 < f2){
            ans = mid1;
            right = mid2 - 1;
        }
        else{
            ans = mid2;
            left = mid1 + 1;
        }
        
    }
    cout<<f(ans,a,b)<<endl;

}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
