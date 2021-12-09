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

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!

int isPrime[1000000 + 11];

void sieve(int N)
{
    for (int i = 2; i <= N; ++i)
    {
        if (isPrime[i] == 0)
        {
            isPrime[i] = 1;
            for (int j = i + i; j <= N; j += i)
                isPrime[j] = isPrime[j] + 1;
        }
    }
}

int dp[1000011][8];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve(1000000);
    rep(i, 1, 1000000)
    {

        rep(j, 1, 7)
        {
            if (isPrime[i] == j)
                dp[i][isPrime[i]] = dp[i - 1][isPrime[i]] + 1;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        cout << dp[b][k] - dp[a - 1][k] << '\n';
    }
}