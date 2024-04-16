#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

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

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, c; cin >> c >> n;
    vi teams(n);
    rep(i, n) {
        int team = 0;
        rep(j, c) {
            char c; cin >> c;
            if(c == 'H') team += (1 << j);
        }
        teams[i] = team;
    }

    queue<int> q;
    vector<int> distances((1 << c) + 1, INF);
    vector<bool> visited((1 << c) + 1);
    for(int team : teams) {
        q.push(team);
        visited[team] = 1;
        distances[team] = 0;
    }

    int dis = 0;
    while(!q.empty()) {
        int cycles = q.size();
        while(cycles--) {
            int node = q.front(); q.pop();
            for(int j = 0; j < c; j++) {
                int newNode = node ^ (1 << j);
                if(!visited[newNode]) {
                    distances[newNode] = dis + 1;
                    visited[newNode] = 1;
                    q.push(newNode);
                }
            }
        }
        dis++;
    }

    for(int team : teams) {
        cout << c - distances[((1 << c) - 1) ^ team] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}