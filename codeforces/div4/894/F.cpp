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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, k; cin >> n >> k;
    vll a(n), h(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> h[i];

    int l = 0, r = 1;
    int curk = a[0];
    int ans = 1;

    if(*min_element(all(a)) > k) {
        cout << 0 << '\n';
        return;
    }

    for(; r < n; ) {
        while(r < n && (h[r - 1] % h[r]) == 0 && curk + a[r] <= k) {
            curk += a[r];
            r++;
        }

        if(r == n) {
            ans = max(ans, r - l);
            break;
        } else if((h[r - 1] % h[r]) != 0) {
            ans = max(ans, r - l);
            while(l < r) l++;
            if(l != n) curk = a[l];
            r = l + 1;
        } else if(curk + a[r] > k) {
            ans = max(ans, r - l);
            while(curk + a[r] > k) {
                curk -= a[l];
                l++;
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

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}