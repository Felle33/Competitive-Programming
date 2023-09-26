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

vvi adj;
vvi dp;
vi arcIn;
int n, m;
vector<char> chars;

// return true if there is a cycle
bool topSort() {
    int cnt = 0;
    queue<int> q;
    rep(i, n) {
        if(arcIn[i] == 0) {
            q.push(i);
            cnt++;
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        dp[node][chars[node] - 'a']++;

        for(int to : adj[node]) {
            arcIn[to]--;

            for(int i = 0; i < 26; i++) {
                dp[to][i] = max(dp[node][i], dp[to][i]);
            }

            if(arcIn[to] == 0) {
                q.push(to);
                cnt++;
            }
        }
    }

    return cnt != n;
}

void solve(){
    cin >> n >> m;
    adj = vvi(n);
    // dp[i][j] = max of chars 'j' from a generic start to i
    dp = vvi(n, vi(26));
    arcIn = vi(n);

    string s; cin >> s;
    chars = vector<char>(n);
    rep(i, n) chars[i] = s[i];

    rep(i, m) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        arcIn[b]++;
    }

    if(topSort()) {
        cout << -1 << '\n';
    } else {
        int ans = 0;
        rep(i, n) {
            ans = max(ans, *max_element(all(dp[i])));
        }
        cout << ans << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}