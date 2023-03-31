#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int count_factors(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> dp(1001, vector<int>(n+1));
    dp[2][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i-1] == 2) {
            dp[2][i] = dp[2][i-1];
        }
        for (int j = 3; j <= 1000; j++) {
            dp[j][i] = dp[j][i-1];
            if (a[i-1] % j == 0) {
                dp[j][i] = (dp[j][i] + dp[j-1][i]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int j = 2; j <= 1000; j++) {
        ans = (ans + dp[j][n]) % MOD;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
    }
    cout << count_factors(a) << endl;
    return 0;
}
