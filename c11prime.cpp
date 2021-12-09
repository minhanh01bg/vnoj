#include <bits/stdc++.h>
using namespace std;
bool check[10000000 + 1];
void checksnt()
{
    int N = 10000000;

    for (int i = 2; i <= N; i++)
    {
        check[i] = true;
    }

    for (int i = 2; i <= N; i++)
    {
        if (check[i] == true)
        {
            for (int j = 2 * i; j <= N; j += i)
            {
                check[j] = false;
            }
        }
    }
}

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return n > 1;
}

int main()
{
    long long n;
    cin >> n;
    bool check1 = true;
    checksnt();
    int q = 0, p = 0;
    double k1 = sqrt(n);
    long long k2 = sqrt(n);
    if (k1 == k2 && isPrime(k2))
    {
        cout << k2 << " " << 2;
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (check[i] == false && i < 1000000)
            continue;
        while (n % i == 0)
        {
            q++;
            n /= i;
            p = i;
            check1 = false;
        }
        if (check1 == false)
            break;
    }
    if (n > 1)
        cout << 0;
    else
        cout << p << " " << q << endl;
}
