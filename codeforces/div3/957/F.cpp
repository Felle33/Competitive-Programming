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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

void solve(){
    int n, x; cin >> n >> x;

    vi a(n);
    rep(i, n) cin >> a[i];

    set<int> s{x};
    int ans = 1;

    for(int i = 0; i < n; i++) {
        for(int y : s) {
            if(y % a[i]) continue;
            if(y == a[i]) {
                ans++;
                s = {x, x / a[i]};
                break;
            }
            s.insert(y / a[i]);
        }
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}