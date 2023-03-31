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
    vector<int> tree;
    void build(vector<int> &arr,int node,int l,int r){
        if(l==r){
            tree[node]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(arr,node*2,l,mid);
        build(arr,node*2+1,mid+1,r);
        tree[node]=min(tree[node*2],tree[node*2+1]);
    }
    int query(int node,int l,int r,int ql,int qr){
        if(ql>r||qr<l){
            return INT_MAX;
        }
        if(ql<=l&&qr>=r){
            return tree[node];
        }
        int mid=(l+r)/2;
        return min(query(node*2,l,mid,ql,qr),query(node*2+1,mid+1,r,ql,qr));
    }

    void run(){
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            string s;
            cin>>s;
            vector<pair<int,int>> arr;
            vector<int> tt;
            vector<int> pp;
            int count=0;
            fora(i,n){
                int x;
                cin>>x;
                // arr.pb({x,i});
                tt.pb(x);
            }
            // sort(arr.begin(),arr.end(),greater<pair<int,int>>());
            vector<int> csum(n+1,0);
            for(int i=n-1;i>=0;i--){
                if(s[i]=='1')
                    csum[i]=csum[i+1]+s[i]-'0';
            }
            forb(i,n-1){
                if(s[i-1]=='0' && s[i]=='1'){
                    int start=i;
                    while(i<n && s[i]=='1'){
                        i++;
                    }
                    arr.pb({start,i-1});
                    i--;
                }
            }
            tree.resize(4*n);
            build(tt,1,0,n-1);
            ll ans=0;
            fora(i,n){
                if(s[i]=='1'){
                    ans+=tt[i];
                }
            }
            for(int i=0;i<arr.size();i++){
                int l=arr[i].first-1;
                int r=arr[i].second;
                int minn=query(1,0,n-1,l,r);
                ans-=minn;
                ans+=tt[l];
            }
            cout<<ans<<endl;

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
