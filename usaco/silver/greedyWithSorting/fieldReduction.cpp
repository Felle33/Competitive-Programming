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

struct Point {
    int i, x, y;
};

bool cmpHor(Point p1, Point p2) {
    return p1.x > p2.x;
}

bool cmpVer(Point p1, Point p2) {
    return p1.y > p2.y;
}

void solve(){
    int n; cin >> n;
    vector<Point> a(n);
    rep(i, n) {
        int x, y; cin >> x >> y;
        a[i].i = i;
        a[i].x = x;
        a[i].y = y;
    }

    vector<Point> hor = a;
    vector<Point> ver = a;

    // the firsts are the highest values
    sort(all(hor), cmpHor);
    sort(all(ver), cmpVer);

    set<int> indexCowsDeleted;
    ll ans = INF;
    for(int i = 0; i < 4; i++) {
        int cowsToDeleteUp = 3 - i;
        int cowsToDeleteRight = i;
        ll startFenceLeft = hor[n - 1].x;
        ll startFenceDown = ver[n - 1].y;

        int j = 0;
        for(int added = 0; added < cowsToDeleteUp; j++) {
            if(indexCowsDeleted.count(ver[j].i) == 0) {
                indexCowsDeleted.insert(ver[j].i);
                added++;
            }
        }

        ll endFenceUp = ver[j].y;

        int k = 0;
        for(int added = 0; added < cowsToDeleteRight; k++) {
            if(indexCowsDeleted.count(hor[k].i) == 0) {
                indexCowsDeleted.insert(hor[k].i);
                added++;
            }
        }

        ll endFenceRight = hor[k].x;
        ans = min(ans, (endFenceRight - startFenceLeft) * (endFenceUp - startFenceDown));
        indexCowsDeleted.clear();
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("lemonade.in", "r", stdin);
	//freopen("lemonade.out", "w", stdout);

    solve();
}