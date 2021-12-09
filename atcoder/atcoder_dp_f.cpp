#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mp make_pair
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOR1(i, a, b) for (int i = a; i >= b; i--)
#define FOR2(i, a, b) for (ll i = a; i >= b; i--)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define For(i, l, r) for (int i = l; i <= r; i++)
#define ii pair<ll, ll>
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
using namespace std;
/*_____________________________________MY CODE_____________________________________*/
int dp[3011][3011];
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans = "";
    while (n && m)
    {
        if (s1[n - 1] == s2[m - 1])
        {
            ans += s1[n - 1];
            n--;
            m--;
        }
        else if (dp[n - 1][m] < dp[n][m - 1])
            m--;
        else
            n--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}