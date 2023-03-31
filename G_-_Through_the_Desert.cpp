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
vector<string> split(string s){
    vector<string> res;
    string temp;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            res.push_back(temp);
            temp="";
        }else{
            temp+=s[i];
        }
    }
    res.push_back(temp);
    return res;
}
pair<int,pair<int,int>> parser(string s){
    vector<string> res=split(s);
    int a=stoi(res[0]);
    if(res[1]=="Fuel"){
        return mkp(0,mkp(a,stoi(res[3])));
    }else if(res[1]=="Goal"){
        return mkp(1,mkp(a,0));
    }else if(res[1]=="Leak"){
        return mkp(2,mkp(a,0));
    }else if(res[1]=="Mechanic"){
        return mkp(3,mkp(a,0));
    }else if(res[1]=="Gas"){
        return mkp(4,mkp(a,0));
    }
    return mkp(5,mkp(a,0));
}
bool calc(vector<pair<int,pair<int,int>>> v, double fuel_tank){
    //check if we can reach the goal with the given fuel tank
    double fuel_left=fuel_tank;
    double leak=0;
    int prev=0;
    double fuel_comsumption=0;
    for(int i=0;i<v.size();i++){
        fuel_left-=(v[i].second.first-prev)*leak;
        fuel_left-=(v[i].second.first-prev)*fuel_comsumption;
        if(fuel_left<0){
            return false;
        }
        prev=v[i].second.first;
        if(v[i].first==0){
            fuel_comsumption=v[i].second.second/100.0;
        }else if(v[i].first==1){
            return true;
        }else if(v[i].first==2){
            leak++;
        }else if(v[i].first==3){
            leak=0;
        }else if(v[i].first==4){
            fuel_left=fuel_tank;
        }
    }

    return false;
}

double binary_search(vector<pair<int,pair<int,int>>> v){
    double l=0;
    double r=1e9;
    double mid;
    while(r-l>1e-6){
        mid=(l+r)/2;
        if(calc(v,mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    return r;
}
void run(){
    string s;
    int t=1;
    vector<pair<int,pair<int,int>>> v;
    while(getline(cin,s)){
        auto p=parser(s);
        if(p.first==1){
            v.push_back(p);
            double res=binary_search(v);
            cout<<fixed<<setprecision(3)<<res<<endl;
            v.clear();

        }else if(p.first==0 && p.second.second==0){
            continue;
        }else{
            v.push_back(p);
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
