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
vector<int> DI = {0, 1, -1, 0};
vector<int> DJ = {1, 0, 0, -1};

ll dis(pair<ll, ll>& p1, pair<ll, ll>& p2) {
    ll difX = p1.first - p2.first;
    ll difY = p1.second - p2.second;
    return difX * difX + difY * difY;
}

void solve(){
    int n; cin >> n;
    vector<pair<ll, ll>> circles(n);
    rep(i, n) cin >> circles[i].first >> circles[i].second;
    pair<ll, ll> pl, dest;
    cin >> pl.first >> pl.second >> dest.first >> dest.second;

    ll minDis = dis(circles[0], dest);

    for(pair<ll, ll>& point : circles) {
        minDis = min(minDis, dis(point, dest));
    }

    if(dis(pl, dest) < minDis) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}