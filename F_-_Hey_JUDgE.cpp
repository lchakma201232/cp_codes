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


void run(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        s.append("F");
        s.append("F");
        map<char,int> m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        bool can=false;
        map<int,int> taken;
        for(int i=0;i<7 && !can;i++){
            taken[i]=1;
            for(int j=i+1;j<7 && !can;j++){
                taken[j]=1;
                for(int k=0;k<7 && !can;k++){
                    if(taken[k])continue;
                    if('A'+(s[i]+s[j]-2*'A'+2)>'E'){
                        continue;
                    }
                    taken[k]=1;
                    for(int l=k+1;l<7 && !can;l++){
                        if(taken[l])continue;
                        if('A'+(s[k]+s[l]-2*'A'+2)>'E'){
                            continue;
                        }
                        taken[l]=1;
                        set<char> st;
                        for(int x=0;x<n;x++){
                            if(!taken[x])st.insert(s[x]);
                        }
                        st.insert('A'+(s[i]+s[j]-2*'A'+2));
                        // cout<<s[i]<<s[j]<<s[k]<<s[l]<<endl;
                        // cout<<(char)('A'+(s[i]+s[j]-2*'A'+2));
                        st.insert('A'+(s[k]+s[l]-2*'A'+2));
                        if(st.size()==5){
                            can=true;
                            break;
                        }
                        taken[l]=0;
                    }
                    taken[k]=0;

                }
                taken[j]=0;
            }
            taken[i]=0;
        }
        if(can){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
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