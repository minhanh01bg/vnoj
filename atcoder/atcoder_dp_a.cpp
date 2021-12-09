#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOR1(i, a, b) for (int i = a; i >= b; i--)
#define FOR2(i, a, b) for (ll i = a; i >= b; i--)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)

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
    ll a[n];
    FOR(i, 0, n - 1)
    cin >> a[i];
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = abs(a[0] - a[1]);
    FOR(i, 2, n - 1)
    {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[n - 1];
}