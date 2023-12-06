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

bool cmp(pii& a, pii& b) {
    return a.second < b.second;
}

void solve(){
    int m; cin >> m;
    // first is row and second is column
    vector<pii> booths(m);
    pii sam;

    rep(i, m) {
        cin >> booths[i].second;
    }

    cin >> sam.first >> sam.second;

    int n; cin >> n;
    vector<pii> contestants(n);

    rep(i, n) {
        cin >> contestants[i].first >> contestants[i].second;
    }

    sort(all(booths), cmp);
    sort(all(contestants), cmp);

    vector<vector<ll>> time(m);
    // compute the time for every booths
    for(int i = 0, j = 0; i < n; i++) {
        ll dis1 = abs(booths[j].first - contestants[i].first) + abs(booths[j].second - contestants[i].second);
        ll dis2 = j + 1 < m ? abs(booths[j + 1].first - contestants[i].first) + abs(booths[j + 1].second - contestants[i].second) : INF;

        if(dis1 <= dis2) {
            time[j].push_back(dis1);
        } else {
            time[j + 1].push_back(dis2);
            j++;
        }
    }

    for(int i = 0; i < m; i++) sort(all(time[i]));

    ll ans = INF;
    for(int i = 0; i < m; i++) {
        ll t = abs(booths[i].first - sam.first) + abs(booths[i].second - sam.second);
        auto it = upper_bound(all(time[i]), t);
        ll d = distance(time[i].begin(), it);
        ans = min(ans, d);
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