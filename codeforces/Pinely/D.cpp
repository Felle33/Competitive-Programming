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

// fist one is black and the other is white
vector<pii> rows, columns;
vector<int> charRows, charCol;
vector<vector<char>> finalGrid;
vector<vector<char>> grid;
vector<pii> dominos;
int n, m;

// coordinates of the i-th dominos
bool dfs(int ind) {
    if(ind == dominos.size()) {
        return true;
    }

    int i = dominos[ind].first, j = dominos[ind].second;
    if(grid[i][j] == 'L') {
        bool res = 0;
        rows[i].first++, rows[i].second++;

        if(rows[i].first > (charRows[i] / 2) || rows[i].second > (charRows[i] / 2)) {
            rows[i].first--, rows[i].second--;
            return false;
        }

        if(columns[j].first + 1 <= (charCol[j] / 2) && columns[j + 1].second + 1 <= (charCol[j + 1] / 2)) {
            columns[j].first++;
            columns[j + 1].second++;
            finalGrid[i][j] = 'B';
            finalGrid[i][j + 1] = 'W';
            res = dfs(ind + 1);
            if(!res) {
                columns[j].first--;
                columns[j + 1].second--;
                finalGrid[i][j] = '.';
                finalGrid[i][j + 1] = '.';
            }
        }

        if(res) return true;

        if(columns[j].second + 1 <= (charCol[j] / 2) && columns[j + 1].first + 1 <= (charCol[j + 1] / 2)) {
            columns[j].second++;
            columns[j + 1].first++;
            finalGrid[i][j] = 'W';
            finalGrid[i][j + 1] = 'B';
            res = dfs(ind + 1);
            if(!res) {
                columns[j].second--;
                columns[j + 1].first--;
                finalGrid[i][j] = '.';
                finalGrid[i][j + 1] = '.';
            }
        }

        if(!res) {
            rows[i].first--, rows[i].second--;
        }
        return res;
    }

    bool res = 0;
    columns[j].first++, columns[j].second++;

    if(columns[j].first > (charCol[j] / 2) || columns[j].second > (charCol[j] / 2)) {
        columns[j].first--, columns[j].second--;
        return false;
    }

    if(rows[i].first + 1 <= (charRows[i] / 2) && rows[i + 1].second + 1 <= (charRows[i + 1] / 2)) {
        rows[i].first++;
        rows[i + 1].second++;
        finalGrid[i][j] = 'B';
        finalGrid[i + 1][j] = 'W';
        res = dfs(ind + 1);
        if(!res) {
            rows[i].first--;
            rows[i + 1].second--;
            finalGrid[i][j] = '.';
            finalGrid[i + 1][j] = '.';
        }
    }

    if(res) return true;

    if(rows[i].second + 1 <= (charRows[i] / 2) && rows[i + 1].first + 1 <= (charRows[i + 1] / 2)) {
        rows[i].second++;
        rows[i + 1].first++;
        finalGrid[i][j] = 'W';
        finalGrid[i + 1][j] = 'B';
        res = dfs(ind + 1);
        if(!res) {
            rows[i].second--;
            rows[i + 1].first--;
            finalGrid[i][j] = '.';
            finalGrid[i + 1][j] = '.';
        }
    }

    if(!res) {
        columns[j].first--, columns[j].second--;
    }
    return res;
}

void solve(){
    cin >> n >> m;
    grid = vector<vector<char>>(n, vector<char>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> grid[i][j];
        }
    }

    bool imp = false;
    dominos.clear();
    charRows.resize(n, 0);
    charCol.resize(m, 0);
    for(int i = 0; i < n; i++) {
        int cells = 0;
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != '.') cells++;
            if(grid[i][j] == 'L') {
                dominos.push_back(mp(i, j));
                charRows[i] += 2;
                charCol[j] += 1;
                charCol[j + 1] += 1;
            }

            if(grid[i][j] == 'U') {
                dominos.push_back(mp(i, j));
                charCol[j] += 2;
                charRows[i] += 1;
                charRows[i + 1] += 1;
            }
        }
        if(cells % 2) {
            imp = true;
        }
    }

    for(int j = 0; j < m; j++) {
        int cells = 0;
        for(int i = 0; i < n; i++) {
            if(grid[i][j] != '.') cells++;
        }
        if(cells % 2) {
            imp = true;
        }
    }

    if(imp) {
        cout << -1 << '\n';
        return;
    }

    rows = vector<pii>(n);
    columns = vector<pii>(m);
    finalGrid = vector<vector<char>>(n, vector<char>(m, '.'));
    if(dominos.empty() || dfs(0)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << finalGrid[i][j];
            }
            cout << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}