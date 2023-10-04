#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;

int n;
vector<vector<ll>> dp;
vector<ll> bosses;

// turn (0 = friend, 1 = me)
ll rec(int i, bool turn){
    if(i >= n) return 0;
    if(dp[i][turn] != -1) return dp[i][turn];
    
    ll oneKill = INF, twoKill = INF;
    if(turn) {
        oneKill = rec(i + 1, !turn);
        twoKill = rec(i + 2, !turn);
    } else {
        oneKill = (bosses[i] == 1 ? 1 + rec(i + 1, !turn) : rec(i + 1, !turn));
        if(i < n - 1) {
            if(bosses[i] == 1 && bosses[i + 1] == 1) {
                twoKill = 2 + rec(i + 2, !turn);
            } else if(bosses[i] == 1 || bosses[i + 1] == 1) {
                twoKill = 1 + rec(i + 2, !turn);
            } else {
                twoKill = rec(i + 2, !turn);
            }
        }
    }
    dp[i][turn] = min(oneKill, twoKill);
    return dp[i][turn];
}

void solve(){
    cin >> n;

    dp = vector<vector<ll>>(n, vector<ll>(2, -1));
    bosses = vector<ll>(n);
    for(int i = 0; i < n; i++){
        cin >> bosses[i];
    }

    ll ans = rec(0, 0);
    cout << ans << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout); */
    int t;
    cin >> t;
    while(t--) solve();
}