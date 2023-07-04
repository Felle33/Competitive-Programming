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

const int DIM = 1e5 + 1;
const ll inf = 1e12;
int n, k;
vector<ll> dp(DIM, inf);
vector<ll> stones(DIM);

void rec(int i){
    if(i == n - 1){
        dp[i] = 0;
        return;
    }

    for(int j = 1; j <= k; j++){
        if(i + j < n){
            if(dp[i + j] == inf) rec(i + j);
            dp[i] = min(dp[i], dp[i + j] + abs(stones[i] - stones[i + j]));
        }
    }
}

void solve(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> stones[i];
    }

    rec(0);
    cout << dp[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 