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

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));
    vi cnt(2 * k + 1);

    for(int x : a) {
        x = x % (2 * k);
        cnt[x]++;
        if(x + k < 2 * k) {
            cnt[x + k]--;
        } else {
            cnt[2 * k]--;
            cnt[0]++;
            int val = (x + k) % (2 * k);
            cnt[val]--;
        }
    }

    int cur = 0;
    for(int i = 0; i < 2 * k; i++) {
        cur += cnt[i];
        cnt[i] = cur;
    }

    int res = -1;
    for(int i = a[n - 1]; i < a[n - 1] + 2 * k; i++) {
        if(cnt[i % (2 * k)] == n) {
            res = i;
            break;
        }
    }

    cout << res << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}