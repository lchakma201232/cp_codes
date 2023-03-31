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
vector<ll> hash_array;
vector<ll> p_pow_array;
const int p = 31;
const int m = 1e7 + 9;
void compute_hash(string const& s) {
    int n = s.size();
    hash_array.resize(n);
    p_pow_array.resize(n);
    hash_array[0] = s[0] - 'a' + 1;
    p_pow_array[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow_array[i] = (p_pow_array[i - 1] * p) % m;
        hash_array[i] = (hash_array[i - 1] + (s[i] - 'a' + 1) * p_pow_array[i]) % m;
    }

}

ll get_hash(int l, int r) {
    int result = hash_array[r];
    if (l > 0)
        result = (result - hash_array[l - 1] + m) % m;
    result = (result * p_pow_array[hash_array.size() - l - 1]) % m;
    return result;
}
// ll mm[(int)(1e7+10)];
void run(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    compute_hash(s);
    vector<pair<ll,ll>> ms;
    for(ll i=2;i*i<=n+n;i++){
        for(int j=0;j<n;j++){
            if(j+i-1<n){
                ll h=get_hash(j,j+i-1);
                ms.push_back({h,i});
            }else{
                break;
            }
        }
    }
    ll ans=n;
    sort(ms.begin(),ms.end());
    for(int i=0;i<ms.size();i++){
        int j=i;
        while(j<ms.size() && ms[i].first==ms[j].first){
            j++;
        }
        ans+=(j-i)%ms[i].second==0?(j-i):0;
        i=j-1;
    }

    // for(auto it:m){

    //     ans+=it.second % m1[it.first]==0?it.second:0;
    // }
    cout<<ans<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
