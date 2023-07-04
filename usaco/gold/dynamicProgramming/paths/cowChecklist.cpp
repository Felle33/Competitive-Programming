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

int h, g;
vector<pair<int, int>> holsteins;
vector<pair<int, int>> guernseys;

int dis(int firstX, int firstY, int secondX, int secondY){
    return abs(firstX - secondX) * abs(firstX - secondX) + abs(firstY - secondY) * abs(firstY - secondY);
}

int minPath(int holToWrite, int gueToWrite, int x, int y){
    if(holToWrite == 0 && gueToWrite == 0) return 0;

    ll res1 = 1e9, res2 = 1e9;

    if(holToWrite > 1 || (holToWrite == 1 && gueToWrite == 0)){
        res1 = minPath(holToWrite - 1, gueToWrite, holsteins[h - holToWrite].first, holsteins[h - holToWrite].second) +
        dis(x, y, holsteins[h - holToWrite].first, holsteins[h - holToWrite].second);
    } 

    if(gueToWrite >= 1){
        res2 = minPath(holToWrite, gueToWrite - 1, guernseys[g - gueToWrite].first, guernseys[g - gueToWrite].second) +
        dis(x, y, guernseys[g - gueToWrite].first, guernseys[g - gueToWrite].second);
    }

    return min(res1, res2);
}

void solve(){
    cin >> h >> g;
    holsteins.resize(h);
    guernseys.resize(g);

    for(int i = 0; i < h; i++){
        cin >> holsteins[i].first >> holsteins[i].second;
    }

    for(int i = 0; i < g; i++){
        cin >> guernseys[i].first >> guernseys[i].second;
    }

    cout << minPath(h - 1, g, holsteins[0].first, holsteins[0].second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}