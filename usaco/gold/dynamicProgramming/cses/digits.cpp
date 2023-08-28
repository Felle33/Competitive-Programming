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
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vll dp;
ll minPath(ll n) {
    if(n == 0) return 0;
    if(dp[n] != INF) return dp[n];

    ll ans = INF;
    ll copy = n;
    for(; copy > 0;) {
        if(copy % 10 != 0) {
            ans = min(ans, 1 + minPath(n - (copy % 10)));
        }
        copy /= 10;
    }
    dp[n] = ans;
    return ans;
}

void solve(){
    int n; cin >> n;

    dp = vll(n + 1, INF);
    cout << minPath(n) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}