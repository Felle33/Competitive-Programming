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
const ll INF = 1e9 + 2;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vi notBefore;
vector<vector<pii>> adj;
vi arcIn;
vi ans;
int n;

void topSort() {
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(arcIn[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(pii arc : adj[node]) {
            int to = arc.first;
            int weight = arc.second;
            arcIn[to]--;
            ans[to] = max(ans[to], weight + ans[node]);

            if(arcIn[to] == 0) {
                q.push(to);
            }
        }
    }
}

void solve(){
    int m, c; cin >> n >> m >> c;
    notBefore = vi(n);
    arcIn = vi(n);
    adj = vector<vector<pii>>(n);
    ans = vi(n);

    rep(i, n) {
        cin >> notBefore[i];
        ans[i] = notBefore[i];
    }

    rep(i, c) {
        int a, b, x; cin >> a >> b >> x;
        a--, b--;
        adj[a].push_back(mp(b, x));
        arcIn[b]++;
    }

    topSort();

    for(int x : ans) {
        cout << x << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);

    solve();
}