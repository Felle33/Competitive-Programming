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

// points has two different meanings: for the root it has the value of the experience of all the group and itself
// for the others it represents the difference of points between itself and the ancestor until the ancestor is the 
// root of the set
struct DSU {
    vector<int> p;
    vector<unsigned int> r;
    vector<int> points;

    DSU(int N) {
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);
        points = vector<int>(N);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) {
        if(p[x] == x) return x;
        return get(p[x]);
    }

    int get_points(int x) {
        if(p[x] == x) return points[x];
        return get_points(p[x]) + points[x];
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) 
            r[x]++;
        
        if(r[x] > r[y]){
            p[y] = x;
            points[y] = points[y] - points[x];
        }    
        else {
            p[x] = y;
            points[x] = points[x] - points[y];
        }
        return true;
    }

    void add(int a, int exp) {
        a = get(a);
        points[a] += exp;
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

        if(s == "join"){
            int a, b;
            cin >> a >> b;
            a--, b--;
            dsu.unite(a, b);
        } else if(s == "add") {
            int a, x;
            cin >> a >> x;
            a--;
            dsu.add(a, x);
        } else {
            int a;
            cin >> a;
            a--;

            cout << dsu.get_points(a) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}