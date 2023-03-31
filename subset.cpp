#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// rod cutting problem

int dp[200];
vector<int> result;
int max_pp=0;
int max_price(int price[], int n, vector<int> &current)
{
    int mxPrice = 0;
    if(n==0){
        int cost=0;
        for(int i=0;i<current.size();i++){
            cost+=price[current[i]];
        }
        if(cost>max_pp){
            max_pp=cost;
            result=current;
        }
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        current.push_back(i);
        mxPrice = max(mxPrice, price[i] + max_price(price, n - i, current));
        current.pop_back();
    }
    return  mxPrice;
}

int main()
{
    int x;
    int p[30];
    cout << "Enter the number of slices" << endl;
    cin >> x;
    p[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        cin >> p[i];
    }
    vector<int> current;
    int res = max_price(p, x, current);
    cout << "Income :" << res<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" pieces "<<p[result[i]]<<endl;
    }
}