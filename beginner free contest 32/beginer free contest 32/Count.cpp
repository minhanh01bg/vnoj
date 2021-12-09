#include<bits/stdc++.h>
using namespace std;
vector<int> matrix[200001];
bool checker[200001];
int Cnt[200001];
// 1764 5792 6937 1914 3261 3663 3727 8744 7537 1553 2511 7476 3173 6358 8270 316 7950 
// 2664 1790 8208 4906 9654 4702 6690 6444 3892 8668 4550 8701 3244 5643 556 4388 7824 
// 7605 5411 989 4113 489 418 2667 2563 771 8265 2474 4778 7299 4891 1388 7133 2042 634 
// 184 9792 7758 4012 2758 3017 3870 6417 7557 1053 624 4126 2122 8736 3356 1992 736 7476
//  860 52 3993 1322 7502 2446 3272 4445 1434 6825 5809 9168 2972 3254 9394 2675 3605 3353 6467

void DFS(int u){
    checker[u] = true;
    for(int i: matrix[u]){
        if(checker[i]==false){
            DFS(i);
            Cnt[u]+=(Cnt[i]+1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1;i <= n - 1; i++){
        int x, y;
        cin >> x >> y;
        matrix[x].push_back(y);
        matrix[y].push_back(x);
    }
    DFS(1);
    for(int i = 1;i <= n; i++){
        int x1; cin >> x1;
        cout<<Cnt[i]+1<<" ";
    }
}