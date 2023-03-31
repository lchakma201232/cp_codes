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
void run(){
    ll l=0,r=60;
    ll n=0;
    string last="yes";
    while(l<r){
        ll mid=(l+r)/2;
        if(n==3){
            cout<<"? "<<1<<endl;
            string response;
            cin>>response;
        }
        cout<<"? "<<(ll)pow(2,mid)<<endl;
        string response;
        cin>>response;
        assert(response=="YES" || response=="NO");
        if(response=="yes"){
            last=response;
            l=mid+1;
        }else{
            n=(last=="no" ?n+1:1);
            last=response;
            r=mid;
        }
        // n++;
    }
    // cout<<n<<endl;
    cout<<"! "<<(ll)pow(2,l-1)<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
