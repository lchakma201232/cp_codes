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
        trie *curr=this;
        for(int i=0;i<s.size();i++){
            if(curr->child[s[i]-'@']==NULL){
                curr->child[s[i]-'@']=new trie();
            }
            curr=curr->child[s[i]-'@'];
        }
        curr->cnt++;
    }
    int search(string s){
        trie *curr=this;
        for(int i=0;i<s.size();i++){
            if(curr->child[s[i]-'@']==NULL){
                return 0;
            }
            curr=curr->child[s[i]-'@'];
        }
        return curr->cnt;
    }

};

void run(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        set<string> st;
        trie *root=new trie();
        int total=0;
        
        while(getline(cin,s)){
            if(s==""){
                break;
            }
            st.insert(s);
            for(int i=0;i<s.size();i++){
                s[i]=toupper(s[i]);
            }
            if(s.find(" ")!=string::npos){
                s.replace(s.find(" "),1,"@");
            }
            root->insert(s);
            total++;
        }
        for(auto it=st.begin();it!=st.end();it++){
            string p=*it;
            if(p.find(" ")!=string::npos){
                p.replace(p.find(" "),1,"@");
            }
            for(int i=0;i<p.size();i++){
                p[i]=toupper(p[i]);
            }
            
            cout<<*it<<" "<<fixed<<setprecision(4)<<(double)root->search(p)*100/total<<endl;
        }
        if(t){
            cout<<endl;
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
