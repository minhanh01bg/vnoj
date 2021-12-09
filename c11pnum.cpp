#include <bits/stdc++.h>

#define int unsigned long long
#define mp make_pair
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOR2(i, a, b) for (int i = a; i >= b; i--)
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
    if (n < 2)
        return false;
    else if (n == 2 || n == 3 || n == 5)
        return true;
    else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        return false;
    for (int i = 7; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

// eratosthenes prime number
const int MAX = 3e6;
bool PRIME[MAX];
int prime[MAX];
void EratosthenesPrime()
{
    memset(PRIME, true, sizeof(PRIME));
    PRIME[0] = false;
    PRIME[1] = false;
    for (int i = 2; i <= MAX; i++)
        if (PRIME[i] == true)
            for (int j = 2 * i; j <= MAX; j += i)
                PRIME[j] = false;
    int cnt = 0;
    for (int i = 2; i <= MAX; i++)
        if (PRIME[i])
            prime[cnt++] = i;
}

/*_____________________________________MY CODE_____________________________________*/

int check(int n, int k)
{
    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans *= prime[i];
    }
    if (ans < n)
        return ans;
    else
        return -1;
}
void process()
{
    int n = 0, k = 0;
    cin >> n >> k;

    EratosthenesPrime();
    int ans = check(n, k);
    if (ans == -1)
    {
        cout << -1 << endl;
        return;
    }
    for (int j = 0; j <= n; j++)
    {
        int cur = 1, cnt = 0;
        for (int i = j; i < 3e6; i++)
        {
            cur *= prime[i];
            cnt++;
            if (cnt == k || cur > n)
                break;
        }
        if (cur > n)
            break;
        else
            ans = max(cur, ans);
    }

    cout << ans << endl;
}

signed main()
{
    faster();
    run() process();
    return 0;
}
