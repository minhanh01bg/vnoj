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
#define mp make_pair
// #define fi first
#define se second

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
const int MX = 5e4 + 7;
const ll INF = 1e18;
const int NM = 1e6 + 7;
const ldb PI = acos((ldb)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
/*_______________________________________MY CODE_____________________________________*/
//

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
        return false;
    for (int i = 11; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}

/*
Đây là 1 bài quy hoạch động chữ số kinh điển.

Ta sẽ xây dựng lần lượt các chữ số của cả x và y từ phải sang trái:

Đặt f(i, rem, sum_x, sum_y) = số cách xây dựng các chữ số từ i -> n, sao cho tổng (phần đã xây dựng của x) + 2*(phần đã xây dựng của y) khớp với các chữ số từ i đến n.

rem = nhớ của tổng (phần đã xây dựng của x) + (phần đã xây dựng của y)
sum_x = tổng các chữ số đã xây dựng của x
sum_y = tổng các chữ số đã xây dựng của y
*/
ll f[20][3][155][155];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);
    str s;
    cin >> s;

    int n = s.size();
    vector<ll> digits(n);
    for (int i = 0; i < n; i++)
        digits[i] = s[i] - '0';

    f[n][0][0][0] = 1;
    for (int i = n; i > 0; i--)
    {
        rep(rem, 0, 2) // x+2y => tối đa nhớ 2
        {
            rep(sumx, 0, 150) // 10^15 => tổng chữ số tối đa là 150
            {
                rep(sumy, 0, 150)
                {
                    ll cur = f[i][rem][sumx][sumy];
                    if (!cur)
                        continue;
                    rep(x, 0, 9)
                    {
                        rep(y, 0, 9)
                        {
                            ll t = x + 2 * y + rem;
                            if (t % 10 == digits[i - 1])
                            {
                                f[i - 1][t / 10][sumx + x][sumy + y] += cur;
                            }
                        }
                    }
                }
            }
        }
    }
    ll res = 0;
    rep(sumx, 1, 150)
        rep(sumy, 1, 150) if (isPrime(sumx) && isPrime(sumy))
            res += f[0][0][sumx][sumy];
    cout << res << endl;
}