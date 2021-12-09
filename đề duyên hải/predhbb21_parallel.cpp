#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define run()     \
    int N;        \
    cin >> N;     \
    cin.ignore(); \
    while (N--)
#define pause() system("pause");

using namespace std;

main()
{
    faster();
    while (1)
    {
        int a[12];
        FOR(i, 0, 11)
        cin >> a[i];
        if (a[0] == 0)
            break;
        sort(a, a + 12);
        int ans = a[0];
        int x = 0;
        FOR(i, 1, 3)
        {
            if (ans != a[i])
            {
                x = 1;
                cout << "no\n";
                break;
            }
        }
        if (x == 1)
            continue;
        ans = a[4];
        FOR(i, 5, 7)
        {
            if (ans != a[i])
            {
                x = 1;
                cout << "no\n";
                break;
            }
        }
        if (x == 1)
            continue;
        ans = a[8];
        FOR(i, 9, 11)
        {
            if (ans != a[i])
            {
                cout << "no\n";
                x = 1;
                break;
            }
        }
        if (x == 1)
            continue;
        cout << "yes\n";
    }
}
