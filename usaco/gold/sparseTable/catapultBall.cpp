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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

struct SparseTable {
    static const int K = 25;
    vector<ll> table[K];
    int n;

    SparseTable(vll& a) {
        n = a.size();
        for(int i = 0; i < K; i++) table[i].resize(n);
        for(int i = 0; i < n; i++) {
            table[0][i] = a[i];
        }

        for(int i = 1; i < K; i++) {
            for(int j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    // maximum from l to r inclusive [l, r]
    ll maximum(int l, int r) {
        int ln2 = log2_floor(r - l + 1);
        return max(table[ln2][l], table[ln2][r - (1 << ln2) + 1]);
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vll a(n);
    rep(i, n) cin >> a[i];

    SparseTable st = SparseTable(a);
    ll ans = 0;
    rep(i, m) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        if(abs(e - s) <= 1) {
            ans++;
            continue;
        }

        if(s < e) {
            ll res = st.maximum(s + 1, e - 1);
            if(res <= a[s]) {
                ans++;
            }
        } else {
            ll res = st.maximum(e + 1, s - 1);
            if(res <= a[s]) {
                ans++;
            }
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