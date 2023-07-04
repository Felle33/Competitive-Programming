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

    vector<int> rooms(n);
    for(int i = 0; i < n; i++){
        cin >> rooms[i];
    }

    int res = 1e9;

    for(int i = 0; i < n; i++){
        int walk = 0;
        int count = 1;
        for(int j = (i + 1) % n; count < n; count++, j++){
            walk += count * rooms[j % n];
        }

        res = min(res, walk);
    }

    cout << res << '\n';
}

int main(){
    freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
    solve();
} 