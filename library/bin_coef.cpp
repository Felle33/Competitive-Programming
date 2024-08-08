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
const ll MAX_N = 20;

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

int inverse(int x) {
    return exponentiation(x, MOD1 - 2);
}

int binomial(int n, int k, ll* fact) {
    if(n < k) return 0;
    return fact[n] * inverse(fact[k] * fact[n - k] % MOD1) % MOD1;
}

int main(){
    FELLE
    // first method for each binomial O(log(MOD)) with O(MAX_N) precomputation
    ll fact[MAX_N + 1];
    fact[0] = 1;
    for(int i = 1; i <= MAX_N; i++) fact[i] = fact[i - 1] * i % MOD1;

    for(int k = 0; k <= MAX_N; k++) {
        cout << binomial(MAX_N, k, fact) << " ";
        if(k % 10 == 9) cout << "\n";
    }

    // second method precomputation of all the inverses in O(n + LOG(MOD))
    fact[0] = 1;
    for(int i = 1; i <= MAX_N; i++) fact[i] = fact[i - 1] * i % MOD1;
    ll invs[MAX_N + 1];

    ll x = 1;
    for(int i = 0; i <= MAX_N; i++) {
        invs[i] = x;
        x = x * fact[i] % MOD1;
    }

    x = inverse(x);

    for(int i = MAX_N; i >= 0; i--) {
        invs[i] = invs[i] * x % MOD1;
        x = x * fact[i] % MOD1;
    }

    cout << "\n\n";
    for(int k = 0; k <= MAX_N; k++) {
        cout << (fact[MAX_N] * (invs[k] * invs[MAX_N - k] % MOD1) % MOD1) << " ";
        if(k % 10 == 9) cout << "\n";
    }
}