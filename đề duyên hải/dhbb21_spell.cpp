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
/*________________________MY CODE___________________*/
const int MN = 311;

int d[MN][MN][MN];
//    k,  i , j
int mRow, nCol, k;
string board[MN];
string need;

bool inside(int u, int v)
{
    return 1 <= u && u <= mRow && 1 <= v && v <= nCol;
}

const int dirs[5] = {0, 1, 0, -1, 0};

void bfs()
{
    queue<tuple<int, int, int>> qu;
    memset(d, -1, sizeof(d));

    FOR(i, 1, mRow)
    {
        FOR(j, 1, nCol)
        {
            qu.push({0, i, j});
            d[0][i][j] = 0;
        }
    }

    while (!qu.empty())
    {
        auto [matched, u, v] = qu.front();
        qu.pop();
        if (matched == k)
        {
            cout << d[matched][u][v] << endl;
            return;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int uu = u + dirs[dir];
            int vv = v + dirs[dir + 1];
            if (!inside(uu, vv))
                continue;

            int matched2 = matched;
            if (need[matched2 + 1] == board[uu][vv])
                ++matched2;

            if (d[matched2][uu][vv] < 0)
            {
                d[matched2][uu][vv] = d[matched][u][v] + 1;
                qu.push({matched2, uu, vv});
            }
        }
    }
}
void process()
{
    cin >> mRow >> nCol >> k;
    cin >> need;
    need = " " + need + " ";
    FOR(i, 1, mRow)
    {
        cin >> board[i];
        board[i] = " " + board[i] + " ";
    }
    bfs();
}

signed main()
{
    faster();
    process();
}
