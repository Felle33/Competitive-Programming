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
const ll DIM = 1e5;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

vi divisors[DIM + 1];
bool prime[DIM + 1];

void sieve() {
    for(int i = 2; i <= DIM; i++) {
        for(int j = 2 * i; j <= DIM; j += i) {
            prime[j] = 0;
            divisors[j].push_back(i);
        }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i <= DIM; i++) prime[i] = 1;
    sieve();
    if(prime[n]) {
        cout << n << "\n";
        return;
    }

    string ans;

    for(int x : divisors[n]) {
        while(n % x == 0) {
            n /= x;

            ans += to_string(x) + "x";
        }
    }

    ans.pop_back();
    cout << ans << "\n";
}

int main(){
    FELLE
    solve();
}