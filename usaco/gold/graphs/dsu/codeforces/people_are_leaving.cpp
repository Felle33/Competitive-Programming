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
typedef pair<int, int> pii;

struct DSU
{
    vector<int> p;
    vector<unsigned int> r;

    DSU(int N) {
        p = vector<int>(N + 1);

        for(int i = 0; i < N + 1; i++){
            p[i] = i;
        }
    }

    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        p[x] = y;
        return true;
    }
};

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, q;
    cin >> n >> q;
    DSU dsu = DSU(n);

    while(q--) {
        char c;
        int x;
        cin >> c >> x;
        x--;

        if(c == '?') {
            int p = dsu.get(x);
            if(p == n) {
                cout << -1 << '\n';
            } else {
                cout << p + 1 << '\n';
            }
        } else {
            dsu.unite(x, x + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}