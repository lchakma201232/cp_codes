#include <bits/stdc++.h>

using namespace std;

struct rabin_karp{
    const int p = 71;
    const int m = 1e9 + 9;
    vector<long long> p_pow;
    vector<long long> h;
    rabin_karp(string s){
        int n = s.size();
        p_pow.resize(n);
        h.resize(n + 1);
        p_pow[0] = 1;
        for (int i = 1; i < n; i++)
            p_pow[i] = (p_pow[i - 1] * p) % m;
        for (int i = 0; i < n; i++)
            h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    long long get(int l, int r){
        long long res = h[r + 1] + m - h[l];
        return res;
    }
};

int main(){
    rabin_karp str("hello"), str1("helloo");
    if (str.get(0, 3) == str1.get(0, 3)) cout << "Yes" << endl;
    else cout << "no" << endl;
}