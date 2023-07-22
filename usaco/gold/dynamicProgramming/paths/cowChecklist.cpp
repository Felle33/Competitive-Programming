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

int dis(int firstX, int firstY, int secondX, int secondY){
    return (firstX - secondX) * (firstX - secondX) + (firstY - secondY) * (firstY - secondY);
}

void solve(){
    int h, g;
    cin >> h >> g;

    vector<pair<int, int>> holsteins(h);
    vector<pair<int, int>> guernseys(g);

    for(int i = 0; i < h; i++){
        cin >> holsteins[i].first >> holsteins[i].second;
    }

    for(int i = 0; i < g; i++){
        cin >> guernseys[i].first >> guernseys[i].second;
    }

    /**min_dist[i][j][k] represents the minimum distance for
	 * Farmer John to visit the first i Holsteins and the first
	 * j Guernseys, given that Farmer John is currently at
	 * k (0: ith Holstein, 1: ith Guernsey)
     * **/
    vector<vector<vector<ll>>> min_dist(h + 1, vector<vector<ll>>(g + 1, vector<ll>(2, 1e18)));
    
    min_dist[1][0][0] = 0;

    for(int i = 1; i < h; i++) {
        min_dist[i + 1][0][0] = min_dist[i][0][0] +
        dis(holsteins[i].first, holsteins[i].second, holsteins[i - 1].first, holsteins[i - 1].second);
    }

    for(int i = 1; i < g; i++) {
        min_dist[1][i + 1][] = min_dist[0][i] +
        dis(guernseys[i].first, guernseys[i].second, guernseys[i - 1].first, guernseys[i - 1].second);
    }

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= g; j++) {
            // from holstein i - 1 to i
            int add1 = min_dist[i - 1][j] + dis()
            min_dist[i][j] = min(min_dist[i - 1][j], min_dist[i][j - 1]);
        }
    }
    
    cout << min_dist[h - 1][g - 1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}