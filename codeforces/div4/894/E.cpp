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

vll heights;
ll n, x;

bool good(ll t) {
    ll sum = 0;
    rep(i, n) {
        if(t >= heights[i]) {
            sum += (t - heights[i]);
        }
    }

    return sum <= x;
}

void solve(){
    cin >> n >> x;
    heights = vll(n);
    rep(i, n) cin >> heights[i];

    ll l = 1, r = 5e9;

    while(l + 1 < r) {
        ll m = l + (r - l) / 2;
        if(good(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << '\n';
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