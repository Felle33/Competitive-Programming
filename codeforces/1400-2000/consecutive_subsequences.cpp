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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define FELLE ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.precision(10); cout << std::fixed;

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
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

void solve(){
    int n; cin >> n;
    vi nums(n);
    map<int, int> dp;
    int ans = 0, curr = 0;
    rep(i, n) {
        int a; cin >> a;
        nums[i] = a;
        if(dp[a] < dp[a - 1] + 1) {
            dp[a] = dp[a - 1] + 1;
            
            if(ans < dp[a]) {
                ans = dp[a];
                curr = a;
            }
        }
    }

    cout << ans << "\n";
    vi ans_v;
    for(int i = n - 1, j = ans; i >= 0 && j > 0; i--) {
        if(nums[i] == curr) {
            ans_v.push_back(i + 1);
            curr--;
            j--;
        }
    }

    reverse(all(ans_v));
    rep(i, ans) cout << ans_v[i] << " ";
}

int main(){
    FELLE
    solve();
}