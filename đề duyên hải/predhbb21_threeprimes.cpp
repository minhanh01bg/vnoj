#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define cint cpp_int
#define all(C) C.begin(), C.end()

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

// vector<int> prime;

vector<int> prime;
vector<int> lpf;
void sieve(int n)
{
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);

    for (int x = 3; x <= n; x += 2)
    {
        if (lpf[x] == 2)
            prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i)
            lpf[prime[i] * x] = prime[i];
    }
}

bool isPrime(int x)
{
    return (x > 1) && (lpf[x] == x);
}

void slove(int n)
{
    int cnt = 0;
    FOR(cnt, 0, prime.size() - 1)
    {
        if (isPrime(prime[cnt] * 2 - 1))
        {
            n--;
            if (n == 0)
            {
                cout << prime[cnt] << " " << prime[cnt] << " " << prime[cnt] * 2 - 1;
                return;
            }
        }
        if (isPrime(prime[cnt] * 2 + 1))
        {
            n--;
            if (n == 0)
            {
                cout << prime[cnt] << " " << prime[cnt] << " " << prime[cnt] * 2 + 1;
                return;
            }
        }
    }
}

int main()
{
    sieve(1e7);
    int n;
    cin >> n;
    slove(n);
    return 0;
}
