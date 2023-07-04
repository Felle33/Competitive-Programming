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
int n;
vector<ll> dp(DIM, inf);
vector<ll> stones(DIM);

void rec(int i){
    if(i == n - 1){
        dp[i] = 0;
        return;
    } 

    if(i + 1 < n){
        if(dp[i + 1] == -1) rec(i + 1);

        ll ans = min(dp[i], dp[i + 1] + abs(stones[i] - stones[i + 1]));
        dp[i] = ans;
    }

    if(i + 2 < n){
        if(dp[i + 2] == -1) rec(i + 2);

        ll ans = min(dp[i], dp[i + 2] + abs(stones[i] - stones[i + 2]));
        dp[i] = ans;
    }
}

void solve(){
    cin >> n;

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