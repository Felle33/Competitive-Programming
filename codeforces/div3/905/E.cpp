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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n; cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    if(n == 1) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;
    ll last = 0;
    for(int i = 1; i < n; i++) {
        ll prev = a[i - 1];
        ll cur = a[i];
        ll op = 0;

        if(cur <= prev) {
            while(cur < prev) {
                op++;
                cur *= 2;
            }
            ans += last + op;
            last = op + last;
        } else {
            while(prev < cur) {
                op++;
                prev *= 2;
            }

            ans += max(last - op + (prev != cur), 0ll);
            last = max(last - op + (prev != cur), 0ll);
        }
        
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}