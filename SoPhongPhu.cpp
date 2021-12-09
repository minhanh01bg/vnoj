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

signed main()
{
    int C[100010];
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= b; i++)
        C[i] = 0;
    for (int i = 2; i <= b; i++)
        for (int j = i * 2; j <= b; j += i)
            C[j] += i;

    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (C[i] + 1 > i)
            cnt += 1;
    }
    cout << cnt;
}