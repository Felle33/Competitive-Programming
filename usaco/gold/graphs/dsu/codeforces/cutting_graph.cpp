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
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) 
            r[x]++;
        
        if(r[x] > r[y])
            p[y] = x;
        else 
            p[x] = y;
        return true;
    }
};

struct Action{
    string action;
    int a, b;
};

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    DSU dsu = DSU(n);
    set<pii> edges;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges.insert({a, b});
    }

    vector<Action> actions(q);
    for(int i = 0; i < q; i++){
        string s;
        int a, b;
        cin >> s >> a >> b;

        a--, b--;
        actions[i] = {s, a, b};
        if(s == "cut") {
            if(edges.erase(make_pair(a, b)) == 0) {
                edges.erase(make_pair(b, a));
            }
        }
    }

    for(auto it = edges.begin(); it != edges.end(); it++) {
        dsu.unite(it->first, it->second);
    }

    vector<string> ans;
    for(int i = q - 1; i >= 0; i--) {
        if (actions[i].action == "cut") {
            dsu.unite(actions[i].a, actions[i].b);
        } else {
            if(dsu.get(actions[i].a) == dsu.get(actions[i].b)) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        }
    }

    for(int i = (int) ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}