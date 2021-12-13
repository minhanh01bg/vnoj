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

const int MOD = 1e9 + 7;
const int MX = 1e6 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!

vi abc;
queue<str> Q;
int InttoStr(str x)
{
    int y = 0;
    rep(i, 0, x.size() - 1)
    {
        y = y * 10 + int(x[i] - '0');
    }
    return y;
}
void init()
{
    rep(i, 1, 9)
    {
        str s = "";
        char x = char(i + '0');
        s += x;
        Q.push(s);
    }
    while (!Q.empty())
    {
        str x = Q.front();
        Q.pop();
        int y = InttoStr(x);
        if (y > 1111111)
            break;
        abc.pb(y);

        Q.push(x + x[0]);
    }
}
int n, a[MX];
int mp[1111111];
void Process()
{
    init();
    cin >> n;
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) mp[a[i]] = 0;
    rep(i, 0, n - 1) mp[a[i]]++;
    ll ans = 0;
    rep(i, 0, n - 1)
    {
        rep(j, 0, abc.size() - 1)
        {
            int x = abc[j] - a[i];
            if (x >= 0)
            {
                if (mp[x])
                {
                    ans += mp[x];
                    if (x == a[i])
                        ans -= 1;
                }
            }
        }
    }
    cout << ans / 2;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    cout.tie(null);
    Process();
}