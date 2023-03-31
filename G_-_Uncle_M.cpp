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
ll arr[1000][1000];
ll csum[1001][1001];
ll csqsum[1001][1001];


void run(){
    int r,c;
    cin>>r>>c;
    fora(i,r){
        fora(j,c){
            cin>>arr[i][j];
            csum[i+1][j+1]=arr[i][j];
            csqsum[i+1][j+1]=arr[i][j]*arr[i][j];
        }
    }
    forb(i,r){
        forb(j,c){
            csum[i][j]+=csum[i][j-1];
        }
    }
    forb(i,r){
        forb(j,c){
            csqsum[i][j]+=csqsum[i][j-1];
        }
    }
    // dbgA2(csum,r+1,c+1);
    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        double sum=0;
        double sqsum=0;
        for(int i=x1;i<=x2;i++){
            sum+=csum[i][y2]-csum[i][y1-1];
            sqsum+=csqsum[i][y2]-csqsum[i][y1-1];
        }
        double n=(x2-x1+1)*(y2-y1+1);
        double p = pow(1/(double)n*sum,2);
        double ans=p*n-2*sum/n*sum + sqsum;
        cout<<fixed<<setprecision(10)<<ans/n<<endl;
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
