#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

const int MOD = 998244353;

// Compute the prime factorization of a number
unordered_map<int, int> prime_factorization(int n) {
    unordered_map<int, int> factors;
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

// Compute the number of positive integers that have a given multiset of prime factors
int count_factors(vector<int>& a) {
    int n = a.size() / 2;
    map<vector<pair<int, int>>, int> freq;
    for (int i = 0; i < (1 << n); i++) {
        vector<pair<int, int>> factors;
        for (int j = 0; j < n; j++) {
            int count = (i >> j) & 1 ? a[n+j] : a[j];
            if (count > 0) {
                factors.push_back({a[j], count});
            }
        }
        freq[factors]++;
    }
    int ans = 0;
    for (auto p : freq) {
        vector<pair<int, int>> factors = p.first;
        int count = p.second;
        int prod = 1;
        for (auto f : factors) {
            prod = (prod * (f.second + 1)) % MOD;
        }
        ans = (ans + (prod * count) % MOD) % MOD;
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
