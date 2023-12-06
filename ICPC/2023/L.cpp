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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

bool cmp(pii& a, pii& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void solve(){
    int n; cin >> n;
    vector<pii> log(n);

    rep(i, n) {
        int a, b;
        cin >> log[i].second >> log[i].first;
    }

    sort(all(log), cmp);

    ll ans = 0;
    ll cur = 0;

    for(pii& p : log) {
        if(p.second == -1) {
            cur--;
        } else {
            cur++;
        }
        ans = max(ans, cur);
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