#include <bits/stdc++.h>
using namespace std;

#define fo(i, j, n) for (i = j; i < n; i++)
#define cinn(x) \
    for (int i = 0; i < x.size(); i++) cin >> x[i];
#define printa(x) \
    for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
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
void solve() {
    vector<vector<int>> a(5, vector<int>(5, 0));
    int n = 5;
    int b = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char k;
            cin >> k;
            if (k == 'k') {
                b++;
                a[i][j] = 1;
            }
        }
    }

    if (b != 9) {
        cout << "invalid\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           if (a[i][j]) {
                vector<vector<int>>  b = {
                    {2, 1},
                    {2, -1},
                    {-2, 1},
                    {-2, -1},
                    {1, -2},
                    {-1, -2},
                    {1, 2},
                    {-1, 2}
                };

                for (auto it: b) {
                    if (i + it[0] >= 0 && i + it[0] < 5 && j + it[1] >= 0 && j + it[1] < n 
                    && a[i + it[0]][j + it[1]]) {
                        cout << "invalid\n";
                        return;
                    }
                }
           }
        }
    }
    cout << "valid\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // si(t);
    while (t--) {
        solve();
    }
    return 0;
}