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
    ll n, k; cin >> n >> k;
    ll mx_sum = 0;
    for(int i = 0, l = 1, r = n; i < n; i++, l++, r--) {
        mx_sum += abs(r - l);
    }

    if(k > mx_sum || k % 2 == 1) {
        cout << "No\n";
        return;
    }

    k /= 2;
    vi ans(n);
    for(int i = 0; i < n; i++) ans[i] = i + 1;

    for(int jump = n - 1, r = 1; jump >= 1 && k > 0; jump -= 2, r++) {
        if(jump <= k) {
            k -= jump;

            ans[r - 1] = n - r + 1;
            ans[n - r] = r;
        } else {
            ans[r - 1] = ans[r + k - 1];
            ans[r + k - 1] = r;

            k = 0;
        }
    }

    cout << "Yes\n";
    for(int x : ans) cout << x << " ";
    cout << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}