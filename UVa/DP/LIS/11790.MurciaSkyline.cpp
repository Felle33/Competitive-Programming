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
    vi h(n), w(n);
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> w[i];

    vi lis(n), lds(n);

    rep(i, n) lis[i] = w[i];
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(h[j] < h[i]) {
                lis[i] = max(lis[i], lis[j] + w[i]);
            }
        }
    }

    rep(i, n) lds[i] = w[i];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(h[j] > h[i]) {
                lds[i] = max(lds[i], lds[j] + w[i]);
            }
        }
    }

    int lengthLIS = *max_element(all(lis));
    int lengthLDS = *max_element(all(lds));

    if(lengthLIS >= lengthLDS) {
        cout << "Increasing (" << lengthLIS << "). Decreasing (" << lengthLDS << ").\n" ;
    } else {
        cout << "Decreasing (" << lengthLDS << "). Increasing (" << lengthLIS << ").\n" ;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    int t; cin >> t;
    rep(i, t) {
        cout << "Case " << i + 1 << ". ";
        solve();
    }
}