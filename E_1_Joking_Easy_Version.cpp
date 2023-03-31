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
bool found = false;
void solve(int l, int r, int x, int y, bool confusion)
{
    if (found)
        return;
    if(l==r){
        if(confusion){
            cout<<"? 1 "<<l<<endl;
            string s;
            cin>>s;
            cout<<"? 1 "<<l<<endl;
            string s2;
            cin>>s2;
            if(s==s2){
                if(s=="YES"){
                    cout<<"! "<<l<<endl;
                    found=true;
                    string k;
                    cin>>k;
                }
            }else{
                cout<<"! "<<l<<endl;
                // found=true;
                string k;
                cin>>k;
                if(k==":)"){
                    found=true;
                }
            }
        }else{
            cout<<"! "<<l<<endl;
            found=true;
            string k;
            cin>>k;
        }
        return;
    }
    if (confusion)
    {
        cout << "? " << y - x + 1 << " ";
        for (int i = x; i <= y; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        string s;
        cin >> s;
        cout << "? " << y - x + 1 << " ";
        for (int i = x; i <= y; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        string s1;
        cin >> s1;
        if (s1 == s)
        {
            if (s == "YES")
            {
                solve(x, y, x, y, false);
                return;
            }
            else
            {
                return;
            }
        }
    }
    int mid = (l + r) / 2;
    cout << "? " << mid - l + 1 << " ";
    for (int i = l; i <= mid; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    string s2;
    cin >> s2;
    cout << "? " << mid - l + 1 << " ";
    for (int i = l; i <= mid; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    string s3;
    cin >> s3;
    if(s2==s3){
        if(s2=="YES"){
            solve(l,mid,l,mid,false);
        }
        else{
            solve(mid+1,r,mid+1,r,false);
        }
    }
    else{
        solve(l,mid,l,mid,true);
        solve(mid+1,r,mid+1,r,true);
    }
}

void run()
{
    int n;
    cin >> n;
    solve(1, n,1,n, 0);
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
