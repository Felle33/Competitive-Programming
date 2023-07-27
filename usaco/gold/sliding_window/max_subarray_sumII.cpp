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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> nums(n);
    vector<ll> pref(n + 1);
    rep(i, n) {
        cin >> nums[i];
        pref[i + 1] = pref[i] + nums[i];
    }

    multiset<ll> multi;
    ll ans = -1e18;
    for(int i = a; i <= n; i++) {
        if(i > b) {
            multi.erase(multi.find(pref[i - b - 1]));
        }

        multi.insert(pref[i - a]);
        ans = max(ans, pref[i] - *multi.begin());
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}