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
const ll DIM = 2e5;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

ll fact[DIM + 1];

void prec() {
    fact[0] = 1;
    for(int i = 1; i <= DIM; i++) fact[i] = fact[i - 1] * i % MOD1;
}

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

ll inverse(int x) {
    return exponentiation(x, MOD1 - 2);
}

ll binomial(int n, int k) {
    if(n < k) return 0;
    return fact[n] * inverse(fact[k] * fact[n - k] % MOD1) % MOD1;
}

void solve(){
    int n, k; cin >> n >> k;
    int one = 0, zero = 0;

    rep(i, n) {
        int a; cin >> a;
        if(a == 1) one++;
        else zero++;
    }

    ll ans = 0;
    for(int m = k / 2 + 1; m <= k; m++) {
        ans = ans + binomial(one, m) * binomial(zero, k - m) % MOD1;
        ans %= MOD1;
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    prec();
    while(t--){
        solve();
    }
}