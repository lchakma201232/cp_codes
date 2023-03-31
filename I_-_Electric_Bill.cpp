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
ll cwhToPrice(ll unit){
    vector<int> prices={2,3,5,7};
    vector<ll> units={100,9900,990000,99000000};
    ll cost=0;
    fora(i,3){
        if(unit>units[i]){
            unit-=units[i];
            cost+=units[i]*prices[i];
        }else{
            cost+=unit*prices[i];
            unit-=unit;
            break;
        }
    }
    cost+=unit*prices[3];
    return cost;
}
ll priceToCwh(ll price){
    vector<ll> prices={2,3,5,7};
    vector<ll> units={100,9900,990000,99000000};
    ll unit=0;
    fora(i,3){
        if(price>units[i]*prices[i]){
            price-=units[i]*prices[i];
            unit+=units[i];
        }else{
            unit+=price/prices[i];
            price-=price;
            break;
        }
    }
    unit+=price/prices[3];
    return unit;
}
int bsearch(int l, int r, int a, int b){
    if(l==r) return cwhToPrice(l);
    int mid=(l+r)/2;
    int others=priceToCwh(a)-mid;
    int cost_diff=cwhToPrice(others)-cwhToPrice(mid);
    if(cost_diff==b) return cwhToPrice(mid);
    if(cost_diff>b) return bsearch(mid+1,r,a,b);
    return bsearch(l,mid,a,b);
}
void run(){
    int a,b;
    while(cin>>a>>b){
        if(a==0&&b==0) break;
        int res=bsearch(0,priceToCwh(a),a,b);
        cout<<res<<endl;
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
