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
#define mp make_pair
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

// loops
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
// #define rep(i, a) rep(i, 0, a)
#define rof(i, a, b) for (int i = (b); i >= (a); --i)
#define r0f(i, a) rof(i, 0, a)
#define trav(a, x) for (auto &a : x)

const int MOD = 1e9 + 7; // 998244353;
const int MX = 2e5 + 5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!

// map<str, int> MP;
// loga(b) = log_k(b)/log_k(a)
ld log_10(ld x)
{
    return log(x) / log(10);
}
void Process()
{
    string p;
    cin >> p;
    ld dP = p[0] - '0';

    int mul = 10;
    for (int i = 1; i < 20; i++)
    {
        if (i > p.length() - 1)
            break;
        dP = dP + (double)(p[i] - '0') / mul;
        mul *= 10;
    }

    ld log_10p = log_10(dP);//log10(dP)
    ld F[100011];
    rep(i, 2, 100000)
        F[i] = log_10(i);
    F[1] = 0;
    int start = 1, i = 1;
    ld check = 0, k = p.length() - 1;

    while (i <= 100000)
    {
        check = check + F[i];
        // cout << check << endl;
        while (check >= k + log_10p + 0.1 && start < i)
        {
            check -= F[start];
            start += 1;
        }
        // cout << check << ' ';
        if (check > k)
        {
            ld x = check - (k + log_10p);
            // cout << check << " " << k + log_10p << " " << x << endl;
            if (x >= -0.0000001 && x <= 0.0000001)
            {
                cout << start << " " << i;
                return;
            }
        }
        // cout << endl;
        i += 1;
    }
    // cout << p;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    Process();
}