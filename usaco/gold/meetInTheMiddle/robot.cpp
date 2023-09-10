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
#include <bit>

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

struct coord {
    int x, y;

    bool operator<(const coord& c2) const {
        if(x == c2.x) return y < c2.y;
        return x < c2.x;
    }
};

int n;
int fX, fY;
vector<coord> moves;
vector<map<int, vector<int>>> first, last;
vector<int> ans;

// from l to r inclusive [l, r]
vector<map<int, vector<int>>> allMoves(int l, int r) {
    int len = r - l + 1;
    vector<map<int, vector<int>>> resMoves(len + 1);

    for(int i = 1; i < (1 << len); i++) {
        coord in = {0, 0};
        for(int b = 0; b < len; b++) {
            if(i & (1 << b)) {
                in.x += moves[l + b].x;
                in.y += moves[l + b].y;
            }
        }
        int ones = __popcount(i);
        if(in.x == fX && in.y == fY) ans[ones]++;
        resMoves[ones][in.x].push_back(in.y);
    }

    return resMoves;
}

void solve(){
    cin >> n >> fX >> fY;
    moves = vector<coord>(n);
    rep(i, n) cin >> moves[i].x >> moves[i].y;
    ans = vector<int> (n + 1);
    coord allMovesTog = {0, 0};
    // only 1 move
    for(const coord& c : moves) {
        if(c.x == fX && c.y == fY) ans[1]++;
        allMovesTog.x += c.x, allMovesTog.y += c.y;
    }

    // all the moves
    if(allMovesTog.x == fX && allMovesTog.y == fY) ans[n]++;

    first = allMoves(0, n / 2 - 1);
    last = allMoves(n / 2, n - 1);

    for(int i = 1; i <= (n / 2 - 1); i++) {
        for(const auto& mapOfIMoves : first[i]) {
            int targetX = fX - mapOfIMoves.first;
            const vector<int> vMap = move(mapOfIMoves.second);
            for(int y : vMap) {

            }
            int targetY = fX - mapOfIMoves.first;
        }
    }

    for(int x : ans) {
        cout << x << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}