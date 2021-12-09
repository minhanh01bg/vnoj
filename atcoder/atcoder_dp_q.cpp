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
const int N = 2e5 + 10;
ll bit[N];
int n;

ll getSum(ll p)
{
    ll idx = p, ans = 0;
    while (idx > 0)
    {
        ans = max(ans, bit[idx]);
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(ll u, ll v)
{
    ll idx = u;
    while (idx <= n)
    {
        bit[idx] = max(bit[idx], v);
        idx += (idx & (-idx));
    }
}
//i & (-i) sẽ trả về bit đầu tiên khác 0 của i(tính từ cuối), ví dụ 
// i = 20, có biểu diễn nhị phân là 10100, 
// thì i & (-i) sẽ có biểu diễn nhị phân là 100, tức là 20 & (-20) = 4.
// https://vietcodes.github.io/algo/fenwick

signed main()
{
    cin >> n;
    ll a[n + 5], h[n + 5];
    FOR(i, 0, n - 1)
    cin >> h[i];

    FOR(i, 0, n - 1)
    cin >> a[i];

    FOR(i, 0, n - 1)
    update(h[i], getSum(h[i] - 1) + a[i]);
    cout << getSum(n);
    // cerr << "\nTime : " << clock() << "ms\n";
}