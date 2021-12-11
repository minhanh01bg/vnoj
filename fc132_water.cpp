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
#define null NULL
// loops
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
// #define rep(i, a) rep(i, 0, a)
#define rof(i, a, b) for (int i = (b); i >= (a); --i)
#define r0f(i, a) rof(i, 0, a)
#define trav(a, x) for (auto &a : x)

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const int N = 1e6 + 11;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
int n;
ll h[N];
ll ans = 0;
stack<int> st;
void Process()
{
    cin >> n;
    rep(i, 1, n) cin >> h[i];

    st.push(1);
    int x, y;
    rep(i, 2, n)
    {
        x = st.top();
        st.pop();
        while (!st.empty() && h[st.top()] >= h[x] && h[x] <= h[i]) // xóa h[x] nhỏ hơn ở giữa
        {
            x = st.top();
            st.pop();
        }
        st.push(x);
        st.push(i);
    }
    y = st.top();
    st.pop();
    int them = 0;
    while (!st.empty())
    {
        x = st.top();
        st.pop();
        int m = min(h[x], h[y]);
        rep(i, x + 1, y - 1) ans = ans + m - h[i]; // tính lượng nước giữa hai chiều cao
        if (h[x] != h[y])
            them = max(them, y - x - 1); // tìm cột +1 lớn nhất
        y = x;
    }
    cout << ans + them; // cộng thêm đoạn tăng 1
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    Process();
}