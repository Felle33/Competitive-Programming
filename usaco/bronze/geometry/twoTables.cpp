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

void solve(){
    int w, h;
    cin >> w >> h;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int w2, h2;
    cin >> w2 >> h2;

    int w1 = x2 - x1;
    int h1 = y2 - y1;

    if(w1 + w2 > w && h1 + h2 > h){
        cout << -1 << '\n';
        return;
    }

    int ans = INT_MAX;
    if(w2 <= w - w1){
        ans = min(ans, max(0, w2 - x1));
        ans = min(ans, max(0, x2 - (w - w2)));
    }
    
    if(h2 <= h - h1){
        ans = min(ans, max(0, h2 - y1));
        ans = min(ans, max(0, y2 - (h - h2)));
    }

    cout << setprecision(9) << double(ans) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}