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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Player{
    ll points, penalty, index;
};

bool cmp(Player& p1, Player& p2) {
    if(p1.points != p2.points) return p1.points > p2.points;
    if(p1.penalty != p2.penalty) return p1.penalty < p2.penalty;
    return p1.index < p2.index;
}

void solve(){
    int n, m, h;
    cin >> n >> m >> h;

    vector<vector<int>> part(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> part[i][j];
        }
    }

    vector<Player> rank(n);
    int i = 0;
    for(vector<int>& p : part) {
        sort(all(p));
        ll time = 0, penalty = 0;
        int points = 0;

        for(int j = 0; j < m; j++) {
            if(time + p[j] <= h) {
                time += p[j];
                penalty += time;
                points++;
            }
        }

        rank[i] = {points, penalty, i};
        i++;
    }

    sort(all(rank), cmp);
    for(int i = 0; i < n; i++) {
        if(rank[i].index == 0) {
            cout << i + 1 << '\n';
            break;
        }
    }
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