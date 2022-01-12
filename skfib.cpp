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
using ldb = long double;
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
// #define f first
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
#define reset(x) memset(x, 0, sizeof(x))
const int mod = 1e9 + 7;
const int MX = 2505;
const ll INF = 1e18;
const int NM = 1e6 + 7;
const ldb PI = acos((ldb)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
/*_______________________________________MY CODE_____________________________________*/

int dp[MX][MX], n, a[MX], _idx[NM << 1], *idx = _idx + NM;
int Max = 1e6;
void Process()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    reset(dp);
    int ans = 0;
    rep(i, 1, n)
    {
        rep(j, 1, i - 1)
        {
            int val = a[i] - a[j];
            dp[i][j] = 2;
            if (val <= Max && val >= -Max && idx[val] > 0)
                dp[i][j] = dp[j][idx[val]] + 1;
            ans = max(ans, dp[i][j]);
            idx[a[j]] = j;
        }
        rep(j, 1, i - 1) idx[a[j]] = 0;
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    cout.tie(null);
    int t;
    cin >> t;
    while (t--)
        Process();
}