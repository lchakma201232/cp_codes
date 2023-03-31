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

vector<int> dp;
bool solve(vector<int> &ans,int index){
    if(index==ans.size()-1){
        return 1;
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    if(ans[index]>1){
        ans[index]=1;
        int second=solve(ans,index+1);
        int first=solve(ans,index);
        return dp[index]=!first||!second;
    }else{
        return dp[index]=!solve(ans,index+1);
    }
}
void run(){
    int a,b;
    while((cin>>a>>b) && (a+b)){

        int n=0;
        int x=max(a,b),y=min(a,b);
        vector<int> ans;
        while(x && y){
            int count=0;
            while(x>=y){
                x-=y;
                count++;
            }
            ans.push_back(count);
            swap(x,y);
        }
        // cout<<ans.size()<<endl;
        dp.assign(ans.size(),-1);
        // dbgA(ans,ans.size());
        if(solve(ans,0)){
            cout<<"Stan wins"<<endl;
        }else{
            cout<<"Ollie wins"<<endl;
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
