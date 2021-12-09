#include <bits/stdc++.h>

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int N = 1001;

int n;
int a[N];
int tree[N*4];

void build(int id,int l,int r){
    if(l == r){
        tree[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id * 2, l , mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = max(tree[id * 2] , tree[id * 2 + 1]);
}

void update(int id, int left, int right, int u, int v, int val){
    if(u > right || v < left)
        return;
    if(left == right){
        tree[id] += val;
        return;
    }
    int mid = (left + right) / 2;
    update((id<<1), left, mid, u , v, val);
    update((id<<1)+1, mid + 1, right, u, v, val);
    tree[id] = max(tree[id*2], tree[id*2+1]);
}

int getVal(int id,int l,int r,int u,int v){
    if(u>r||v<l)    return 0;
    if(l == r){
        return tree[id];
    }
    int mid = (l+r)/2;
    return max(getVal(id*2,l,mid,u,v),getVal(id*2,mid+1,r,u,v));
}

main() {
    faster
    cin >> n;
    for(int i = 1;i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int quest;  cin >> quest;
    while(quest--){
        int L, R;   cin >> L >> R;        
        cout<<getVal(1, 1, n, L, R)<<endl;
    }   
}
