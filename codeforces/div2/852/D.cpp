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
    int n;
	cin >> n;

	vector<int> p(n + 1), q(n + 1);
	ll res = 1;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		p[x] = i;
	}

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		q[x] = i;
	}

	ll left = min(p[1], q[1]);
	ll right = max(p[1], q[1]);
	ll numbers = left;
	res += numbers * (numbers + 1) / 2;

	numbers = n - right - 1;
	res += numbers * (numbers + 1) / 2;

	numbers = max(0ll, right - left - 1);
	res += numbers * (numbers + 1) / 2;

	for(int mex = 2; mex <= n; mex++){
		ll loc_left = min(p[mex], q[mex]);
		ll loc_right = max(p[mex], q[mex]);

		if(left > loc_right) res += (left - loc_right) * (n - right);
		else if(right < loc_left) res += (loc_left - right) * (left + 1);
		else if(loc_left < left && right < loc_right) res += (left - loc_left) * (loc_right - right);

		left = min(left, loc_left);
		right = max(right, loc_right);
	}

	cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }
}