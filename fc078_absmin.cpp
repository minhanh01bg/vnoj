/**
                                        .-''-.
                                      .' .-.  )
                                     / .'  / /
    .-''` ''-.        .-''` ''-.    (_/   / /
  .'          '.    .'          '.       / /
 /              `  /              `     / /
'                ''                '   . '
|         .-.    ||         .-.    |  / /    _.-')
.        |   |   ..        |   |   ..' '  _.'.-''
 .       '._.'  /  .       '._.'  //  /.-'_.'
  '._         .'    '._         .'/    _.'
     '-....-'`         '-....-'` ( _.-'
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string; // yay python!

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
// #define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

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
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
/*_______________________________________MY CODE_____________________________________*/

void Process()
{
    ll n;
    cin >> n;
    ll a[n];
    rep(i, 0, n - 1) cin >> a[i];
    sort(a, a + n);
    ll ans = abs(a[0] - a[1]);
    rep(i, 1, n - 1)
    {
        ans = min(ans, a[i] - a[i - 1]);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    Process();
}