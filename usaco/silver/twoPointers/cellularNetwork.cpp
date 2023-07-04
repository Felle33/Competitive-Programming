#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> cities(n), towers(m);
    for(int i = 0; i < n; i++){
        cin >> cities[i];
    }

    for(int i = 0; i < m; i++){
        cin >> towers[i];
    }

    int ans = 0;
    for(int u = 0, d = 0; u < n; u++){
        while(d < m - 1 && abs(cities[u] - towers[d]) >= abs(cities[u] - towers[d + 1])){
            d++;
        }

        ans = max(ans, abs(cities[u] - towers[d]));
    }

    cout << ans << '\n';
}

int main(){
    /* freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout); */
    solve();
} 