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

const int mod = 1e9 + 7;
const int MX = 1e6 + 5;
const ll INF = 1e18;
const ldb PI = acos((ldb)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
/*_______________________________________MY CODE_____________________________________*/
// #define int ll
bool ok[7];
int ba[7];
ll ab[7];
bool check = false;
void init()
{
    rep(i, 1, 6)
    {
        ok[i] = false;
    }
    check = false;
}

ldb volumn(ll u, ll U, ll v, ll V, ll w, ll W) // cong thuc heron
{
    ldb X = (w * w + u * u - V * V);
    ldb Y = (v * v + w * w - U * U);
    ldb Z = (u * u + v * v - W * W);
    ldb T = (u * v * w);
    return sqrt(X * Y * Z + 2 * 2 * T * T - u * u * Y * Y - v * v * X * X - w * w * Z * Z) / 12;
}
bool isTri(ll a, ll b, ll c)
{
    return (a + b > c) && (b + c > a) && (c + a > b);
}

///
///                *A
///               /|\
///              / | \
///             / d|  \                 a = BC
///            /   |   \                b = CA
///           /    O    \               c = AB
///        c /    / \    \ b            d = OA
///         /   /     \   \             e = OB
///        /  /         \  \            f = OC
///       / / e         f \ \
///      //                 \\
///     /         a           \
///    *-----------------------*
///    B                       C
///
/*
ll BC = ab[0];
ll CA = ab[1];
ll AB = ab[2];
ll OA = ab[3];
ll OB = ab[4];
ll OC = ab[5];
*/
bool rel()
{
    ll a = ab[ba[1]], b = ab[ba[2]], c = ab[ba[3]], d = ab[ba[4]], e = ab[ba[5]], f = ab[ba[6]];
    if (volumn(d, a, e, b, f, c) > 0 && isTri(a, b, c) && isTri(e, c, d) && isTri(b, d, f) && isTri(a, e, f))
    {
        return true;
    }
    return false;
}
void Try(int i)
{
    rep(j, 1, 6)
    {
        if (ok[j] == false)
        {
            ba[i] = j;
            ok[j] = true;
            if (i == 6)
            {
                if (rel() == true)
                {
                    check = true;
                }
            }
            else
                Try(i + 1);
            ok[j] = false;
        }
    }
}

void Process()
{
    init();
    rep(i, 1, 6) cin >> ab[i];
    Try(1);
    if (check == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        Process();
}