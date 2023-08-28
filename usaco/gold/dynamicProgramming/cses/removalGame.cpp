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

vll nums;
// dp[i][j][player] = max point that player can reach if the range of the remaining numbers is [i, j)
ll dp[5001][5001][2];
ll pref[5001];

ll maxWin(int i, int j, int player) {
    if(j - i == 1) return nums[i];
    if(dp[i][j][player] != -1) return dp[i][j][player];

    ll sumOfAllSegment = pref[j - 1] - (i == 0 ? 0 : pref[i - 1]);
    ll ans = max(sumOfAllSegment - maxWin(i + 1, j, !player), sumOfAllSegment - maxWin(i, j - 1, !player));
    dp[i][j][player] = ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    nums = vll(n);
    rep(i, n) cin >> nums[i];

    pref[0] = nums[0];
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + nums[i];
    }

    for(int i = 0; i < 5001; i++) {
        for(int j = 0; j < 5001; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }

    cout << maxWin(0, n, 0) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}