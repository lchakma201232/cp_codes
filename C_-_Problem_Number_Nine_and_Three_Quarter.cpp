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
pair<double,double> findIntersection(double r, double angle,double pos){
    double m=tan((180-angle/pos)/180.0*acos(-1.0));
    double h=0,k=-r,c=0;
    double A=m*m+1,B=-2*k+2*h*m,C=k*k+c*c+h*h-2*h*c-r*r;
    // double x1=(-B+sqrt(B*B-4*A*C))/(2*A);
    double x2=(-B-sqrt(B*B-4*A*C))/(2*A);
    // double y1=m*x1+c;
    double y2=m*x2+c;
    return mkp(x2,y2);
}
pair<double,double> findMid(pair<double,double> a,pair<double,double> b){
    return mkp((a.first+b.first)/2.0,(a.second+b.second)/2.0);
}
double findSlope(pair<double,double> a,pair<double,double> b){
    return (a.second-b.second)/(a.first-b.first);
}
pair<double,double> findIntersectionPoint(double r, double m,double k,double h){
    // double x=(-r-h)/m + k;
    double y=m*(-r-k)+h;
    return mkp(-r,y);
}
void run(){
    int t;
    cin>>t;
    while(t--){
        double r,angle;
        cin>>r>>angle;
        pair<double,double> p=findIntersection(r,angle,2);
        pair<double,double> q=findIntersection(r,angle,1);
        pair<double,double> mid=findMid(q,{0,0});
        double m=findSlope(p,mid);
        // cout<<m<<endl;
        pair<double,double> ans=findIntersectionPoint(r,m,p.first,p.second);
        // cout<<fixed<<setprecision(6)<<p.first<<" "<<p.second<<endl;
        // cout<<fixed<<setprecision(6)<<q.first<<" "<<q.second<<endl;
        // cout<<fixed<<setprecision(6)<<mid.first<<" "<<mid.second<<endl;
        cout<<fixed<<setprecision(6)<<ans.second<<endl;
        // cout<<endl;
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
