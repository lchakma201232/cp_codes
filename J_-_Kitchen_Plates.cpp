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
vector<char> toposort;
bool dfs(int v, vector<vector<int>> &v1, vector<int> &visited, vector<int> &stack){
    if(visited[v]==1){
        return true;
    }
    if(visited[v]==2){
        return false;
    }
    visited[v]=1;
    stack[v]=1;
    for(auto i:v1[v]){
        if(stack[i]||dfs(i,v1,visited,stack)){
            return true;
        }
    }
    stack[v]=0;
    visited[v]=2;
    toposort.pb(v+'A');
    return false;
}
void run(){
    vector<vector<int>> v(5);
    fora(i,5){
        string s;
        cin>>s;
        if(s[1]=='>'){
            v[s[0]-'A'].pb(s[2]-'A');
        }else{
            v[s[2]-'A'].pb(s[0]-'A');
        }
    }
    vector<int> visited(5,0);
    vector<int> stack(5,0);
    fora(i,5){
        if(!visited[i]){
            if(dfs(i,v,visited,stack)){
                cout<<"impossible";
                return;
            }
        }
    }
    // reverse(toposort.begin(),toposort.end());
    for(auto i:toposort){
        cout<<i;
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
