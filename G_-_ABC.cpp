#include <bits/stdc++.h>
using namespace std;

#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define fo(i, j, n) for (i = j; i < n; i++)
#define cinn(x) \
    for (int i = 0; i < x.size(); i++) cin >> x[i];
#define printa(x) \
    for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
#define LL long long
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define sl2(x, y) scanf("%lld %lld", &x, &y)
#define sl3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define si2(x, y) scanf("%d %d", &x, &y);
#define si3(x, y, z) scanf("%d %d %d", &x, &y, &z);
#define ss(s) scanf("%s", s)
#define pis(x) printf("%d ", x)
#define pi(x) printf("%d", x)
#define pl(x) printf("%lld", x)
#define ps(s) printf("%s", s)
#define lb() printf("\n")
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define dbgA2(A, n, m)                    \
    {                                     \
        cout << "-->" << #A << "=\n";     \
        for (int i = 0; i < n; i++) {     \
            for (int j = 0; j < n; j++) { \
                cout << A[i][j] << " ";   \
            }                             \
            cout << "\n";                 \
        }                                 \
        cout << "\n";                     \
    }
#define dbgA(A, n)                                       \
    {                                                    \
        cout << "-->" << #A << "=(";                     \
        for (int i = 0; i < n; i++) cout << A[i] << " "; \
        cout << ")\n";                                   \
    }
