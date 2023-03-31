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

void run(){
    int t;
    cin>>t;
    int tt=1;
    while(t--){
        cout<<"Case "<<tt++<<": ";
        int n,m;
        cin>>n>>m;
        vector<string> graph(n);
        fora(i,n)cin>>graph[i];
        vector<vector<int>> fires(n,vector<int>(m,0));
        vector<vector<ll>> janes(n,vector<ll>(m,1e9));
        fora(i,n){
            fora(j,m){
                if(graph[i][j]=='F'){
                    fires[i][j]=1;
                }
                if(graph[i][j]=='J'){
                    janes[i][j]=0;
                }
            }
        }
        for(int time=0;time<n;time++){
            vector<vector<int>> new_fires(n,vector<int>(m,0));
            vector<vector<ll>> new_janes(n,vector<ll>(m,1e9));
            fora(i,n){
                fora(j,m){
                    if(fires[i][j]){
                        if(i>0 && graph[i-1][j]!='#')new_fires[i-1][j]=1;
                        if(i<n-1 && graph[i+1][j]!='#')new_fires[i+1][j]=1;
                        if(j>0 && graph[i][j-1]!='#')new_fires[i][j-1]=1;
                        if(j<m-1 && graph[i][j+1]!='#')new_fires[i][j+1]=1;
                        new_fires[i][j]=1;
                    }
                }
            }
            bool ok=0;
            fora(i,n){
                fora(j,m){
                    if(janes[i][j]==time){
                        ok=1;
                        if(i>0 && (!new_fires[i-1][j] && graph[i-1][j]!='#'))new_janes[i-1][j]=min(new_janes[i-1][j],janes[i][j]+1);
                        if(i<n-1 && (!new_fires[i+1][j] && graph[i+1][j]!='#' ))new_janes[i+1][j]=min(new_janes[i+1][j],janes[i][j]+1);
                        if(j>0 && (!new_fires[i][j-1] && graph[i][j-1]!='#'))new_janes[i][j-1]=min(new_janes[i][j-1],janes[i][j]+1);
                        if(j<m-1 && (!new_fires[i][j+1] && graph[i][j+1]!='#'))new_janes[i][j+1]=min(new_janes[i][j+1],janes[i][j]+1);
                    }
                    if(janes[i][j]<new_janes[i][j])new_janes[i][j]=janes[i][j];
                }
            }
            if(!ok)break;
            // dbgA2(janes,n,m);
            fires=new_fires;
            janes=new_janes;
        }
        // dbgA2(fires,n,m);

        // dbgA2(janes,n,m);
        int ans=1e9;
        fora(i,n){
            if(janes[i][0]<ans)ans=janes[i][0];
            if(janes[i][m-1]<ans)ans=janes[i][m-1];
        }
        fora(i,m){
            if(janes[0][i]<ans)ans=janes[0][i];
            if(janes[n-1][i]<ans)ans=janes[n-1][i];
        }
        // cout<<ans<<endl;
        if(ans>=1e9){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<ans+1<<endl;
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
