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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

// dp[i] -> is a pair in which the first number is the number of rides and the second number
// is the remain capacity of the last ride
void solve(){
    int n; cin >> n;
    ll capacity; cin >> capacity;

    vll weights(n);
    rep(i, n) cin >> weights[i];

    vector<pair<ll,ll>> dp((1 << n), mp(INF, -1));
    dp[0] = mp(0, 0);
    for(int mask = 1; mask <= ((1 << n) - 1); mask++) {
        for(int bit = 0; bit < n; bit++) {
            if((mask & (1 << bit)) == 0) continue;
            int precState = mask ^ (1 << bit);
            ll ridesPrecState = dp[precState].first;
            ll remCapPrecState = dp[precState].second;

            ll ridesThisState = ridesPrecState;
            ll remCapThisState = remCapPrecState;
            if(remCapPrecState - weights[bit] < 0) {
                ridesThisState++;
                remCapThisState = capacity - weights[bit];
            } else {
                remCapThisState -= weights[bit];
            }

            if(ridesThisState <= dp[mask].first) {
                dp[mask].first = ridesThisState;
                if(dp[mask].second < remCapThisState) {
                    dp[mask].second = remCapThisState;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].first << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}