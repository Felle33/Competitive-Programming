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
#define f first
#define s second
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<vector<ll>> dp;
vector<int> values, weights;
int n, w;

void solve(){
    
    cin >> n >> w;
    
    values = vector<int>(n);
    weights = vector<int>(n);
    rep(i, n) {
        cin >> weights[i] >> values[i];
    }

    dp = vector<vector<ll>>(n + 1,vector<ll>(1e5 + 1, INF));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int value = 0; value <= 1e5; value++) {
            dp[i][value] = dp[i - 1][value];

            if(value - values[i - 1] >= 0 && dp[i - 1][value - values[i - 1]] != INF) {
                dp[i][value] = min(dp[i][value], dp[i - 1][value - values[i - 1]] + weights[i - 1]);
            }
        }
    }

    ll ans = 0;
    for(ll value = 1; value <= 1e5; value++) {
        if(dp[n][value] <= w) {
            ans = max(ans, value);
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}