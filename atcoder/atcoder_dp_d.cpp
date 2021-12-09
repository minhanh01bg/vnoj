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
    ll n, W;
    cin >> n >> W;
    ll a[n+5][2];
    FOR(i, 1, n)
    cin >> a[i][0] >> a[i][1];
    ll dp[n + 5][W + 5];
    FOR(i, 0, n)
        dp[i][0] = 0;
    FOR(i,0,W)
        dp[0][i] = 0;
    
    FOR(i, 1, n)
    {
        FOR(j, 1, W)
        {
            if (j < a[i][0])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i][0]] + a[i][1]);
        }
    }
    cout<<dp[n][W];
}