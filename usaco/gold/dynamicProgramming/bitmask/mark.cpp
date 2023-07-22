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
const ll INF = 1e18;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Cow {
    int height, weight, strength;
};

void solve(){
    int n, mark;
    cin >> n >> mark;

    vector<Cow> cows(n);
    rep(i, n) {
        int h, w, s;
        cin >> h >> w >> s;
        cows[i] = {h, w, s};
    }

    // dp[S] = max height and max safety for the subset S
    // safety = max weigth that the stack can support
    vector<pair<ll, ll>> dp(1 << n);
    dp[0].first = 0;
    dp[0].second = INF;

    for(int s = 1; s < (1 << n); s++) {
        dp[s] = {0, -1};
        for(int x = 0; x < n; x++) {
            // if x is not present in the subset continue
            if((s & (1 << x)) == 0) continue;

            //subset without x
            int prev_sub = s - (1 << x);

            // update of the height, since we iterate over all the bits on of the subset
            // we also add the height of every cow
            dp[s].first += cows[x].height;

            // update of the maximum safety, it is the minimum
            // between the strength of the new cow on the stack
            // or the safety before the add minus the weight of the last cow
            dp[s].second = max(dp[s].second,
                min(dp[prev_sub].second - cows[x].weight, (ll) cows[x].strength));
        }
    }

    ll max_saf = -1;
    for(int x = 1; x < (1 << n); x++) {
        if(dp[x].first >= mark) max_saf = max(max_saf, dp[x].second);
    }

    if(max_saf < 0) {
        cout << "Mark is too tall";
    } else {
        cout << max_saf;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);

    solve();
}