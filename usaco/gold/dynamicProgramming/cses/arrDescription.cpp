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

void add(ll &a, ll b) {
    a += b;
    if(a >= MOD) a-= MOD;
}

void solve(){
    int n, m; cin >> n >> m;
    vi nums(n);
    rep(i, n) cin >> nums[i];

    vvll dp = vvll(n, vll(m + 1, 0));

    if(nums[0] != 0) {
        dp[0][nums[0]] = 1;
    } else {
        for(int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i < n; i++) {
        if(nums[i] != 0) {
            for(int k = -1; k < 2; k++) {
                if(nums[i] + k <= 0 || nums[i] + k > m) continue;
                add(dp[i][nums[i]], dp[i - 1][nums[i] + k]);
            }
        } else {
            for(int j = 1; j <= m; j++) {
                for(int k = -1; k < 2; k++) {
                    if(j + k <= 0 || j + k > m) continue;
                    add(dp[i][j], dp[i - 1][j + k]);
                }
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= m; i++) add(ans, dp[n - 1][i]);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}