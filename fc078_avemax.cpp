#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define null NULL
#define endl '\n'
// loops
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
// #define rep(i, a) rep(i, 0, a)
#define rof(i, a, b) for (int i = (b); i >= (a); --i)
#define r0f(i, a) rof(i, 0, a)
#define trav(a, x) for (auto &a : x)

const int mod = 1e9 + 7;
const int MX = 1e6 + 5;
const ll INF = 1e18;
// const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
/*_______________________________________MY CODE_____________________________________*/

ll n;
ll a[MX];
void Process()
{
    cin >> n;
    rep(i, 0, n - 1) cin >> a[i];
    int x = 0;
    ll ans = *max_element(a, a + n); // số lớn nhất trong đoạn con
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    Process();
}