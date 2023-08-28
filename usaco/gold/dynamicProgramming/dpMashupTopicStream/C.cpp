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

void solve(){
    int n; cin >> n;

    // dp[i][k] = minimum cost after have visited i shops and bought juices to have bitmask k vitamins
    vector<vector<ll>> dp(n + 1, vector<ll>(8, INF));

    dp[0][0] = 0;
    rep(i, n) {
        ll cost; cin >> cost;
        string str; cin >> str;

        int bitmask = 0;
        for(int pos = 2; pos >= 0; pos--) {
            char vit = 'C' - pos;
            for(char c : str) {
                if(vit == c) bitmask += (1 << pos);
            }
        }

        for(int bit = 0; bit < 8; bit++) {
            if(dp[i][bit] != INF) {
                dp[i + 1][bit] = min(dp[i + 1][bit], dp[i][bit]);
                dp[i + 1][bit | bitmask] = min(dp[i + 1][bit | bitmask], dp[i][bit] + cost);
            }
        }
    }
    
    ll ans = dp[n][7];
    if(ans == INF) ans = -1;
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}