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

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

bool win(char c, vector<vector<char>>& grid) {
    bool has_win = true;
    for(int i = 0; i < 3; i++) {
        has_win = true;
        for(int j = 0; j < 3; j++) {
            if(grid[i][j] != c) has_win = false;
        }
        if(has_win) return true;
    }

    for(int i = 0; i < 3; i++) {
        has_win = true;
        for(int j = 0; j < 3; j++) {
            if(grid[j][i] != c) has_win = false;
        }
        if(has_win) return true;
    }

    return (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) ||
    (grid[2][0] == c && grid[1][1] == c && grid[0][2] == c);
}

void solve(){
    vector<vector<char>> grid(3, vector<char>(3));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    set<char> s = {'X', 'O', '+'};
    bool winner = false;
    for(char c : s) {
        if(win(c, grid)) {
            cout << c << '\n';
            winner = true;
            break;
        }
    }

    if(!winner) cout << "DRAW" << '\n';
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