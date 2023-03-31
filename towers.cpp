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
bool solveSudoku(vector<vector<int>> &a, int n, int i, int j){
    if(i==n){
        return true;
    }
    if(j==n){
        return solveSudoku(a,n,i+1,0);
    }
    if(a[i][j]!=0){
        return solveSudoku(a,n,i,j+1);
    }
    for(int k=1;k<=n;k++){
        bool flag=true;
        for(int l=0;l<n;l++){
            if(a[i][l]==k){
                flag=false;
                break;
            }
        }
        if(flag){
            for(int l=0;l<n;l++){
                if(a[l][j]==k){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            int x=i/3;
            int y=j/3;
            for(int l=3*x;l<3*x+3;l++){
                for(int m=3*y;m<3*y+3;m++){
                    if(a[l][m]==k){
                        flag=false;
                        break;
                    }
                }
            }
        }
        if(flag){
            a[i][j]=k;
            if(solveSudoku(a,n,i,j+1)){
                return true;
            }
            a[i][j]=0;
        }
    }
    return false;
}
void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(n));
        fora(i,n){
            fora(j,n){
                char x;
                cin>>x;
                if(x!='-'){
                    a[i][j]=x-'0';
                }
            }
        }
        bool result=solveSudoku(a,n,0,0);
        if(result){
            fora(i,n){
                fora(j,n){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else{
            cout<<"no"<<endl;
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
