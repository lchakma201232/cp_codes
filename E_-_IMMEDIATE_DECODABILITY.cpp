#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

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
    trie *child[2];
    trie(){
        child[0]=child[1]=NULL;
    }
    void insert(string s){
        trie *cur=this;
        for(int i=0;i<s.size();i++){
            if(cur->child[s[i]-'0']==NULL){
                cur->child[s[i]-'0']=new trie();
            }
            cur=cur->child[s[i]-'0'];
        }
    }
    bool search(string s){
        trie *cur=this;
        for(int i=0;i<s.size();i++){
            if(cur->child[s[i]-'0']==NULL){
                return false;
            }
            cur=cur->child[s[i]-'0'];
        }
        return true;
    }
};


void run(){
    int t=0;
    string s;
    while(getline(cin,s)){
        t++;
        vector<string> v;
        v.pb(s);
        while(getline(cin,s)){
            if(s=="9"){
                break;
            }
            v.pb(s);
        }
        sort(v.begin(),v.end(),greater<string>());
        trie *root=new trie();
        bool flag=false;
        for(int i=0;i<v.size();i++){
            if(root->search(v[i])){
                flag=true;
                break;
            }
            root->insert(v[i]);
        }
        if(flag){
            cout<<"Set "<<t<<" is not immediately decodable\n";
        }else{
            cout<<"Set "<<t<<" is immediately decodable\n";
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
