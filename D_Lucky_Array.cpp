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

vector<int> nums={4, 7, 44, 47,74,77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747 ,4774, 4777 ,7444, 7447 ,7474, 7477, 7744, 7747, 7774 ,7777};
void run(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    int len=sqrt(n)+1;
    vector<map<int,int>> cnt(len);
    vector<int> anss(len);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cnt[i/len][arr[i]]++;
    }
    fora(i,q){
        string s;
        cin>>s;
        if(s=="count"){
            int i,j;
            cin>>i>>j;
            i--;
            j--;
            int l=i/len,r=j/len;
            int ans=0;
            if(l==r){
                for(int k=i;k<=j;k++){
                    ans+=binary_search(nums.begin(),nums.end(),arr[k]+anss[l]);
                }
            }else{
                if(i%len!=0){
                    for(int k=i;k<(l+1)*len;k++){
                        ans+=binary_search(nums.begin(),nums.end(),arr[k]+anss[l]);
                    }
                    l++;
                }
                if(j%len!=len-1){
                    for(int k=r*len;k<=j;k++){
                        ans+=binary_search(nums.begin(),nums.end(),arr[k]+anss[r]);
                    }
                    r--;
                }
                for(int k=l;k<=r;k++){
                    int lowest=lower_bound(nums.begin(),nums.end(),(*cnt[k].begin()).first+anss[k])-nums.begin();
                    int highest=upper_bound(nums.begin(),nums.end(),(*cnt[k].rbegin()).first+anss[k])-nums.begin();
                    for(int m=lowest;m<highest;m++){
                        ans+=cnt[k][nums[m]-anss[k]];
                    }
                }
                
            }
            cout<<ans<<endl;
        }else{
            int l,r,x;
            cin>>l>>r>>x;
            l--;
            r--;
            int lf=l/len,rg=r/len;
            if(lf==rg){
                for(int i=l;i<=r;i++){
                    cnt[i/len][arr[i]]--;
                    if(cnt[i/len][arr[i]]==0)
                        cnt[i/len].erase(arr[i]);
                    arr[i]+=x;
                    cnt[i/len][arr[i]]++;
                }
            }else{
                if(l%len!=0){
                    for(int i=l;i<(lf+1)*len;i++){
                        cnt[i/len][arr[i]]--;
                        if(cnt[i/len][arr[i]]==0)
                            cnt[i/len].erase(arr[i]);
                        arr[i]+=x;
                        cnt[i/len][arr[i]]++;
                    }
                    lf++;
                }
                if(r%len!=len-1){
                    for(int i=r;i>=rg*len;i--){
                        cnt[i/len][arr[i]]--;
                        if(cnt[i/len][arr[i]]==0)
                            cnt[i/len].erase(arr[i]);
                        arr[i]+=x;
                        cnt[i/len][arr[i]]++;
                    }
                    rg--;
                }
                for(int i=lf;i<=rg;i++){
                    anss[i]+=x;
                }
                
            }
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
