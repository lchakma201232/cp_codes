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
const int mod = 1e9+7;
void add_self(ll &a, ll b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
}
void add_self(int &a, int b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
}

ll mul(ll a, ll b){
    return ((ll)a*b)%mod;
}

struct Matrix{
    int n;
    vector<vector<ll>> mat;
    Matrix(int n){
        this->n = n;
        mat.resize(n,vector<ll>(n,0));
    }

    Matrix operator*(Matrix &b) const{
        Matrix res(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    add_self(res.mat[i][k],mul(mat[i][j],b.mat[j][k]));
                }
            }
        }
        return res;
    }
};
void run(){
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> g(n,vector<ll>(n,0));
    fora(i,n){
        fora(j,n){
            cin>>g[i][j];
        }
    }
    Matrix m(n);
    m.mat = g;
    Matrix ans = Matrix(n);
    fora(i,n){
        ans.mat[i][i] = 1;
    }
    while(k){
        if(k%2){
            ans = ans*m;
        }
        m = m*m;
        k/=2;
    }
    ll total = 0;
    fora(i,n){
        fora(j,n){
            add_self(total,ans.mat[i][j]);
        }
    }
    cout<<total<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
