#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <climits>
#include <iomanip>
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
struct trie{
    trie *child[27];
    int cnt;
    trie(){
        cnt=0;
        for(int i=0;i<27;i++){
            child[i]=NULL;
        }
    }
    void insert(string s){
        trie *cur=this;
        for(int i=0;i<s.size();i++){
            if(cur->child[s[i]-'@']==NULL){
                cur->child[s[i]-'@']=new trie();
            }
            cur=cur->child[s[i]-'@'];
            cur->cnt++;
        }
    }
    string find(string s){
        trie *cur=this;
        string ans="";
        for(int i=0;i<s.size();i++){
            ans+=tolower(s[i]);
            cur=cur->child[s[i]-'@'];
            if(cur->cnt==1){
                return ans;
            }
        }
        return ans;
    }
};


void run(){
    vector<string> st;
    string s;
    trie *root=new trie();
    while(getline(cin,s)){
        fora(i,s.size()){
            if(s[i]==' '){
                s[i]='@';
            }else{
                s[i]=toupper(s[i]);
            }
        }
        st.pb(s);
        root->insert(s);
    }
    fora(i,st.size()){
        string k=st[i];
        for(int j=0;j<k.size();j++){
            if(k[j]=='@'){
                k[j]=' ';
            }else{
                k[j]=tolower(k[j]);
            }
        }
        cout<<k<<" ";
        cout<<root->find(st[i])<<endl;
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
