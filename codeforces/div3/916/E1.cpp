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
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

const int MAX_N = 6;
int n;
ll dp[1 << MAX_N][1 << MAX_N][2];
vll a(MAX_N), b(MAX_N);

ll rec(ll A, ll B, int turn) {
    if((A & B) == 0) {
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            if(A & (1 << i)) {
                ans += a[i] - 1;
            }

            if(B & (1 << i)) {
                ans -= b[i] - 1;
            }
        }
        return ans;
    }

    if(dp[A][B][turn] != INF) return dp[A][B][turn];

    ll ans = INF;
    for(int i = 0; i < n; i++) {
        if(A & (1 << i) && B & (1 << i)) {
            if(turn == 0) {
                if(ans == INF) ans = rec(A, B ^ (1 << i), !turn);
                else ans = max(ans, rec(A, B ^ (1 << i), !turn));
                
            } else {
                if(ans == INF) ans = rec(A ^ (1 << i), B, !turn);
                else ans = min(ans, rec(A ^ (1 << i), B, !turn));
            }
        }
    }

    dp[A][B][turn] = ans;
    return ans;
}

void solve(){
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    // Initialization
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < (1 << n); j++) {
            for(int turn = 0; turn < 2; turn++) {
                dp[i][j][turn] = INF;
            }
        }
    }

    
    cout << rec((1 << n) - 1, (1 << n) - 1, 0) << '\n';
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
