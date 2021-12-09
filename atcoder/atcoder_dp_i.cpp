#include <bits/stdc++.h>
using namespace std;
long double dp[3011][3011];
// sác xuất để tung i đồng xu và có j đồng là ngửa
long double a[3011];
int n;
void running()
{
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i - 1][0] * (1 - a[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j - 1] * a[i] + dp[i - 1][j] * (1 - a[i]);

    long double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
        ans += dp[n][i];

    cout << fixed << setprecision(10) << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    running();
    return 0;
}