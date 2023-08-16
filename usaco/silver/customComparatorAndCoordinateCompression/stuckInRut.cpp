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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<int[3]> east;
vector<int[3]> north;

int dfs(int node, int parent) {
    int ans = 1;

    for(int next : adj[node]) {
        if(next != parent) {
            ans += dfs(next, node);
        }
    }

    ansV[node] = ans;

    return ans;
}

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> pos(n);
    rep(i, n) {
        char d;
        cin >> d;
        pii p;
        cin >> p.first >> p.second;

        int varr[3] = {p.first, p.second, i};
        if(d == 'E') {
            east.push_back(varr);
        } else {
            north.push_back(varr);
        }
        pos[i] = p;
    }

    vector<vector<int>> meetTime;

    for(auto nC : north) {
        for (auto eC : east) {
            int yT = eC[1] - nC[1];
            int xT = eC[0] - nC[0];

            if(xT == yT) continue;
            
        }
    }
}

int main(){
    freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
    solve();
} 