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
    set<pair<double, double>> set_diag;
    set<int> set_hor;
    set<int> set_ver;

    ll ans = 0;
    ll ver = 0, hor = 0, diag = 0;
    rep(i, n) {
        cin >> points[i].first >> points[i].second;
        for(int j = 0; j < i; j++) {
            if(points[j].first == points[i].first) {
                // it is a vertical point
                if(set_ver.count(points[i].first) == 0) {
                    ver++;
                    set_ver.insert(points[i].first);
                    ans += diag + hor;
                }
                
            } else if(points[j].second == points[i].second) {
                if(set_hor.count(points[i].second) == 0) {
                    hor++;
                    set_hor.insert(points[i].second);
                    ans += diag + ver;
                }
                
            } else {
                // calc the slope and the y in (0, 0)
                double m =  ((double) points[j].second - points[i].second) / ((double) points[j].first - points[i].first);
                double y0 = -m * points[i].first + points[i].second;
                if(set_diag.count({m, y0}) == 0) {
                    ans += diag + ver + hor;
                    set_diag.insert({m, y0});
                    diag++;
                }
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

    solve();
}