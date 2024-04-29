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
const int INF = 1e9;
const ll LLINF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

int maximumRectangle(vvi& a, int rows, int cols) {
    vi kadane(rows);
    int maximumRectangle = -128;

    for(int l = 0; l < rows; l++) {
        fill(all(kadane), 0);
        for(int r = l; r < cols; r++) {
            for(int i = 0; i < rows; i++) {
                kadane[i] += a[i][r];
            }

            int curSum = 0, ans = *max_element(all(kadane));
            for(int i = 0; i < rows; i++) {
                curSum += kadane[i];
                if(curSum < 0) curSum = 0;
                else ans = max(ans, curSum);
            }

            maximumRectangle = max(maximumRectangle, ans);
        }
    }

    return maximumRectangle;
}


// This was done using kadane O(n^3)
// maybe I should try to use pref sum O(n^4)
// This algo fails because I don't check the boundary of the wrap (it should be at maximum n)
void solve(){
    int n; cin >> n;
    vvi a(n, vi(n));

    rep(i, n) 
        rep(j, n) cin >> a[i][j];
    
    vvi grid(n, vi(2 * n));

    for(int i = 0; i < n; i++) {
        bool dop = false;
        for(int j = 0; j < n; j++) {
            int col = (dop ? j + n : j);
            grid[i][col] = a[i][j];
            if(j == n - 1 && !dop) {
                j = -1;
                dop = 1;
            }
        }
    }

    vvi grid2(2 * n, vi(n));

    bool dop = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int row = (dop ? n + i : i);
            grid2[row][j] = a[i][j];
        }

        if(i == n - 1 && !dop) {
            i = -1;
            dop = 1;
        }
    }
    
    int ans = maximumRectangle(grid, n, 2 * n);
    ans = max(ans, maximumRectangle(grid2, 2 * n, n));

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("catch.in", "r", stdin);
	freopen("catch.out", "w", stdout);
    int t; cin >> t;
    while(t--) solve();
}