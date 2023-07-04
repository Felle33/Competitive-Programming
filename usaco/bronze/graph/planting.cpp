#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, 1 + (int) adj[i].size());
    }

    cout << ans << '\n';

}

int main(){
    freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
    solve();
} 