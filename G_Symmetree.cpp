#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)                  \
    {                                   \
        cout << "-->" << #A << "=\n";   \
        for (int i = 0; i < n; i++)     \
        {                               \
            for (int j = 0; j < m; j++) \
            {                           \
                cout << A[i][j] << " "; \
            }                           \
            cout << "\n";               \
        }                               \
        cout << "\n";                   \
    }
#define dbgA(A, n)                   \
    {                                \
        cout << "-->" << #A << "=("; \
        for (int i = 0; i < n; i++)  \
            cout << A[i] << " ";     \
        cout << ")\n";               \
    }
#define dbg(args...)                                  \
    {                                                 \
        string sss(#args);                            \
        sss += ',';                                   \
        cout << "-->";                                \
        debugger::call(sss.begin(), sss.end(), args); \
        cout << "\n";                                 \
    }
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I, n) for (int I = 0; I < n; I++)
#define forb(I, n) for (int I = 1; I <= n; I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mkp(a, b) make_pair(a, b)
using namespace std;
/*struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it)
            if(*it!=' ')
                b+=*it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
ll siev_arr[mXI];
void siev(ll n)
{
    siev_arr[0] = siev_arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!siev_arr[i])
        {
            cout<<i<<endl;
            for (int j = i + i; j <= n; j += i)
            {
                siev_arr[j] = 1;
            }
        }
    }
}

int dfs(int v, int *arr, int *visited){
    if(visited[arr[v]]){
        return arr[v]=arr[arr[v]];
    }
    visited[v]=1;
    return arr[v]=dfs(arr[v],arr,visited);
}*/
class TreeNode
{
public:
    int val;
    vector<TreeNode *> children;
    TreeNode(int val)
    {
        this->val = val;
    }
};
bool isMirror(vector<TreeNode*> nodes1, vector<TreeNode*> nodes2) {
    int n = nodes1.size();
    for (int i = 0; i < n; i++) {
        TreeNode* node1 = nodes1[i];
        TreeNode* node2 = nodes2[n-i-1];
        if ((node1 == nullptr && node2 != nullptr) ||
            (node1 != nullptr && node2 == nullptr) ||
            (node1 != nullptr && node2 != nullptr && node1->val != node2->val)) {
            return false;
        }
        if (node1 != nullptr) {
            if (!isMirror(node1->children, node2->children)) {
                return false;
            }
        }
    }
    return true;
}
bool isMirror(vector<TreeNode *> nodes)
{
    int n = nodes.size();
    for (int i = 0; i < n / 2; i++)
    {
        TreeNode *node1 = nodes[i];
        TreeNode *node2 = nodes[n - i - 1];
        if ((node1 == nullptr && node2 != nullptr) ||
            (node1 != nullptr && node2 == nullptr) ||
            (node1 != nullptr && node2 != nullptr && node1->val != node2->val))
        {
            return false;
        }
        if (node1 != nullptr)
        {
            if (!isMirror(node1->children, node2->children))
            {
                return false;
            }
        }
    }
    return true;
}
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    return isMirror(root->children);
}




void run()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adjList(n + 1);
        fora(i, n - 1)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].pb(b);
            adjList[b].pb(a);
        }
        vector<TreeNode *> nodes(adjList.size());
        for (int i = 0; i < adjList.size(); i++)
        {
            if (adjList[i][0] != 0)
            {
                nodes[i] = new TreeNode(adjList[i][0]);
                for (int j = 1; j < adjList[i].size(); j++)
                {
                    if (adjList[i][j] != 0)
                    {
                        nodes[i]->children.push_back(new TreeNode(adjList[i][j]));
                    }
                    else
                    {
                        nodes[i]->children.push_back(0);
                    }
                }
            }
            else
            {
                nodes[i] = 0;
            }
        }
        TreeNode *root = nodes[0];
        cout << (isSymmetric(root) ? "YES" : "NO") << endl;
    }
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
