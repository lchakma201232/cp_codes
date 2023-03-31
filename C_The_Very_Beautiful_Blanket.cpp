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
void check(vector<vector<int>> &arr){
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<arr.size()-3;i++){
        for(int j=0;j<arr[i].size()-3;j++){
            int ans=0;
            for(int k=0;k<2;k++){
                ans^=arr[i][j+k];
                
            }
            for(int k=0;k<2;k++){
                ans^=arr[i+1][j+k];
            }
            for(int k=0;k<2;k++){
                ans^=arr[i+2][j+k+2];
                ans^=arr[i+3][j+k+2];
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}
void check2(vector<vector<int>> &arr){
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<arr.size()-3;i++){
        for(int j=0;j<arr[i].size()-3;j++){
            int ans=0;
            for(int k=0;k<2;k++){
                ans^=arr[i+2][j+k];
                ans^=arr[i+3][j+k];
            }
            for(int k=0;k<2;k++){
                ans^=arr[i][j+k+2];
                ans^=arr[i][j+k+2];
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}
void run(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(n,vector<int>(m));
        int last=0;
        int counter=10;
        for(int i=0;i<n;i+=2){
            for(int j=0;j<m;j+=2){
                for(int k=0;k<2;k++){
                    if(j+k<m)
                    arr[i][j+k]=last+k;
                }
                for(int k=0;k<2;k++){
                    if(i+k<m && i+1<n)
                    arr[i+1][j+k]=last+k+2;
                }
                last+=10;
            }
        }
        check(arr);
        check2(arr);
        dbgA2(arr,n,m);

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
