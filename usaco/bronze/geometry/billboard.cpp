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

ll area(vector<ll> rect) {
	ll width = rect[2] - rect[0];
	ll height = rect[3] - rect[1];
	return width * height;
}

ll inter_area(vector<ll> s1, vector<ll> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	ll l1 = min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x);
	ll l2 = min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y);

	if(l1 <= 0 || l2 <= 0) return 0;

	return l1 * l2;
}

void solve(){
    vector<ll> b1(4), b2(4), t(4);

	for(int i = 0; i < 4; i++){
		cin >> b1[i];
	}

	for(int i = 0; i < 4; i++){
		cin >> b2[i];
	}

	for(int i = 0; i < 4; i++){
		cin >> t[i];
	}

	ll ans = area(b1) + area(b2);

	ans -= inter_area(b1, t);
	ans -= inter_area(b2, t);

	cout << ans << '\n';
}

int main(){
    freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
    solve();
}