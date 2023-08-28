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

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Project {
    ll start, end, reward;
};

bool cmp(Project p1, Project p2) {
    return p1.end < p2.end;
}

void solve(){
    int n; cin >> n;
    vector<Project> projects(n);
    rep(i, n) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(all(projects), cmp);
    map<ll, ll> dp;
    dp[0] = 0;
    ll best = 0;

    for(Project project : projects) {
        ll bestTaking = project.reward;
        auto it = dp.lower_bound(project.start);
        --it;
        bestTaking += it->second;
        best = max(best, bestTaking);
        dp[project.end] = best;
    }

    cout << dp[projects[n - 1].end] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}