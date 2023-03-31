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
int mp[200005][26];
vector<int> parents;
int find(int x){
    if(parents[x]==x){
        return x;
    }
    return parents[x]=find(parents[x]);
}
void uni(int x, int y){
    int px=find(x);
    int py=find(y);
    if(px!=py){
        parents[px]=py;
    }
}

void dfs(string s,int k, int i,int j,int p=-1){
    if(i>=s.size() || i<0){
        return;
    }
    if(p!=-1 && find(i)==find(p)){
        return;
    }
    if(find(i)!=find(j)){
        uni(i,j);
    }
    mp[j][s[i]-'a']++;
    dfs(s,k,i+k,j,i);
    dfs(s,k,i+k+1,j,i);
    dfs(s,k,i-k,j,i);
    dfs(s,k,i-k-1,j,i);
}

void run(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        if(a==b){
            cout<<"YES"<<endl;
            continue;
        }
        map<char,int> m1,m2;
        for(int i=0;i<n;i++){
            m1[a[i]]++;
            m2[b[i]]++;
        }
        bool ok=true;
        fora(i,26){
            if(m1[i+'a']!=m2[i+'a']){
                ok=false;
                break;
            }
        }
        if(!ok){
            cout<<"NO"<<endl;
            continue;
        }
        if(n>=2*k){
            cout<<"YES"<<endl;
            continue;
        }
        if(n-1==2*k){
            if(a[k-1]!=b[k-1]){
                ok=false;
            }
        }
        if(n-1==k){
            swap(a[0],a[n-1]);
            if(a!=b){
                ok=false;
            }
        }
        if(n<=k){
            ok=false;
        }else{
            int j=k-1;
            int g=2*k-n;
            while(j>=0 && g>0){
                if(a[j]!=b[j]){
                    ok=false;
                    break;
                }
                j--;
                g--;
            }
        }
        if(ok){
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
