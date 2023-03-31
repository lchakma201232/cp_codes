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
bool isIllegal(vector<string> &s){
    int x_counter=0,o_counter=0;
    for(auto &x:s){
        for(auto &y:x){
            x_counter+=y=='X';
            o_counter+=y=='0';
        }
    }
    return o_counter>x_counter || (abs(o_counter-x_counter)>1);
}
bool isDraw(vector<string> &s){
    int x_counter=0,o_counter=0;
    for(auto &x:s){
        for(auto &y:x){
            x_counter+=y=='X';
            o_counter+=y=='0';
        }
    }
    return (x_counter+o_counter)==9;
}
bool isPWin(vector<string> &s, char x){
    bool ok=0;
    fora(i,3){
        bool o=1;
        fora(j,3){
            if(s[i][j]!=x) o=0;
        }
        ok=max(o,ok);
    }
    fora(i,3){
        bool o=1;
        fora(j,3){
            if(s[j][i]!=x) o=0;
        }
        ok=max(o,ok);
    }
    bool k=1;
    fora(i,3){
        if(s[i][i]!=x) k=0;
    }
    ok=max(k,ok);
    k=1;
    fora(i,3){
        if(s[i][2-i]!=x) k=0;
    }
    ok=max(k,ok);
    return ok;
}
bool p1Turn(vector<string> &s){
    int x_counter=0,o_counter=0;
    for(auto &x:s){
        for(auto &y:x){
            x_counter+=y=='X';
            o_counter+=y=='0';
        }
    }
    return x_counter==o_counter;
}
void run(){
    vector<string> s;
    fora(i,3){
        string k;
        cin>>k;
        s.pb(k);
    }
    if(isIllegal(s) || isPWin(s,'X') && isPWin(s,'0') || (isPWin(s,'0') && !p1Turn(s)) || (isPWin(s,'X') && p1Turn(s)) ){
        cout<<"illegal"<<endl;
        return;
    }
    if(isPWin(s,'X')){
        cout<<"the first player won"<<endl;
        return;
    }
    if(isPWin(s,'0')){
        cout<<"the second player won"<<endl;
        return;
    }
    if(isDraw(s)){
        cout<<"draw"<<endl;
        return;
    }
    if(p1Turn(s)){
        cout<<"first"<<endl;
        return;
    }else{
        cout<<"second"<<endl;
        return;
    }

}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin>>t;
    t=1;

    while(t--){
        run();
    }
}
