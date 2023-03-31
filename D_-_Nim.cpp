#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

void run(){
    int n;
    while(cin>>n && n){
        long long ans=0;
        vector<long long> arr;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            ans^=x;
            arr.push_back(x);
        }
        long long count=0;
        for(int i=0;i<n;i++){
            if(((arr[i]-ans)^ans^arr[i]) == 0 && arr[i]>ans && ans){
                count++;
            }
        }
        cout<<count<<endl;
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
