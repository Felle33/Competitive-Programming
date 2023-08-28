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

vector<vector<char>> grid;

bool contains(char c, int column) {
    int n = grid.size();
    for(int i = 0; i < n; i++) {
        if(grid[i][column] == c) return true;
    }
    return false;
}

void solve(){
    int n, m; cin >> n >> m;
    
    grid = vector<vector<char>>(n, vector<char>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        if(contains('v', i)) {
            for(int j = i + 1; j < m; j++) {
                if(contains('i', j)) {
                    for(int k = j + 1; k < m; k++) {
                        if(contains('k', k)) {
                            for(int l = k + 1; l < m; l++) {
                                if(contains('a', l)) {
                                    cout << "YES\n";
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "NO\n";
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