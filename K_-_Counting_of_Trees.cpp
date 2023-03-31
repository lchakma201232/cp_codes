#include <bits/stdc++.h>
using namespace std;

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

const int MOD = 998244353;

long long fac[100001];

void fact() {
    fac[0] = 1;
    for (int i = 1; i <= 100000; i++) fac[i] = (fac[i - 1] * i) % MOD;
}

unsigned long long power(unsigned long long x, int y, int p) {
    unsigned long long res = 1;  // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res * x) % p;

        // y must be even now
        y = y >> 1;  // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p) {
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
    // If n<r, then nCr should return 0
    if (n < r) return 0;
    // Base case
    if (r == 0) return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) %
            p) %
           p;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> x(n);
    ll mx=0;
    int f = 0;
    for (int i = 0; i < n; i++) {
        ll k; 
        cin >> k;
        x[k]++;
        if (i == 0 && k!=0) {
            f = 1;
        }
        mx=max(k,mx);
    }   
    if (f || x[0] > 1) {
        cout << 0 << "\n";
        return; 
    }
    ll ans = 1;
    for (int i = 0; i < mx; i++) {
        if(x[i]==0 && x[i+1]==0){
            ans=0;
            break;
        };
        ll pows=(ll)pow(x[i], x[i+1]) % MOD;
        ans = (ans * pows % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    // si(t);
    while (t--) {
        solve();
    }
    return 0;
}