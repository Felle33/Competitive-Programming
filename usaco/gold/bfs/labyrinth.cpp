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

ll area(vector<ll> rect) {
	ll width = rect[2] - rect[0];
	ll height = rect[3] - rect[1];
	return width * height;
}

// return 0 if it doesn't intersect
int inter_area(vector<ll> s1, vector<ll> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	ll l1 = min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x);
	ll l2 = min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y);

	if(l1 <= 0 || l2 <= 0) return 0;

	return l1 * l2;
}

// return true if x,y is covered by the rectangle s
bool covered(ll x, ll y, vector<ll> s){
	return x >= s[0] && x <= s[2] && y >= s[1] && y <= s[3];
}

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= MOD;
    while(e > 0){
        if(e & 1)
            res = res * b % MOD;
        
        b = b * b % MOD;
        e >>= 1;
    }

    return res;
}
int n, m;
vector<pair<int, int>> DIRS = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void start(int starti, int startj, vector<vector<char>>& graph){
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m));

    q.push({starti, startj});
    visited[starti][startj] = true;
    parents[starti][startj] = make_pair(-1, -1);

    int ans = 0;
    while(!q.empty()){
        int cycles = q.size();
        ans++;

        while(cycles--){
            pair<int, int> node = q.front();
            q.pop();

            for(pair<int, int> dir : DIRS){
                int newI = node.first + dir.first;
                int newJ = node.second + dir.second;

                if(newI < 0 || newJ < 0 || newI >= n || newJ >= m || visited[newI][newJ] || graph[newI][newJ] == '#') continue;

                visited[newI][newJ] = true;
                parents[newI][newJ] = {node.first, node.second};
                
                if(graph[newI][newJ] != 'B'){
                    q.push({newI, newJ});
                }
                else{
                    cout << "YES" << '\n' << ans << '\n';
                    int i = newI, j = newJ;
                    int pi = parents[i][j].first, pj = parents[i][j].second;
                    vector<char> ans;

                    while(pi != -1 && pj != -1){
                        if(i == pi){
                            if(j < pj) ans.push_back('L');
                            else ans.push_back('R');
                        }
                        else{
                            if(i < pi) ans.push_back('U');
                            else ans.push_back('D');
                        }

                        i = pi, j = pj;
                        pi = parents[i][j].first, pj = parents[i][j].second;
                    }

                    reverse(all(ans));

                    for(char c : ans){
                        cout << c;
                    }

                    return;
                }
            }
        }
    }

    cout << "NO";
}

void solve(){
    
    cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 'A'){
                start(i, j, graph);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout); */

    solve();
}