#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mp make_pair
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOR1(i, a, b) for (int i = a; i >= b; i--)
#define FOR2(i, a, b) for (ll i = a; i >= b; i--)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define ii pair<ll, ll>
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);                  \
    cin.tie(0);

using namespace std;
/*_____________________________________MY CODE_____________________________________*/

signed main()
{
    int n;
    cin >> n;
    int a[n][3];
    FOR(i, 0, n - 1)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int dp[n][3];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    FOR(i, 1, n - 1)
    {
        dp[i][0] = max(dp[i - 1][1] + a[i][0], dp[i - 1][2] + a[i][0]);
        dp[i][1] = max(dp[i - 1][0] + a[i][1], dp[i - 1][2] + a[i][1]);
        dp[i][2] = max(dp[i - 1][1] + a[i][2], dp[i - 1][0] + a[i][2]);
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    return 0;
}