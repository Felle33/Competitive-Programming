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
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

void solve(){
    int n, q; cin >> n >> q;
    vi a(n), b(n + 1);
    map<int, vector<int>> mp;
    rep(i, n) {
        cin >> a[i];
        b[i + 1] = b[i] ^ a[i];
        mp[b[i + 1]].push_back(i);
    }

    rep(i, q) {
        int l, r; cin >> l >> q;
        // to have r included b[r + 1] for left
        // to have r excluded b[r] for left
        l--, r--;
        if(b[r + 1] == b[l]) {
            cout << "YES\n";
        } else {
            auto it1 = 
        }
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}