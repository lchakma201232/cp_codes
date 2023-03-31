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
int getIndx(vector<int> &segs,int num){
    return lower_bound(segs.begin(),segs.end(),num)-segs.begin();
}
pair<int,int> getRange(vector<int> &segs, pii &froga, pii &frogb, int time){
    int lowerLimit=0,upperLimit=1e9;
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)/2;
        int newtime= time-mid;
        if(newtime<0){
            r=mid;
            continue;
        }
        int a=getIndx(segs,froga.first+newtime*froga.second);
        int b=getIndx(segs,frogb.first+newtime*frogb.second);
        if(a==b){
            l=mid + 1;
            lowerLimit=time-mid;
        }else{
            r=mid;
        }
    }
    // lowerLimit=l;
    l=0,r=1e9;
    while(l<r){
        int mid=(l+r)/2;
        int newtime= time+mid;
        if(newtime>1e9){
            l=mid + 1;
            continue;
        }
        int a=getIndx(segs,froga.first+newtime*froga.second);
        int b=getIndx(segs,frogb.first+newtime*frogb.second);
        if(a==b){
            r=mid;
            upperLimit=time+mid;
        }else{
            l=mid + 1;
        }
    }
    return mkp(lowerLimit,upperLimit);
}
void run(){
    int t;
    cin>>t;
    int casse=1;
    while(t--){
        cout<<"Case "<<casse++<<": ";
        int f,n;
        cin>>f>>n;
        vector<pii> frogs(f);
        fora(i,f){
            int x;
            cin>>x;
            frogs[i]=mkp(x,i);
        }
        fora(i,f){
            int x;
            cin>>x;
            frogs[i].second=x;
        }
        sort(frogs.begin(),frogs.end());
        vector<int> segs;
        segs.pb(0);
        fora(i,n){
            int x;
            cin>>x;
            segs.pb(x);
        }
        segs.pb(1e9);
        sort(segs.begin(),segs.end());
        if(f==1){
            cout<<0<<endl;
            continue;
        }
        int time=0;
        for(int i=0;i<=n+1;i++){
            if(segs[i+1]+1<frogs[f-1].first){
                continue;
            }
            int start=ceil((double)(segs[i]-frogs[0].first+1)/frogs[0].second);
            int end=ceil((double)(segs[i+1]-frogs[0].first)/frogs[0].second);
            start=max(start,(int)ceil((double)(segs[i]-frogs[f-1].first+1)/frogs[f-1].second));
            end=min(end,(int)ceil((double)(segs[i+1]-frogs[f-1].first)/frogs[f-1].second));
            if(start<=end){
                time=start;
                break;
            }
        }
        
        pair<int,int> range=getRange(segs,frogs[0],frogs[f-1],time);
        for(int i=1;i<f-1;i++){
            pair<int,int> newRange=getRange(segs,frogs[i],frogs[0],time);
            range.first=max(range.first,newRange.first);
            range.second=min(range.second,newRange.second);
        }
        if(range.first>range.second){
            cout<<"-1"<<endl;
        }else{
            cout<<range.first<<endl;
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
