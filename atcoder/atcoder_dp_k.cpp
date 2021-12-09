#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 10];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    bool dp[k + 11]; // dp[i] : trang thai thang/thua cua cua nguoi choi voi i vien da
    dp[0] = false;
    for (int i = 1; i <= k; i++)
        dp[i] = false;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            if (i >= a[j] && !dp[i - a[j]])
                dp[i] = true;
    //dp[i-a[j]] = false => taro đi trước và thua nếu taro đi sau thì win
    // => dp[i] => taro đi trước và thắng vì khi trừ đi a[j] thì tại dp[i-a[j]] taro thành người đi sau
    cout << (dp[k] ? "First" : "Second");
    return 0;
}