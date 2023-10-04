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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vll skill;
vll dp;
int n, k;

void solve(){
    cin >> n >> k;
    skill.resize(n);
    dp.resize(n);
    rep(i, n) cin >> skill[i];
    
    dp[0] = skill[0];
    for(int i = 1; i < n; i++) {
        ll curMax = skill[i];
        for(int len = 0; len < k; len++) {
            int j = i - len;
            if(j < 0) break;

            curMax = max(curMax, skill[j]);
            dp[i] = max(dp[i], (j - 1 < 0 ? 0 : dp[j - 1]) + curMax * (len + 1));
        }
    }

    cout << dp[n - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);

    solve();
}