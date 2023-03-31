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

int bsearch(int l,int r,vector<pair<int,int>> &pp,int total){
    if(l>=r) return r;
    int mid=(l+r)/2;
    if(((mid-pp[0].first)*pp[0].second + (mid-pp[1].first)*pp[1].second)<=total && ((mid+1-pp[0].first)*pp[0].second + (mid+1-pp[1].first)*pp[1].second)>total){
        return mid;
    }else if(((mid-pp[0].first)*pp[0].second + (mid-pp[1].first)*pp[1].second)<total){
        return bsearch(mid+1,r,pp,total);
    }else{
        return bsearch(l,mid,pp,total);
    }
}

void run(){
    string s;
    cin>>s;
    vector<pair<int,int>> nums(3);
    fora(i,3){
        cin>>nums[i].first;
    }
     fora(i,3){
        cin>>nums[i].second;
    }
    int r;
    cin>>r;
    unordered_map<char,int> p;
    p['B']=0;
    p['S']=1;
    p['C']=2;
    int unitCost=0;
    for(auto &x:s) unitCost+=p[x];
    sort(nums.begin(),nums.end());
    int counter=nums[0].first;
    if(nums[0].first!=nums[2].first){
        int x=bsearch(nums[0].first,nums[2].first,nums,r);
        

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
