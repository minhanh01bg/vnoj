#include<bits/stdc++.h>


const int N = 3e5 + 12;
const long long Mod = 1e9 + 7;
const long long oo = 1e18;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back

#define FOR(i, a, b) for (int _ = a, __ = b, i = _; i <= __; i++)
#define FORD(i, a, b) for (int _ = a, __ = b, i = _; i >= __; i--)

using namespace std;

int n;
int id[N], ans[N], vis[N];
vector<int> g[N];
set<int>::iterator it;
set<int> s[N];

void Dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) if(!vis[v]){
        Dfs(v);
        int pu = id[u], pv = id[v];
        if (s[pu].size() >= s[pv].size()) {
            for (it = s[pv].begin(); it != s[pv].end(); it++) s[pu].insert(*it);
        } else {
            id[u] = id[v];
            for (it = s[pu].begin(); it != s[pu].end(); it++) s[pv].insert(*it);
        }
        ans[u] = s[id[u]].size();
    }
}

main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }

    FOR(i, 1, n) {
        int x;
        cin >> x;
        id[i] = i; ans[i] = 1;
        s[i].insert(x);
    }

    FOR(i, 1, n) vis[i] = 0;
    Dfs(1);
    FOR(i, 1, n) cout << ans[i] << " " ;
}
