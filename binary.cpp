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
ll f[33][2][33][2], n[33];

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    ll N, K;
    while (cin >> N >> K)
    {

        // init bits of n
        vector<int> bits;
        while (N > 0)
        {
            bits.push_back(N % 2);
            N /= 2;
        }
        if (bits.empty())
            bits.push_back(0);
        if (K > bits.size())
        {
            cout << 0 << endl;
            continue;
        }
        int ind = 1;
        for (int i = bits.size() - 1; i >= 0; i--)
            n[ind++] = bits[i];

        // dp
        memset(f, 0, sizeof f);
        f[0][0][0][0] = 1;
        // f(xây dựng i chữ số,kiếm tra nó có nhỏ hơn n hay bằng n,có k sô 0 thỏa mãn,có lớn hơn 0 hay không)
        // f(i, lower, k, > 0)
        for (int i = 0; i < bits.size(); i++)
        {
            for (int lower = 0; lower <= 1; lower++)
            {
                for (int k = 0; k <= i; k++)
                {
                    for (int positive = 0; positive <= 1; positive++)
                    {
                        for (int digit = 0; digit <= 1; digit++)
                        {
                            ll cur = f[i][lower][k][positive];
                            if (!cur)
                                continue;
                            if (!lower && digit > n[i + 1]) // lower = false => số hiện tại bằng n, digit(số tiếp theo) > n[n+1] => số đó lớn hơn n
                                continue;

                            int lower2 = lower || (digit < n[i + 1]); // số xây dựng đến vị trí i + 1 có nhỏ hơn n không
                            int k2 = k;
                            if (positive && digit == 0) // positive = 0 => số hiện tại !=0 và digit(số tiếp theo) = 0
                                k2++;
                            int positive2 = positive || (digit > 0); // số xây dựng đến vị trí i+1 có dương hay không
                            f[i + 1][lower2][k2][positive2] += cur;
                        }
                    }
                }
            }
        }
        ll res = 0;
        for (int lower = 0; lower <= 1; lower++)
        {
            res += f[bits.size()][lower][K][1];
        }
        if (K == 1)
            res += 1;
        cout << res << endl;
    }
}
