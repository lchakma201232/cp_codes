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
struct game{
    int a,b,c,d;
};
int n,k,x;
unordered_map<int,int> mp[2001];
int getMax(vector<game> &arr, int i,int curr){
    if(i==arr.size()){
        return curr+x;
    }
    if(mp[i].find(curr)!=mp[i].end()){
        return mp[i].find(curr)->second;
    }
    int ans=-1e9;
    if((x-k)>curr+x){
        ans=max(getMax(arr,i+1,curr+(arr[i].c==1?arr[i].a:-arr[i].b)),ans);
    }else if((x+k)<curr+x){
        ans=max(ans,getMax(arr,i+1,curr+(arr[i].d==1?arr[i].a:-arr[i].b)));
    }else{
        ans=max(getMax(arr,i+1,curr+(arr[i].c==1?arr[i].a:-arr[i].b)),getMax(arr,i+1,curr+(arr[i].d==1?arr[i].a:-arr[i].b)));
    }
    return mp[i][curr]=ans;
}

void run(){
    cin>>n>>k>>x;
    vector<game> v;
    fora(i,n){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v.pb({a,b,c,d});
    }
    cout<<getMax(v,0,0);
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
