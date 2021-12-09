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

vector<ll> a(360);
vector<ll> C;

int power(int a, int b)
{
    if (b == 0)
        return 1;
    int t = power(a, b / 2);
    return (b & 1) ? t * t * a : t * t;
}

void init()
{
    bool ok[100000];
    for (int i = 2; i <= 100000; i++)
        ok[i] = false;
    for (int i = 2; i <= 350; i++)
        a[i] = i;

    for (int i = 2; i <= 350; i++)
    {
        for (int j = 2; j <= 17; j++)
        {
            int k = power(i, j);
            if (k > 100000)
                break;
            if (ok[k] == false)
            {
                C.pb(power(i, j));
                ok[k] = true;
            }
        }
    }
    sort(all(C));
}

signed main()
{
    init();
    int X;
    cin >> X;
    ll ans = 1;
    for (int i = 0; i < C.size(); i++)
    {
        if (C[i] <= X)
            ans = max(ans, C[i]);
        else
            break;
    }
    cout << ans;
}
