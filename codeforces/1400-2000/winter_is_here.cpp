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
const ll DIM = 1e6 + 10;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

ll cnt[DIM + 1];
ll dp[DIM + 1];

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= MOD1;
    while(e > 0){
        if(e & 1) {
            res = res * b % MOD1;
        }  
        
        b = b * b % MOD1;
        e >>= 1;
    }

    return res;
}

void prime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            cnt[i]++;
            if(i * i != x) cnt[x / i]++;
        }
    }
    cnt[x]++;
}

void solve(){
    int n; cin >> n;
    rep(i, n) {
        int x; cin >> x;
        prime(x);
    }

    for(int x = DIM; x > 1; x--) {
        dp[x] = cnt[x] * exponentiation(2, cnt[x] - 1) % MOD1;
    }

    ll ans = 0;
    for(int x = DIM; x > 1; x--) {
        for(int j = 2 * x; j <= DIM; j += x) {
            dp[x] -= dp[j];
            if(dp[x] < 0) dp[x] += MOD1;
        }
        ans = (ans + dp[x] * x % MOD1) % MOD1;
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    solve();
}