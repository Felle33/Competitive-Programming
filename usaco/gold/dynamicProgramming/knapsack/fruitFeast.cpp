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

ll area(vector<ll> rect) {
	ll width = rect[2] - rect[0];
	ll height = rect[3] - rect[1];
	return width * height;
}

// return 0 if it doesn't intersect
int inter_area(vector<ll> s1, vector<ll> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	ll l1 = min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x);
	ll l2 = min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y);

	if(l1 <= 0 || l2 <= 0) return 0;

	return l1 * l2;
}

// return true if x,y is covered by the rectangle s
bool covered(ll x, ll y, vector<ll> s){
	return x >= s[0] && x <= s[2] && y >= s[1] && y <= s[3];
}

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= MOD;
    while(e > 0){
        if(e & 1)
            res = res * b % MOD;
        
        b = b * b % MOD;
        e >>= 1;
    }

    return res;
}

ll t, a, b;


int maxFullness(int f, bool w, vector<vector<int>>& dp){
    if(dp[f][w] != -1) return dp[f][w];
    bool canA = t - f >= a;
    bool canB = t - f >= b;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;

    if(canA) res1 = maxFullness(f + a, w, dp);
    if(canB) res2 = maxFullness(f + b, w, dp);

    if(!canA && !canB && !w) res3 = maxFullness(f / 2, true, dp);

    dp[f][w] = max({f, res1, res2, res3});
    return dp[f][w];
}

void solve(){
    cin >> t >> a >> b;
    vector<vector<int>> dp(t + 1, vector<int>(2, -1));
    cout << maxFullness(0, false, dp);

    dp[0][0] = true;
    for(int state = 1; state <= t; state++){
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout); */

    solve();
}