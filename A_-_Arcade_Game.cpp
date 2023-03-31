#include<bits/stdc++.h>
 
using namespace std;
 
#define fRead(x)  freopen(x,"r",stdin)
#define fWrite(x) freopen (x,"w",stdout)
 
#define LL long long
#define ULL unsigned long long
#define ff first
#define ss second
#define pb push_back
#define INF 2e16
#define PI acos(-1.0)
#define mk make_pair
 
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,b) for(int i=0;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define ABS(x) ((x)<0?-(x):(x))
 
#define scanI(a) scanf("%d",&a)
#define scanI2(a,b) scanI(a) , scanI(b)
#define scanI3(a,b,c) scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)
 
#define scanL(a) scanf("%I64d",&a)
#define scanL2(a,b) scanL(a) , scanL(b)
#define scanL3(a,b,c) scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)
 
#define SORT(v) sort(v.begin(),v.end())
#define REV(v) reverse(v.begin(),v.end())
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);
 
double power(double b,int p)
{
    double ret = 1;
    while(p > 0){
        if(p % 2 == 1)ret = (ret * b);
        p/=2;
        b = (b * b);
    }
    return ret;
}
int main()
{
    FastRead
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        string s = str;
        SORT(s);
        map<char,int>mp;
        for(int i = 0;i < str.size();i++){
            mp[s[i]] = i + 1;
        }
        vector<int>nums;
 
        for(int i = 0;i < str.size();i++){
            nums.push_back(mp[str[i]]);
        }
 
        double fac[11];
        fac[0] = 1;
        int n = str.size();
        for(int i = 1;i <= n;i++)fac[i] = fac[i - 1] * i;
        int below = 0;
        for(int i = 0;i < nums.size();i++){
            int ni = 0;
            for(int j = i + 1;j < nums.size();j++){
                if(nums[j] < nums[i]){
                    ni++;
                }
            }
            below += ni * fac[n - 1 - i];
        }
        int up = fac[n] - 1 - below;
        double div = fac[n];
        double ans=0,ans2=0;
        for(int i=1;i<=up;i++){
            ans=(ans2+1)/div;
            ans2+=ans;
        }

        if(up>0){
            cout << fixed << setprecision(9) << ans << "\n";
        }else{
            cout<<fixed<<setprecision(9)<<0.0000000<<"\n";
        }
    }
 
 
}