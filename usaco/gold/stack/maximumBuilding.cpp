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
#include <stack>

#define all(x) (x).begin(), (x).end()
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, m;
    cin >> n >> m;

    vector<ll> a(m);
    vector<vector<char>> grid(n, vector<char>(m));
    rep(i, n) {
        rep(j, m) cin >> grid[i][j];
    }

    stack<pair<ll, ll>> s;
    vector<ll> frontSmall(m), behindSmall(m);
    ll ans = 0;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*') a[j] = 0;
            else a[j]++;
        }

        for(int j = 0; j < m; j++){
            while(!s.empty() && s.top().first > a[j]) {
                pair<ll, ll> top = s.top();
                s.pop();
                frontSmall[top.second] = j;
            }

            s.push({a[j], j});
        }

        while(!s.empty()) {
            pair<ll, ll> top = s.top();
            s.pop();
            frontSmall[top.second] = m;
        }

        for(int j = m - 1; j >= 0; j--){
            while(!s.empty() && s.top().first > a[j]) {
                pair<ll, ll> top = s.top();
                s.pop();
                behindSmall[top.second] = j;
            }

            s.push({a[j], j});
        }

        while(!s.empty()) {
            pair<ll, ll> top = s.top();
            s.pop();
            behindSmall[top.second] = -1;
        }

        for(int j = 0; j < m; j++) {
            ans = max(ans, a[j] * (frontSmall[j] - behindSmall[j] - 1));
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}