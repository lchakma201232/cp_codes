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
        int r,c,w;
        cin>>r>>c>>w;
        vector<string> arr(r);
        fora(i,r)cin>>arr[i];
        vector<vector<ll>> dp(r,vector<ll>(c,1e18));
        int x,y;
        int first_x,first_y;
        int second_x,second_y;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]=='D'){
                    x=i;
                    y=j;
                }
                if(arr[i][j]=='1'){
                    first_x=i;
                    first_y=j;
                }
                if(arr[i][j]=='2'){
                    second_x=i;
                    second_y=j;
                }
            }
        }
        dp[first_x][first_y]=0;
        int counter=1;
        for(int i=0;i<=(r+c);i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    if(arr[j][k]!='#' && dp[j][k]==counter-1){
                        for(int l=1;l<=counter;l++){
                            if(j+l<r && arr[j+l][k]!='#'){
                                dp[j+l][k]=min(dp[j+l][k],dp[j][k]+1);
                            }else{
                                break;
                            }
                        }
                        for(int l=1;l<=counter;l++){
                            if(j-l>=0 && arr[j-l][k]!='#'){
                                dp[j-l][k]=min(dp[j-l][k],dp[j][k]+1);
                            }else{
                                break;
                            }
                        }
                        for(int l=1;l<=counter;l++){
                            if(k+l<c && arr[j][k+l]!='#'){
                                dp[j][k+l]=min(dp[j][k+l],dp[j][k]+1);
                            }else{
                                break;
                            }
                        }
                        for(int l=1;l<=counter;l++){
                            if(k-l>=0 && arr[j][k-l]!='#'){
                                dp[j][k-l]=min(dp[j][k-l],dp[j][k]+1);
                            }else{
                                break;
                            }
                        }
                    }
                }
            }
            counter++;
        }
        ll countfirst=dp[x][y];
        dp=vector<vector<ll>>(r,vector<ll>(c,1e18));
        dp[second_x][second_y]=0;
        counter=1;
        for(int i=0;i<=(r+c);i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    if(arr[j][k]!='#' && dp[j][k]==counter-1){
                        for(int l=1;l<=counter;l++){
                            if(j+l<r && arr[j+l][k]!='#'){
                                dp[j+l][k]=min(dp[j+l][k],dp[j][k]+1);
                            }else{
                                break;
                            }
                        }
                        for(int l=1;l<=counter;l++){
                            if(j-l>=0 && arr[j-l][k]!='#'){
                                dp[j-l][k]=min(dp[j-l][k],dp[j][k]+1);
                            }else{
                                break;
                            }
                        }
                        for(int l=1;l<=counter;l++){
                            if(k+l<c && arr[j][k+l]!='#'){
                                dp[j][k+l]=min(dp[j][k+l],dp[j][k]+1);
                            }else{
                                break;
                            }
                        }
                        for(int l=1;l<=counter;l++){
                            if(k-l>=0 && arr[j][k-l]!='#'){
                                dp[j][k-l]=min(dp[j][k-l],dp[j][k]+1);
                            }else{
                                break;
                            }
                        }
                    }
                }
            }
            counter++;
        }
        ll countsecond=dp[x][y];
        // cout<<countfirst<<" "<<countsecond<<endl;
        if(countfirst==1e18 || countsecond==1e18){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            if(w==1){
                cout<<(countfirst<=countsecond?"Saif":"Sabi")<<endl;
            }else{
                cout<<(countsecond<=countfirst?"Sabi":"Saif")<<endl;
            }
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
