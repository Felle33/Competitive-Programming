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

struct Coord {
    int x, y;
};

int dis(Coord& c1, Coord& c2){
    int difx = c1.x - c2.x;
    int dify = c1.y - c2.y;
    return difx * difx + dify * dify;
}

void calc_path(char c, vector<Coord>& path) {
    Coord last_pos = path.back();
    if(c == 'N') {
        path.push_back({last_pos.x, last_pos.y + 1});
    } else if(c == 'S') {
        path.push_back({last_pos.x, last_pos.y - 1});
    } else if(c == 'W') {
        path.push_back({last_pos.x - 1, last_pos.y});
    } else {
        path.push_back({last_pos.x + 1, last_pos.y});
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    Coord John, Bessie;
    cin >> John.x >> John.y;
    cin >> Bessie.x >> Bessie.y;

    string movementJohn, movementBessie;
    cin >> movementJohn >> movementBessie;

    // coordinate after i movements
    vector<Coord> john_Coord, bessie_Coord;
    john_Coord.push_back(John);
    bessie_Coord.push_back(Bessie);
    for(char c : movementJohn) {
        calc_path(c, john_Coord);
    }

    for(char c : movementBessie) {
        calc_path(c, bessie_Coord);
    }

    // dp[i][j] = minimum radio cost after i steps of john and j steps of bessie
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e18));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dis(john_Coord[i], bessie_Coord[0]);
    }

    for(int i = 1; i <= m; i++) {
        dp[0][i] = dp[0][i - 1] + dis(john_Coord[0], bessie_Coord[i]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + dis(john_Coord[i], bessie_Coord[j]);
        }
    }

    cout << dp[n][m] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);

    solve();
}