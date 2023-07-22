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

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;

void solve(){
    int x, y, k, m;
    cin >> x >> y >> k >> m;

    vector<vector<bool>> can(x + 1, vector<bool>(y + 1));

    can[0][0] = 1;
    int ans = abs(m);
    while(k--) {
        vector<vector<bool>> next(x + 1, vector<bool>(y + 1));
        for(int i = 0; i <= x; i++) {
            for(int j = 0; j <= y; j++) {
                // i = milk in x, j = milk in y
                if(can[i][j]) {
                    next[i][j] = 1;
                    // fill x
                    next[x][j] = 1;
                    ans = min(ans, abs(m - (x + j)));
                    // fill y
                    next[i][y] = 1;
                    ans = min(ans, abs(m - (i + y)));
                    // empty x
                    next[0][j] = 1;
                    ans = min(ans, abs(m - j));
                    // empty y
                    next[i][0] = 1;
                    ans = min(ans, abs(m - i));
                    // pour x in y
                    int i_plus_j = i + j;
                    if(i_plus_j > y) {
                        int diff = i_plus_j - y;
                        next[diff][y] = 1;
                        ans = min(ans, abs(m - (diff + y)));
                    } else {
                        next[0][i_plus_j] = 1;
                        ans = min(ans, abs(m - i_plus_j));
                    }
                    // pour y in x
                    if(i_plus_j > x) {
                        int diff = i_plus_j - x;
                        next[x][diff] = 1;
                        ans = min(ans, abs(m - (x + diff)));
                    } else {
                        next[i_plus_j][0] = 1;
                        ans = min(ans, abs(m - i_plus_j));
                    }
                }
            }
        }
        can = next;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

    solve();
}