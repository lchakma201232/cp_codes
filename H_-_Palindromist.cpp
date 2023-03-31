#include <bits/stdc++.h>
using namespace std;

#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define fo(i, j, n) for (i = j; i < n; i++)
#define cinn(x)                        \
    for (int i = 0; i < x.size(); i++) \
        cin >> x[i];
#define printa(x)                      \
    for (int i = 0; i < x.size(); i++) \
        cout << x[i] << " ";
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

#define dbgA2(A, n, m)                  \
    {                                   \
        cout << "-->" << #A << "=\n";   \
        for (int i = 0; i < n; i++)     \
        {                               \
            for (int j = 0; j < n; j++) \
            {                           \
                cout << A[i][j] << " "; \
            }                           \
            cout << "\n";               \
        }                               \
        cout << "\n";                   \
    }
#define dbgA(A, n)                   \
    {                                \
        cout << "-->" << #A << "=("; \
        for (int i = 0; i < n; i++)  \
            cout << A[i] << " ";     \
        cout << ")\n";               \
    }
#define dbg(args...)                                  \
    {                                                 \
        string sss(#args);                            \
        sss += ',';                                   \
        cout << "-->";                                \
        debugger::call(sss.begin(), sss.end(), args); \
        cout << "\n";                                 \
    }

struct debugger
{
    typedef string::iterator si;

    static void call(si it, si ed) {}

    template <typename T, typename... aT>
    static void call(si it, si ed, T a, aT... rest)
    {
        string b;
        for (; *it != ','; ++it)
            if (*it != ' ')
                b += *it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
struct stringhash
{
    ll m = 1e10 + 7;
    ll p = 31;
    long long p_pow = 1;
    long long p_pow2 = 1;
    ll fhash=0,hhash=0;
    
    ll fow_hash(char s, ll h_value, int t)
    {
        if (t == 1)
        {
            h_value = (h_value + ((ll)(s - 'a' + 1) * p_pow) % m) % m;
        }
        else
        {
            h_value = ((ll)(s - 'a' + 1) + (h_value * p) % m) % m;
        }
        p_pow = (p_pow * p) % m;

        fhash = h_value;
        return h_value;
    }
    ll rev_hash(char s, ll h_value, int t)
    {
        if (t == 0)
        {
            h_value = (h_value + ((ll)(s - 'a' + 1) * p_pow2) % m) % m;
        }
        else
        {
            h_value = ((ll)(s - 'a' + 1) + (h_value * p) % m) % m;
        }
        p_pow2 = (p_pow2 * p) % m;
        hhash = h_value;
        return h_value;
    }
    stringhash(string s){
        ll i;
        fo(i,0,s.size()){
            fow_hash(s[i],fhash,1);
            rev_hash(s[i],hhash,1);
        }
    }
    stringhash(){
        fhash=0;
        hhash=0;
    }
    void inithash(string s){
        ll i;
        fo(i,0,s.size()){
            fow_hash(s[i],fhash,1);
            rev_hash(s[i],hhash,1);
        }
    }
    bool calcHash(char c,int t){
        return fow_hash(c,fhash,t)==rev_hash(c,hhash,t);
    }
    bool getHash(){
        return fhash==hhash;
    }
};

void solve()
{
    string str;
    cin >> str;
    // string st = str;
    // reverse(st.begin(), st.end());
    int q;
    cin >> q;
    int n = str.size();
    // cout<<h1<<" "<<h2<<endl;
    stringhash h1, h2;
    h2.p=37;
    h1.inithash(str);
    h2.inithash(str);
    while (q--)
    {
        char a, b;
        ll p;
        cin >> a >> b >> p;
        // cout<<a<<" "<<b<<" "<<p<<"\n";
        ll t = 1;
        if (a == 'L')
            t = 0;
        for(int i=0;i<p;i++){
            h1.calcHash(b,t);
            h2.calcHash(b,t);
        }
        // cout<<h1.hhash<<" "<<h1.fhash<<" "<<h2.hhash<<" "<<h2.fhash<<endl;
        if (h1.getHash() && h2.getHash())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{

    int t = 1;

    Fast_io;

    cin >> t;
    int c = 1;
    while (t--)
    {
        cout << "Case " << c++ << ":\n";
        solve();
    }
    return 0;
}