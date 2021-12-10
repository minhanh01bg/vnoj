#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'

void Process()
{
    ll n;
    cin >> n;
    if (n % 2 == 0)
        cout << n / 2 << endl;
    else
        cout << (-n - 1) / 2 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Process();
}