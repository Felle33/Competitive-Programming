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

struct DSU
{
    vector<int> p;
    vector<unsigned int> r;
    vector<pii> max_min;
    vector<int> size_set;

    DSU(int N) {
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);
        max_min = vector<pii>(N);
        size_set = vector<int>(N, 1);

        for(int i = 0; i < N; i++){
            p[i] = i;
            max_min[i].first = i;
            max_min[i].second = i;
        }
    }

    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) 
            r[x]++;
        
        if(r[x] > r[y]){
            p[y] = x;
            size_set[x] += size_set[y];
            max_min[x].first = max(max_min[x].first, max_min[y].first);
            max_min[x].second = min(max_min[x].second, max_min[y].second);
        }    
        else {
            p[x] = y;
            size_set[y] += size_set[x];
            max_min[y].first = max(max_min[x].first, max_min[y].first);
            max_min[y].second = min(max_min[x].second, max_min[y].second);
        }
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
    int n, m;
    cin >> n >> m;

    DSU dsu = DSU(n);

    while(m--){
        string s;
        cin >> s;

        if(s == "union"){
            int a, b;
            cin >> a >> b;
            a--, b--;
            dsu.unite(a, b);
        } else {
            int a;
            cin >> a;
            a--;
            int root = dsu.get(a);
            cout << dsu.max_min[root].second + 1 << " " << dsu.max_min[root].first + 1 << " " << dsu.size_set[root] << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}