#include <bits/stdc++.h>
using namespace std;
int n, k;
// int dp[40][10000+5][2][2][10000+5]
int counter(int index, int sum, int flag1, int flag2, string a, string b,string c)
{
    // cout<<c<<" "<<sum<<endl;
    if(k>74) return 0;
    if (index == b.size() && sum == 0)
    {
        return 1;
    }
    if (index == b.size())
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        // cout<<flag1<<" "<<flag2<<endl;
        if (flag1 && i < a[index] - '0')
        {
            continue;
        }
        if (flag2 && i > b[index] - '0')
        {
            break;
        }
        if (index == 0)
        {
            if (i < a[index] - '0')
            {
                continue;
            }
            if(i>b[index]-'0'){
                break;
            }
            ans += counter(index + 1, (sum + i) % k, (a[index] - '0') == i, (b[index] - '0') == i, a, b,c+to_string(i));
        }
        else
        {
            ans += counter(index + 1, (sum*10 + i) % k, flag1 && (a[index] - '0') == i, flag2 && (b[index] - '0') == i, a, b,c+to_string(i));
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b >> k;
        a = string(b.size() - a.size(), '0') + a;
        cout << counter(0, 0, 0, 0, a, b,"") << endl;
    }
}