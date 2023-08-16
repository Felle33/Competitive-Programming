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
#define f first
#define s second
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

vector<vector<pii>> adj;
vector<int> colors;

void colorVector(int node, int parent, int color) {
    colors[node] = color;

    for(pii son : adj[node]) {
        if(son.f == parent) continue;
        if(son.s % 2 == 0) {
            colorVector(son.f, node, color);
        } else {
            colorVector(son.f, node, !color);
        }
    }
}

// white = 0 => even
// black = 1 => odd
void solve(){
    int n;
    cin >> n;
    adj.resize(n);
    colors.resize(n);
    rep(i, n - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        a--,b--;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    colorVector(0, -1, 0);

    for(int x : colors) {
        cout << x << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}