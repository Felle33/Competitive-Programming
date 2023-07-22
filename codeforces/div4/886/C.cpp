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

void solve(){
    vector<vector<char>> grid(8, vector<char>(8));
    rep(i, 8) {
        rep(j, 8) {
            cin >> grid[i][j];
        }
    }

    string s;
    rep(i, 8) {
        rep(j, 8) {
            if(grid[i][j] != '.') {
                int u = 0;
                while((u + j) < 8 && grid[i][j + u] != '.') {
                    s.push_back(grid[i][j + u]);
                    u++;
                }
            }
        }
    }

    cout << s << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}