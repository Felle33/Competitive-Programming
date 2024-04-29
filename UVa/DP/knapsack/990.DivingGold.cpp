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
    bool first = true;
    int t, w;
    while(cin >> t >> w) {
        int n; cin >> n;

        vector<pii> a(n);
        rep(i, n) cin >> a[i].first >> a[i].second;

        // How much gold i take if i have processed i treasures with t oxigen left
        vvi maxGold(n + 1, vi(t + 1, -INF));
        vvi parent(n + 1, vi(t + 1, -1));

        maxGold[0][t] = 0;

        for(int i = 0; i < n; i++) {
            for(int ox = 0; ox <= t; ox++) {
                if(maxGold[i + 1][ox] < maxGold[i][ox]) {
                    maxGold[i + 1][ox] = maxGold[i][ox];
                    parent[i + 1][ox] = ox;
                }
                
                int oxLeft = ox - 3 * w * a[i].first;

                if(oxLeft >= 0) {
                    if(maxGold[i + 1][oxLeft] < maxGold[i][ox] + a[i].second) {
                        maxGold[i + 1][oxLeft] = maxGold[i][ox] + a[i].second;
                        parent[i + 1][oxLeft] = ox;
                    }
                }
            }
        }

        int ans = 0; int timeRem = -1;
        for(int i = 0; i <= t; i++) {
            if(ans < maxGold[n][i]) {
                ans = maxGold[n][i];
                timeRem = i;
            }
        }

        if(!first) cout << '\n';
        first = 0;

        cout << ans << '\n';
        vi treasure;
        int idx = n;

        while(parent[idx][timeRem] != -1) {
            if(parent[idx][timeRem] != timeRem) {
                treasure.push_back(idx - 1);
            }

            timeRem = parent[idx][timeRem];
            idx--;
        }

        cout << treasure.size() << '\n';
        sort(all(treasure));
        for(int x : treasure) {
            cout << a[x].first << " " << a[x].second << '\n';
        }
    }
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