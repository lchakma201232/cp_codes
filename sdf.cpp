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
map<char,string> mp;
map<ll,string> mp2;
// map<char,char> mp2;
__int128_t stringToLongLong(string s){
    __int128_t ans=0;
    for(int i=0;i<s.size();i++){
        ans*=10;
        ans+=s[i]-'0';
    }
    return ans;
}
__int128_t baseChanger(string s, int base){
    __int128_t ans=0;
    for(int i=0;i<s.size();i++){
        ans*=base;
        string temp=mp[s[i]];
        // cerr<<mp[s[i]]<<endl;

        ans+=stringToLongLong(temp);
    }
    return ans;
}
string toString(__int128_t n){
    string ans="";
    while(n){
        ans+=n%10+'0';
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string base10tobase11(__int128_t n){
    string ans="";
    //after 11 comes 1 
    // n--;
    while(n){
        // cout<<n<<endl;
        string temp=toString(n);
        // cerr<<temp<<endl;
        cout<<(ll)(stringToLongLong(temp)%11)<<endl;
        ans+=mp2[stringToLongLong(temp)%11];
        n/=11LL;
    }
    reverse(ans.begin(),ans.end());
    // for(int i=1;i<ans.size();i++){
    //     // ans.pop_back();
    //     // // ans[]
        
    //     int ind=i;
    //     while(ind>0 && ans[ind]=='0'){
    //         char c=ans[ind-1];
    //         // cerr<<c<<endl;
    //         int index=stringToLongLong(mp[c]);
    //         ans[ind-1]=mp2[index-1][0];
    //         ans[ind]=('Y');
    //         ind--;
    //     }
    // }
    // if(ans[0]=='0'){
    //     ans.erase(ans.begin());
    // }
    return ans;
}
void run(){
    // A, H, I, M, O, T, U, V, W, X, Y
    mp['A']="1";
    mp['H']="2";
    mp['I']="3";
    mp['M']="4";
    mp['O']="5";
    mp['T']="6";
    mp['U']="7";
    mp['V']="8";
    mp['W']="9";
    mp['X']="10";
    mp['Y']="11";
    mp2[0]="0";
    mp2[1]="A";
    mp2[2]="H";
    mp2[3]="I";
    mp2[4]="M";
    mp2[5]="O";
    mp2[6]="T";
    mp2[7]="U";
    mp2[8]="V";
    mp2[9]="W";
    mp2[10]="X";
    mp2[11]="Y";


    int t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        string s;
        cin>>s;
        __int128_t ans=baseChanger(s,11);
        // cout<<ans<<endl;
        // cout<<ans<<endl;
        // cout<<(ll)ans<<endl;
        cout<<base10tobase11(ans)<<endl;

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
