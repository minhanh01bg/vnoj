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
void Process()
{
    ll n;
    cin >> n;
    ll a[35];
    rep(i, 0, 34)
        a[i] = pow(2, i);
    string s = "";
    while (n)
    {
        if (n % 2 == 0)
        {
            s += "0";
        }
        else
            s += "1";
        n /= 2;
    }
    // cout << s << endl;
    rep(i, 0, s.size() - 1)
    {
        if (s[i] == '1')
            cout << a[i] << " ";
    }
}
// 
void Process1()
{
    ll n;
    cin >> n;
    ll a[35];
    rep(i, 0, 34)
        a[i] = pow(2, i);
    int cnt = 0;
    ll m = n;
    // 2^cnt < m    (cnt lớn nhất)
    while (n % 2 == 0) // tính cnt
    {
        cnt += 1;
        n /= 2;
    }
    if (n == 1) // 2 ^ cnt = m
    {
        cout << m;
        return;
    }
    ll b[35];
    int x = 0;
    while (m != 0)
    {
        m -= a[cnt]; // m = m - 2 ^ cnt
        b[x] = a[cnt];
        x += 1;
        cnt = 0;
        n = m; // lặp lại quá trình trên
        while (n % 2 == 0) // tính cnt
        {
            cnt += 1;
            n /= 2;
        }
        if (cnt == 0)
            break;
        if (n == 1)  // 2 ^ cnt = n
        {
            b[x] = a[cnt];
            x += 1;
            break;
        }
    }
    rep(i, 0, x - 1) cout << b[i] << " ";
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    cout.tie(null);
    Process();
}