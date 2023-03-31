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
bool isCorners(vector<string> &arr,int x,int y){
    if(x==0 && y==0 || x==0 && y==arr[0].size()-1 || x==arr.size()-1 && y==0 || x==arr.size()-1 && y==arr[0].size()-1){
        return true;
    }
    int corners[4][4]={{-1,0,0,1},{-1,0,0,-1},{1,0,0,1},{1,0,0,-1}};
    int ignores[4][4]={{-1,0,1,0},{0,-1,0,1}};
    int corn[][2]={{-1,-1},{1,1},{-1,1},{1,-1}};
    for(int i=0;i<4;i++){
        int x1=x+corners[i][0];
        int y1=y+corners[i][1];
        int x2=x+corners[i][2];
        int y2=y+corners[i][3];
        if(x1>=0 && x1<arr.size() && y1>=0 && y1<arr[0].size() && x2>=0 && x2<arr.size() && y2>=0 && y2<arr[0].size()){
            if(arr[x1][y1]=='1' && arr[x2][y2]=='1'){
                cout<<x<<" "<<y<<endl;
                bool ok=true;
                for(int j=0;j<2;j++){
                    int x3=x+ignores[j][0];
                    int y3=y+ignores[j][1];
                    int x4=x+ignores[j][2];
                    int y4=y+ignores[j][3];
                    if(x3>=0 && x3<arr.size() && y3>=0 && y3<arr[0].size() && x4>=0 && x4<arr.size() && y4>=0 && y4<arr[0].size()){
                        if(arr[x3][y3]=='1' && arr[x4][y4]=='1'){
                            ok=false;
                            break;
                        }
                    }
                }
                if(ok){
                    return true;
                }
            }
        }
    }
    return false;
}
bool isCorner(vector<string> &arr, int x,int y){
    if(x==0 && y==0 || x==0 && y==arr[0].size()-1 || x==arr.size()-1 && y==0 || x==arr.size()-1 && y==arr[0].size()-1){
        return true;
    }
    int directions[][2]={{-1,0},{0,-1},{1,0},{0,1}};
    int counter=0;
    for(int i=0;i<4;i++){
        int x1=x+directions[i][0];
        int y1=y+directions[i][1];
        if(x1>=0 && x1<arr.size() && y1>=0 && y1<arr[0].size()){
            if(arr[x1][y1]=='1'){
                counter++;
            }
        }
        
    }
    int corners[4][4]={{-1,0,0,1},{-1,0,0,-1},{1,0,0,1},{1,0,0,-1}};
    if(counter==0 || counter==1){
        return true;
    }
    if(counter==2){
        for(int i=0;i<4;i++){
            int x1=x+corners[i][0];
            int y1=y+corners[i][1];
            int x2=x+corners[i][2];
            int y2=y+corners[i][3];
            if(x1>=0 && x1<arr.size() && y1>=0 && y1<arr[0].size() && x2>=0 && x2<arr.size() && y2>=0 && y2<arr[0].size()){
                if(arr[x1][y1]=='1' && arr[x2][y2]=='1'){
                    return true;
                }
            }
        }
    }else if(counter==4){
        int corn[][2]={{-1,-1},{1,1},{-1,1},{1,-1}};
        for(int i=0;i<4;i++){
            int x1=x+corn[i][0];
            int y1=y+corn[i][1];
            if(x1>=0 && x1<arr.size() && y1>=0 && y1<arr[0].size()){
                if(arr[x1][y1]=='0'){
                    return true;
                }
            }
        }
    }
    return false;
}
void run(){
    int t;
    cin>>t;
    int tt=1;
    while(t--){
        cout<<"Case "<<tt++<<": ";
        int n,m;
        cin>>n>>m;
        vector<string> arr(n);
        fora(i,n)cin>>arr[i];
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='1'){
                    if(isCorner(arr,i,j)){
                        ans[i][j]=1;
                    }
                }
            }
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<ans[i][j];
                sum+=ans[i][j];
            }
            // cout<<endl;
        }
        cout<<sum<<endl;
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