#define dbg(args...)                                  \
    {                                                 \
        string sss(#args);                            \
        sss += ',';                                   \
        cout << "-->";                                \
        debugger::call(sss.begin(), sss.end(), args); \
        cout << "\n";                                 \
    }

struct debugger {
    typedef string::iterator si;

    static void call(si it, si ed) {}

    template <typename T, typename... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for (; *it != ','; ++it)
            if (*it != ' ') b += *it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};

int parent[10000 + 1];
int sz[10000 + 1];

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void union_set(int u, int v) {
    int a = find(u);
    int b = find(v);
    if (b < a) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}

struct triple {
    ll a, b, c;
};
ll binpow(ll n, ll k, ll mod){
    if(k==0){
        return 1;
    }
    ll res=binpow(n,k/2,mod);
    if(k&1){
        res*=res;
        res%=mod;
        res*=n;
        res%=mod;
        return res;
    }else{
        res*=res;
        res%=mod;
        return res;
    }
}
ll mod=1000000007;
vector<string> ss;
ll counts(string s,ll k, ll bound){
    if(s.size()>=bound){
        ll a_count=0,c_count=0;
        ll ck=k;
        ll index=s.size()-1;
        if(s.size()>=ck){
            while(ck--){
                a_count+=s[index]=='a' || s[index]=='b';
                c_count+=s[index]=='c';
                index--;
            }
            ll ans=0;
            if(a_count==c_count){
                ss.push_back(s);
                // cout<<s<<endl;
                return 1;
            }else{
                return 0;
            }
        }else{
            return 0;
        }
        
    }
    ll a_count=0,c_count=0;
    ll ck=k;
    ll index=s.size()-1;
    if(s.size()>=ck){
        while(ck--){
            a_count+=s[index]=='a' || s[index]=='b';
            c_count+=s[index]=='c';
            index--;
        }
        ll ans=0;
        if(a_count==c_count){
            ans=counts(s+'a',k,bound)+counts(s+'b',k,bound)+counts(s+'c',k,bound);
        }
        return ans;
    }else{
        ll ans=0;
        ans=counts(s+'a',k,bound)+counts(s+'b',k,bound)+counts(s+'c',k,bound);
        return ans;
    }
}
ll counts(string s,ll k, ll bound, ll pp){
    if(s.size()>=bound){
        ll a_count=0,c_count=0;
        ll ck=k;
        ll index=s.size()-1;
        if(s.size()>=ck){
            while(ck--){
                a_count+=s[index]=='a' || s[index]=='b';
                c_count+=s[index]=='c';
                index--;
            }
            for(int i=0;i<pp;i++){
                if(s[i]=='c'){
                    return 0;
                }
            }
            ll ans=0;
            if(a_count==c_count){
                ss.push_back(s);
                // cout<<s<<endl;
                return 1;
            }else{
                return 0;
            }
        }else{
            return 0;
        }
        
    }
    ll a_count=0,c_count=0;
    ll ck=k;
    ll index=s.size()-1;
    if(s.size()>=ck){
        while(ck--){
            a_count+=s[index]=='a' || s[index]=='b';
            c_count+=s[index]=='c';
            index--;
        }
        ll ans=0;
        if(a_count==c_count){
            ans=counts(s+'a',k,bound,pp)+counts(s+'b',k,bound,pp)+counts(s+'c',k,bound,pp);
        }
        return ans;
    }else{
        ll ans=0;
        ans=counts(s+'a',k,bound,pp)+counts(s+'b',k,bound,pp)+counts(s+'c',k,bound,pp);
        return ans;
    }
}
ll nCr(ll n, ll r, ll mod) {
    if (r > n - r) r = n - r;
    ll ans = 1;
    for (ll i = 1; i <= r; i++) {
        ans = (ans * (n - r + i)) % mod;
        ans = (ans * binpow(i, mod - 2, mod)) % mod;
    }
    return ans;
}
ll nPr(ll n, ll r, ll mod) {
    ll ans = 1;
    for (ll i = 1; i <= r; i++) {
        ans = (ans * (n - r + i)) % mod;
    }
    return ans;
}
void solve() {
    int n,k;
    cin>>n>>k;
    // if(k<=1 || k%2==1 || k>n){
    //     cout<<"0\n";
    //     return;
    // }
    // cout<<"real:"<<counts("",k,n,2)<<endl<<"Fake:";
    // if(n%2==0){
    //     ll blocks=n-n/k*k/2;
    //     ll ans=binpow(2,blocks,mod);
    //     ans%=mod;
    //     ans*=nCr(k,k/2,mod);
    //     ans%=mod;
    //     cout<<(ll)ans<<endl;
    //     assert(ans<mod);
    // }else{
    //     n--;
    //     ll blocks=n-n/k*k/2;
    //     ll ans=binpow(2,blocks,mod);
    //     ans%=mod;
    //     ans*=nCr(k,k/2,mod);
    //     ans%=mod;
    //     ll temp=binpow(2,blocks,mod);
    //     temp*=nCr(k,k/2,mod);
    //     temp%=mod;
    //     temp/=2;
    //     temp%=mod;
    //     ans+=temp;
    //     ans%=mod;
    //     cout<<ans<<endl;
    //     assert(ans<mod);
    // }
    cout<<counts("",k,n,2)<<endl;
    ll blocks=n-n/k*k/2;
    ll ans=binpow(2,blocks,mod);
    ans%=mod;
    ans*=nCr(k,k/2,mod);
    ans%=mod;
    ans/=nCr(2,1,mod);
    ans/=nCr(2,2,mod);
    ans%=mod;
    cout<<ans<<endl;
    sort(ss.begin(),ss.end());
    for(auto s:ss){
        cout<<s<<endl;
    }

}


void test(int n, int k){
    // if(k<=1 || k%2==1 || k>n){
    //     cout<<"0\n";
    //     return;
    // }
    // cout<<"real:"<<counts("",k,n)<<endl;
    // int left=n%k;
    // n-=left;
    // ll blocks=n-n/k*k/2;
    // ll ans=binpow(2,blocks,mod);
    // ans%=mod;
    // ans*=nCr(k,k/2,mod);
    // ans%=mod;
    // int ex=k-(left==0?k:left);
    // ll ans2=0;
    // dbg(ans);
    // for(int i=0;i<=min(ex,k/2);i++){
    //     dbg(nCr(k,i,mod));
    //     ll temp=ans/nCr(k,i,mod);
    //     temp%=mod;
    //     temp*=binpow(2,k-i,mod);
    //     temp%=mod;
    //     ans2+=temp;
    //     ans2%=mod;
    //     cout<<ans2 <<" "<<temp<<endl;
    // }
    
    // cout<<"Fake: ";
    // cout<<ans2<<endl;

}

int main() {
    // for(int i=1;i<=10;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<i<<" "<<j<<endl;
    //         test(i,j);
    //     }
    // }
    int t;
    cin>>t;
    while(t--){
        int n,k;
        ss={};
        // cin>>n>>k;
        solve();
        // test(n,k);
    }
    return 0;
}