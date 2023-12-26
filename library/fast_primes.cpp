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

const int MAX_N = 2e5;
int max_div[MAX_N + 1];

void solve(){
    int n; cin >> n;

    // calculate the maximum divisor of a number
    // REMEMBER: max_div[i] == 0 if only if the number is prime
    // max_div[j] = i, if j has a greater prime divisor it will be overwritten in the future (with another i)
    for (int i = 2; i <= MAX_N; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= MAX_N; j += i) { 
                max_div[j] = i;
            }
        }
    }

    rep(i, n) {
        int x; cin >> x;
        int cp = x;
        vector<pii> prime_factors;

        while(cp != 1) {
            int prime = max_div[cp];
            int d = 0;

            while(cp % prime == 0) {
                d++;
                cp /= prime;
            }

            prime_factors.push_back({prime, d});
        }

        cout << "PRIME FACTOR OF " << x << '\n';
        for(pii prime : prime_factors) {
            cout << prime.first << " " << prime.second << '\n';
        }
        cout << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}