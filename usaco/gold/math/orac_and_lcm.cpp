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

const int MAX_N = 1e5;
int max_div[2 * MAX_N + 1];

ll exponentiation(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e & 1) {
            res = res * b;
        }  
        
        b = b * b;
        e >>= 1;
    }

    return res;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    for (int i = 2; i <= 2 * MAX_N; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= 2 * MAX_N; j += i) { 
                max_div[j] = i;
            }
        }
    }

    vector<map<int, int>> all_prime_factors;

    for(int x : a) {
        int cp = x;
        map<int, int> prime_factors;

        while(cp != 1) {
            int prime = max_div[cp];
            int d = 0;

            while(cp % prime == 0) {
                d++;
                cp /= prime;
            }

            prime_factors[prime] = d;
        }

        all_prime_factors.push_back(prime_factors);
    }
    
    int ans = 1;
    set<int> already_seen;
    
    for(int i = 0; i < 2; i++) {
        map<int, int>& prime_factor_i = all_prime_factors[i];
        for(pii p : prime_factor_i) {
            if(already_seen.count(p.first)) continue;

            int not_found = 0;
            int first_min = p.second, second_min = INF_INT;

            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                map<int, int>& prime_factor_j = all_prime_factors[j];
                if(prime_factor_j.count(p.first)) {
                    int d = prime_factor_j[p.first];
                    if(d < first_min) {
                        second_min = first_min;
                        first_min = d;
                    } else if(d < second_min){
                        second_min = d;
                    }
                } else {
                    not_found++;
                }
            }

            if(not_found <= 1) {
                ans *= exponentiation(p.first, second_min);
            }
            already_seen.insert(p.first);
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}