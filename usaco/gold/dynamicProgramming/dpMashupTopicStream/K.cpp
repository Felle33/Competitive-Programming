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

void add(int &a, int b) {
    a += b;
    if(a >= MOD) {
        a -= MOD;
    }
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) a[i] = i + 1;

    // dp[i][j] = 
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    dp[0][1] = 1;

    for(int i = 0; i < k; i++) {
        for(int j = 1; j <= n; j++) {
            for(int v = j; v <= n; v += j) {
                add(dp[i + 1][v], dp[i][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        add(ans, dp[k][i]);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}