#include <bits/stdc++.h>
#define endl "\n"
#define ii pair<ll, ll>
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
using namespace std;
/*_____________________________________MY CODE_____________________________________*/
const int MN = 1e5 + 11;
vector<vector<int>> a;
int dp[MN];
int n, m, x, y;
int dfs(int u)
{
    if (dp[u] != -1)
        return dp[u];

    dp[u] = 0;
    for (int v : a[u])
        if (dp[u] < dfs(v) + 1)
            dp[u] = dfs(v) + 1;

    return dp[u];
}
signed main()
{
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        dp[x] = dp[y] = -1;
    }

    int ans = 0;
    for (int u = 1; u <= n; u++)
        ans = (ans < dfs(u)) ? dfs(u) : ans;
    cout << ans;
}