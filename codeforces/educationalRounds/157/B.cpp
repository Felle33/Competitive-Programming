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
    vector<int> a(2 * n);
    rep(i, 2 * n) {
        cin >> a[i];
    }

    sort(all(a));

    ll s = 0;
    vector<pii> points(n);
    for(int i = 0; i < n; i++) {
        points[i].first = a[i];
        points[i].second = a[i + n];
    }

    for(int i = 1; i < n; i++) {
        s += abs(points[i].first - points[i - 1].first) + abs(points[i].second - points[i - 1].second);
    }

    cout << s << '\n';
    for(pii point : points) {
        cout << point.first << " " << point.second << '\n';
    }
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