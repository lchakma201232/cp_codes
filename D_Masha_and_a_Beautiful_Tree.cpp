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
bool can(int l,int r, int start,int end,vector<int> &arr){
    if(l==r){
        // cout<<start<<" "<<end<<" "<<arr[l]<<endl;
        return arr[l]==start;
    }
    int mid=(l+r)/2;
    int m2=(start+end)/2;
    bool res=can(l,mid,start,m2,arr) && can(mid+1,r,m2+1,end,arr);
    res|=can(l,mid,m2+1,end,arr) && can(mid+1,r,start,m2,arr);
    return res;
}
int counter=0;
vector<int> count(int l,int r,vector<int> &arr){
    if(l==r){
        return {arr[l]};
    }
    int mid=(l+r)/2;
    vector<int> v1=count(l,mid,arr);
    vector<int> v2=count(mid+1,r,arr);
    int a=v1[0],b=v1[v1.size()-1],c=v2[0],d=v2[v2.size()-1];
    vector<int> res;
    if(b<c){
        fora(i,v1.size())res.pb(v1[i]);
        fora(i,v2.size())res.pb(v2[i]);
    }else{
        counter++;
        fora(i,v2.size())res.pb(v2[i]);
        fora(i,v1.size())res.pb(v1[i]);
    }
    return res;
}
void run(){
    int t;
    cin>>t;
    while(t--){
        counter=0;
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // cout<<"hehe"<<endl;
        // cout<<can(0,n-1,1,n,arr)<<"\n";
        if(can(0,n-1,1,n,arr)){
            counter=0;
            count(0,n-1,arr);
            cout<<counter<<"\n";
        }
        else{
            cout<<"-1\n";
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
