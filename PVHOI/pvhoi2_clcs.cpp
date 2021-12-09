#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define p pair
#define all(C) C.begin(), C.end()

#define FOR(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define FOR2(i, a, b) for (ll i = (ll)a; i <= (ll)b; ++i)
#define FORD(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)

using namespace std;
int row, col, h, w;
int need;
int a[3011][3011], f[3011][3011];
int getsummax(int i, int j, int u, int v)
{
    return f[u][v] - f[u][j - 1] - f[i - 1][v] + f[i - 1][j - 1];
}
bool check(int val)
{
    FOR(i, 1, row)
    {
        FOR(j, 1, col)
        {
            f[i][j] = a[i][j] >= val;
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    for (int i1 = 1, i2 = h; i2 <= row; i1++, i2++)
    {
        for (int j1 = 1, j2 = w; j2 <= col; j1++, j2++)
        {
            if (getsummax(i1, j1, i2, j2) >= need)
            {
                return true;
            }
        }
    }
    return false;
}
void process()
{
    need = (h * w) / 2 + 1;
    int l = 1, r = row * col;
    int res = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << res << endl;
}

void readinput()
{
    cin >> row >> col >> h >> w;
    FOR(i, 1, row)
    {
        FOR(j, 1, col)
        {
            cin >> a[i][j];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);
    readinput();
    process();
    return 0;
}
