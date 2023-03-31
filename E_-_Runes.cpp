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
bool parser(string s){
    ll ans=0;
    char op='+';
    char op2='+';
    bool flag=false;
    // cout<<s<<endl;
    ll rhs=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            ll num=0;
            ll len=0;
            while(s[i]>='0' && s[i]<='9' && i<s.size()){
                num=num*10+(s[i]-'0');
                len++;
                i++;
            }
            if(len>1 && num==0) return false;
            if(num==0 && (op2=='-' || (i==2 && op=='-'))) return false;
            if(op=='+'){
                if(op2=='-'){
                    ans+=-num;
                }else{
                    ans+=num;
                }
                op='+',op2='+';
            }else if(op=='-'){
                if(op2=='-'){
                    ans-=-num;
                }else{
                    ans-=num;
                }
                op='+',op2='+';
            }else if(op=='*'){
                if(op2=='-'){
                    ans*=-num;
                }else{
                    ans*=num;
                }
                op='+',op2='+';
            }else{
                if(op2=='-'){
                    rhs=-num;
                }else{
                    rhs=num;
                }
                op='+',op2='+';
            }
            flag=false;
            i--;
        }else{
            op=s[i];
            if(i<s.size()-1 && s[i+1]=='-'){
                op2='-';
                i++;
            }else{
                op2='+';
            }
        }
    }
    if(op!='+' || op2!='+') return false;
    return ans==rhs;
}
void run(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool flag=false;
        set<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                st.insert(s[i]);
            }
        }
        for(int i=0;i<=9;i++){
            if(st.find(i+'0')!=st.end()) continue;
            string temp=s;
            for(int j=0;j<temp.size();j++){
                if(temp[j]=='?'){
                    temp[j]=i+'0';
                }
            }
            if(parser(temp)){
                cout<<i<<endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"-1"<<endl;
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
