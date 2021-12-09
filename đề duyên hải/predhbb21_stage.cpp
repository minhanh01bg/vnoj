#include <bits/stdc++.h>
using namespace std;
int a[10][3];
int main()
{
	cin.tie(0),cout.tie(0)->sync_with_stdio(0);
	while (true)
    {
        for (int i = 1; i <= 3 ; ++i)
        {
            cin>>a[i][0]>>a[i][1];
        }
        if (!a[1][0]) return 0;;
        int res = 1e9;
        for (int i = 0; i <= 1 ; ++i)
        {
            for (int j = 0; j <= 1 ; ++j)
            {
                for (int k = 0; k <= 1 ; ++k)
                {
                    if (a[1][i] < a[2][j] ) swap(a[1][i] , a[2][j] ), swap(a[1][1-i] , a[2][1-j] );
                    if (a[1][i] < a[3][k] ) swap(a[1][i] , a[3][k] ), swap(a[1][1-i] , a[3][1-k] );
                    if (a[2][j] < a[3][k] ) swap(a[2][j] , a[3][k] ), swap(a[2][1-j] , a[3][1-k] );
                    res = min(res ,(a[1][i] * a[1][1-i] + a[2][j] * max(a[2][1-j] - a[1][1-i], 0) + a[3][k] * max(a[3][1-k] - max(a[1][1-i], a[2][1-j]), 0)));
                }
            }
        }
        cout << res << '\n';
    }
	return 0;
}
