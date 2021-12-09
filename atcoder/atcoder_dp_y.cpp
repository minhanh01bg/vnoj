#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define fi first
#define se second
#define int long long
#define ii pair<int, int>
#define endl "\n"
#define mp make_pair
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fora(i, l, r) for (int i = l; i < r; i++)
#define Forb(i, r, l) for (int i = r; i >= l; i--)
#define Forc(x, a) for (auto x : a)

const int M = 2e5 + 5;
const int N = 3e3 + 5;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;

int inv[M], fact[M];

int binpow(int a, int n)
{
    int sum = 1;
    while (n)
    {
        if (n & 1)
            sum = (sum * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return sum;
}

int n, h, w, dp[N];
ii a[N];

int C(int k, int n)
{
    if (k > n)
        return 0;
    return fact[n] * inv[k] % mod * inv[n - k] % mod;
}

void init()
{
    fact[0] = inv[0] = 1;
    For(i, 1, h + w)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = binpow(fact[i], mod - 2);
    }
}

void solve()
{
    For(i, 1, n + 1)
    {
        dp[i] = C(a[i].fi - 1, a[i].fi + a[i].se - 2);
        For(j, 1, i - 1)
        {
            if (a[i].fi >= a[j].fi && a[i].se >= a[j].se)
            {
                dp[i] = (dp[i] - dp[j] * C(a[i].fi - a[j].fi, a[i].fi + a[i].se - a[j].fi - a[j].se) % mod + mod) % mod;
            }
        }
    }
    cout << dp[n + 1];
}
signed main()
{
    fastio;
    cin >> h >> w >> n;
    For(i, 1, n)
            cin >>
        a[i].fi >> a[i].se;
    a[n + 1].fi = h, a[n + 1].se = w;
    sort(a + 1, a + n + 2);
    memset(dp, 0, sizeof dp);
    init();
    solve();
    return 0;
}