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
int find(map<int,int> &parents, int x){
    if(parents[x]==x)
        return x;
    return parents[x]=find(parents,parents[x]);
}

bool join(map<int,int> &parents, int x, int y){
    int xset = find(parents,x);
    int yset = find(parents,y);
    if(xset!=yset){
        parents[xset]=yset;
        return true;
    }
    return false;
}
void run(){
    int t;
    cin>>t;
    forb(tt,t){
        cout<<"Case #"<<tt<<": ";
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        fora(i,n)cin>>arr[i];
        map<int,int> parents,parents2;
        fora(i,n)parents2[arr[i]]=parents[arr[i]]=arr[i];
        parents[-1]=-1;
        parents[-1]=-1;
        bool ok=true;
        int k2=k;
        fora(i,n){
            if(k&& join(parents,-1,arr[i])){
                // cout<<arr[i]<<">";
                k--;
            }else if(k2&&join(parents2,-2,arr[i])){
                // cout<<arr[i]<<"<";
                k2--;
            }else{
                ok=false;
                break;
            }
        }
        if(!ok){
            cout<<"NO"<<endl;
            continue;
        }else{
            cout<<"YES"<<endl;
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
