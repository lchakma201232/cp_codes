#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        long long int sum = 0;
        long long c=n;
        vector<long long> divisors;
        for(long long int i=2; i<=n; i++)
        {
            while(n%i==0){
                n/=i;
            }
            divisors.push_back(i);
        }
        for(int i=0;i<divisors.size();i++){
            for(int j=i+1;)
        }
        if(sum == c) cout << "YES, " << c << " is a perfect number!" << endl;
        else cout << "NO, " << c << " is not a perfect number!" << endl;
    }
}