#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (i < 2)
            continue;
        int k = 1;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                k = 0;
                break;
            }
        }
        if (k == 1)
            cout << i << endl;
    }
}
