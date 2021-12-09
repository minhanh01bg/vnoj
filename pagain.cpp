#include <bits/stdc++.h>

#define ll unsigned long long
#define mp make_pair
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOR1(i, a, b) for (int i = a; i >= b; i--)
#define FOR2(i, a, b) for (ll i = a; i >= b; i--)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);                  \
    cin.tie(0);
using namespace std;

/*__________ prime number ___________ */

//check prime number
bool isPrime(int n)
{
    if (n == 2 || n == 3 || n == 5)
        return true;
    if (n < 2 || n % 3 == 0 || n % 2 == 0)
        return false;
    if (n % (int)sqrt(n) == 0)
        return false;
    for (int i = 7; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;

    return true;
}

// ll power(ll x, ll y, ll p)
// {
//     int res = 1;
//     x = x % p;
//     while (y > 0)
//     {
//         if (y & 1)
//             res = (res*x) % p;

//         y = y>>1; // y = y/2
//         x = (x*x) % p;
//     }
//     return res;
// }
ll power(ll a, ll b, ll n)
{
    if (b == 0)
        return 1;
    ll res = power(a, b / 2, n);
    return (b % 2 == 1) ? (((res * res) % n) * a) % n : ((res * res) % n);
}

bool miillerTest(ll d, ll s, ll n)
{
    ll a = 2 + rand() % (n - 2);
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    FOR1(i, s, 1)
    {
        x = (x * x) % n;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3 || n == 5)
        return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        return false;

    ll d = n - 1, s = 1;
    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }
    //ll s = 63 - __builtin_clzll((n - 1) & (1 - n)), d = (n - 1) >> s;
    for (int i = 0; i < 5; i++)
        if (!miillerTest(d, s, n))
            return false;

    return true;
}

// eratosthenes prime number
// int MAX = 3e6;
// bool PRIME[MAX];
// int prime[MAX];
// void EratosthenesPrime()
// {
//     memset(PRIME, true, sizeof(PRIME));
//     PRIME[0] = false;
//     PRIME[1] = false;
//     for (int i = 2; i <= MAX; i++)
//         if (PRIME[i] == true)
//             for (int j = 2 * i; j <= MAX; j += i)
//                 PRIME[j] = false;
//     int cnt = 0;
//     for (int i = 2; i <= MAX; i++)
//         if (PRIME[i])
//             prime[cnt++] = i;
// }

/*_____________________________________MY CODE_____________________________________*/

void process()
{
    ll n;
    cin >> n;
    FOR2(i, n - 1, 2)
    {
        if (isPrime(i))
        {
            cout << i << endl;
            return;
        }
    }
}

signed main()
{
    faster();
    run() process();
    return 0;
}