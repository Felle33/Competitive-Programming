#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> signalsDamaged(n + 1);
    vector<bool> damaged(n + 1);

    for(int i = 0; i < b; i++){
        int x;
        cin >> x;

        damaged[x] = true;
    }

    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        signalsDamaged[i] = signalsDamaged[i - 1] + damaged[i];

        if(i - k >= 0){
            ans = min(ans, signalsDamaged[i] - signalsDamaged[i - k]);
        }
    }

    cout << ans << '\n';
}

int main(){
    freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
    solve();
} 