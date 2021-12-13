#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl '\n'
// loops
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
// #define rep(i, a) rep(i, 0, a)
#define rof(i, a, b) for (int i = (b); i >= (a); --i)
#define r0f(i, a) rof(i, 0, a)
#define trav(a, x) for (auto &a : x)

signed main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    sort(a, a + n);
    int m = INT_MIN;
    m = max(a[n - 1] * a[n - 2] * a[n - 3], a[n - 1] * a[n - 2]);
    m = max(a[0] * a[1] * a[2], m);
    m = max(a[0] * a[1], m);
    m = max(a[0] * a[1] * a[n - 1], m);
    cout << m;
}