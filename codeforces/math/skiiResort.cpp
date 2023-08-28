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

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    vi deg(n);
    rep(i, n) cin >> deg[i];

    ll ans = 0;
    int l = 0, r = 0;
    for(; r < n; ) {
        while(r < n && deg[r] <= q) {
            r++;
        }

        ll el = r - l;
        if(el >= k) {
            el = el - k + 1;
            ans += (el) * (el + 1) / 2;
        }
        l = r + 1;
        r++;
    }

    if(l != r) {
        ll el = r - l;
        if(el >= k) {
            el = el - k + 1;
            ans += (el) * (el + 1) / 2;
        } 
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}