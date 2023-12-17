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
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n; cin >> n;
    vector<pii> points(n);

    set<int> set_hor;
    set<int> set_ver;

    ll ans = 0;
    // add a map with key the slope
    map<pii, set<int>> slope_int;

    rep(i, n) {
        cin >> points[i].first >> points[i].second;
        for(int j = 0; j < i; j++) {
            if(points[j].first == points[i].first) {
                // it is a vertical point
                if(set_ver.count(points[i].first) == 0) {
                    set_ver.insert(points[i].first);
                }
                
            } else if(points[j].second == points[i].second) {
                if(set_hor.count(points[i].second) == 0) {
                    set_hor.insert(points[i].second);
                }
                
            } else {
                // calc the slope and the y in (0, 0)
                // I count the intersection of 2 different lines with the same slope
                int a = points[i].second - points[j].second;
                int b = -(points[i].first - points[j].first);
                int c = -points[i].second * points[j].first - points[j].second * points[i].first;

                int gcd = __gcd(abs(a), __gcd(abs(b), abs(c)));
                a /= gcd;
                b /= gcd;
                c /= gcd;

                if(a < 0 || (a == 0 && b < 0)) {
                    a = -a;
                    b = -b;
                    c = -c;
                }

                if(slope_int[{a, b}].count(c) == 0) {
                    slope_int[{a, b}].insert(c);
                }
            }
        }
    }

    ll ver = set_ver.size();
    ll hor = set_hor.size();
    ll diag = 0;
    for(auto it = slope_int.begin(); it != slope_int.end(); it++) {
        diag += it->second.size();
    }

    ans += hor * ver + hor * diag + ver * diag;

    for(auto it = slope_int.begin(); it != slope_int.end(); it++) {
        diag -= it->second.size();
        ans += 1LL * diag * it->second.size();
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}