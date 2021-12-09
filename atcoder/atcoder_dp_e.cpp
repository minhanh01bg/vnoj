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
const int MN = 1e5 + 11;
ll dp[MN]; // dp[i] khối lượng nhỏ nhất với giá trị là i

signed main()
{
    int n, w;
    cin >> n >> w;
    int a[n][2];
    FOR(i, 0, n - 1)
    cin >> a[i][0] >> a[i][1];
        // a[i][0]: khối lượng
        // a[i][1]: giá trị
    for (int i = 0; i < MN - 10; i++)
        dp[i] = 1e18;
    
    dp[0] = 0;
    FOR(i, 0, n - 1)
    {
        FOR1(j, MN - 11, 0)
        {
            if (dp[j] + a[i][0] <= w)
            {
                dp[j + a[i][1]] = min(dp[j + a[i][1]], dp[j] + a[i][0]);
            }
        }
    }
    FOR1(i, MN - 11, 0)
    if (dp[i] != 1e18)
    {
        cout << i << endl;
        break;
    }
    return 0;
}