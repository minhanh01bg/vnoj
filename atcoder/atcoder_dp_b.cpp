#include <bits/stdc++.h>
#define endl "\n"
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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    FOR(i, 0, n - 1)
    cin >> a[i];
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = abs(a[0] - a[1]);
    FOR(i, 2, n - 1)
    {
        dp[i] = INT_MAX;
        FOR(j, 1, min(i, k))
        {
            dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
        }
    }
    cout << dp[n - 1];
}