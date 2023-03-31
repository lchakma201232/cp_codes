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
void run(){
    int t;
    cin>>t;
    int cass=1;
    cin.ignore();
    string s;
    // getline(cin,s);
    while(t--){
        // string ss;
        // cin>>ss;
        cout<<"CASE "<<cass++<<": ";
        // int counter=0;
        getline(cin,s);
        // cin.ignore();
        int space=0;
        int cc=0;
        map<char,int> counter,counter2;
        for(int i=0;i<s.size();i++){
            cc++;
            counter[s[i]-'A']++;
            counter2[s[i]-'A']++;
            if(s[i]==' '){
                space++;
            }
        }
        // cerr<<spaces<<endl;
        string a="SELISE Digital Platforms",b="SELISE";
        bool ok=true,ok2=true,ok3=true;
        for(auto &x:a){
            if(counter[x-'A']==0){
                ok2=false;
                break;
            }
            counter[x-'A']--;
        }
        for(auto &x:b){
            if(counter2[x-'A']==0){
                ok=false;
                break;
            }
            counter2[x-'A']--;
        }
        if(ok2){
            cout<<"BOTH"<<endl;
        }else if(ok){
            if(cc==6 || space>0){
                cout<<"SELISE"<<endl;
            }else{
                cout<<"NONE"<<endl;
            }
        }else{
            cout<<"NONE"<<endl;
        }
    }
}

int main() {
    run();
}
