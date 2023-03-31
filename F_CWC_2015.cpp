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
void generate(vector<int> &arr,int i,int j,vector<pair<int,ll>> &ans,int counter,int sum){
    if(i==j){
        ans.pb(mkp(counter,sum));
        return;
    }
    generate(arr,i+1,j,ans,counter,sum);
    generate(arr,i+1,j,ans,counter+1,sum+arr[i]);
}
void run(){
    int t;
    cin>>t;
    int ccase=1;
    while(t--){
        int n;
        cin>>n;
        cout<<"Case "<<ccase++<<": ";
        vector<int> arr;
        ll tsum=0;
        fora(i,n){
            int x;
            cin>>x;
            arr.pb(x);
            tsum+=x;
        }
        if(tsum&1) {
            cout<<"No\n";
            continue;
        }
        tsum/=2;
        sort(arr.begin(),arr.end());
        vector<pair<int,ll>> ans1,ans2;
        generate(arr,0,n/2,ans1,0,0);
        generate(arr,n/2,n,ans2,0,0);
        sort(ans2.begin(),ans2.end());
        bool ok=0;
        // cout<<tsum<<endl;
        fora(i,ans1.size()){
            int res=binary_search(ans2.begin(),ans2.end(),mkp(n/2-ans1[i].first,tsum-ans1[i].second));
            if(res){
                ok=1;
                break;
            }
        }
        if(ok){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
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
