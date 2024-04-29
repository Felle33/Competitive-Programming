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

void solve(){
    int n; cin >> n;
    vvi a(n, vi(n));

    rep(i, n) 
        rep(j, n) cin >> a[i][j];
    
    vi kadane(n);
    int maximumRectangle = -128;

    for(int l = 0; l < n; l++) {
        fill(all(kadane), 0);
        for(int r = l; r < n; r++) {
            for(int i = 0; i < n; i++) {
                kadane[i] += a[i][r];
            }

            int curSum = 0, ans = *max_element(all(kadane));
            for(int i = 0; i < n; i++) {
                curSum += kadane[i];
                if(curSum < 0) curSum = 0;
                else ans = max(ans, curSum);
            }

            maximumRectangle = max(maximumRectangle, ans);
        }
    }

    cout << maximumRectangle << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    solve();
}