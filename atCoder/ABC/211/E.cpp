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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, k;
vector<string> grid;
ull red = 0;
set<ull> grid_processed;
ull answer = 0;

void change(pii p) {
    int num = p.f * n + p.s;
    if(grid[p.f][p.s] == '.') {
        red += ull(1) << num;
        grid[p.f][p.s] = '@';
    } else {
        red -= ull(1) << num;
        grid[p.f][p.s] = '.';
    }
}

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

void dfs(int num) {
    if(grid_processed.find(red) != grid_processed.end()) {
        return;
    }
    grid_processed.insert(red);

    if(num == 0) {
        answer++;
        return;
    }

    vector<pii> next;
    rep(i, n) {
        rep(j, n) {
            if(grid[i][j] == '.') {
                bool flag = false;

                rep(z, 4) {
                    int newi = i + DX[z];
                    int newj = j + DY[z];

                    if(valid(newi, newj) && grid[newi][newj] == '@') {
                        flag = true;
                    }
                }
                if(flag) {
                    next.push_back(mp(i, j));
                }
            }
        }
    }

    for(pii pos : next) {
        change(pos);
        dfs(num - 1);
        change(pos);
    }

}

void solve(){
    cin >> n >> k;
    grid = vector<string>(n);
    rep(i, n) {
        cin >> grid[i];
    }

    rep(i, n) {
        rep(j, n) {
            if(grid[i][j] == '.') {
                change(mp(i, j));
                dfs(k - 1);
                change(mp(i, j));
            }
        }
    }

    cout << answer << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}