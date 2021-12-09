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
ll p = 1e9 + 7;
const int N = 2e5 + 11;

int H, W, n;
ll ifac[N], fac[N];
ll powerMod(ll n, ll x)
{
    if (x == 0)
        return 1;
    ll res = powerMod(n, x / 2);
    return (x & 1) ? ((((res * res) % p) * n) % p) : ((res * res) % p);
}

void init()
{
    fac[0] = ifac[0] = 1;
    FOR(i, 1, H + W)
        fac[i] = (i * fac[i - 1]) % p;

    
    //C(n,k) = n!/k!*(n-k)!
    ifac[H + W] = powerMod(fac[H + W], p - 2);
    // ta cần chứng minh: a^(p-2) % p = a ^ -1
    // phi(n) = n * (1-1/p1) * ... * (1-1/pn)  (p1,...,pn) là các ước nguyên tố của n
    // n là số nguyên tố => phi(n) = n - 1   (1)
    // theo euler: a^phi(n) % n = 1 (với gcd(a,n)=1) (2)
    // (1) và (2) => a^(n-1) % n = 1  (nhân 2 vế với a^-1) => a^(n-2) % n = a^-1 (điều phải chứng minh)
    
    FOR1(i, H + W - 1, 0)
        ifac[i] = ((i + 1) * ifac[i + 1]) % p;
}
// n!/(r!*(n-r)!)

ll C(int n, int r)
{
    if (n < r)
        return 0;
    return (((fac[n] * ifac[n - r]) % mod) * ifac[r]) % mod;
}

ii a[N];
ll dp[N];

void process()
{
    dp[1] = C(a[1].first + a[1].second - 2, a[1].first - 1);
    FOR(i, 2, n + 1)
    {
        dp[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);
        FOR(j, 1, i - 1)
        {
            if (a[i].first >= a[j].first && a[i].second >= a[j].second)
                dp[i] = (dp[i] - C(a[i].first + a[i].second - a[j].first - a[j].second, a[i].first - a[j].first) * dp[j] % p + p) % p;
        }
    }
    cout << dp[n + 1] << endl;
}

signed main()
{
    cin >> H >> W >> n;
    FOR(i, 1, n)
    cin >> a[i].first >> a[i].second;

    a[n + 1].first = H, a[n + 1].second = W;
    sort(a + 1, a + n + 2);
    init();
    process();
}