#include <bits/stdc++.h>
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
    run()
    {
        int i, t;
        cin >> i >> t;
        if ((i <= 2 && t <= 1) || (i <= 1 && t <= 2))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
