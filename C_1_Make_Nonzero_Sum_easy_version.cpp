// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write C++ code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
            counter += x;
        }
        arr.push_back(0);
        int ans = counter / 2;
        if (counter & 1)
        {
            cout << "-1" << endl;
        }
        else
        {
            vector<pair<int, int>> tt;
            for (int i = 0; i < n; i++)
            {
                if (counter < 0 && ans)
                {
                    if (arr[i] == 1 && arr[i + 1] == -1)
                    {
                        tt.push_back({i, i + 1});
                        i++;
                        ans++;
                    }
                    else if (arr[i] == -1 && arr[i + 1] == -1)
                    {
                        tt.push_back({i, i + 1});
                        i++;
                        ans++;
                    }
                    else if (arr[i] == 0 && arr[i + 1] == -1)
                    {
                        tt.push_back({i, i + 1});
                        i++;
                        ans++;
                    }
                    else
                    {
                        tt.push_back({i, i});
                    }
                }
                else if (counter > 0 && ans)
                {
                    if (arr[i] == -1 && arr[i + 1] == 1)
                    {
                        tt.push_back({i, i + 1});
                        ans--;
                        i++;
                    }
                    else if (arr[i] == 1 && arr[i + 1] == 1)
                    {
                        tt.push_back({i, i + 1});
                        ans--;
                        i++;
                    }
                    else if (arr[i] == 0 && arr[i + 1] == 1)
                    {
                        tt.push_back({i, i + 1});
                        ans--;
                        i++;
                    }
                    else
                    {
                        tt.push_back({i, i});
                    }
                }
                else
                {
                    tt.push_back({i, i});
                }
            }
            if (ans == 0)
            {
                cout << tt.size() << endl;
                for (auto &x : tt)
                {
                    cout << x.first + 1 << " " << x.second + 1 << endl;
                }
            }
            else
            {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}