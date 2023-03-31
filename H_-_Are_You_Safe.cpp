#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)                  \
    {                                   \
        cout << "-->" << #A << "=\n";   \
        for (int i = 0; i < n; i++)     \
        {                               \
            for (int j = 0; j < m; j++) \
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
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I, n) for (int I = 0; I < n; I++)
#define forb(I, n) for (int I = 1; I <= n; I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mkp(a, b) make_pair(a, b)
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
struct pt
{
    double x, y;
};

int orientation(pt a, pt b, pt c)
{
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0)
        return -1; // clockwise
    if (v > 0)
        return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear)
{
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear)
{
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

vector<pt> convex_hull(vector<pt> &a, bool include_collinear = false)
{
    if (a.size() == 1)
        return a;

    sort(a.begin(), a.end(), [](pt a, pt b)
         { return make_pair(a.x, a.y) < make_pair(b.x, b.y); });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear))
        {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size())
    {
        reverse(a.begin(), a.end());
        return a;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
    return a;
}
bool isInside(vector<pt> points,
              pt query)
{

    points.push_back(query);

    points = convex_hull(points);

    for (auto x : points)
    {

        if (x.x == query.x && x.y == query.y)
            return false;
    }

    return true;
}
void run()
{
    int t;
    cin >> t;
    int cc = 1;
    while (t--)
    {
        cout << "Case " << cc++ << endl;
        int n, q;
        cin >> n >> q;
        vector<pt> a(n);
        fora(i, n)
        {
            cin >> a[i].x >> a[i].y;
        }
        vector<pt> b(q);
        map<pii, int> m;
        fora(i, q)
        {
            cin >> b[i].x >> b[i].y;
        }
        vector<pt> hull = convex_hull(a);
        hull.pb(hull[0]);
        reverse(hull.begin(), hull.end());
        map<pii, int> m2;
        for (auto &i : hull)
        {
            cout << i.x << " " << i.y << endl;
        }
        for (auto &x : b)
        {
            cout << x.x << " " << x.y << " is " << (isInside(hull, x) ? "unsafe!" : "safe!") << endl;
        }
        cout << endl;
    }
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
