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

void solve(){
    int n;
    cin >> n;

    vector<int> nums(n);
    priority_queue<pair<int, int>> pq;
    bool oneDetected = false;
    int m = 1e9 + 1;
    int index;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if(a == 1) oneDetected = true;
        nums[i] = a;
        if(nums[i] < m){
            index = i;
            m = nums[i];
        }
    }

    bool allEquals = true;
    for(int i = 0; i < n - 1; i++){
        if(nums[i] != nums[i + 1]) allEquals = false;
    }

    if(allEquals){
        cout << 0 << '\n';
        return;
    }

    if(oneDetected){
        cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(i != index) pq.push({nums[i], i});
    }

    int numOp = 0;
    vector<pair<int, int>> ans;
    while(!pq.empty()){
        pair<int, int> val = pq.top();
        pq.pop();

        if(val.first == m){
            continue;
        }

        numOp++;
        int res = (val.first + m - 1) / m;
        ans.push_back({val.second, index});
        if(res < m){
            pq.push({m, index});
            m = res;
            index = val.second;
        }
        else if(res >= m){
            pq.push({res, val.second});
        }
    }

    cout << numOp << '\n';

    for(int i = 0; i < (int) ans.size(); i++){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
    }
    
}

int main(){
    /* ios_base::sync_with_stdio(false);
    cin.tie(NULL); */

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}