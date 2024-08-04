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
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

int mp[2 * DIM + 1];

void solve(){
    int n, q; cin >> n >> q;

    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<vll> ways(n, vll(n));

    for(int i = 0; i < n - 2; i++) {
        mp[a[i + 1] + DIM]++;
        for(int j = i + 2; j < n; j++) {
            int sum = a[i] + a[j];

            if(-sum + DIM >= 0 && -sum + DIM <= 2 * DIM) ways[i][j] = mp[-sum + DIM];
            mp[a[j] + DIM]++;
        }
        
        for(int j = i + 1; j < n; j++) mp[a[j] + DIM]--;
    }

    for(int k = 3; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            ways[i][j] += ways[i + 1][j] + ways[i][j - 1] - ways[i + 1][j - 1];
        }
    }

    for(int _ = 0; _ < q; _++) {
        int l, r; cin >> l >> r;
        l--, r--;
        cout << ways[l][r] << "\n";
    }
}

int main(){
    FELLE
    freopen("threesum.in", "r", stdin);
	freopen("threesum.out", "w", stdout);
    solve();
}