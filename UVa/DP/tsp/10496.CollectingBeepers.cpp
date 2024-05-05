#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

int n, m, starti, startj;
int k;
vector<pii> beep;

int dis(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

void solve(){
    cin >> n >> m >> startj >> starti;
    cin >> k;
    beep.resize(k);
    rep(i, k) cin >> beep[i].second >> beep[i].first;

    vvi dp(1 << k, vi(k, INF));
    dp[0][0] = 0;

    for(int state = 0; state < (1 << k); state++) {
        for(int pos = 0; pos < k; pos++) {
            if((state & (1 << pos)) == 0) continue;
            
            int prevState = state ^ (1 << pos);
            if(prevState == 0) {
                dp[state][pos] = min(dp[state][pos], dis(starti, startj, beep[pos].first, beep[pos].second));
            } else {
                for(int prevLast = 0; prevLast < k; prevLast++) {
                    if(prevState & (1 << prevLast)) {
                        dp[state][pos] = min(dp[state][pos], dp[prevState][prevLast] +
                                dis(beep[prevLast].first, beep[prevLast].second, beep[pos].first, beep[pos].second));
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < k; i++) {
        ans = min(ans, dp[(1 << k) - 1][i] + dis(starti, startj, beep[i].first, beep[i].second));
    }

    cout << "The shortest path has length " << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}