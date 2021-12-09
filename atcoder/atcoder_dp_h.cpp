#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mp make_pair
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOR1(i, a, b) for (int i = a; i >= b; i--)
#define FOR2(i, a, b) for (ll i = a; i >= b; i--)
#define repd(i, n) for (ll i = (n)-1; i >= 0; --i)
#define iit pair<int, int>
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define run() \
    ll t;     \
    cin >> t; \
    while (t--)

using namespace std;
/*_____________________________________MY CODE_____________________________________*/
const int MAX = 1e3 + 11;
const int mod = 1e9 + 7;
int h, w;
ll dp[MAX][MAX];

void solve(string s[])
{
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (s[i][j] == '#')
            {
                dp[i][j] = 0;
                continue;
            }
            if (i > 1)
                dp[i][j] += (dp[i - 1][j]) % mod;
            if (j > 1)
                dp[i][j] += (dp[i][j - 1]) % mod;
            dp[i][j] %= mod;
        }
    }
    cout << dp[h][w];
}

signed main()
{
    cin >> h >> w;
    string s[h + 11];
    for (ll i = 1; i <= h; i++)
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    solve(s);
}