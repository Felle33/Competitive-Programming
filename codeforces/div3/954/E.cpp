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

int n, k;

bool cmp(int i, int j) {
    if((i % k) == (j % k)) return i < j;
    return (i % k) < (j % k);
}

void solve(){
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    sort(all(a), cmp);
    int ans = 0;
    bool foundOdd = 0;

    for(int l = 0, r = 0; r < n; ) {
        while(r <  n && a[l] % k == a[r] % k) r++;
        int cnt = r - l;

        if(cnt % 2 == 0) {
            for(int i = l; i < r; i += 2) {
                ans += (a[i + 1] - a[i]) / k;
            }
        } else {
            if(n % 2 == 0) {
                ans = -1;
                break;
            }

            if(foundOdd) {
                ans = -1;
                break;
            }

            foundOdd = 1;
            int pref = 0, suf = 0;
            int mn = INF;
            for(int i = r - 1; i > l; i -= 2) {
                suf += a[i] - a[i - 1];
            }

            for(int i = l; i < r; i += 2) {
                mn = min(mn, suf + pref);
                if(i + 1 < r) pref += a[i + 1] - a[i];
                if(i + 2 < r) suf -= (a[i + 2] - a[i + 1]);
            }

            ans += mn / k;
        }
        l = r;
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