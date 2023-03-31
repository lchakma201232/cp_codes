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
void dfs(vector<vector<int>> &graph,int u,vector<int> &nodes){
    nodes.push_back(u);
    if(graph[u].size()==0){
        cout<<nodes.size()<<endl;
        for(int i=0;i<nodes.size();i++){
            cout<<nodes[i]+1<<" ";
        }
        cout<<endl;
        nodes=vector<int>();
        return;
    }
    for(auto v:graph[u]){
        dfs(graph,v,nodes);
    }
}
void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        int root;
        vector<int> leafs(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==i+1){
                root=i;
            }
            leafs[arr[i]-1]++;
        }
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                graph[arr[i]-1].push_back(i);
            }
        }
        int counter=0;
        fora(i,n){
            if(leafs[i]==0){
                counter++;
            }
        }
        vector<int> nodes;
        cout<<(counter==0?1:counter)<<endl;
        dfs(graph,root,nodes);
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
